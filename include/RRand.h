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
    RRand();
    virtual ~RRand();

    /** \brief Generates a random number within the specified range.
     *
     * \param base int The minimum value.
     * \param range int The range of numbers from the minimum value.
     * \return int The random number generated.
     *
     */
    int random( int base, int range );

    /** \brief Rolls a dice, returning the value we landed on.
     *
     * \param number int The number of dice to roll.
     * \param sides int The number of sides per dice.
     * \return int The total for the current roll.
     *
     */
    int roll ( int number, int sides );

    /** \brief Tries the specified chance, returning true if good.
     *
     * \param numerator int The chances.
     * \param denominator int The total roll.
     * \return bool True if the chance was good.
     *
     */
    bool chance ( int numerator, int denominator );
  protected:
  private:
    unsigned int seed;
};

#endif // RRAND_H
