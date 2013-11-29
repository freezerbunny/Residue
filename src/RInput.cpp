#include "RInput.h"

RInput::RInput( bool mapped ) {
  this->mapped = mapped;
  drawable = NULL;

  limiter = new RLimiter( FRAME_RATE );
}

RInput::RInput( bool mapped, RDrawable *drawable ) {
  this->drawable = drawable;
  this->mapped = mapped;

  limiter = new RLimiter( FRAME_RATE );
}

SDL_Keycode RInput::pollForInput() {
  bool done = false;
  SDL_Keycode input;
  while( !done ) {
    // Message processing loop
    SDL_Event event;
    while( SDL_PollEvent( &event ) ) {
      // Check for messages
      switch( event.type ) {
          // Exit if the window is closed
        case SDL_QUIT:
          input = SDLK_ESCAPE;
          done = true;
          break;

          // Check for keypresses
        case SDL_KEYDOWN:
          if( event.key.keysym.sym == SDLK_ESCAPE ) {
            input = SDLK_ESCAPE;
            done = true;
          }
          break;
      }
    }
    limiter->hold();
    if ( drawable )
      drawable->invoke();
    limiter->release();
  }
  return input;
}

RInput::~RInput() {
  delete limiter;
}
