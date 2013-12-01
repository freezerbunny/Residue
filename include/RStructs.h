#ifndef RSTRUCTS_H_INCLUDED
#define RSTRUCTS_H_INCLUDED

#include "REntity.h"

/**< Defines structures that are used for wrapping data */
namespace RPackage {
  struct Package {
    std::string id;

    std::map<std::string, unsigned int> mappings;/**< A map between the names of each entry and their indexes. */
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

namespace RBit {
  struct Bit {/**< A structure that represents a single world tile. */
    unsigned char x;
    unsigned char y;
    std::vector<REntity> entities;
  };
}

#endif // RSTRUCTS_H_INCLUDED
