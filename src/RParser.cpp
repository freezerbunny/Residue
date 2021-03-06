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
  bool escape = false;
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

      if( c == '\\' ) {
        escape = true;
        continue;
      }
      escape = false;

      if( c == ';' && !escape )
        break;
    }
  }
  if( !isGood() ) {
    return pack;
  }

  // Now grab the id.
  char *part = new char[256];
  package.get( part, 64, '@' );
  std::stringstream dump;
  for ( int i = 0; i < 256; i++ ) {
    if ( part[i] == ' ' )
      continue;
    if ( part[i] == '\0' )
      break;
    dump << part[i];
  }
  pack.id = dump.str();

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
    escape = false;
    delete []part;
    delete []handle;
    part = new char[256];
    handle = new char[64];
    handlecol = 0;
    col = 0;

    while( package.get( c ) ) {
      if( !escape ) {
        if( c == ',' || c == ';' || c == '!' ) {
          part[col] = '\0';
          break;
        }
        if( c == ' ' && !start ) {
          continue;
        }
      }
      if( c == '\\' ) {
        escape = true;
        continue;
      }
      escape = false;
      if( start ) {
        part[col] = c;
        col++;
      }
      if( c == ':' && !start ) {
        start = true;
        // Push back the current handle.
        handle[handlecol] = '\0';
        if ( level < 2 )
          pack.mappings[handle] = id;
        continue;
      }
      if( !start && c != '@' && level < 2 ) {
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
        id = 0;
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
