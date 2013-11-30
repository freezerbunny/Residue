#include "RModel.h"

RModel::RModel() {
  printf("RModel: Creating new model.\n");
  // Create blocks.
  RBlock *block = new RBlock;
  blocks.push_back(*block);
  printf("RModel: Pushed back a block.\n");
}

RModel::~RModel() {
  printf("RModel: Destroying model.\n");
  // Save blocks.
  // Destroy them.
  blocks.clear();
  printf("RModel: Destroyed blocks.\n");
}
