#include "RTitleScreen.h"

RTitleScreen::RTitleScreen( RTiler *rtiler ) {
  this->rtiler = rtiler;

  mainmenu = new RMenu( rtiler, 0, 0, 60, RMenuType::MAINMENU, this );
  mainmenu_entry.name = "Exit";
  mainmenu_entry.color = "white";
  mainmenu_entry.key = SDLK_ESCAPE;
  mainmenu->addEntry( mainmenu_entry );

  // Logo
  rng = new RRand();
  glitched = 0;
  moverx = 0;
  movery = 0;

  // Particles
  maxparticles = 12;

  holdrelease = new RHoldRelease( 6 );
}

bool RTitleScreen::enter() {
  bool done = false;
  RMenuEntry::Entry choice;
  while( !done ) {
    // Enter the main menu.
    choice = mainmenu->enter();
    switch( choice.key ) {
      case SDLK_ESCAPE:
        done = true;
        break;
    }
  }
  return true;
}

void RTitleScreen::invoke() {
  drawMainMenu();
  return;
}

bool RTitleScreen::drawMainMenu() {
  // Clear screen
  rtiler->drawBackgroundArea( 0, 0, TERMINAL_COLUMNS, TERMINAL_ROWS, "black", 255 );

  // HOLD LIMITER.
  holdrelease->hold();
  bool release = holdrelease->release();

  // START DRAWING.
  // Floating particles.
  if( release ) {
    if( particles.size() + backparticles.size() < maxparticles && rng->chance( 1, 12 ) ) {
      // Create new particles.
      int newparticles = rng->random( 1, 3 );
      for( int i = 0; i < newparticles; i++ ) {
        // Construct new particles.
        RTitleParticle particle( TERMINAL_COLUMNS, TERMINAL_ROWS,
                                 rng->random( 0, 48 ) );
        if( rng->chance( 1, 4 ) )
          particles.push_back( particle );
        else
          backparticles.push_back( particle );
      }
    }
  }
  int linger = rng->random(1, 11);
  // Iterate our particles and draw them.
  SDL_Point particle_point;
  rtiler->setTileColour( "almostblack" );
  for( std::vector<RTitleParticle>::iterator itr = backparticles.begin();
       itr != backparticles.end(); ++itr ) {
    if( release && ( ( linger + particle_point.y ) % 2 ) )
      particle_point = itr->iterate();
    else
      particle_point = itr->get();

    if( !rtiler->outOfBounds( particle_point ) )
      rtiler->drawTile( particle_point, "·" );

    // Destroy the particle.
    if( itr->died() ) {
      backparticles.erase( itr );
    }
  }
  rtiler->setTileColour( "darkgrey" );
  for( std::vector<RTitleParticle>::iterator itr = particles.begin();
       itr != particles.end(); ++itr ) {
    if( release && ( ( linger + particle_point.y ) % 2 ) )
      particle_point = itr->iterate();
    else
      particle_point = itr->get();

    if( !rtiler->outOfBounds( particle_point ) )
      rtiler->drawTile( particle_point, "∙" );

    // Destroy the particle.
    if( itr->died() ) {
      particles.erase( itr );
    }
  }

  // Logo.
  std::stringstream logo;
  logo << "### ### ### # ##  # # ###\n";
  logo << "# # #   ##  # # # # # ## \n";
  logo << "##  ##    # # # # # # #  \n";
  logo << "# # ### ### # ### ### ###\n";
  char line[26];
  int row = 0;
  int left = TERMINAL_COLUMNS / 2 - 13;
  int top = TERMINAL_ROWS / 2 - 9;

  if( release ) {
    glitched = rng->random( 0, 25 );
    moverx += rng->random( -1, 3 );
    movery += rng->random( -1, 3 );
    if( moverx < 0 || moverx > 25 )
      moverx = 0;
    if( movery < 0 )
      movery = 0;
    if( movery > 3 )
      movery = 3;
  }

  rtiler->setTileColour( "aliceblue" );
  while( logo.getline( line, 26 ) ) {
    for( int i = 0; i < 26; i++ ) {
      if( line[i] == '#' ) {
        if( i == moverx && row == movery ) {
          rtiler->drawTile( left + i, top + row, "░" );
        } else if( i == glitched ) {
          rtiler->drawTile( left + i, top + row, "▒" );
        } else {
          rtiler->drawTile( left + i, top + row, "▓" );
        }
      }
    }
    row++;
  }

  // Update the screen
  rtiler->flush();

  return true;
}

RTitleScreen::~RTitleScreen() {
  delete mainmenu;
  delete rng;
  delete holdrelease;
}
