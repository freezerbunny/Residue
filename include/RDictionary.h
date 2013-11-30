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
  protected:
  private:
    RParser *parser;
    void parse();

    std::map<std::string, unsigned int> mappings;
    std::vector<REntity> entities;
};

#endif // RENTITYGENERATOR_H
