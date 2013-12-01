#include "RModel.h"

RModel::RModel( RDictionary *dictionary ) {
  printf( "RModel: Creating new model.\n" );
  this->dictionary = dictionary;

  // Create initial blocks.
  printf( "RModel: \n" );
  for( int x = 0; x < 3; x++ ) {
    for( int y = 0; y < 3; y++ ) {
      addNewBlock( x, y );
      printf( "        Pushed back a block @ %d, %d\n", x, y );
    }
  }
  // Update the active blocks.
  updateActiveBlocks( 1, 1 );

  // Create the player.
  addNewEntity( 1, 1, 128, 128, "player" );
  printf( "RModel: Added the player!\n" );
}

void RModel::addNewEntity( unsigned int blockx, unsigned int blocky, int bitx, int bity, std::string id ) {
  if ( dictionary->find( id ) ) {
    // Create a new entity from the id.
    REntity new_entity = dictionary->lookup( id );
    // Get the right block.
    RBlock *block = referenceBlockAt( blockx, blocky );
    // Get a rand bit.
  }
  return;
}

void RModel::addNewBlock( unsigned int x, unsigned int y ) {
  RBlock block( x, y );
  // Create mapping.
  mapping[std::make_pair( x, y )] = blocks.size();
  // Push back the block.
  blocks.push_back( block );
  return;
}

RBlock *RModel::referenceBlockAt( unsigned int x, unsigned int y ) {
  return &blocks[mapping[std::make_pair( x, y )]];
}

bool RModel::updateActiveBlocks( unsigned int x, unsigned int y ) {
  currentx = x;
  currenty = y;

  currentblock = referenceBlockAt( currentx, currenty );
  for ( int i = 0; i < 3; i++ ) {
    for ( int j = 0; j < 3; j++ ) {
      activeblocks[i][j] = referenceBlockAt( i, j );
    }
  }
  printf( "RModel: Updated active blocks\n" );
  return true;
}

RModel::~RModel() {
  printf( "RModel: Destroying model.\n" );
  // Save blocks.
  // Destroy them.
  blocks.clear();
  printf( "RModel: Destroyed blocks.\n" );
}
