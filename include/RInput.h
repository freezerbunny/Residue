#ifndef RINPUT_H
#define RINPUT_H

#include "RInclude.h"
#include "RLimiter.h"
#include "RDrawable.h"

class RInput {
  public:
    /** \brief Constructor of a new input watcher.
     *
     * \param mapped bool Whether the object uses mapped keys.
     *
     */
    RInput( bool mapped );
    /** \brief Constructor of a new input watcher.
     *
     * \param mapped bool Whether the object uses mapped keys.
     * \param drawable RDrawable* A drawable object to invoke whilst watching for inputs.
     *
     */
    RInput( bool mapped, RDrawable *drawable );
    virtual ~RInput();

    /** \brief Takes control and waits for user input, returning the keycode pressed.
     *
     * \return SDL_Keycode The keycode of the user's input.
     *
     */
    SDL_Keycode pollForInput();
  protected:
  private:
    RDrawable *drawable;
    RLimiter *limiter;
    bool mapped;
};

#endif // RINPUT_H
