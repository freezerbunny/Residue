#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "SDL.h"
#include "SDL_image.h"

int main( int argc, char **argv ) {
  // Initialize SDL video
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "Unable to init SDL: %s\n", SDL_GetError() );
    return 1;
  }

  // Clean up before exit
  atexit( SDL_Quit );

  // Create a new window
  SDL_Surface *screen = SDL_SetVideoMode( 640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF );
  if( !screen ) {
    printf( "Unable to set 640x480 video. SDL_SetVideoMode: %s\n", SDL_GetError() );
    return 1;
  }

  // Load tiles
  SDL_Surface *tiles;
  tiles = IMG_Load("resources/tiles/alloy_curses_12x12_alpha.png");
  if(!tiles) {
      printf("Could not load tileset. IMG_Load: %s\n", IMG_GetError());
      // handle error
  }

  // Program main loop
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
    SDL_FillRect( screen, 0, SDL_MapRGB( screen->format, 0, 0, 0 ) );

    // DRAWING ENDS HERE

    // Finally, update the screen
    SDL_Flip( screen );
  } // End main loop

  // All is well!
  printf( "Exited cleanly\n" );
  return 0;
}
