#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

#include "RTile.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define TILES_WIDTH 192
#define TILES_HEIGHT 192
#define TILE_WIDTH 12
#define TILE_HEIGHT 12

int main( int argc, char **argv ) {
  // Initialize SDL video
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    return 1;
  }

  // Clean up before exit
  atexit( SDL_Quit );

  // Create a new window
  SDL_Window *window = SDL_CreateWindow( "Residue", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                         SCREEN_WIDTH, SCREEN_HEIGHT, 0 );
  if( !window ) {
    printf( "Unable to set 640x480 video: %s\n", SDL_GetError() );
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

  // Initialise tiles class.
  RTile tile_renderer = RTile( renderer, texture, TILE_WIDTH, TILE_HEIGHT );

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

    // DRAWING ENDS HERE

    // Update the screen
    SDL_RenderPresent( renderer );

    // Wait until next execution.
    SDL_Delay( 100 );

  } // MAIN LOOP ENDS HERE

  // Call deconstructors.

  // All is well!
  printf( "Exited cleanly.\n" );
  return 0;
}
