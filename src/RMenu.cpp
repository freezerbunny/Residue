#include "RMenu.h"

RMenu::RMenu( RTile *rtiler, int row, int column, int width, RMenuType::MenuType type ) {
  this->rtiler = rtiler;
  this->type = type;
  this->row = row;
  this->col = column;
  this->width = width;
  current = 0;
}

bool RMenu::addEntry( std::string name, std::string col, SDL_Keycode key ) {
  RMenuEntry::Entry entry;
  entry.name = name;
  entry.color = col;
  entry.key = key;

  entries.push_back( entry );
  return true;
}

int RMenu::enter() {
  bool done = false;
  while( !done ) {
    // Message processing loop
    SDL_Event event;
    while( SDL_PollEvent( &event ) ) {
      // Check for messages
      switch( event.type ) {
          // Exit if the window is closed
        case SDL_QUIT:
          done = true;
          break;

          // Check for keypresses
        case SDL_KEYDOWN: {
            // Exit if ESCAPE is pressed
            if( event.key.keysym.sym == SDLK_ESCAPE )
              done = true;
            break;
          }
      }
    }

    // DRAWING STARTS HERE.
    switch( type ) {
      case MAINMENU:
        break;
      default:
        break;
    }
  }
}

bool drawMainMenu() {
  // Clear screen
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
  SDL_RenderClear( renderer );

  // Start drawing.
  for (

  // Update the screen
  SDL_RenderPresent( renderer );

  // Wait until next execution.
  SDL_Delay( 100 );
}

RMenu::~RMenu() {
}
