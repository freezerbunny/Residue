#ifndef RBLOCK_H
#define RBLOCK_H

#include "RInclude.h"
#include "RStructs.h"

/** \brief A block of 256*256 tiles and all their entities.
 */
class RBlock {
  public:
    RBlock();
    virtual ~RBlock();

    /** \brief Sets the bit at that location with the bit specified by the parameters.
     *
     * \param x unsigned char The x location of the bit.
     * \param y unsigned char The y location of the bit.
     * \param bit RBit::Bit The bit to use.
     * \return void
     *
     */
    void setBit( unsigned char x, unsigned char y, RBit::Bit bit );

    /** \brief Returns the pointer to the bit specified by the parameters.
     *
     * \param x The x location of the bit.
     * \param y The y location of the bit.
     * \return RBit::Bit The bit at the specified location.
     *
     */
    RBit::Bit getBit( unsigned char x, unsigned char y );
  protected:
  private:
    RBit::Bit bits[256][256];
};

#endif // RBLOCK_H
