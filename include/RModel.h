#ifndef RMODEL_H
#define RMODEL_H

#include "RInclude.h"
#include "RBlock.h"

/** \brief The active model of the world.
 */
class RModel {
  public:
    RModel();
    virtual ~RModel();
  protected:
  private:
    std::vector<RBlock> blocks;
};

#endif // RMODEL_H
