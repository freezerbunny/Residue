#ifndef RHOLDRELEASE_H
#define RHOLDRELEASE_H

#include <RLimiter.h>


/** \brief A class to slow down the execution of elements.
 */
class RHoldRelease : public RLimiter {
  public:
    /** \brief Constructor.
     *
     * \param rate int The number of executions per second allowed.
     *
     */
    RHoldRelease( int rate );
    virtual ~RHoldRelease();

    /** \brief Prepares a hold. This will set the limit once, until the object is released.
     *
     * \return void
     *
     */
    void hold();

    /** \brief Attempts to release the object. Returns true if enough time has passed.
     *
     * \return bool True if we are allowed to release.
     *
     */
    bool release();
  protected:
  private:
    unsigned int start;
    unsigned int elapsed;

    bool ready;
};

#endif // RHOLDRELEASE_H
