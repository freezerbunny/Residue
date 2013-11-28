#ifndef RSTRING_H
#define RSTRING_H

#include "RInclude.h"

/** \brief A formatted string object.
 */
class RString {
  public:
    /** \brief Constructor, taking a string of characters and formatting it.
     *
     * \param str std::string The string to be formatted.
     * \param ... Parameters to be inserted into the string.
     *
     */
    RString(std::string str, ...);
    virtual ~RString();

    std::string str();/**< Returns the formatted string */
  protected:
  private:
    char buffer[256];
};

#endif // RSTRING_H
