#ifndef __VEXLIB_VECTOR3_H__
#define __VEXLIB_VECTOR3_H__

#include "Vector2.h"

namespace VexLib {

  template <typename T>
  class Vector3 : public VectorBase<T, 3> {
   public: 
    Vector3() { }
    Vector3(T x, T y, T z) {
      X() = x;
      Y() = y;
      Z() = z;
    }
    
    // Overloaded functions
    template<typename _T>
    Vector3(const Vector3<_T> &v) : VectorBase<T, 3>(v) { }

    template<typename _T>
    Vector3<T> &operator=(const Vector3<_T> &v) {
      VectorBase<T, 3>::operator=(v);
      return *this;
    }

    // Accessors
    T &X() { return (*this)[0]; }
    const T &X() const { return (*this)[0]; }

    T &Y() { return (*this)[1]; }
    const T &Y() const { return (*this)[1]; }

    T &Z() { return (*this)[2]; }
    const T &Z() const { return (*this)[2]; }

    // Swizzle
    Vector2<T> XX() const { return Vector2<T>(X(), X()); }
    Vector2<T> XY() const { return Vector2<T>(X(), Y()); }
    Vector2<T> XZ() const { return Vector2<T>(X(), Z()); }
    Vector2<T> YX() const { return Vector2<T>(Y(), X()); }
    Vector2<T> YY() const { return Vector2<T>(Y(), Y()); }
    Vector2<T> YZ() const { return Vector2<T>(Y(), Z()); }
    Vector2<T> ZX() const { return Vector2<T>(Z(), X()); }
    Vector2<T> ZY() const { return Vector2<T>(Z(), Y()); }
    Vector2<T> ZZ() const { return Vector2<T>(Z(), Z()); }

    Vector3<T> XXX() const { return Vector3<T>(X(), X(), X()); }
    Vector3<T> XXY() const { return Vector3<T>(X(), X(), Y()); }
    Vector3<T> XXZ() const { return Vector3<T>(X(), X(), Z()); }
    Vector3<T> XYX() const { return Vector3<T>(X(), Y(), X()); }
    Vector3<T> XYY() const { return Vector3<T>(X(), Y(), Y()); }
    Vector3<T> XYZ() const { return Vector3<T>(X(), Y(), Z()); }
    Vector3<T> XZX() const { return Vector3<T>(X(), Z(), X()); }
    Vector3<T> XZY() const { return Vector3<T>(X(), Z(), Y()); }
    Vector3<T> XZZ() const { return Vector3<T>(X(), Z(), Z()); }
    Vector3<T> YXX() const { return Vector3<T>(Y(), X(), X()); }
    Vector3<T> YXY() const { return Vector3<T>(Y(), X(), Y()); }
    Vector3<T> YXZ() const { return Vector3<T>(Y(), X(), Z()); }
    Vector3<T> YYX() const { return Vector3<T>(Y(), Y(), X()); }
    Vector3<T> YYY() const { return Vector3<T>(Y(), Y(), Y()); }
    Vector3<T> YYZ() const { return Vector3<T>(Y(), Y(), Z()); }
    Vector3<T> YZX() const { return Vector3<T>(Y(), Z(), X()); }
    Vector3<T> YZY() const { return Vector3<T>(Y(), Z(), Y()); }
    Vector3<T> YZZ() const { return Vector3<T>(Y(), Z(), Z()); }
    Vector3<T> ZXX() const { return Vector3<T>(Z(), X(), X()); }
    Vector3<T> ZXY() const { return Vector3<T>(Z(), X(), Y()); }
    Vector3<T> ZXZ() const { return Vector3<T>(Z(), X(), Z()); }
    Vector3<T> ZYX() const { return Vector3<T>(Z(), Y(), X()); }
    Vector3<T> ZYY() const { return Vector3<T>(Z(), Y(), Y()); }
    Vector3<T> ZYZ() const { return Vector3<T>(Z(), Y(), Z()); }
    Vector3<T> ZZX() const { return Vector3<T>(Z(), Z(), X()); }
    Vector3<T> ZZY() const { return Vector3<T>(Z(), Z(), Y()); }
    Vector3<T> ZZZ() const { return Vector3<T>(Z(), Z(), Z()); }
  };

  typedef Vector3<float> Vec3f;
  typedef Vector3<double> Vec3d;
  typedef Vector3<int> Vec3i;

};

#endif //__VEXLIB_VECTOR3_H__
