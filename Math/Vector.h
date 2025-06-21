#pragma once
#include "../Base/Types.h"

class SECPPAPI FLOAT2D
{
public:
  explicit FLOAT2D(FLOAT2D_* p, bool owner = false);
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
  FLOAT2D operator-() const;
  // between two vectors
  FLOAT2D operator+(const FLOAT2D& vector2) const;
  FLOAT2D& operator+=(const FLOAT2D& vector2);
  FLOAT2D operator-(const FLOAT2D& vector2) const;
  FLOAT2D& operator-=(const FLOAT2D& vector2);
  // multiplication with scalar
  FLOAT2D operator*(const FLOAT scalar) const;
  FLOAT2D& operator*=(const FLOAT scalar);
  // division with scalar
  FLOAT2D operator/(const FLOAT scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOAT2D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOAT2D& vector);

  inline FLOAT2D_* C_Handle() { return mp_vector; }
  inline const FLOAT2D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  FLOAT2D_* mp_vector = nullptr;
};

class SECPPAPI FLOAT3D
{
public:
  explicit FLOAT3D(FLOAT3D_* p, bool owner = false);
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
  FLOAT3D operator-() const;
  // between two vectors
  FLOAT3D operator+(const FLOAT3D& vector2) const;
  FLOAT3D& operator+=(const FLOAT3D& vector2);
  FLOAT3D operator-(const FLOAT3D& vector2) const;
  FLOAT3D& operator-=(const FLOAT3D& vector2);
  // multiplication with scalar
  FLOAT3D operator*(const FLOAT scalar) const;
  FLOAT3D& operator*=(const FLOAT scalar);
  // division with scalar
  FLOAT3D operator/(const FLOAT scalar) const;
  FLOAT3D& operator/=(const FLOAT scalar);
  // multiplication by a square matrix (sides swapped)
  FLOAT3D operator*(const FLOATmatrix3D& matrix2) const;
  FLOAT3D& operator*=(const FLOATmatrix3D& matrix2);
  // scalar product - dot product, inner product
  FLOAT operator%(const FLOAT3D& vector2) const;
  // vector product - cross product, outer product
  FLOAT3D operator*(const FLOAT3D& vector2) const;
  FLOAT3D& operator*=(const FLOAT3D& vector2);
  // comparing vectors
  BOOL operator==(const FLOAT3D& vector2) const;
  BOOL operator!=(const FLOAT3D& vector2) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOAT3D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOAT3D& vector);

  inline FLOAT3D_* C_Handle() { return mp_vector; }
  inline const FLOAT3D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  FLOAT3D_* mp_vector = nullptr;
};

class SECPPAPI FLOAT4D
{
public:
  explicit FLOAT4D(FLOAT4D_* p, bool owner = false);
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
  FLOAT4D operator-() const;
  // between two vectors
  FLOAT4D operator+(const FLOAT4D& vector2) const;
  FLOAT4D& operator+=(const FLOAT4D& vector2);
  FLOAT4D operator-(const FLOAT4D& vector2) const;
  FLOAT4D& operator-=(const FLOAT4D& vector2);
  // multiplication with scalar
  FLOAT4D operator*(const FLOAT scalar) const;
  FLOAT4D& operator*=(const FLOAT scalar);
  // division with scalar
  FLOAT4D operator/(const FLOAT scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOAT4D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOAT4D& vector);

  inline FLOAT4D_* C_Handle() { return mp_vector; }
  inline const FLOAT4D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  FLOAT4D_* mp_vector = nullptr;
};

class SECPPAPI DOUBLE2D
{
public:
  explicit DOUBLE2D(DOUBLE2D_* p, bool owner = false);
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
  DOUBLE2D operator-() const;
  // between two vectors
  DOUBLE2D operator+(const DOUBLE2D& vector2) const;
  DOUBLE2D& operator+=(const DOUBLE2D& vector2);
  DOUBLE2D operator-(const DOUBLE2D& vector2) const;
  DOUBLE2D& operator-=(const DOUBLE2D& vector2);
  // multiplication with scalar
  DOUBLE2D operator*(const DOUBLE scalar) const;
  DOUBLE2D& operator*=(const DOUBLE scalar);
  // division with scalar
  DOUBLE2D operator/(const DOUBLE scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLE2D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLE2D& vector);

