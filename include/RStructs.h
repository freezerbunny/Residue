#ifndef RSTRUCTS_H_INCLUDED
#define RSTRUCTS_H_INCLUDED

#include "RInclude.h"

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

namespace RDrawUnit {
  struct DrawUnit {
    bool background;
    std::string character;
    SDL_Color color;
  };
}

#endif // RSTRUCTS_H_INCLUDED
