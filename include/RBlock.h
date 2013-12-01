#ifndef RBLOCK_H
#define RBLOCK_H

#include "RInclude.h"
#include "REntity.h"

namespace RBit {
  struct Bit {/**< A structure that represents a single world tile. */
    unsigned char x;
    unsigned char y;
    std::vector<REntity> entities;
  };
}

/** \brief A block of 256*256 tiles and all their entities.
 */
class RBlock {
  public:
    /** \brief Constructs a block with the specified coordinates.
     *
     * \param x unsigned int The x position.
     * \param y unsigned int The y position.
     *
     */
    RBlock( unsigned int x, unsigned int y );
    virtual ~RBlock();

    /** \brief Sets the bit at that location with the bit specified by the parameters.
     *
     * \param bit RBit::Bit* A pointer to the bit to use.
     * \return void
     *
     */
    void setBit( RBit::Bit *bit );

    /** \brief Returns the pointer to the bit specified by the parameters.
     *
     * \param x The x location of the bit.
     * \param y The y location of the bit.
     * \return RBit::Bit* A pointer to the bit at the specified location.
     *
     */
    RBit::Bit *getBit( unsigned char x, unsigned char y );

    unsigned int posx() { return x; }/**< Returns the block's x coordinate. */
    unsigned int posy() { return y; }/**< Returns the block's y coordinate. */
  protected:
  private:
    // Our individual bits.
    RBit::Bit *bits[256][256];

    // Our coordinates.
    unsigned int x;
    unsigned int y;
};

#endif // RBLOCK_H