  inline DOUBLE2D_* C_Handle() { return mp_vector; }
  inline const DOUBLE2D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  DOUBLE2D_* mp_vector = nullptr;
};

class SECPPAPI DOUBLE3D
{
public:
  explicit DOUBLE3D(DOUBLE3D_* p, bool owner = false);
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
  DOUBLE3D operator-() const;
  // between two vectors
  DOUBLE3D operator+(const DOUBLE3D& vector2) const;
  DOUBLE3D& operator+=(const DOUBLE3D& vector2);
  DOUBLE3D operator-(const DOUBLE3D& vector2) const;
  DOUBLE3D& operator-=(const DOUBLE3D& vector2);
  // multiplication with scalar
  DOUBLE3D operator*(const DOUBLE scalar) const;
  DOUBLE3D& operator*=(const DOUBLE scalar);
  // division with scalar
  DOUBLE3D operator/(const DOUBLE scalar) const;
  DOUBLE3D& operator/=(const DOUBLE scalar);
  // multiplication by a square matrix (sides swapped)
  DOUBLE3D operator*(const DOUBLEmatrix3D& matrix2) const;
  DOUBLE3D& operator*=(const DOUBLEmatrix3D& matrix2);
  // scalar product - dot product, inner product
  DOUBLE operator%(const DOUBLE3D& vector2) const;
  // vector product - cross product, outer product
  DOUBLE3D operator*(const DOUBLE3D& vector2) const;
  DOUBLE3D& operator*=(const DOUBLE3D& vector2);
  // comparing vectors
  BOOL operator==(const DOUBLE3D& vector2) const;
  BOOL operator!=(const DOUBLE3D& vector2) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLE3D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLE3D& vector);

  inline DOUBLE3D_* C_Handle() { return mp_vector; }
  inline const DOUBLE3D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  DOUBLE3D_* mp_vector = nullptr;
};

class SECPPAPI DOUBLE4D
{
public:
  explicit DOUBLE4D(DOUBLE4D_* p, bool owner = false);
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
  DOUBLE4D operator-() const;
  // between two vectors
  DOUBLE4D operator+(const DOUBLE4D& vector2) const;
  DOUBLE4D& operator+=(const DOUBLE4D& vector2);
  DOUBLE4D operator-(const DOUBLE4D& vector2) const;
  DOUBLE4D& operator-=(const DOUBLE4D& vector2);
  // multiplication with scalar
  DOUBLE4D operator*(const DOUBLE scalar) const;
  DOUBLE4D& operator*=(const DOUBLE scalar);
  // division with scalar
  DOUBLE4D operator/(const DOUBLE scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLE4D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLE4D& vector);

  inline DOUBLE4D_* C_Handle() { return mp_vector; }
  inline const DOUBLE4D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  DOUBLE4D_* mp_vector = nullptr;
};

class SECPPAPI INDEX2D
{
public:
  explicit INDEX2D(INDEX2D_* p, bool owner = false);
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
  INDEX2D operator-() const;
  // between two vectors
  INDEX2D operator+(const INDEX2D& vector2) const;
  INDEX2D& operator+=(const INDEX2D& vector2);
  INDEX2D operator-(const INDEX2D& vector2) const;
  INDEX2D& operator-=(const INDEX2D& vector2);
  // multiplication with scalar
  INDEX2D operator*(const INDEX scalar) const;
  INDEX2D& operator*=(const INDEX scalar);
  // division with scalar
  INDEX2D operator/(const INDEX scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEX2D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEX2D& vector);

