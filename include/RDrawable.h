#ifndef RDRAWABLE_H
#define RDRAWABLE_H


/** \brief Abstract class defines objects that have draw functions to be invoked by other classes.
 */
class RDrawable {
  public:
    RDrawable();
    virtual ~RDrawable();

    /** \brief Used to invoke the draw function of classes that inherit from it.
     *
     * \return virtual void
     *
     */
    virtual void invoke() = 0;
  protected:
  private:
};

#endif // RDRAWABLE_H
