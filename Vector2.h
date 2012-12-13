#ifndef __VEXLIB_VECTOR2_H__
#define __VEXLIB_VECTOR2_H__

#include "VectorBase.h"

namespace VexLib {

  template<typename T>
  class Vector2 : public VectorBase<T, 2> {
   public:
    // Ideally, we would be able to do this with initialization
    // lists, but I'm not really sure how to do that without gross
    // code duplication.
    Vector2() { }
    Vector2(T x, T y) {
      X() = x;
      Y() = y; 
    }

    // Overloaded functions
    template<typename _T>
    Vector2(const Vector2<_T> &v) : VectorBase<T, 2>(v) { }

    template<typename _T>
    Vector2<T> &operator=(const Vector2<_T> &v) {
      VectorBase<T, 2>::operator=(v);
      return *this;
    }

    // Accessors
    T &X() { return (*this)[0]; }
    const T &X() const { return (*this)[0]; }

    T &Y() { return (*this)[1]; }
    const T &Y() const { return (*this)[1]; }

    // Swizzle
    Vector2<T> XX() const {
      return Vector2<T>(X(), X());
    }

    Vector2<T> YX() const {
      return Vector2<T>(Y(), X());
    }

    Vector2<T> YY() const {
      return Vector2<T>(Y(), Y());
    }
  };

  typedef Vector2<float> Vec2f;
  typedef Vector2<double> Vec2d;
  typedef Vector2<int> Vec2i;
};

#endif // __VEXLIB_VECTOR2_H__
