#ifndef RTITLESCREEN_H
#define RTITLESCREEN_H

#include "RTiler.h"
#include "RHoldRelease.h"
#include "RRand.h"
#include "RDrawable.h"
#include "REnums.h"
#include "RStructs.h"
#include "RMenu.h"

#include "RTitleParticle.h"

/** \brief Class that functions to draw fancy title screen graphics and handle the main menu.
 */
class RTitleScreen : public RDrawable {
  public:
    RTitleScreen( RTiler *rtiler );
    virtual ~RTitleScreen();

    /** \brief Enters the title screen which then assumes control.
     *
     * \return SDL_Keycode The keycode of the selected choice.
     *
     */
    SDL_Keycode enter();

    /** \brief Invokes the draw function of the title screen.
     *
     * \return void
     *
     */
    void invoke();
  protected:
  private:
    RTiler *rtiler;
    RMenuEntry::Entry mainmenu_entry;
    RMenu *mainmenu;

    RHoldRelease *holdrelease;
    RRand *rng;
    unsigned int maxparticles;
    std::vector<RTitleParticle> particles;
    std::vector<RTitleParticle> backparticles;

    int moverx;
    int movery;
    int glitched;
    bool drawMainMenu();
};

#endif // RTITLESCREEN_H
