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

  // Generate bindings.
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

  // Create entities.
  int index = 0;
  while( parser->hasMore() ) {
    pack = parser->getNext();
    if( pack.valid ) {
      id = pack.id;
      maps = pack.mappings;
      vars = pack.vars;
      strings = pack.strings;
      flags = pack.flags;
      entity = new REntity( id, maps, vars, strings, flags );

      // Push back the new entity.
      entities.push_back( *entity );

      // Finally, map its id.
      mappings[id] = index;
      index++;
    }
  }
  printf( "RDictionary: Parsed entity file. Total @ %d, Last @ %s\n", index, id.c_str() );
  printf( "             Name @ %s, Character @ %s\n",
          strings[maps["name"]].c_str(), strings[maps["character"]].c_str() );
}

bool RDictionary::find( std::string id ) {
  std::map<std::string, unsigned int>::iterator it = mappings.find( id );
  if( it == mappings.end() ) {
    printf( "RDictionary: Could not find an entity with the id @ %s\n", id.c_str() );
    printf( "             \"If an item does not appear in our records, it does not exist!\"\n" );
    return false;
  }
  return true;
}

REntity RDictionary::lookup( std::string id ) {
  printf( "RDictionary: Looking up %s\n", id.c_str() );
  return entities[mappings[id]];
}

RDictionary::~RDictionary() {
  printf( "RDictionary: Destroying dictionary.\n" );
}
