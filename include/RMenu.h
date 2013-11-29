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
     * \param row int The top left row.
     * \param column int The top left column.
     * \param width int The width of the menu.
     * \param type RMenuType::MenuType The menu type.
     *
     */
    RMenu( RTiler *rtiler, int row, int column, int width, RMenuType::MenuType type, RDrawable *drawable );
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
     * \param drawable RDrawable* A drawable object to be invoked when this menu draws.
     * \return RMenuEntry::Entry The menu entry of the choice entered by the player.
     *
     */
    RMenuEntry::Entry enter();

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

    std::vector<RMenuEntry::Entry> entries;
    int choice;/**< The current entry we have selected. */
};

#endif // RMENU_H
