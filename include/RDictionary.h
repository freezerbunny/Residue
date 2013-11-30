#ifndef RENTITYGENERATOR_H
#define RENTITYGENERATOR_H

#include "RInclude.h"
#include "RParser.h"
#include "REntity.h"

/** \brief Generates, substantiates, and records information on all entities.
 */
class RDictionary {
  public:
    /** \brief Constructs the dictionary, initialising the entity list from the specified path.
     *
     * \param filepath std::string A path pointing to the file with the entity definitions.
     *
     */
    RDictionary( std::string filepath );
    virtual ~RDictionary();

    /** \brief Checks if an entity exists with the corresponding id.
     *
     * \param id std::string The entity to try and find.
     * \return bool True if it exists.
     *
     */
    bool find( std::string id );

    /** \brief Looks up the entity with the specified id and returns it.
     *
     * \param id std::string The id of the entity to lookup.
     * \return REntity The entity corresponding to the id.
     *
     */
    REntity lookup( std::string id );
  protected:
  private:
    RParser *parser;
    void parse();

    std::map<std::string, unsigned int> mappings;
    std::vector<REntity> entities;
};

#endif // RENTITYGENERATOR_H
