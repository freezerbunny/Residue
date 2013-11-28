#include "RCol.h"

RCol::RCol() {
  //ctor
}

bool RCol::readColorFile( std::string filepath ) {
  // Parse the colour file.
  RParser *parser = new RParser( filepath );

  if( !parser->isGood() ) {
    printf( "RCol: Unable to parse colour file @ %s\n", filepath.c_str() );
    return false;
  }

  // Map colour names.
  RPackage::Package pack;

  SDL_Color color;
  while( parser->hasMore() ) {
    pack = parser->getNext();
    if( pack.valid ) {
      color.r = pack.vars[0];
      color.g = pack.vars[1];
      color.b = pack.vars[2];
      color.a = 255;

      color_map[pack.name] = color;
    }
  }

  delete parser;
  return true;
}

SDL_Color RCol::getColor( std::string name ) {
  std::map<std::string, SDL_Color>::iterator itr;
  itr = color_map.find( name );

  if ( itr == color_map.end() ) {
    printf( "RCol: Couldn't find mapped color @ %s. Returning default.\n", name.c_str() );
    return color_map["white"];
  }

  return color_map[name];
}

RCol::~RCol() {
  //dtor
}
