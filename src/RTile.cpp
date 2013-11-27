#include "RTile.h"

RTile::RTile( SDL_Renderer *renderer, SDL_Texture *tiles, int w, int h ) {
  this->renderer = renderer;
  this->tiles = tiles;
  tile_w = w;
  tile_h = h;
}

bool RTile::draw_tile( int screen_x, int screen_y, const char *c ) {
  return false;
}

RTile::~RTile() {
  //dtor
}
