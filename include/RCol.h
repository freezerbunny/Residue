#ifndef RCOL_H
#define RCOL_H

#include "RInclude.h"

/** \brief A macro class that maps colour names to RGB values.
 */
class RCol {
  public:
    RCol();
    virtual ~RCol();

    /** \brief Initialises colour mappings from color rdat file.
     *
     * \param filepath std::string A path pointing to the file with colour mappings.
     * \return bool Returns true if successful;
     *
     */
    bool readColorFile( std::string filepath );

    SDL_Color getColor( std::string name );
  protected:
  private:
    std::map<std::string, SDL_Color> color_map;
};

#endif // RCOL_H
