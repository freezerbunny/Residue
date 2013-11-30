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
  char *part = new char[256];
  package.get( part, 64, '@' );
  pack.id = part;

  // Ready the map handle.
  char *handle;

  // Now grab data.
  // 0: vars, 1: strings, 2: flags.
  int level = 0;

  bool start;
  int col;
  int handlecol;
  unsigned int id = 0;
  while( package.peek() != EOF ) {
    start = false;
    delete []part;
    delete []handle;
    part = new char[256];
    handle = new char[64];
    handlecol = 0;
    col = 0;

    while( package.get( c ) ) {
      if( c == '!' ) {
        break;
      }
      if( c == ',' || c == ';' || c == '!' ) {
        part[col] = '\0';
        break;
      }
      if( start ) {
        part[col] = c;
        col++;
      }
      if( c == ':' ) {
        start = true;
        // Push back the current handle.
        handle[handlecol] = '\0';
        pack.mappings[handle] = id;
        continue;
      }
      if( !start && c != '@' && c != ' ' ) {
        handle[handlecol] = c;
        handlecol++;
      }
    }
    if( start ) {
      // Vars.
      if( level == 0 ) {
        pack.vars.push_back( atoi( part ) );
        id++;
      }
      // Strings.
      else if( level == 1 ) {
        pack.strings.push_back( part );
        id++;
      }
      // Flags.
      else {
        pack.flags.push_back( part );
        id++;
      }
      if( c == ';' )
        break;
    }
    if( c == '!' ) {
        level++;
        continue;
    }
  }
  pack.valid = true;

  delete []part;
  delete []handle;

  return pack;
}

RParser::~RParser() {
  input.close();
}
