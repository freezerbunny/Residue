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

bool RTile::drawTile( int column, int row, int c ) {
  // Check if row is within terminal limits.
  if( row < 0 || row > TERMINAL_ROWS ) {
    printf( "Tried to draw out of bounds: %d,  %d\n", row, column );
    return false;
  }
  if( column < 0 || column > TERMINAL_COLUMNS ) {
    printf( "Tried to draw out of bounds: %d,  %d\n", row, column );
    return false;
  }

  // DRAW THE TILE.

  // Determine where to source and destination.
  SDL_Point point = code_to_point( c );
  srcrect->x = point.x * TILE_W;
  srcrect->y = point.y * TILE_H;

  dstrect->x = column * TILE_W;
  dstrect->y = row * TILE_H;

  // Copy to the renderer.
  SDL_RenderCopy( renderer, tiles, srcrect, dstrect );

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
    if( cur_column > width ) {
      cur_column = 0;
      cur_row++;
    }
    x = cur_column + column;
    y = cur_row + row;
    if ( !drawTile( x, y, *itr ) ) {
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
