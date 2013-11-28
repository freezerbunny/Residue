#ifndef RLIMITER_H
#define RLIMITER_H

#include "RInclude.h"
#include "RDefs.h"

/** \brief Creates SDL_Delays to limit the framerate.
 */
class RLimiter {
  public:
    /** \brief Constructs the RLimiter with the specified framerate.
     *
     * \param framerate int The number of frames allowed per second.
     *
     */
    RLimiter( int framerate );
    virtual ~RLimiter();

    /** \brief Prepares a delay. Must be used with release.
     *
     * \return void
     *
     */
    void hold();

    /** \brief Executes the delay. Must be used with hold.
     *
     * \return void
     *
     */
    void release();

    /** \brief Sets the framerate.
     *
     * \param framerate int The number of frames allowed per second.
     * \return void
     *
     */
    void set_rate( int framerate ) { framerate_ = framerate; }
    int get_rate() { return framerate_; }

    unsigned int get_start() { return start; }
  protected:
  private:
    bool ready;
    unsigned int start;
    unsigned int elapsed;

    int framerate_;
};

#endif // RLIMITER_H
