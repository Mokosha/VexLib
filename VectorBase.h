#ifndef __VEXLIB_VECTOR_H__
#define __VEXLIB_VECTOR_H__

// !FIXME! For sqrt function. This increases compilation time by a LOT 
// but I couldn't guarantee any faster general-purpose implementation
#include <cmath>

namespace VexLib {

  template <typename T, const int N>
  class VectorBase {
   protected:

    // Vector representation
    T vec[N];

   public:
    
    VectorBase() { }
    VectorBase(const VectorBase<T, N> &other) {
      for(int i = 0; i < N; i++) vec[i] = other[i];
    }

    VectorBase(T *_vec) {
      for(int i = 0; i < N; i++) {
	vec[i] = _vec[i];
      }
    }

    // Accessors
    T &operator()(int idx) { return vec[idx]; }
    T &operator[](int idx) { return vec[idx]; }
    const T &operator()(int idx) const { return vec[idx]; }
    const T &operator[](int idx) const { return vec[idx]; }

    // Allow casts to the respective array representation...
    operator T *() const { return vec; }
    VectorBase<T, N> &operator=(const T *v) {
      for(int i = 0; i < N; i++) vec[i] = v[i];
      return *this;
    }

    // Allows casting to other vector types if the underlying type system does as well...
    template<typename _T>
    operator VectorBase<_T, N>() const { 
      return VectorBase<_T, N>(vec); 
    }

    // Operators
    template<typename _T>
    VectorBase<T, N> operator+(const VectorBase<_T, N> &v) const {
      VectorBase a;
      for(int i = 0; i < N; i++) {
	a.vec[i] = v(i) + vec[i];
      }
      return a;
    }

    template<typename _T>
    VectorBase<T, N> operator-(const VectorBase<_T, N> &v) const {
      VectorBase<T, N> a;
      for(int i = 0; i < N; i++) {
	a(i) = v[i] - vec[i];
      }
      return a;
    }

    template<typename _T>
    VectorBase<T, N> &operator=(const VectorBase<_T, N> &v) {
      for(int i = 0; i < N; i++) {
	vec[i] = v[i];
      }
      return *this;
    }

    template<typename _T>
    VectorBase<T, N> operator*(const _T s) const {
      VectorBase<T, N> a;
      for(int i = 0; i < N; i++) a[i] = vec[i] * s;
      return a;
    }
  
    template<typename _T>
    friend VectorBase<T, N> operator*(const _T s, const VectorBase<T, N> &v) {
      VectorBase<T, N> a;
      for(int i = 0; i < N; i++) a[i] = v(i) * s;
      return a;
    }

    template<typename _T>
    void operator*=(const _T s) {
      for(int i = 0; i < N; i++) vec[i] *= s;
    }

    // Vector operations
    template<typename _T>
    T Dot(const VectorBase<_T, N> &v) const {
      T sum = 0;
      for(int i = 0; i < N; i++) sum += vec[i] * v[i];
      return sum;
    }

    float Length() const {
      return sqrt((float)(this->Dot(*this)));
    }

    double LengthD() const {
      return sqrt((double)(this->Dot(*this)));
    }
  };
};

#endif //__VEXLIB_VECTOR_H__
