#include "RRand.h"

RRand::RRand( unsigned int seed ) {
  this->seed = seed;
  srand( seed );
}

int RRand::random( int base, int range ) {
  int rng = rand() % range + base;
  return rng;
}

RRand::~RRand() {
}
