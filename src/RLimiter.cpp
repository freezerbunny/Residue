#include "RLimiter.h"

RLimiter::RLimiter( int framerate ) {
  framerate_ = framerate;
}

void RLimiter::hold() {
  start = SDL_GetTicks();
  ready = true;
  return;
}

void RLimiter::release() {
  elapsed = SDL_GetTicks() - start;

  unsigned int delay = ( 1000 / framerate_ ) - elapsed;
  if ( int(delay) < 1000 / framerate_ )
    SDL_Delay( delay );
  ready = false;
  return;
}

RLimiter::~RLimiter() {
  //dtor
}
