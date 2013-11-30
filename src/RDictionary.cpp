#include "RDictionary.h"

RDictionary::RDictionary( std::string filepath ) {
  parser = new RParser( filepath );
  printf( "RDictionary: Created new parser @ %s\n", filepath.c_str() );
  if ( !parser->isGood() )
    printf( "RDictionary: Parser reports it is not ready for processing.\n" );

  // Parse the file.
  parse();
}

void RDictionary::parse() {

}

RDictionary::~RDictionary() {
  delete parser;
  printf( "RDictionary: Destroyed parser.\n" );
}
