#ifndef RSTRING_H
#define RSTRING_H

#include <string>
#include <cstdarg>
#include <cstdio>
#include <cstring>

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

    std::string str();/**< Returns the formatted string */

    virtual ~RString();
  protected:
  private:
    char buffer[256];
};

#endif // RSTRING_H
