#include "RMenu.h"

RMenu::RMenu( RTiler *rtiler, int column, int row, int width, RMenuType::MenuType type, RDrawable *drawable ) {
  this->rtiler = rtiler;
  this->drawable = drawable;
  this->col = column;
  this->row = row;
  this->width = width;
  this->type = type;
  choice = 0;
  maxstringlength = 0;

  rinput = new RInput( false, this );
}

bool RMenu::addEntry( RMenuEntry::Entry entry ) {
  maxstringlength += entry.name.length();
  entries.push_back( entry );
  return true;
}

RMenuEntry::Entry RMenu::enter() {
  bool done = false;
  while( !done ) {
    switch( rinput->pollForInput() ) {
      case SDLK_ESCAPE:
        choice = entries.size() - 1;
        done = true;
        break;
      case SDLK_RETURN:
      case SDLK_RETURN2:
      case SDLK_KP_ENTER:
        done = true;
        break;
      case SDLK_KP_4:
        choice++;
        break;
      case SDLK_KP_6:
        choice++;
        break;
    }
    if ( choice >= entries.size() )
      choice = 0;
    if ( choice < 0 )
      choice = entries.size() - 1;
  }
  return entries[choice];
}

bool RMenu::draw() {
  switch( type ) {
    case RMenuType::MAINMENU:
      drawMainMenu();
      break;
    default:
      break;
  }
  return true;
}

bool RMenu::drawMainMenu() {
  // Draw menu based on type.
  int middle = col + width / 2 + 2;

  // Draw text for every entry.
  int pos = middle - ( entries.size() * 2 + maxstringlength / 2 );
  unsigned int cur = 0;
  for( std::vector<RMenuEntry::Entry>::iterator it = entries.begin();
       it != entries.end(); ++it ) {
    if( it != entries.begin() )
      pos += it->name.length() + 2;
    if( cur == choice )
      rtiler->drawBackgroundArea( pos, row, it->name.length(), 1, "darkblue", 255 );
    else
      rtiler->drawBackgroundArea( pos, row, it->name.length(), 1, "black", 255 );
    rtiler->setTileColour( it->color );
    rtiler->drawString( pos, row, width, it->name );
    cur++;
  }
  return true;
}

void RMenu::invoke() {
  rtiler->clear();
  if( drawable )
    drawable->invoke();
  draw();
  rtiler->flush();
  return;
}

RMenu::~RMenu() {
  delete rinput;
}
