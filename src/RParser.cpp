#include "RParser.h"

RParser::RParser( std::string filepath ) {
  this->filepath = filepath;
  input.open( filepath.c_str() );
}

bool RParser::isGood() {
  if( input.bad() ) {
    printf( "RParser: Error on stream @ %s\n", filepath.c_str() );
    return false;
  }
  if( input.fail() ) {
    return false;
  }
  if( input.is_open() ) {
    return true;
  }
  return false;
}

bool RParser::hasMore() {
  return !input.eof();
}

RPackage::Package RParser::getNext() {
  RPackage::Package pack;

  // Package assumed invalid until all parsing passes.
  pack.valid = false;

  std::string id;

  std::vector<int> variables;
  std::vector<std::string> strings;
  std::vector<std::string> flags;

  // PARSING BEGINS.
  // Parse the package.
  char c;
  std::stringstream package;

  bool comment = false;
  while( hasMore() ) {
    c = input.get();

    // Ignore commented line.
    if( c == '\n' )
      comment = false;
    if( c == '#' ) {
      comment = true;
      continue;
    }

    // Extract character to stream.
    if( !comment ) {
      if( c == '\n' )
        continue;
      package << c;

      if( c == ';' )
        break;
    }
  }
  if( !isGood() ) {
    return pack;
  }

  // Now grab the id.
  char *part = new char[64];
  package.get( part, 64, '@' );
  pack.id = part;

  // Now grab the vars.
  std::stringstream varstream;

  bool start;
  int col;
  while( package.peek() != -1 ) {
    start = false;
    delete []part;
    part = new char[64];
    col = 0;

    while( package.get( c ) ) {
      if( c == ',' )
        break;
      if( start ) {
        part[col] = c;
        col++;
      }
      if( c == ':' ) {
        start = true;
        continue;
      }
    }
    if( start ) {
      if( c == '!' )
        break;
      pack.vars.push_back( atoi( part ) );
    }
  }
  pack.valid = true;

  delete []part;

  return pack;
}

RParser::~RParser() {
  input.close();
}
