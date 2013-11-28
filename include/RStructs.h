#ifndef RSTRUCTS_H_INCLUDED
#define RSTRUCTS_H_INCLUDED

#include "RInclude.h"
#include "REnums.h"

/**< Defines structures that are used for wrapping data */

namespace RPackage {
  struct Package {
    std::string name;

    std::vector<int> vars;
    std::vector<std::string> flags;
    std::string desc;

    bool valid;
  };
}

namespace RMenuEntry {
  struct Entry {
    std::string name;/**< The name of the menu entry. */
    std::string color;/**< The color to draw the entry with. */
    SDL_Keycode key;/**< The keycode to select that entry. */
  };
}

#endif // RSTRUCTS_H_INCLUDED
