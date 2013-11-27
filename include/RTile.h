#ifndef RTILE_H
#define RTILE_H

#include <string>
#include <map>

#include "SDL.h"

#include "RHandles.h"

/** \brief Used to draw individual tiles to the screen.
 */
class RTile {
  public:
    /** \brief R_tile constructor.
     *
     * \param renderer SDL_Renderer* Handle to the renderer to draw on.
     * \param tiles SDL_Texture* Texture containing the tiles file.
     *
     */
    RTile(SDL_Renderer *renderer, SDL_Texture *tiles);

    /** \brief Draws a tile to the screen.
     *
     * \param screen_x int Horizontal position of the tile (left to right).
     * \param screen_y int Vertical position of the tile (top to bottom).
     * \param c const char* The character to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool draw_tile(int screen_x, int screen_y, const char *c);

    /** \brief Macro function to get the character of a tile from a string handle.
     *
     * \param s std::string The handle of the tile to draw.
     * \return char* The character associated with the handle.
     *
     */
    static char *get_character(std::string s);

    /** \brief Macro function to get the alt-code of a character.
     *
     * \param c char The character to get the alt code from.
     * \return int* The altcode for the character.
     *
     */
    static int *get_altcode(char c);

    virtual ~RTile();
  protected:
  private:
    SDL_Renderer *renderer;
    SDL_Texture *tiles;

    std::map<std::string, char> *tile_handles;
    std::map<char, int> *char_handles;
};

#endif // R_TILE_H
