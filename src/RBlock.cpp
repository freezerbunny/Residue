#include "RBlock.h"

RBlock::RBlock( unsigned int x, unsigned int y ) {
  this->x = x;
  this->y = y;
}

void RBlock::setBit( unsigned char x, unsigned char y, RBit::Bit bit ) {
  bit.x = x;
  bit.y = y;
  bits[x][y] = bit;
  return;
}

RBit::Bit RBlock::getBit( unsigned char x, unsigned char y ) {
  return bits[x][y];
}

RBlock::~RBlock() {
}
