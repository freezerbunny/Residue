#ifndef RMODEL_H
#define RMODEL_H

#include "RInclude.h"
#include "RDictionary.h"
#include "RBlock.h"

/** \brief The active model of the world.
 */
class RModel {
  public:
    /** \brief Constructor of a new model. Requires a pointer to the substantiated dictionary.
     *
     * \param dictionary RDictionary* The dictionary needed by the model.
     *
     */
    RModel( RDictionary *dictionary );
    virtual ~RModel();
  protected:
  private:
    RDictionary *dictionary;

    std::map<std::pair<unsigned int, unsigned int>, unsigned int> mapping;
    std::vector<RBlock> blocks;
    RBlock *activeblocks[3][3];/**< Should always be centered around the player. */
    RBlock *currentblock;/**< Should always be the player's immediate block. */
    unsigned int currentx;/**< Should always point to the block the player is in. */
    unsigned int currenty;

    void addNewEntity( unsigned int blockx, unsigned int blocky, int bitx, int bity, std::string id );/**< Adds a new entity to the specified mapped block. */
    void addNewBlock( unsigned int x, unsigned int y );/**< Adds a new block to the stack. */
    RBlock *referenceBlockAt( unsigned int x, unsigned int y );/**< Returns a reference to the block at the mapped location. */
    bool updateActiveBlocks( unsigned int x, unsigned int y );/**< Updates the set of active blocks, optionally loading more blocks when needed and generating terrain. */
};

#endif // RMODEL_H
