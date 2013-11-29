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
    }
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
  int middle = col + width / 2 + 1;

  // Draw text for every entry.
  int currow = row;
  for( std::vector<RMenuEntry::Entry>::iterator it = entries.begin();
       it != entries.end(); ++it ) {

    if( it != entries.begin() )
      currow++;
    rtiler->drawBackgroundArea( middle - it->name.length() / 2, currow, width, 1, "black", 255 );
    rtiler->setTileColour( "aliceblue" );
    rtiler->drawString( middle - it->name.length(), currow, width, it->name );
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
