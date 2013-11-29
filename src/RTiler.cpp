#include "RTiler.h"

RTiler::RTiler( SDL_Window *window, SDL_Renderer *renderer, SDL_Surface *tiles, RCol *colormap ) {
  this->window = window;
  this->renderer = renderer;
  this->tiles = tiles;
  this->colormap = colormap;

  // Mapping from string character to alt-code.
  RHandles *r_handles = new RHandles();
  tile_handles = r_handles->tile_handles();
  delete r_handles;

  // Sources and destination rects.
  srcrect = new SDL_Rect;
  srcrect->w = TILE_W, srcrect->h = TILE_H;

  dstrect = new SDL_Rect;
  dstrect->w = TILE_W, dstrect->h = TILE_H;

  // Generate textures.
  safe = false;
  generateTextures();
}

void RTiler::clear() {
  if( SDL_GetWindowFlags( window ) & SDL_WINDOW_INPUT_FOCUS ) {
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
  }
  return;
}

bool RTiler::generateTextures() {
  texture = SDL_CreateTextureFromSurface( renderer, tiles );
  if( !texture ) {
    printf( "RTiler: Could not create texture from surface: %s\n", IMG_GetError() );
    return false;
  }
  safe = true;
  return true;
}

bool RTiler::setTileColour( Uint8 r, Uint8 g, Uint8 b ) {
  if( SDL_SetTextureColorMod( texture, r, g, b ) ) {
    printf( "RTiler: Unable to set tile colour @ %s\n", SDL_GetError() );
    return false;
  }
  return true;
}

bool RTiler::setTileColour( SDL_Color col ) {
  if( !setTileColour( col.r, col.g, col.b ) )
    return false;

  return true;
}

bool RTiler::setTileColour( std::string col ) {
  if( !setTileColour( colormap->getColor( col ) ) )
    return false;

  return true;
}

bool RTiler::outOfBounds( int column, int row ) {
  if( column < 0 || column > TERMINAL_COLUMNS ) {
    return true;
  }
  if( row < 0 || row > TERMINAL_ROWS ) {
    return true;
  }
  return false;
}

bool RTiler::outOfBounds( SDL_Point point ) {
  return outOfBounds( point.x, point.y );
}

bool RTiler::drawTile( int column, int row, int c ) {
  // Check if row is within terminal limits.
  if( outOfBounds( column, row ) ) {
    printf( "RTiler: Tried to draw out of bounds @ %d,  %d\n", row, column );
    return false;
  }

  // Set the draw mode.
  SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );

  // DRAW THE TILE.

  // Determine where to source and destination.
  SDL_Point point = code_to_point( c );
  srcrect->x = point.x * TILE_W;
  srcrect->y = point.y * TILE_H;

  dstrect->x = column * TILE_W;
  dstrect->y = row * TILE_H;


  // Check if it's safe to copy.
  if( !( SDL_GetWindowFlags( window ) & SDL_WINDOW_INPUT_FOCUS ) ) {
    safe = false;
  } else if( !safe ) {
    generateTextures();
  }

  // Copy to the renderer.
  if( safe ) {
    if( SDL_RenderCopy( renderer, texture, srcrect, dstrect ) ) {
      printf( "RTiler: Unable to copy texture to renderer @ %s\n", SDL_GetError() );
      return false;
    }
  }

  return true;
}

bool RTiler::drawTile( int column, int row, std::string c ) {
  if( drawTile( column, row, get_code( c ) ) )
    return true;

  return false;
}

bool RTiler::drawTile( SDL_Point point, std::string c ) {
  if( drawTile( point.x, point.y, c ) )
    return true;

  return false;
}

bool RTiler::drawString( int column, int row, int width, std::string str ) {
  if( !width ) {
    width = column - TERMINAL_COLUMNS;
  }

  // Repeatedly call drawTile to draw the string.
  int cur_column = 0;
  int cur_row = 0;
  int x = 0;
  int y = 0;
  for( std::string::iterator itr = str.begin(); itr != str.end(); ++itr ) {
    if( width && cur_column >= width ) {
      cur_column = 0;
      cur_row++;
    }
    x = cur_column + column;
    y = cur_row + row;
    if( !drawTile( x, y, *itr ) ) {
      return false;
    }
    cur_column++;
  }
  return true;
}

bool RTiler::drawBackground( int column, int row, Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {
  // Initialise rect.
  srcrect->x = column * TILE_W;
  srcrect->y = row * TILE_H;

  // Set the colour.
  SDL_SetRenderDrawColor( renderer, r, g, b, a );

  // Set the draw mode.
  SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );

  // Check if it's safe to copy.
  if( !( SDL_GetWindowFlags( window ) & SDL_WINDOW_INPUT_FOCUS ) ) {
    safe = false;
  } else if( !safe ) {
    generateTextures();
  }
  // Draw the rect.
  if( safe ) {
    if( SDL_RenderFillRect( renderer, srcrect ) ) {
      printf( "RTiler: Unable to fill rect to renderer @ %s\n", SDL_GetError() );
      return false;
    }
  }
  return true;
}

bool RTiler::drawBackground( int column, int row, SDL_Color col ) {
  if( !drawBackground( column, row, col.r, col.g, col.b, col.a ) ) {
    return false;
  }
  return true;
}

bool RTiler::drawBackground( int column, int row, std::string col, Uint8 a ) {
  SDL_Color color = colormap->getColor( col );
  color.a = a;
  if( !drawBackground( column, row, color ) ) {
    return false;
  }
  return true;
}

bool RTiler::drawBackgroundArea( int column, int row, int width, int height,
                                 Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {
  // Repeatedly call drawBackground instead.
  int cur_column = 0;
  int cur_row = 0;
  int x = 0;
  int y = 0;
  int total_tiles = width * height;
  for( int i = 0; i < total_tiles; i++ ) {
    if( cur_column >= width ) {
      cur_column = 0;
      cur_row++;
    }
    x = cur_column + column;
    y = cur_row + row;
    if( !drawBackground( x, y, r, g, b, a ) ) {
      return false;
    }
    cur_column++;
  }
  return true;
}

bool RTiler::drawBackgroundArea( int column, int row, int width, int height,
                                 SDL_Color col ) {
  if( !drawBackgroundArea( column, row, width, height,
                           col.r, col.g, col.b, col.a ) )
    return false;
  return true;
}

bool RTiler::drawBackgroundArea( int column, int row, int width, int height,
                                 std::string col, Uint8 a ) {
  SDL_Color color = colormap->getColor( col );
  color.a = a;
  if( !drawBackgroundArea( column, row, width, height, color ) )
    return false;
  return true;
}

int RTiler::get_code( std::string s ) {
  int c = tile_handles[s];
  return c;
}

SDL_Point RTiler::code_to_point( int kC ) {
  SDL_Point point;
  point.y = kC / 16; // Row.
  point.x = kC % 16; // Column.

  return point;
}

RTiler::~RTiler() {
  //dtor
}
