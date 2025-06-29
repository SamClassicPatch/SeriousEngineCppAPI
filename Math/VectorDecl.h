#pragma once
#include "../Base/Types.h"
#include "MatrixDecl.h"
#include <SeriousEngineCAPI/Math/Vector.h>

class FLOAT2D
{
public:
  FLOAT2D(FLOAT2D_* p, bool owner = false);
  FLOAT2D();
  FLOAT2D(FLOAT x, FLOAT y);
  FLOAT2D(const FLOAT2D& o);
  ~FLOAT2D();

  FLOAT2D& operator=(const FLOAT2D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  FLOAT Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  FLOAT ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  FLOAT MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  FLOAT& operator()(INDEX i);
  FLOAT operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  FLOAT2D& Normalize();
  FLOAT2D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  FLOAT2D& Flip();
  __forceinline FLOAT2D operator-() const { return FLOAT2D(FLOAT2D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline FLOAT2D operator+(const FLOAT2D& vector2) const { return FLOAT2D(FLOAT2D_Plus(mp_vector, vector2.mp_vector), true); }
  FLOAT2D& operator+=(const FLOAT2D& vector2);
  __forceinline FLOAT2D operator-(const FLOAT2D& vector2) const { return FLOAT2D(FLOAT2D_Minus(mp_vector, vector2.mp_vector), true); }
  FLOAT2D& operator-=(const FLOAT2D& vector2);
  // multiplication with scalar
  __forceinline FLOAT2D operator*(const FLOAT scalar) const { return FLOAT2D(FLOAT2D_Multiply(mp_vector, scalar), true); }
  FLOAT2D& operator*=(const FLOAT scalar);
  // division with scalar
  __forceinline FLOAT2D operator/(const FLOAT scalar) const { return FLOAT2D(FLOAT2D_Divide(mp_vector, scalar), true); }
  FLOAT2D& operator/=(const FLOAT scalar);
  // multiplication by a square matrix (sides swapped)
  FLOAT2D operator*(const FLOATmatrix2D& matrix2) const;
  FLOAT2D& operator*=(const FLOATmatrix2D& matrix2);
  // scalar product - dot product, inner product
  FLOAT operator%(const FLOAT2D& vector2) const;
  // comparing vectors
  BOOL operator==(const FLOAT2D& vector2) const;
  BOOL operator!=(const FLOAT2D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOAT2D& vector);
  friend CTStream& operator<<(CTStream& strm, FLOAT2D& vector);

  inline FLOAT2D_* C_Handle() { return mp_vector; }
  inline const FLOAT2D_* C_Handle() const { return mp_vector; }
  inline operator FLOAT2D_* () { return C_Handle(); }
  inline operator const FLOAT2D_* () const { return C_Handle(); }
protected:
  bool m_owner = true;
  FLOAT2D_* mp_vector = nullptr;
};

class FLOAT3D
{
public:
  FLOAT3D(FLOAT3D_* p, bool owner = false);
  FLOAT3D();
  FLOAT3D(FLOAT x, FLOAT y, FLOAT z);
  FLOAT3D(const FLOAT3D& o);
  ~FLOAT3D();

  FLOAT3D& operator=(const FLOAT3D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  FLOAT Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  FLOAT ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  FLOAT MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  FLOAT& operator()(INDEX i);
  FLOAT operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  FLOAT3D& Normalize();
  FLOAT3D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  FLOAT3D& Flip();
  __forceinline FLOAT3D operator-() const { return FLOAT3D(FLOAT3D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline FLOAT3D operator+(const FLOAT3D& vector2) const { return FLOAT3D(FLOAT3D_Plus(mp_vector, vector2.mp_vector), true); }
  FLOAT3D& operator+=(const FLOAT3D& vector2);
  __forceinline FLOAT3D operator-(const FLOAT3D& vector2) const { return FLOAT3D(FLOAT3D_Minus(mp_vector, vector2.mp_vector), true); }
  FLOAT3D& operator-=(const FLOAT3D& vector2);
  // multiplication with scalar
  __forceinline FLOAT3D operator*(const FLOAT scalar) const { return FLOAT3D(FLOAT3D_Multiply(mp_vector, scalar), true); }
  FLOAT3D& operator*=(const FLOAT scalar);
  // division with scalar
  __forceinline FLOAT3D operator/(const FLOAT scalar) const { return FLOAT3D(FLOAT3D_Divide(mp_vector, scalar), true); }
  FLOAT3D& operator/=(const FLOAT scalar);
  // multiplication by a square matrix (sides swapped)
  FLOAT3D operator*(const FLOATmatrix3D& matrix2) const;
  FLOAT3D& operator*=(const FLOATmatrix3D& matrix2);
  // scalar product - dot product, inner product
  FLOAT operator%(const FLOAT3D& vector2) const;
  // vector product - cross product, outer product
  __forceinline FLOAT3D operator*(const FLOAT3D& vector2) const { return FLOAT3D(FLOAT3D_Multiply_vector(mp_vector, vector2.mp_vector), true); }
  FLOAT3D& operator*=(const FLOAT3D& vector2);
  // comparing vectors
  BOOL operator==(const FLOAT3D& vector2) const;
  BOOL operator!=(const FLOAT3D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOAT3D& vector);
  friend CTStream& operator<<(CTStream& strm, FLOAT3D& vector);

  inline FLOAT3D_* C_Handle() { return mp_vector; }
  inline const FLOAT3D_* C_Handle() const { return mp_vector; }
  inline operator FLOAT3D_* () { return C_Handle(); }
  inline operator const FLOAT3D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  FLOAT3D_* mp_vector = nullptr;
};

class FLOAT4D
{
public:
  FLOAT4D(FLOAT4D_* p, bool owner = false);
  FLOAT4D();
  FLOAT4D(FLOAT x, FLOAT y, FLOAT z, FLOAT w);
  FLOAT4D(const FLOAT4D& o);
  ~FLOAT4D();

  FLOAT4D& operator=(const FLOAT4D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  FLOAT Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  FLOAT ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  FLOAT MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  FLOAT& operator()(INDEX i);
  FLOAT operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  FLOAT4D& Normalize();
  FLOAT4D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  FLOAT4D& Flip();
  __forceinline FLOAT4D operator-() const { return FLOAT4D(FLOAT4D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline FLOAT4D operator+(const FLOAT4D& vector2) const { return FLOAT4D(FLOAT4D_Plus(mp_vector, vector2.mp_vector), true); }
  FLOAT4D& operator+=(const FLOAT4D& vector2);
  __forceinline FLOAT4D operator-(const FLOAT4D& vector2) const { return FLOAT4D(FLOAT4D_Minus(mp_vector, vector2.mp_vector), true); }
  FLOAT4D& operator-=(const FLOAT4D& vector2);
  // multiplication with scalar
  __forceinline FLOAT4D operator*(const FLOAT scalar) const { return FLOAT4D(FLOAT4D_Multiply(mp_vector, scalar), true); }
  FLOAT4D& operator*=(const FLOAT scalar);
  // division with scalar
  __forceinline FLOAT4D operator/(const FLOAT scalar) const { return FLOAT4D(FLOAT4D_Divide(mp_vector, scalar), true); }
  FLOAT4D& operator/=(const FLOAT scalar);
  // multiplication by a square matrix (sides swapped)
  FLOAT4D operator*(const FLOATmatrix4D& matrix2) const;
  FLOAT4D& operator*=(const FLOATmatrix4D& matrix2);
  // scalar product - dot product, inner product
  FLOAT operator%(const FLOAT4D& vector2) const;
  // comparing vectors
  BOOL operator==(const FLOAT4D& vector2) const;
  BOOL operator!=(const FLOAT4D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOAT4D& vector);
  friend CTStream& operator<<(CTStream& strm, FLOAT4D& vector);

  inline FLOAT4D_* C_Handle() { return mp_vector; }
  inline const FLOAT4D_* C_Handle() const { return mp_vector; }
  inline operator FLOAT4D_* () { return C_Handle(); }
  inline operator const FLOAT4D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  FLOAT4D_* mp_vector = nullptr;
};

class DOUBLE2D
{
public:
  DOUBLE2D(DOUBLE2D_* p, bool owner = false);
  DOUBLE2D();
  DOUBLE2D(DOUBLE x, DOUBLE y);
  DOUBLE2D(const DOUBLE2D& o);
  ~DOUBLE2D();

  DOUBLE2D& operator=(const DOUBLE2D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  DOUBLE Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  DOUBLE ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  DOUBLE MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  DOUBLE& operator()(INDEX i);
  DOUBLE operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  DOUBLE2D& Normalize();
  DOUBLE2D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  DOUBLE2D& Flip();
  __forceinline DOUBLE2D operator-() const { return DOUBLE2D(DOUBLE2D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline DOUBLE2D operator+(const DOUBLE2D& vector2) const { return DOUBLE2D(DOUBLE2D_Plus(mp_vector, vector2.mp_vector), true); }
  DOUBLE2D& operator+=(const DOUBLE2D& vector2);
  __forceinline DOUBLE2D operator-(const DOUBLE2D& vector2) const { return DOUBLE2D(DOUBLE2D_Minus(mp_vector, vector2.mp_vector), true); }
  DOUBLE2D& operator-=(const DOUBLE2D& vector2);
  // multiplication with scalar
  __forceinline DOUBLE2D operator*(const DOUBLE scalar) const { return DOUBLE2D(DOUBLE2D_Multiply(mp_vector, scalar), true); }
  DOUBLE2D& operator*=(const DOUBLE scalar);
  // division with scalar
  __forceinline DOUBLE2D operator/(const DOUBLE scalar) const { return DOUBLE2D(DOUBLE2D_Divide(mp_vector, scalar), true); }
  DOUBLE2D& operator/=(const DOUBLE scalar);
  // multiplication by a square matrix (sides swapped)
  DOUBLE2D operator*(const DOUBLEmatrix2D& matrix2) const;
  DOUBLE2D& operator*=(const DOUBLEmatrix2D& matrix2);
  // scalar product - dot product, inner product
  DOUBLE operator%(const DOUBLE2D& vector2) const;
  // comparing vectors
  BOOL operator==(const DOUBLE2D& vector2) const;
  BOOL operator!=(const DOUBLE2D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLE2D& vector);
  friend CTStream& operator<<(CTStream& strm, DOUBLE2D& vector);

  inline DOUBLE2D_* C_Handle() { return mp_vector; }
  inline const DOUBLE2D_* C_Handle() const { return mp_vector; }
  inline operator DOUBLE2D_* () { return C_Handle(); }
  inline operator const DOUBLE2D_* () const { return C_Handle(); }
protected:
  bool m_owner = true;
  DOUBLE2D_* mp_vector = nullptr;
};

class DOUBLE3D
{
public:
  DOUBLE3D(DOUBLE3D_* p, bool owner = false);
  DOUBLE3D();
  DOUBLE3D(DOUBLE x, DOUBLE y, DOUBLE z);
  DOUBLE3D(const DOUBLE3D& o);
  ~DOUBLE3D();

  DOUBLE3D& operator=(const DOUBLE3D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  DOUBLE Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  DOUBLE ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  DOUBLE MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  DOUBLE& operator()(INDEX i);
  DOUBLE operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  DOUBLE3D& Normalize();
  DOUBLE3D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  DOUBLE3D& Flip();
  __forceinline DOUBLE3D operator-() const { return DOUBLE3D(DOUBLE3D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline DOUBLE3D operator+(const DOUBLE3D& vector2) const { return DOUBLE3D(DOUBLE3D_Plus(mp_vector, vector2.mp_vector), true); }
  DOUBLE3D& operator+=(const DOUBLE3D& vector2);
  __forceinline DOUBLE3D operator-(const DOUBLE3D& vector2) const { return DOUBLE3D(DOUBLE3D_Minus(mp_vector, vector2.mp_vector), true); }
  DOUBLE3D& operator-=(const DOUBLE3D& vector2);
  // multiplication with scalar
  __forceinline DOUBLE3D operator*(const DOUBLE scalar) const { return DOUBLE3D(DOUBLE3D_Multiply(mp_vector, scalar), true); }
  DOUBLE3D& operator*=(const DOUBLE scalar);
  // division with scalar
  __forceinline DOUBLE3D operator/(const DOUBLE scalar) const { return DOUBLE3D(DOUBLE3D_Divide(mp_vector, scalar), true); }
  DOUBLE3D& operator/=(const DOUBLE scalar);
  // multiplication by a square matrix (sides swapped)
  DOUBLE3D operator*(const DOUBLEmatrix3D& matrix2) const;
  DOUBLE3D& operator*=(const DOUBLEmatrix3D& matrix2);
  // scalar product - dot product, inner product
  DOUBLE operator%(const DOUBLE3D& vector2) const;
  // vector product - cross product, outer product
  __forceinline DOUBLE3D operator*(const DOUBLE3D& vector2) const { return DOUBLE3D(DOUBLE3D_Multiply_vector(mp_vector, vector2.mp_vector), true); }
  DOUBLE3D& operator*=(const DOUBLE3D& vector2);
  // comparing vectors
  BOOL operator==(const DOUBLE3D& vector2) const;
  BOOL operator!=(const DOUBLE3D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLE3D& vector);
  friend CTStream& operator<<(CTStream& strm, DOUBLE3D& vector);

  inline DOUBLE3D_* C_Handle() { return mp_vector; }
  inline const DOUBLE3D_* C_Handle() const { return mp_vector; }
  inline operator DOUBLE3D_* () { return C_Handle(); }
  inline operator const DOUBLE3D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  DOUBLE3D_* mp_vector = nullptr;
};

class DOUBLE4D
{
public:
  DOUBLE4D(DOUBLE4D_* p, bool owner = false);
  DOUBLE4D();
  DOUBLE4D(DOUBLE x, DOUBLE y, DOUBLE z, DOUBLE w);
  DOUBLE4D(const DOUBLE4D& o);
  ~DOUBLE4D();

  DOUBLE4D& operator=(const DOUBLE4D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  DOUBLE Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  DOUBLE ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  DOUBLE MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  DOUBLE& operator()(INDEX i);
  DOUBLE operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  DOUBLE4D& Normalize();
  DOUBLE4D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  DOUBLE4D& Flip();
  __forceinline DOUBLE4D operator-() const { return DOUBLE4D(DOUBLE4D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline DOUBLE4D operator+(const DOUBLE4D& vector2) const { return DOUBLE4D(DOUBLE4D_Plus(mp_vector, vector2.mp_vector), true); }
  DOUBLE4D& operator+=(const DOUBLE4D& vector2);
  __forceinline DOUBLE4D operator-(const DOUBLE4D& vector2) const { return DOUBLE4D(DOUBLE4D_Minus(mp_vector, vector2.mp_vector), true); }
  DOUBLE4D& operator-=(const DOUBLE4D& vector2);
  // multiplication with scalar
  __forceinline DOUBLE4D operator*(const DOUBLE scalar) const { return DOUBLE4D(DOUBLE4D_Multiply(mp_vector, scalar), true); }
  DOUBLE4D& operator*=(const DOUBLE scalar);
  // division with scalar
  __forceinline DOUBLE4D operator/(const DOUBLE scalar) const { return DOUBLE4D(DOUBLE4D_Divide(mp_vector, scalar), true); }
  DOUBLE4D& operator/=(const DOUBLE scalar);
  // multiplication by a square matrix (sides swapped)
  DOUBLE4D operator*(const DOUBLEmatrix4D& matrix2) const;
  DOUBLE4D& operator*=(const DOUBLEmatrix4D& matrix2);
  // scalar product - dot product, inner product
  DOUBLE operator%(const DOUBLE4D& vector2) const;
  // comparing vectors
  BOOL operator==(const DOUBLE4D& vector2) const;
  BOOL operator!=(const DOUBLE4D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLE4D& vector);
  friend CTStream& operator<<(CTStream& strm, DOUBLE4D& vector);

  inline DOUBLE4D_* C_Handle() { return mp_vector; }
  inline const DOUBLE4D_* C_Handle() const { return mp_vector; }
  inline operator DOUBLE4D_* () { return C_Handle(); }
  inline operator const DOUBLE4D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  DOUBLE4D_* mp_vector = nullptr;
};

class INDEX2D
{
public:
  INDEX2D(INDEX2D_* p, bool owner = false);
  INDEX2D();
  INDEX2D(INDEX x, INDEX y);
  INDEX2D(const INDEX2D& o);
  ~INDEX2D();

  INDEX2D& operator=(const INDEX2D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  INDEX Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  INDEX ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  INDEX MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  INDEX& operator()(INDEX i);
  INDEX operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  INDEX2D& Normalize();
  INDEX2D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  INDEX2D& Flip();
  __forceinline INDEX2D operator-() const { return INDEX2D(INDEX2D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline INDEX2D operator+(const INDEX2D& vector2) const { return INDEX2D(INDEX2D_Plus(mp_vector, vector2.mp_vector), true); }
  INDEX2D& operator+=(const INDEX2D& vector2);
  __forceinline INDEX2D operator-(const INDEX2D& vector2) const { return INDEX2D(INDEX2D_Minus(mp_vector, vector2.mp_vector), true); }
  INDEX2D& operator-=(const INDEX2D& vector2);
  // multiplication with scalar
  __forceinline INDEX2D operator*(const INDEX scalar) const { return INDEX2D(INDEX2D_Multiply(mp_vector, scalar), true); }
  INDEX2D& operator*=(const INDEX scalar);
  // division with scalar
  __forceinline INDEX2D operator/(const INDEX scalar) const { return INDEX2D(INDEX2D_Divide(mp_vector, scalar), true); }
  INDEX2D& operator/=(const INDEX scalar);
  // multiplication by a square matrix (sides swapped)
  INDEX2D operator*(const INDEXmatrix2D& matrix2) const;
  INDEX2D& operator*=(const INDEXmatrix2D& matrix2);
  // scalar product - dot product, inner product
  INDEX operator%(const INDEX2D& vector2) const;
  // comparing vectors
  BOOL operator==(const INDEX2D& vector2) const;
  BOOL operator!=(const INDEX2D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEX2D& vector);
  friend CTStream& operator<<(CTStream& strm, INDEX2D& vector);

  inline INDEX2D_* C_Handle() { return mp_vector; }
  inline const INDEX2D_* C_Handle() const { return mp_vector; }
  inline operator INDEX2D_* () { return C_Handle(); }
  inline operator const INDEX2D_* () const { return C_Handle(); }
protected:
  bool m_owner = true;
  INDEX2D_* mp_vector = nullptr;
};

class INDEX3D
{
public:
  INDEX3D(INDEX3D_* p, bool owner = false);
  INDEX3D();
  INDEX3D(INDEX x, INDEX y, INDEX z);
  INDEX3D(const INDEX3D& o);
  ~INDEX3D();

  INDEX3D& operator=(const INDEX3D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  INDEX Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  INDEX ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  INDEX MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  INDEX& operator()(INDEX i);
  INDEX operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  INDEX3D& Normalize();
  INDEX3D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  INDEX3D& Flip();
  __forceinline INDEX3D operator-() const { return INDEX3D(INDEX3D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline INDEX3D operator+(const INDEX3D& vector2) const { return INDEX3D(INDEX3D_Plus(mp_vector, vector2.mp_vector), true); }
  INDEX3D& operator+=(const INDEX3D& vector2);
  __forceinline INDEX3D operator-(const INDEX3D& vector2) const { return INDEX3D(INDEX3D_Minus(mp_vector, vector2.mp_vector), true); }
  INDEX3D& operator-=(const INDEX3D& vector2);
  // multiplication with scalar
  __forceinline INDEX3D operator*(const INDEX scalar) const { return INDEX3D(INDEX3D_Multiply(mp_vector, scalar), true); }
  INDEX3D& operator*=(const INDEX scalar);
  // division with scalar
  __forceinline INDEX3D operator/(const INDEX scalar) const { return INDEX3D(INDEX3D_Divide(mp_vector, scalar), true); }
  INDEX3D& operator/=(const INDEX scalar);
  // multiplication by a square matrix (sides swapped)
  INDEX3D operator*(const INDEXmatrix3D& matrix2) const;
  INDEX3D& operator*=(const INDEXmatrix3D& matrix2);
  // scalar product - dot product, inner product
  INDEX operator%(const INDEX3D& vector2) const;
  // vector product - cross product, outer product
  __forceinline INDEX3D operator*(const INDEX3D& vector2) const { return INDEX3D(INDEX3D_Multiply_vector(mp_vector, vector2.mp_vector), true); }
  INDEX3D& operator*=(const INDEX3D& vector2);
  // comparing vectors
  BOOL operator==(const INDEX3D& vector2) const;
  BOOL operator!=(const INDEX3D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEX3D& vector);
  friend CTStream& operator<<(CTStream& strm, INDEX3D& vector);

  inline INDEX3D_* C_Handle() { return mp_vector; }
  inline const INDEX3D_* C_Handle() const { return mp_vector; }
  inline operator INDEX3D_* () { return C_Handle(); }
  inline operator const INDEX3D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  INDEX3D_* mp_vector = nullptr;
};

class INDEX4D
{
public:
  INDEX4D(INDEX4D_* p, bool owner = false);
  INDEX4D();
  INDEX4D(INDEX x, INDEX y, INDEX z, INDEX w);
  INDEX4D(const INDEX4D& o);
  ~INDEX4D();

  INDEX4D& operator=(const INDEX4D& o);

  /* Clear function */
  void Clear();
  /* Conversion into scalar -- length of vector (Euclidian norm). */
  INDEX Length() const;
  /* Conversion into scalar -- Manhattan norm of vector. */
  INDEX ManhattanNorm() const;
  /* Conversion into scalar -- Max norm of vector. */
  INDEX MaxNorm() const;

  /* Reference vector member by it's index (1-based indices!). */
  INDEX& operator()(INDEX i);
  INDEX operator()(INDEX i) const;

  /* Normalize vector, i.e. make it a unit vector. */
  INDEX4D& Normalize();
  INDEX4D& SafeNormalize(); // gives vector with (0,0,0) orientation if input is too small

  /* Mathematical operators. */
  // unary minus
  INDEX4D& Flip();
  __forceinline INDEX4D operator-() const { return INDEX4D(INDEX4D_Negative(mp_vector), true); }
  // between two vectors
  __forceinline INDEX4D operator+(const INDEX4D& vector2) const { return INDEX4D(INDEX4D_Plus(mp_vector, vector2.mp_vector), true); }
  INDEX4D& operator+=(const INDEX4D& vector2);
  __forceinline INDEX4D operator-(const INDEX4D& vector2) const { return INDEX4D(INDEX4D_Minus(mp_vector, vector2.mp_vector), true); }
  INDEX4D& operator-=(const INDEX4D& vector2);
  // multiplication with scalar
  __forceinline INDEX4D operator*(const INDEX scalar) const { return INDEX4D(INDEX4D_Multiply(mp_vector, scalar), true); }
  INDEX4D& operator*=(const INDEX scalar);
  // division with scalar
  __forceinline INDEX4D operator/(const INDEX scalar) const { return INDEX4D(INDEX4D_Divide(mp_vector, scalar), true); }
  INDEX4D& operator/=(const INDEX scalar);
  // multiplication by a square matrix (sides swapped)
  INDEX4D operator*(const INDEXmatrix4D& matrix2) const;
  INDEX4D& operator*=(const INDEXmatrix4D& matrix2);
  // scalar product - dot product, inner product
  INDEX operator%(const INDEX4D& vector2) const;
  // comparing vectors
  BOOL operator==(const INDEX4D& vector2) const;
  BOOL operator!=(const INDEX4D& vector2) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEX4D& vector);
  friend CTStream& operator<<(CTStream& strm, INDEX4D& vector);

  inline INDEX4D_* C_Handle() { return mp_vector; }
  inline const INDEX4D_* C_Handle() const { return mp_vector; }
  inline operator INDEX4D_* () { return C_Handle(); }
  inline operator const INDEX4D_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  INDEX4D_* mp_vector = nullptr;
};

__forceinline FLOAT2D ComponentProduct(const FLOAT2D& a, const FLOAT2D& b) { return FLOAT2D(FLOAT2D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline FLOAT3D ComponentProduct(const FLOAT3D& a, const FLOAT3D& b) { return FLOAT3D(FLOAT3D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline FLOAT4D ComponentProduct(const FLOAT4D& a, const FLOAT4D& b) { return FLOAT4D(FLOAT4D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline DOUBLE2D ComponentProduct(const DOUBLE2D& a, const DOUBLE2D& b) { return DOUBLE2D(DOUBLE2D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline DOUBLE3D ComponentProduct(const DOUBLE3D& a, const DOUBLE3D& b) { return DOUBLE3D(DOUBLE3D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline DOUBLE4D ComponentProduct(const DOUBLE4D& a, const DOUBLE4D& b) { return DOUBLE4D(DOUBLE4D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline INDEX2D ComponentProduct(const INDEX2D& a, const INDEX2D& b) { return INDEX2D(INDEX2D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline INDEX3D ComponentProduct(const INDEX3D& a, const INDEX3D& b) { return INDEX3D(INDEX3D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }
__forceinline INDEX4D ComponentProduct(const INDEX4D& a, const INDEX4D& b) { return INDEX4D(INDEX4D_ComponentProduct(a.C_Handle(), b.C_Handle()), true); }

// helper functions for converting between FLOAT and DOUBLE vectors
__forceinline DOUBLE3D FLOATtoDOUBLE(const FLOAT3D& vf) { return DOUBLE3D(FLOAT2DOUBLE(vf.C_Handle()), true); }
__forceinline FLOAT3D DOUBLEtoFLOAT(const DOUBLE3D& vd) { return FLOAT3D(DOUBLE2FLOAT(vd.C_Handle()), true); }
