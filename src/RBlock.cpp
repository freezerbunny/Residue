#include "RBlock.h"

RBlock::RBlock( unsigned int x, unsigned int y ) {
  this->x = x;
  this->y = y;
}

void RBlock::setBit( RBit::Bit *bit ) {
  bits[x][y] = bit;
  return;
}

RBit::Bit *RBlock::getBit( unsigned char x, unsigned char y ) {
  RBit::Bit *bit;
  if ( bits[x][y] == nullptr ) {
    bit = new RBit::Bit;
    bit->x = x;
    bit->y = y;
    return bit;
  }
  return bits[x][y];
}

RBlock::~RBlock() {
}
