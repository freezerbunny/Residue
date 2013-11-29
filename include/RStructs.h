#ifndef RSTRUCTS_H_INCLUDED
#define RSTRUCTS_H_INCLUDED

#include "RInclude.h"
#include "REnums.h"

/**< Defines structures that are used for wrapping data */

namespace RPackage {
  struct Package {
    std::string id;

    std::vector<int> vars;
    std::vector<std::string> strings;
    std::vector<std::string> flags;

    bool valid;
  };
}

namespace RMenuEntry {
  struct Entry {
    std::string name;/**< The name of the menu entry. */
    std::string color;/**< The color to draw the entry with. */
    SDL_Keycode key;/**< The keycode to identify the entry. */
  };
}

#endif // RSTRUCTS_H_INCLUDED
