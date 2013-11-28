#include "RTile.h"

RTile::RTile( SDL_Renderer *renderer, SDL_Texture *tiles ) {
  this->renderer = renderer;
  this->tiles = tiles;

  // Mapping from string character to alt-code.
  RHandles *r_handles = new RHandles();
  tile_handles = r_handles->tile_handles();
  delete r_handles;

  // Sources and destination rects.
  srcrect = new SDL_Rect;
  srcrect->w = TILE_W, srcrect->h = TILE_H;

  dstrect = new SDL_Rect;
  dstrect->w = TILE_W, dstrect->h = TILE_H;
}

bool RTile::setTileColour( Uint8 r, Uint8 g, Uint8 b ) {
  if( SDL_SetTextureColorMod( tiles, r, g, b ) ) {
    printf( "RTile: Unable to set tile colour @ %s\n", SDL_GetError() );
    return false;
  }
  return true;
}

bool RTile::setTileColour( SDL_Color col ) {
  if( !setTileColour( col.r, col.g, col.b ) )
    return false;

  return true;
}

bool RTile::drawTile( int column, int row, int c ) {
  // Check if row is within terminal limits.
  if( row < 0 || row > TERMINAL_ROWS ) {
    printf( "RTile: Tried to draw out of bounds @ %d,  %d\n", row, column );
    return false;
  }
  if( column < 0 || column > TERMINAL_COLUMNS ) {
    printf( "RTile: Tried to draw out of bounds @ %d,  %d\n", row, column );
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

  // Copy to the renderer.
  if( SDL_RenderCopy( renderer, tiles, srcrect, dstrect ) ) {
    printf( "RTile: Unable to copy texture to renderer @ %s\n", SDL_GetError() );
    return false;
  }

  return true;
}

bool RTile::drawTile( int column, int row, std::string c ) {
  if( drawTile( column, row, get_code( c ) ) ) {
    return true;
  }
  return false;
}

bool RTile::drawString( int column, int row, int width, std::string str ) {
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

bool RTile::drawBackground( int column, int row, Uint8 r, Uint8 g, Uint8 b, Uint8 a ) {
  // Initialise rect.
  srcrect->x = column * TILE_W;
  srcrect->y = row * TILE_H;

  // Set the colour.
  SDL_SetRenderDrawColor( renderer, r, g, b, a );

  // Set the draw mode.
  SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_ADD );

  // Draw the rect.
  if( SDL_RenderFillRect( renderer, srcrect ) ) {
    printf( "RTile: Unable to fill rect to renderer @ %s\n", SDL_GetError() );
    return false;
  }
  return true;
}

bool RTile::drawBackgroundArea( int column, int row, int width, int height,
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

int RTile::get_code( std::string s ) {
  int c = tile_handles[s];
  return c;
}

SDL_Point RTile::code_to_point( int kC ) {
  SDL_Point point;
  point.y = kC / 16; // Row.
  point.x = kC % 16; // Column.

  return point;
}

RTile::~RTile() {
  //dtor
}
