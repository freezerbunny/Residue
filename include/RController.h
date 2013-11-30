#ifndef RCONTROLLER_H
#define RCONTROLLER_H

#include "RInclude.h"
#include "RGame.h"
#include "RTiler.h"

class RController
{
  public:
    RController( RTiler *rtiler );
    virtual ~RController();
  protected:
  private:
    RTiler *rtiler;
    RModel *model;
    RObserver *observer;
    RInterface *interface;
};

#endif // RCONTROLLER_H
