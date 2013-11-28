#ifndef RMENU_H
#define RMENU_H

#include "RInclude.h"
#include "REnums.h"
#include "RTile.h"
#include "RRand.h"
#include "RLimiter.h"
#include "RHoldRelease.h"

/** \brief A class for creating menus that poll for user input until escaped.
 */
class RMenu {
  public:
    /** \brief Constructor for a new menu.
     *
     * \param rtiler RTile* The drawing agent.
     * \param row int The top left row.
     * \param column int The top left column.
     * \param width int The width of the menu.
     * \param type RMenuType::MenuType The menu type.
     *
     */
    RMenu( RTile *rtiler, int row, int column, int width, RMenuType::MenuType type );
    virtual ~RMenu();

    /** \brief Adds a new entry to the menu.
     *
     * \param name std::string The name of the entry.
     * \param col std::string The color of the entry (default white).
     * \param key SDL_Keycode The key to select the entry.
     * \return bool True if successful.
     *
     */
    bool addEntry( std::string name, std::string col, SDL_Keycode key );

    /** \brief Enters the menu, taking control until exited.
     *
     * \return int The choice selected by the user. 0 if no choice was made.
     *
     */
    int enter();
  protected:
  private:
    RTile *rtiler;
    RMenuType::MenuType type;
    int row;
    int col;
    int width;

    std::vector<RMenuEntry::Entry> entries;
    int current;/**< The current entry we have selected. */

    RHoldRelease *holdrelease;
    RRand *rrand;
    int moverx;
    int movery;
    int glitched;
    bool drawMainMenu();
};

#endif // RMENU_H
