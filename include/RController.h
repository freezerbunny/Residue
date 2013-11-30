#ifndef RCONTROLLER_H
#define RCONTROLLER_H

#include "RInclude.h"
#include "RGame.h"
#include "RTiler.h"

/** \brief The game and world controller. Responsible for handling/dispatching events and controlling the interface and display.
 */
class RController {
  public:
    RController( RTiler *rtiler );
    virtual ~RController();
  protected:
  private:
    RTiler *rtiler;
    RDictionary *dictionary;
    RModel *model;
    RObserver *observer;
    RInterface *interface;
};

#endif // RCONTROLLER_H
