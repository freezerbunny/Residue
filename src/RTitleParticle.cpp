#include "RTitleParticle.h"

RTitleParticle::RTitleParticle( int columns, int rows, int startingrow ) {
  posx = 0;
  posy = 0;

  this->columns = columns;
  this->rows = rows;
  this->startingrow = startingrow;

  RRand rng;
  amplitude = static_cast<float>( rng.random( 2, 8 ) );
  wavelength = static_cast<float>( rng.random( 1, 100 ) ) * 0.005;

  died_ = false;
}

SDL_Point RTitleParticle::iterate() {
  posx++;
  posy = sin( posx * wavelength ) * amplitude + startingrow;

  SDL_Point point;
  point.x = floor( posx );
  point.y = floor( posy );

  // If we exceed the max column, warp to the other side and die.
  if( point.x > columns ) {
    point.x = 0;
    posx = 0;
    died_ = true;
  }
  return point;
}

SDL_Point RTitleParticle::get() {
  SDL_Point point;
  point.x = floor( posx );
  point.y = floor( posy );

  return point;
}

RTitleParticle::~RTitleParticle() {
}
