#include "RMenu.h"

RMenu::RMenu( RTile *rtiler, int row, int column, int width, RMenuType::MenuType type ) {
  this->rtiler = rtiler;
  this->row = row;
  this->col = column;
  this->width = width;
  this->type = type;
  current = 0;

  // Main menu graphics.
  if (type == RMenuType::MAINMENU) {
    rrand = new RRand(6549234);
    glitched = 0;
    moverx = 0;
    movery = 0;
    holdrelease = new RHoldRelease(6);
  }
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
      case RMenuType::MAINMENU:
        drawMainMenu();
        break;
      default:
        break;
    }
  }
  return 0;
}

bool RMenu::drawMainMenu() {
  // Clear screen
  rtiler->drawBackgroundArea(0, 0, TERMINAL_COLUMNS, TERMINAL_ROWS, "black", 255);

  // HOLD LIMITER.
  RLimiter *limiter = new RLimiter(FRAME_RATE);
  limiter->hold();
  holdrelease->hold();

  // START DRAWING.
  // Title.
  std::stringstream logo;
  logo << "### ### ### # ##  # # ###\n";
  logo << "# # #   ##  # # # # # ## \n";
  logo << "##  ##    # # # # # # #  \n";
  logo << "# # ### ### # ### ### ###\n";
  char line[26];
  int row = 0;
  int left = TERMINAL_COLUMNS / 2 - 13;
  int top = TERMINAL_ROWS / 2 - 9;

  if( holdrelease->release() ) {
    glitched = rrand->random(0, 25);
    moverx += rrand->random(-1, 3);
    movery += rrand->random(-1, 3);
    if (moverx < 0 || moverx > 25)
      moverx = 0;
    if (movery < 0)
      movery = 0;
    if (movery > 3)
      movery = 3;
  }

  rtiler->setTileColour("aliceblue");
  while ( logo.getline(line, 26) ) {
    for( int i = 0; i < 26; i++ ) {
      if ( line[i] == '#' ) {
        if ( i == moverx && row == movery ) {
          rtiler->drawTile(left + i, top + row, "░");
        }
        else if ( i == glitched ) {
          rtiler->drawTile(left + i, top + row, "▒");
        }
        else {
          rtiler->drawTile(left + i, top + row, "▓");
        }
      }
    }
    row++;
  }

  // Floating particles.

  // Update the screen
  rtiler->flush();

  // RELEASE LIMITER.
  limiter->release();
  delete limiter;
  return true;
}

RMenu::~RMenu() {
  if ( type == RMenuType::MAINMENU ) {
    delete rrand;
    delete holdrelease;
  }
}
