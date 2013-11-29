#ifndef RMENU_H
#define RMENU_H

#include "RInclude.h"
#include "RDefs.h"
#include "REnums.h"
#include "RTiler.h"
#include "RDrawable.h"
#include "RRand.h"
#include "RLimiter.h"
#include "RHoldRelease.h"
#include "RInput.h"

/** \brief A class for creating menus that poll for user input until escaped.
 */
class RMenu : public RDrawable {
  public:
    /** \brief Constructor for a new menu.
     *
     * \param rtiler RTile* The drawing agent.
     * \param column int The top left column.
     * \param row int The top left row.
     * \param width int The width of the menu.
     * \param type RMenuType::MenuType The menu type.
      * \param drawable RDrawable* A drawable object to be invoked when this menu draws.
     *
     */
    RMenu( RTiler *rtiler, int column, int row, int width, RMenuType::MenuType type, RDrawable *drawable );
    virtual ~RMenu();

    /** \brief Adds a new entry to the menu.
     *
     * \param entry RMenuEntry::Entry The menu entry to add to this menu.
     * \return bool True if successful.
     *
     */
    bool addEntry( RMenuEntry::Entry entry );

    /** \brief Enters the menu, taking control until exited.
     *
     * \return RMenuEntry::Entry The menu entry of the choice entered by the player.
     *
     */
    RMenuEntry::Entry enter();

    /** \brief Draws the current menu to the screen.
     *
     * \return bool True if drawing was successful.
     *
     */
    bool draw();

    void invoke();
  protected:
  private:
    RTiler *rtiler;
    RInput *rinput;
    RDrawable *drawable;
    RMenuType::MenuType type;
    int row;
    int col;
    int width;
    int maxstringlength;

    std::vector<RMenuEntry::Entry> entries;
    unsigned int choice;/**< The current entry we have selected. */

    // Draw methods.
    bool drawMainMenu();
};

#endif // RMENU_H
