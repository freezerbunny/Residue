#include "RDictionary.h"

RDictionary::RDictionary( std::string filepath ) {
  parser = new RParser( filepath );
  printf( "RDictionary: Created new parser @ %s\n", filepath.c_str() );
  if( !parser->isGood() )
    printf( "RDictionary: Parser reports it is not ready for processing.\n" );

  // Parse the file.
  parse();
  delete parser;
}

void RDictionary::parse() {
  // Get the entities and map them.
  RPackage::Package pack;

  REntity *entity;
  std::string id;
  std::map<std::string, unsigned int> mappings;
  std::vector<int> vars;
  std::vector<std::string> strings;
  std::vector<std::string> flags;

  while( parser->hasMore() ) {
    pack = parser->getNext();
    if( pack.valid ) {
      id = pack.id;
      mappings = pack.mappings;
      vars = pack.vars;
      strings = pack.strings;
      flags = pack.flags;
      entity = new REntity( id, mappings, vars, strings, flags );

      // Finally, push back the new entity.
      entities.push_back( *entity );
    }
  }
}

RDictionary::~RDictionary() {
  printf( "RDictionary: Destroyed parser.\n" );
}
