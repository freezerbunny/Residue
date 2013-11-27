#ifndef RTILE_H
#define RTILE_H

#include <string>
#include <map>
#include <stdio.h>
#include <cstdio>
#include <sstream>
#include <cmath>

#include "SDL.h"

#include "RHandles.h"
#include "RDefs.h"

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

    /** \brief Draws a tile to the screen from an alt-code.
     *
     * \param row int Horizontal position of the tile (left to right).
     * \param column int Vertical position of the tile (top to bottom).
     * \param kC const int The character to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawTile(int column, int row, int c);

    /** \brief Draws a tile to the screen from a string.
     *
     * \param row int Horizontal position of the tile (left to right).
     * \param column int Vertical position of the tile (top to bottom).
     * \param kC std::string The character to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawTile(int column, int row, std::string c);

    /** \brief Draws a string to the screen, wrapping if it is too long.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param row width How many columns before the string is wrapped.
     * \param kString std::string The string to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawString(int column, int row, int width, std::string str);

    /** \brief Macro function to get the alt-code of a character.
     *
     * \param s std::string The character wrapped in a string.
     * \return int The alt-code of the character.
     *
     */
    int get_code(std::string s);

    virtual ~RTile();
  protected:
  private:
    SDL_Renderer *renderer;
    SDL_Texture *tiles;
    SDL_Rect *srcrect;
    SDL_Rect *dstrect;

    std::map<std::string, int> tile_handles;

    SDL_Point code_to_point(int kC);/**< Helper function to convert from a code to a SDL_Point */
};

#endif // R_TILE_H
