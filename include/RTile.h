#ifndef RTILE_H
#define RTILE_H

#include "RInclude.h"
#include "RCol.h"
#include "RHandles.h"
#include "RDefs.h"

/** \brief Used to draw tiles to the screen.
 */
class RTile {
  public:
    /** \brief Rtile constructor.
     *
     * \param renderer SDL_Renderer* Handle to the renderer to draw on.
     * \param tiles SDL_Texture* Texture containing the tiles file.
     *
     */
    RTile( SDL_Renderer *renderer, SDL_Texture *tiles, RCol *colormap );
    virtual ~RTile();

    /** \brief Sets the color all tiles to be drawn by the specified colour.
     *
     * \param r Uint8 The red component.
     * \param g Uint8 The green component.
     * \param b Uint8 The blue component.
     * \return bool True if coloring was successful.
     *
     */
    bool setTileColour( Uint8 r, Uint8 g, Uint8 b );

    /** \brief Sets the color all tiles to be drawn by the SDL_Color object.
     *
     * \param col SDL_Color The SDL_Color object to tint with.
     * \return bool True if coloring was successful.
     *
     */
    bool setTileColour( SDL_Color col );

    /** \brief Sets the color all tiles to be drawn by the mapped color name.
     *
     * \param col std::string The name of the color to draw with.
     * \return bool True if coloring was successful.
     *
     */
    bool setTileColour( std::string col );

    /** \brief Draws a tile to the screen from an alt-code.
     *
     * \param row int Horizontal position of the tile (left to right).
     * \param column int Vertical position of the tile (top to bottom).
     * \param kC const int The character to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawTile( int column, int row, int c );

    /** \brief Draws a tile to the screen from a string.
     *
     * \param row int Horizontal position of the tile (left to right).
     * \param column int Vertical position of the tile (top to bottom).
     * \param kC std::string The character to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawTile( int column, int row, std::string c );

    /** \brief Draws a string to the screen, wrapping if it is too long.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param width int How many columns before the string is wrapped. 0 means no wrapping.
     * \param kString std::string The string to draw.
     * \return bool True if drawing was successful.
     *
     */
    bool drawString( int column, int row, int width, std::string str );

    /** \brief Draws a background to the screen.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param r Uint8 The red component of the background.
     * \param g Uint8 The green component of the background.
     * \param b Uint8 The blue component of the background.
     * \param a Uint8 The alpha component of the background.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackground( int column, int row, Uint8 r, Uint8 g, Uint8 b, Uint8 a );

    /** \brief Draws a background to the screen with the specified SDL_Color object.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param col SDL_Color The SDL_Color to draw with.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackground( int column, int row, SDL_Color col );

    /** \brief Draws a background the screen with the specified color handle.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param col std::string The name of the color to draw with.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackground( int column, int row, std::string col );

    /** \brief Draws a background to an area the screen.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param width int The width of the background.
     * \param height int The height of the background.
     * \param r Uint8 The red component of the background.
     * \param g Uint8 The green component of the background.
     * \param b Uint8 The blue component of the background.
     * \param a Uint8 The alpha component of the background.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackgroundArea( int column, int row, int width, int height,
                             Uint8 r, Uint8 g, Uint8 b, Uint8 a );

    /** \brief Draws a background to an area the screen.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param width int The width of the background.
     * \param height int The height of the background.
     * \param col SDL_Color The SDL_Color to draw with.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackgroundArea( int column, int row, int width, int height,
                             SDL_Color col );

    /** \brief Draws a background to an area the screen.
     *
     * \param column int The column to draw to.
     * \param row int The row to draw to.
     * \param width int The width of the background.
     * \param height int The height of the background.
     * \param col std::string The name of the color to draw with.
     * \param a Uint8 The alpha component of the background.
     * \return bool True if drawing was successful.
     *
     */
    bool drawBackgroundArea( int column, int row, int width, int height,
                             std::string col, Uint8 a );

    /** \brief Macro function to get the alt-code of a character.
     *
     * \param s std::string The character wrapped in a string.
     * \return int The alt-code of the character.
     *
     */
    int get_code( std::string s );
  protected:
  private:
    SDL_Renderer *renderer;
    SDL_Texture *tiles;
    SDL_Rect *srcrect;
    SDL_Rect *dstrect;

    RCol *colormap;

    std::map<std::string, int> tile_handles;

    SDL_Point code_to_point( int kC ); /**< Helper function to convert from a code to a SDL_Point */
};

#endif // R_TILE_H
