#include "RRand.h"

RRand::RRand( unsigned int seed ) {
  this->seed = seed;
  srand( seed );
}

RRand::RRand() {
  seed = time(nullptr);
  srand (seed);
}

int RRand::random( int base, int range ) {
  last = rand();
  lastrange = range;
  int rng = last % range + base;
  return rng;
}

int RRand::steal( int base, int range ) {
  int rng = last % range + base;
  if ( range == lastrange )
    printf("RRand: Warning. Stolen number may a duplicate @ %d\n", rng);
  return rng;
}

int RRand::roll ( int number, int sides ) {
  int total = 0;
  for ( int i = 0; i < number; i++ ) {
    total += random( 1, sides );
  }
  return total;
}

bool RRand::chance ( int numerator, int denominator ) {
  if ( numerator >= random( 1, denominator ) )
    return true;
  return false;
}

RRand::~RRand() {
}
