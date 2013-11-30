#ifndef RENTITY_H
#define RENTITY_H

#include "RInclude.h"
#include "RModel.h"

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

    /** \brief Sets the entity's model.
     *
     * \param model RModel* A pointer to the model to set.
     * \return void
     *
     */
    void setModel( RModel *model ) { this->model = model; }
  protected:
  private:
    RModel *model;
    unsigned int blockx;
    unsigned int blocky;
    unsigned char x;
    unsigned char y;

    std::string id;
    std::map<std::string, unsigned int> mappings;
    std::vector<int> vars;
    std::vector<std::string> strings;
    std::vector<std::string> flags;

    std::vector<REntity> entities;

    RLet::Let graphlet;
};

#endif // RENTITY_H
