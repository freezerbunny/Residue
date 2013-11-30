#include "RDictionary.h"

RDictionary::RDictionary( std::string filepath ) {
  printf( "RDictionary: Creating dictionary.\n" );

  parser = new RParser( filepath );
  printf( "RDictionary: Created new parser @ %s\n", filepath.c_str() );
  if( !parser->isGood() )
    printf( "RDictionary: Parser reports it is not ready for processing.\n" );

  // Parse the file.
  parse();
  delete parser;
  printf( "RDictionary: Destroyed parser.\n" );
}

void RDictionary::parse() {
  // Get the entities and map them.
  RPackage::Package pack;

  REntity *entity;
  std::string id;
  std::map<std::string, unsigned int> maps;
  std::vector<int> vars;
  std::vector<std::string> strings;
  std::vector<std::string> flags;

  int index = 0;
  while( parser->hasMore() ) {
    pack = parser->getNext();
    if( pack.valid ) {
      id = pack.id;
      maps = pack.mappings;
      vars = pack.vars;
      strings = pack.strings;
      flags = pack.flags;
      entity = new REntity( id, mappings, vars, strings, flags );

      // Push back the new entity.
      entities.push_back( *entity );

      // Finally, map its id.
      mappings[id] = index;
      index++;
    }
  }
  printf( "RDictionary: Parsed entity file. Total @ %d Last @ %s\n", index, id.c_str() );
}

RDictionary::~RDictionary() {
  printf("RDictionary: Destroying dictionary.\n");
}
