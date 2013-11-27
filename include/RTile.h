#ifndef RTILE_H
#define RTILE_H

#include <string>
#include <map>

#include "SDL.h"

/** \brief Used to draw individual tiles to the screen.
 */
class RTile {
  public:
    /** \brief R_tile constructor.
     *
     * \param renderer SDL_Renderer* Handle to the renderer to draw on.
     * \param tiles SDL_Texture* Texture containing the tiles file.
     * \param w int Width of each tile.
     * \param h int Height of each tile.
     *
     */
    RTile(SDL_Renderer *renderer, SDL_Texture *tiles, int w, int h);

    bool draw_tile(int screen_x, int screen_y, const char *c);

    /** \brief Macro function to get the character of a tile from a string handle.
     *
     * \param handle std::string The handle of the tile to draw.
     * \return char* A character that points to the correct tile to draw.
     *
     */
    static char *get_character(std::string handle);

    virtual ~RTile();
  protected:
  private:
    SDL_Renderer *renderer;
    SDL_Texture *tiles;
    int tile_w;
    int tile_h;

    std::map<std::string, char> *tile_handles;
};

#endif // R_TILE_H
