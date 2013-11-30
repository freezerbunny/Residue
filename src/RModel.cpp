#include "RModel.h"

RModel::RModel() {
  // Create blocks.
  RBlock *block = new RBlock;
  blocks.push_back(*block);
  printf("RModel: Pushed back a block.\n");
}

RModel::~RModel() {
  // Save blocks.
  // Destroy them.
  blocks.clear();
  printf("RModel: Destroyed blocks.\n");
}
