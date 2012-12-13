#ifndef __VEXLIB_VECTOR3_H__
#define __VEXLIB_VECTOR3_H__

#include "Vector2.h"

#ifdef _VEX_ENABLE_SWIZZLE_
# define _VEX_VEC3_SWIZZLE_DEF(X, Y, Z) \
    Vector3<T> X##Y##Z() const { return Vector3<T>( X(), Y(), Z() ); }
#endif // _VEX_ENABLE_SWIZZLE_

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

    // Vector operations
    template<typename _T>
    Vector3<T> Cross(const Vector3<_T> &v) {
      return Vector3<T>(
	Y() * v.Z() - v.Y() * Z(),
	Z() * v.X() - v.Z() * X(),
	X() * v.Y() - v.X() * Y()
      );
    }

    // Swizzle
    #ifdef _VEX_ENABLE_SWIZZLE_
    _VEX_VEC2_SWIZZLE_DEF(X, X)
    _VEX_VEC2_SWIZZLE_DEF(X, Y)
    _VEX_VEC2_SWIZZLE_DEF(X, Z)
    _VEX_VEC2_SWIZZLE_DEF(Y, X)
    _VEX_VEC2_SWIZZLE_DEF(Y, Y)
    _VEX_VEC2_SWIZZLE_DEF(Y, Z)
    _VEX_VEC2_SWIZZLE_DEF(Z, X)
    _VEX_VEC2_SWIZZLE_DEF(Z, Y)
    _VEX_VEC2_SWIZZLE_DEF(Z, Z)

    _VEX_VEC3_SWIZZLE_DEF(X, X, X)
    _VEX_VEC3_SWIZZLE_DEF(X, X, Y)
    _VEX_VEC3_SWIZZLE_DEF(X, X, Z)
    _VEX_VEC3_SWIZZLE_DEF(X, Y, X)
    _VEX_VEC3_SWIZZLE_DEF(X, Y, Y)
    _VEX_VEC3_SWIZZLE_DEF(X, Y, Z)
    _VEX_VEC3_SWIZZLE_DEF(X, Z, X)
    _VEX_VEC3_SWIZZLE_DEF(X, Z, Y)
    _VEX_VEC3_SWIZZLE_DEF(X, Z, Z)
    _VEX_VEC3_SWIZZLE_DEF(Y, X, X)
    _VEX_VEC3_SWIZZLE_DEF(Y, X, Y)
    _VEX_VEC3_SWIZZLE_DEF(Y, X, Z)
    _VEX_VEC3_SWIZZLE_DEF(Y, Y, X)
    _VEX_VEC3_SWIZZLE_DEF(Y, Y, Y)
    _VEX_VEC3_SWIZZLE_DEF(Y, Y, Z)
    _VEX_VEC3_SWIZZLE_DEF(Y, Z, X)
    _VEX_VEC3_SWIZZLE_DEF(Y, Z, Y)
    _VEX_VEC3_SWIZZLE_DEF(Y, Z, Z)
    _VEX_VEC3_SWIZZLE_DEF(Z, X, X)
    _VEX_VEC3_SWIZZLE_DEF(Z, X, Y)
    _VEX_VEC3_SWIZZLE_DEF(Z, X, Z)
    _VEX_VEC3_SWIZZLE_DEF(Z, Y, X)
    _VEX_VEC3_SWIZZLE_DEF(Z, Y, Y)
    _VEX_VEC3_SWIZZLE_DEF(Z, Y, Z)
    _VEX_VEC3_SWIZZLE_DEF(Z, Z, X)
    _VEX_VEC3_SWIZZLE_DEF(Z, Z, Y)
    _VEX_VEC3_SWIZZLE_DEF(Z, Z, Z)
    #endif // _VEX_ENABLE_SWIZZLE_
  };

  typedef Vector3<float> Vec3f;
  typedef Vector3<double> Vec3d;
  typedef Vector3<int> Vec3i;

};

#endif //__VEXLIB_VECTOR3_H__
