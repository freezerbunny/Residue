#include "RTile.h"

RTile::RTile( SDL_Renderer *renderer, SDL_Texture *tiles ) {
  this->renderer = renderer;
  this->tiles = tiles;

  RHandles *r_handles = new RHandles();
  tile_handles = r_handles->get_tile_handles();
  delete r_handles;
}

bool RTile::draw_tile( int screen_x, int screen_y, const char *c ) {
  return false;
}

RTile::~RTile() {
  //dtor
}
