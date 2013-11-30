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
    /** \brief Constructs an entity with the given parameters.
     *
     * \param id std::string The unique identifier of the entity.
     * \param mappings unsigned int> Mappings between handle and index.
     * \param vars std::vector<int> The entity's variables.
     * \param strings std::vector<std::string> The entity's strings.
     * \param flags std::vector<std::string> The entity's flags.
     *
     */
    REntity( std::string id, std::map<std::string, unsigned int> mappings,
             std::vector<int> vars, std::vector<std::string> strings, std::vector<std::string> flags );
    virtual ~REntity();
  protected:
  private:
    std::string id;
    std::map<std::string, unsigned int> mappings;
    std::vector<int> vars;
    std::vector<std::string> strings;
    std::vector<std::string> flags;

    RLet::Let graphlet;
};

#endif // RENTITY_H
