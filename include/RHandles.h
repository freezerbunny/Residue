#ifndef RHANDLES_H
#define RHANDLES_H

#include <string>
#include <map>

/** \brief Initialises handles between macros and characters.
 */
class RHandles
{
  public:
    RHandles();
    virtual ~RHandles();

    /** \brief Returns a map containing the handles and characters they point to.
     *
     * \return std::map* A pointer to a map containing the handle character pairs.
     *
     */
    std::map<std::string, char> *get_handles();
  protected:
  private:
    std::map<std::string, char> handles;
};

#endif // RHANDLES_H
