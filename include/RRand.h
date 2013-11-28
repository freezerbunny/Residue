#ifndef RRAND_H
#define RRAND_H

#include "RInclude.h"
#include <cstdlib>

/** \brief Class to generate trvial random numbers using C's standard rand function.
 */
class RRand {
  public:
    /** \brief Constructor initialising the seed of the random number generator.
     *
     * \param seed unsigned int
     *
     */
    RRand( unsigned int seed );
    virtual ~RRand();

    /** \brief Generates a random number within the specified range.
     *
     * \param base int The minimum value.
     * \param range int The range of numbers from the minimum value.
     * \return int The random number generated.
     *
     */
    int random( int base, int range );
  protected:
  private:
    unsigned int seed;
};

#endif // RRAND_H
