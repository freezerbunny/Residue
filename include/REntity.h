#ifndef RENTITY_H
#define RENTITY_H

#include "RInclude.h"

namespace RLet {
  struct Let {/**< A structure containing the drawable information of an object or effect. */
    std::string character;
    std::string color;
    int priority;/**< Objects with higher priorities are drawn on top of others. */
  };
}

/** \brief A single generic entity in the world.
 */
class REntity {
  public:
    REntity();
    virtual ~REntity();
  protected:
  private:
    std::hash<std::string> id;
    std::vector<int> vars;
    std::vector<std::string> flags;
    std::vector<std::string> strings;

    RLet::Let graphlet;
};

#endif // RENTITY_H
