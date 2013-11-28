#ifndef RHANDLES_H
#define RHANDLES_H

#include "RInclude.h"

/** \brief Initialises handles between macros and characters.
 */
class RHandles
{
  public:
    RHandles();
    virtual ~RHandles();

    /** \brief Returns a map containing the handles and characters they point to.
     *
     * \return std::map A map containing the associations.
     *
     */
    std::map<std::string, int> tile_handles();
  protected:
  private:
    std::map<std::string, int> tile_handles_;
};

#endif // RHANDLES_H
