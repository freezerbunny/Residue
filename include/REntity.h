#ifndef RENTITY_H
#define RENTITY_H

#include "RInclude.h"

class RModel;
class RBlock;
namespace RBit {
  struct Bit;
}

namespace RLet {
  struct Let {/**< A structure containing the drawable information of an object or effect. */
    std::string character;
    std::string color;
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

    std::string getid() { return id; }/**< Gets the entity's id. */
    std::string getString( std::string handle ) { return strings[mappings[handle]]; }/**< Gets the string mapped to the specified handle. */

    void bindEntity( REntity *entity );/**< Binds an entity to this entity's list. */
    std::vector<REntity*> getBindings() { return entities; }/**< Returns the entity's bindings */

    void setModel( RModel *model ) { this->model = model; }/**< Set's the entity's current model. */
    void setBlock( RBlock *block ) { this->block = block; }/**< Set's the entity's current block. */
    void setBit( RBit::Bit *bit ) { this->bit = bit; }/**< Set's the entity's current bit. */
  protected:
  private:
    RModel *model;
    RBlock *block;
    RBit::Bit *bit;

    std::string id;
    std::map<std::string, unsigned int> mappings;
    std::vector<int> vars;
    std::vector<std::string> strings;
    std::vector<std::string> flags;

    std::vector<REntity*> entities;

    RLet::Let graphlet;
};

#endif // RENTITY_H
