#include "RHoldRelease.h"

RHoldRelease::RHoldRelease( int rate ) : RLimiter::RLimiter( rate ) {
}

void RHoldRelease::hold() {
  if( !ready ) {
    RLimiter::hold();
    start = RLimiter::get_start();
  }
  ready = true;
  return;
}

bool RHoldRelease::release() {
  elapsed = SDL_GetTicks() - start;

  if( ready && static_cast<int>( elapsed ) > 1000 / RLimiter::get_rate() ) {
    ready = false;
    return true;
  }
  return false;
}

RHoldRelease::~RHoldRelease() {
  //dtor
}
