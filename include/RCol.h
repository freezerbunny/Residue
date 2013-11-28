#ifndef RCOL_H
#define RCOL_H

#include "SDL.H"

#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

/** \brief A macro class that maps colour names to RGB values.
 */
class RCol {
  public:
    RCol();
    virtual ~RCol();

    bool init();
  protected:
  private:
    std::map<std::string, SDL_Color> colour_map;
};

#endif // RCOL_H
