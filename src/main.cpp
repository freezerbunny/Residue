#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "RInclude.h"

// Global definitions.
#include "RDefs.h"

// Data objects.
#include "REnums.h"
#include "RStructs.h"
#include "RHandles.h"
#include "RCol.h"

// File I/O.
#include "RParser.h"

// Drawing.
#include "RTiler.h"

// Utility
#include "RLimiter.h"
#include "RHoldRelease.h"

// User Interface
#include "RMenu.h"
#include "RTitleScreen.h"

// String manipulation.
#include "RString.h"

// Game.
#include "RController.h"

int main( int argc, char **argv ) {
  // SDL INITIALISATION
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "main: Unable to init SDL: %s\n", SDL_GetError() );
    return 1;
  }

  // Clean up before exit
  atexit( SDL_Quit );

  // Create a new window
  int screen_width = TERMINAL_COLUMNS * TILE_W;
  int screen_height = TERMINAL_ROWS * TILE_H;

  SDL_Window *window = SDL_CreateWindow( "Residue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                         screen_width, screen_height, 0 );
  if( !window ) {
    printf( "main: Unable to set video: %s\n", SDL_GetError() );
    return 1;
  }

  // Create a new renderer
  SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED & SDL_RENDERER_SOFTWARE );
  if( !renderer ) {
    printf( "main: Could not initialise renderer: %s\n", SDL_GetError() );
    return 1;
  }

  // Load tiles
  SDL_Surface *tile_surface;
  tile_surface = IMG_Load( "resources/tiles/alloy_curses_12x12_alpha.png" );
  if( !tile_surface ) {
    printf( "main: Could not load tileset: %s\n", IMG_GetError() );
    return 1;
  }

  // Load colormap.
  RCol *colormap = new RCol;
  colormap->parseColorFile( "resources/dat/colors.rdat" );

  // OBJECT INTIALISATION

  // Create tile drawer.
  RTiler *rtiler = new RTiler( window, renderer, tile_surface, colormap );
  // Declare game objects.
  RController *controller;

  // START TITLE SCREEN
  RTitleScreen *titlescreen = new RTitleScreen( rtiler  );
  switch ( titlescreen->enter() ) {
    case SDLK_d:  // Begin debug.
      // ENTER GAME.
      controller = new RController( rtiler );
      delete controller;
      // EXIT GAME
      break;
    case SDLK_ESCAPE:
      break;
  } // END TITLE SCREEN

  delete titlescreen;

  // Call deconstructors.
  delete rtiler;
  delete colormap;
  delete tile_surface;

  // All is well!
  printf( "main: Exited cleanly.\n" );
  return 0;
}
