#ifndef RTITLEPARTICLE_H
#define RTITLEPARTICLE_H

#include "RInclude.h"
#include "RRand.h"

/** \brief A fancy particle for the title screen.
 */
class RTitleParticle {
  public:
    /** \brief Constructor for the particle, which initialises its features randomly.
     *
     * \param rows int The maximum number of columns.
     * \param columns int The maximum number of rows.
     * \param startingrow int The starting row for the particle.
     *
     */
    RTitleParticle( int columns, int rows, int startingrow );
    virtual ~RTitleParticle();

    /** \brief Executes one iteration of movement.
     *
     * \return SDL_Point The column and row that the particle has moved to.
     *
     */
    SDL_Point iterate();

    /** \brief Returns the current position of the particle
     *
     * \return SDL_Point The position of the particle.
     *
     */
    SDL_Point get();

    /** \brief Returns if the particle died (ie. went beyond the max columns), resetting its state at the same time.
     *
     * \return bool The state of the particle.
     *
     */
    bool died() { bool ret = died_; died_ = false; return ret; }
  protected:
  private:
    bool died_;

    float amplitude;
    float wavelength;
    float posx;
    float posy;

    int columns;
    int rows;
    int startingrow;
};

#endif // RTITLEPARTICLE_H