  inline INDEX2D_* C_Handle() { return mp_vector; }
  inline const INDEX2D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  INDEX2D_* mp_vector = nullptr;
};

class SECPPAPI INDEX3D
{
public:
  explicit INDEX3D(INDEX3D_* p, bool owner = false);
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
  INDEX3D operator-() const;
  // between two vectors
  INDEX3D operator+(const INDEX3D& vector2) const;
  INDEX3D& operator+=(const INDEX3D& vector2);
  INDEX3D operator-(const INDEX3D& vector2) const;
  INDEX3D& operator-=(const INDEX3D& vector2);
  // multiplication with scalar
  INDEX3D operator*(const INDEX scalar) const;
  INDEX3D& operator*=(const INDEX scalar);
  // division with scalar
  INDEX3D operator/(const INDEX scalar) const;
  INDEX3D& operator/=(const INDEX scalar);
  // multiplication by a square matrix (sides swapped)
  INDEX3D operator*(const INDEXmatrix3D& matrix2) const;
  INDEX3D& operator*=(const INDEXmatrix3D& matrix2);
  // scalar product - dot product, inner product
  INDEX operator%(const INDEX3D& vector2) const;
  // vector product - cross product, outer product
  INDEX3D operator*(const INDEX3D& vector2) const;
  INDEX3D& operator*=(const INDEX3D& vector2);
  // comparing vectors
  BOOL operator==(const INDEX3D& vector2) const;
  BOOL operator!=(const INDEX3D& vector2) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEX3D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEX3D& vector);

  inline INDEX3D_* C_Handle() { return mp_vector; }
  inline const INDEX3D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  INDEX3D_* mp_vector = nullptr;
};

class SECPPAPI INDEX4D
{
public:
  explicit INDEX4D(INDEX4D_* p, bool owner = false);
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
  INDEX4D operator-() const;
  // between two vectors
  INDEX4D operator+(const INDEX4D& vector2) const;
  INDEX4D& operator+=(const INDEX4D& vector2);
  INDEX4D operator-(const INDEX4D& vector2) const;
  INDEX4D& operator-=(const INDEX4D& vector2);
  // multiplication with scalar
  INDEX4D operator*(const INDEX scalar) const;
  INDEX4D& operator*=(const INDEX scalar);
  // division with scalar
  INDEX4D operator/(const INDEX scalar) const;
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
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEX4D& vector);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEX4D& vector);

  inline INDEX4D_* C_Handle() { return mp_vector; }
  inline const INDEX4D_* C_Handle() const { return mp_vector; }

private:
  bool m_owner = true;
  INDEX4D_* mp_vector = nullptr;
};

SECPPAPI FLOAT2D ComponentProduct(const FLOAT2D& a, const FLOAT2D& b);
SECPPAPI FLOAT3D ComponentProduct(const FLOAT3D& a, const FLOAT3D& b);
SECPPAPI FLOAT4D ComponentProduct(const FLOAT4D& a, const FLOAT4D& b);
SECPPAPI DOUBLE2D ComponentProduct(const DOUBLE2D& a, const DOUBLE2D& b);
SECPPAPI DOUBLE3D ComponentProduct(const DOUBLE3D& a, const DOUBLE3D& b);
SECPPAPI DOUBLE4D ComponentProduct(const DOUBLE4D& a, const DOUBLE4D& b);
SECPPAPI INDEX2D ComponentProduct(const INDEX2D& a, const INDEX2D& b);
SECPPAPI INDEX3D ComponentProduct(const INDEX3D& a, const INDEX3D& b);
SECPPAPI INDEX4D ComponentProduct(const INDEX4D& a, const INDEX4D& b);

// helper functions for converting between FLOAT and DOUBLE vectors
SECPPAPI DOUBLE3D FLOATtoDOUBLE(const FLOAT3D& vf);
SECPPAPI FLOAT3D DOUBLEtoFLOAT(const DOUBLE3D& vd);
