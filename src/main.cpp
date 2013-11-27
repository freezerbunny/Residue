#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

#include "Rinclude.h"

int main( int argc, char **argv ) {
  // SDL INITIALISATION
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    return 1;
  }

  // Clean up before exit
  atexit( SDL_Quit );

  // Create a new window
  int screen_width = TERMINAL_ROWS * TILE_W;
  int screen_height = TERMINAL_COLUMNS * TILE_H;

  SDL_Window *window = SDL_CreateWindow( "Residue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                         screen_width, screen_height, 0 );
  if( !window ) {
    printf( "Unable to set video: %s\n", SDL_GetError() );
    return 1;
  }

  // Create a new renderer
  SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_SOFTWARE || SDL_RENDERER_ACCELERATED );
  if( !renderer ) {
    printf( "Could not initialise renderer: %s\n", SDL_GetError() );
    return 1;
  }

  // Load tiles
  SDL_Surface *tile_surface;
  tile_surface = IMG_Load( "resources/tiles/alloy_curses_12x12_alpha.png" );
  if( !tile_surface ) {
    printf( "Could not load tileset: %s\n", IMG_GetError() );
    return 1;
  }

  // Create texture from tiles.
  SDL_Texture *texture;
  texture = SDL_CreateTextureFromSurface( renderer, tile_surface );
  if ( !texture ) {
    printf( "Could not create texture from surface: %s\n", IMG_GetError() );
  }

  // OBJECT INTIALISATION

  // Initialise tiles objects.
  RTile *tile_renderer = new RTile( renderer, texture );

  // MAIN LOOP STARTS HERE
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

    // DRAWING STARTS HERE

    // Clear screen
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );

    // Draw elements.

    // DRAWING ENDS HERE

    // Update the screen
    SDL_RenderPresent( renderer );

    // Wait until next execution.
    SDL_Delay( 100 );

  } // MAIN LOOP ENDS HERE

  // Call deconstructors.
  delete tile_renderer;

  // All is well!
  printf( "Exited cleanly.\n" );
  return 0;
}
