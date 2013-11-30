#include "RBlock.h"

RBlock::RBlock() {
  // Generate bits.
//  REntity entity;
//  for( int x = 0; x < 256; x++ ) {
//    for( int y = 0; y < 256; y++ ) {
//      bits[x][y].entities.push_back(entity);
//    }
//  }
//  printf( "RBlock: Generated bits.\n" );
}

void RBlock::setBit( unsigned char x, unsigned char y, RBit::Bit bit ) {
  bits[x][y] = bit;
  return;
}

RBit::Bit RBlock::getBit( unsigned char x, unsigned char y ) {
  return bits[x][y];
}

RBlock::~RBlock() {
}
