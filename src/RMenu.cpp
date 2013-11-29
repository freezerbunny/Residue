#include "RMenu.h"

RMenu::RMenu( RTiler *rtiler, int row, int column, int width, RMenuType::MenuType type, RDrawable *drawable ) {
  this->rtiler = rtiler;
  this->drawable = drawable;
  this->row = row;
  this->col = column;
  this->width = width;
  this->type = type;
  choice = 0;

  rinput = new RInput( false, this );
}

bool RMenu::addEntry( RMenuEntry::Entry entry ) {
  entries.push_back( entry );
  return true;
}

RMenuEntry::Entry RMenu::enter() {
  bool done = false;
  while ( !done ) {
      switch( rinput->pollForInput() ) {
      case SDLK_ESCAPE:
        choice = entries.size() - 1;
        done = true;
        break;
      }
  }
  return entries[choice];
}

void RMenu::invoke() {
  if( drawable )
    drawable->invoke();
  return;
}

RMenu::~RMenu() {
  delete rinput;
}
