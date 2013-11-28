#ifndef RPARSE_H
#define RPARSE_H

#include "RInclude.h"

/** \brief A class used to parse ".rdat" files.
 */
class RParser {
  public:
    /** \brief Creates a new parser object.
     *
     * \param filepath std::string The .rdat file to parse.
     *
     */
    RParser(std::string filepath);
    virtual ~RParser();

    /** \brief Checks if we are ready for parsing the file.
     *
     * \return bool True if we can start to parse the file.
     *
     */
    bool isGood();

    /** \brief Checks if there are more packages remaining.
     *
     * \return bool True if we have more packages.
     *
     */
    bool hasMore();

    /** \brief Gets the next package from the file.
     *
     * \return RPackage::Package A struct containing all the elements of the package.
     *
     */
    RPackage::Package getNext();
  protected:
  private:
    std::ifstream input;
    std::string filepath;
};

#endif // RPARSE_H
