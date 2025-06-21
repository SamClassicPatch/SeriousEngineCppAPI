#pragma once
#include "../Base/Types.h"

class SECPPAPI FLOATmatrix2D
{
public:
  explicit FLOATmatrix2D(FLOATmatrix2D_* p, bool owner = false);
  FLOATmatrix2D();
  explicit FLOATmatrix2D(FLOAT x);
  FLOATmatrix2D(const FLOATmatrix2D& o);
  ~FLOATmatrix2D();

  FLOATmatrix2D& operator=(const FLOATmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  FLOATmatrix2D operator!() const;
  FLOATmatrix2D& operator!=(const FLOATmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  FLOATmatrix2D operator+(const FLOATmatrix2D& matrix2) const;
  FLOATmatrix2D& operator+=(const FLOATmatrix2D& matrix2);
  FLOATmatrix2D operator-(const FLOATmatrix2D& matrix2) const;
  FLOATmatrix2D& operator-=(const FLOATmatrix2D& matrix2);
  FLOATmatrix2D operator*(const FLOATmatrix2D& matrix2) const;
  FLOATmatrix2D& operator*=(const FLOATmatrix2D& matrix2);
  // matrices and scalars
  FLOATmatrix2D operator*(const FLOAT tMul) const;
  FLOATmatrix2D& operator*=(const FLOAT tMul);
  FLOATmatrix2D operator/(const FLOAT tMul) const;
  FLOATmatrix2D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT2D& v);

  // get main vectors of matrix
  FLOAT2D GetRow(INDEX iRow) const;
  FLOAT2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOATmatrix2D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOATmatrix2D& matrix);

  inline FLOATmatrix2D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix2D_* () { return C_Handle(); }
  inline operator const FLOATmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI FLOATmatrix3D
{
public:
  explicit FLOATmatrix3D(FLOATmatrix3D_* p, bool owner = false);
  FLOATmatrix3D();
  explicit FLOATmatrix3D(FLOAT x);
  FLOATmatrix3D(const FLOATmatrix3D& o);
  ~FLOATmatrix3D();

  FLOATmatrix3D& operator=(const FLOATmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  FLOATmatrix3D operator!() const;
  FLOATmatrix3D& operator!=(const FLOATmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  FLOATmatrix3D operator+(const FLOATmatrix3D& matrix2) const;
  FLOATmatrix3D& operator+=(const FLOATmatrix3D& matrix2);
  FLOATmatrix3D operator-(const FLOATmatrix3D& matrix2) const;
  FLOATmatrix3D& operator-=(const FLOATmatrix3D& matrix2);
  FLOATmatrix3D operator*(const FLOATmatrix3D& matrix2) const;
  FLOATmatrix3D& operator*=(const FLOATmatrix3D& matrix2);
  // matrices and scalars
  FLOATmatrix3D operator*(const FLOAT tMul) const;
  FLOATmatrix3D& operator*=(const FLOAT tMul);
  FLOATmatrix3D operator/(const FLOAT tMul) const;
  FLOATmatrix3D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT3D& v);

  // get main vectors of matrix
  FLOAT3D GetRow(INDEX iRow) const;
  FLOAT3D GetColumn(INDEX iColumn) const;

  FLOAT Determinant() const;
  FLOATmatrix3D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOATmatrix3D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOATmatrix3D& matrix);

  inline FLOATmatrix3D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix3D_* () { return C_Handle(); }
  inline operator const FLOATmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI FLOATmatrix4D
{
public:
  explicit FLOATmatrix4D(FLOATmatrix4D_* p, bool owner = false);
  FLOATmatrix4D();
  explicit FLOATmatrix4D(FLOAT x);
  FLOATmatrix4D(const FLOATmatrix4D& o);
  ~FLOATmatrix4D();

  FLOATmatrix4D& operator=(const FLOATmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  FLOATmatrix4D operator!() const;
  FLOATmatrix4D& operator!=(const FLOATmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  FLOATmatrix4D operator+(const FLOATmatrix4D& matrix2) const;
  FLOATmatrix4D& operator+=(const FLOATmatrix4D& matrix2);
  FLOATmatrix4D operator-(const FLOATmatrix4D& matrix2) const;
  FLOATmatrix4D& operator-=(const FLOATmatrix4D& matrix2);
  FLOATmatrix4D operator*(const FLOATmatrix4D& matrix2) const;
  FLOATmatrix4D& operator*=(const FLOATmatrix4D& matrix2);
  // matrices and scalars
  FLOATmatrix4D operator*(const FLOAT tMul) const;
  FLOATmatrix4D& operator*=(const FLOAT tMul);
  FLOATmatrix4D operator/(const FLOAT tMul) const;
  FLOATmatrix4D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT4D& v);

  // get main vectors of matrix
  FLOAT4D GetRow(INDEX iRow) const;
  FLOAT4D GetColumn(INDEX iColumn) const;

  FLOATmatrix4D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, FLOATmatrix4D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, FLOATmatrix4D& matrix);

  inline FLOATmatrix4D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix4D_* () { return C_Handle(); }
  inline operator const FLOATmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix4D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix2D
{
public:
  explicit DOUBLEmatrix2D(DOUBLEmatrix2D_* p, bool owner = false);
  DOUBLEmatrix2D();
  explicit DOUBLEmatrix2D(DOUBLE x);
  DOUBLEmatrix2D(const DOUBLEmatrix2D& o);
  ~DOUBLEmatrix2D();

  DOUBLEmatrix2D& operator=(const DOUBLEmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  DOUBLEmatrix2D operator!() const;
  DOUBLEmatrix2D& operator!=(const DOUBLEmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  DOUBLEmatrix2D operator+(const DOUBLEmatrix2D& matrix2) const;
  DOUBLEmatrix2D& operator+=(const DOUBLEmatrix2D& matrix2);
  DOUBLEmatrix2D operator-(const DOUBLEmatrix2D& matrix2) const;
  DOUBLEmatrix2D& operator-=(const DOUBLEmatrix2D& matrix2);
  DOUBLEmatrix2D operator*(const DOUBLEmatrix2D& matrix2) const;
  DOUBLEmatrix2D& operator*=(const DOUBLEmatrix2D& matrix2);
  // matrices and scalars
  DOUBLEmatrix2D operator*(const DOUBLE tMul) const;
  DOUBLEmatrix2D& operator*=(const DOUBLE tMul);
  DOUBLEmatrix2D operator/(const DOUBLE tMul) const;
  DOUBLEmatrix2D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE2D& v);

  // get main vectors of matrix
  DOUBLE2D GetRow(INDEX iRow) const;
  DOUBLE2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix2D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix2D& matrix);

  inline DOUBLEmatrix2D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix2D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix3D
{
public:
  explicit DOUBLEmatrix3D(DOUBLEmatrix3D_* p, bool owner = false);
  DOUBLEmatrix3D();
  explicit DOUBLEmatrix3D(DOUBLE x);
  DOUBLEmatrix3D(const DOUBLEmatrix3D& o);
  ~DOUBLEmatrix3D();

  DOUBLEmatrix3D& operator=(const DOUBLEmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  DOUBLEmatrix3D operator!() const;
  DOUBLEmatrix3D& operator!=(const DOUBLEmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  DOUBLEmatrix3D operator+(const DOUBLEmatrix3D& matrix2) const;
  DOUBLEmatrix3D& operator+=(const DOUBLEmatrix3D& matrix2);
  DOUBLEmatrix3D operator-(const DOUBLEmatrix3D& matrix2) const;
  DOUBLEmatrix3D& operator-=(const DOUBLEmatrix3D& matrix2);
  DOUBLEmatrix3D operator*(const DOUBLEmatrix3D& matrix2) const;
  DOUBLEmatrix3D& operator*=(const DOUBLEmatrix3D& matrix2);
  // matrices and scalars
  DOUBLEmatrix3D operator*(const DOUBLE tMul) const;
  DOUBLEmatrix3D& operator*=(const DOUBLE tMul);
  DOUBLEmatrix3D operator/(const DOUBLE tMul) const;
  DOUBLEmatrix3D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE3D& v);

  // get main vectors of matrix
  DOUBLE3D GetRow(INDEX iRow) const;
  DOUBLE3D GetColumn(INDEX iColumn) const;

  DOUBLE Determinant() const;
  DOUBLEmatrix3D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix3D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix3D& matrix);

  inline DOUBLEmatrix3D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix3D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix4D
{
public:
  explicit DOUBLEmatrix4D(DOUBLEmatrix4D_* p, bool owner = false);
  DOUBLEmatrix4D();
  explicit DOUBLEmatrix4D(DOUBLE x);
  DOUBLEmatrix4D(const DOUBLEmatrix4D& o);
  ~DOUBLEmatrix4D();

  DOUBLEmatrix4D& operator=(const DOUBLEmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  DOUBLEmatrix4D operator!() const;
  DOUBLEmatrix4D& operator!=(const DOUBLEmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  DOUBLEmatrix4D operator+(const DOUBLEmatrix4D& matrix2) const;
  DOUBLEmatrix4D& operator+=(const DOUBLEmatrix4D& matrix2);
  DOUBLEmatrix4D operator-(const DOUBLEmatrix4D& matrix2) const;
  DOUBLEmatrix4D& operator-=(const DOUBLEmatrix4D& matrix2);
  DOUBLEmatrix4D operator*(const DOUBLEmatrix4D& matrix2) const;
  DOUBLEmatrix4D& operator*=(const DOUBLEmatrix4D& matrix2);
  // matrices and scalars
  DOUBLEmatrix4D operator*(const DOUBLE tMul) const;
  DOUBLEmatrix4D& operator*=(const DOUBLE tMul);
  DOUBLEmatrix4D operator/(const DOUBLE tMul) const;
  DOUBLEmatrix4D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE4D& v);

  // get main vectors of matrix
  DOUBLE4D GetRow(INDEX iRow) const;
  DOUBLE4D GetColumn(INDEX iColumn) const;

  DOUBLEmatrix4D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix4D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix4D& matrix);

  inline DOUBLEmatrix4D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix4D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix4D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix2D
{
public:
  explicit INDEXmatrix2D(INDEXmatrix2D_* p, bool owner = false);
  INDEXmatrix2D();
  explicit INDEXmatrix2D(INDEX x);
  INDEXmatrix2D(const INDEXmatrix2D& o);
  ~INDEXmatrix2D();

  INDEXmatrix2D& operator=(const INDEXmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  INDEXmatrix2D operator!() const;
  INDEXmatrix2D& operator!=(const INDEXmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  INDEXmatrix2D operator+(const INDEXmatrix2D& matrix2) const;
  INDEXmatrix2D& operator+=(const INDEXmatrix2D& matrix2);
  INDEXmatrix2D operator-(const INDEXmatrix2D& matrix2) const;
  INDEXmatrix2D& operator-=(const INDEXmatrix2D& matrix2);
  INDEXmatrix2D operator*(const INDEXmatrix2D& matrix2) const;
  INDEXmatrix2D& operator*=(const INDEXmatrix2D& matrix2);
  // matrices and scalars
  INDEXmatrix2D operator*(const INDEX tMul) const;
  INDEXmatrix2D& operator*=(const INDEX tMul);
  INDEXmatrix2D operator/(const INDEX tMul) const;
  INDEXmatrix2D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX2D& v);

  // get main vectors of matrix
  INDEX2D GetRow(INDEX iRow) const;
  INDEX2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEXmatrix2D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEXmatrix2D& matrix);

  inline INDEXmatrix2D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix2D_* () { return C_Handle(); }
  inline operator const INDEXmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix3D
{
public:
  explicit INDEXmatrix3D(INDEXmatrix3D_* p, bool owner = false);
  INDEXmatrix3D();
  explicit INDEXmatrix3D(INDEX x);
  INDEXmatrix3D(const INDEXmatrix3D& o);
  ~INDEXmatrix3D();

  INDEXmatrix3D& operator=(const INDEXmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  INDEXmatrix3D operator!() const;
  INDEXmatrix3D& operator!=(const INDEXmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  INDEXmatrix3D operator+(const INDEXmatrix3D& matrix2) const;
  INDEXmatrix3D& operator+=(const INDEXmatrix3D& matrix2);
  INDEXmatrix3D operator-(const INDEXmatrix3D& matrix2) const;
  INDEXmatrix3D& operator-=(const INDEXmatrix3D& matrix2);
  INDEXmatrix3D operator*(const INDEXmatrix3D& matrix2) const;
  INDEXmatrix3D& operator*=(const INDEXmatrix3D& matrix2);
  // matrices and scalars
  INDEXmatrix3D operator*(const INDEX tMul) const;
  INDEXmatrix3D& operator*=(const INDEX tMul);
  INDEXmatrix3D operator/(const INDEX tMul) const;
  INDEXmatrix3D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX3D& v);

  // get main vectors of matrix
  INDEX3D GetRow(INDEX iRow) const;
  INDEX3D GetColumn(INDEX iColumn) const;

  INDEX Determinant() const;
  INDEXmatrix3D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEXmatrix3D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEXmatrix3D& matrix);

  inline INDEXmatrix3D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix3D_* () { return C_Handle(); }
  inline operator const INDEXmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix4D
{
public:
  explicit INDEXmatrix4D(INDEXmatrix4D_* p, bool owner = false);
  INDEXmatrix4D();
  explicit INDEXmatrix4D(INDEX x);
  INDEXmatrix4D(const INDEXmatrix4D& o);
  ~INDEXmatrix4D();

  INDEXmatrix4D& operator=(const INDEXmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  INDEXmatrix4D operator!() const;
  INDEXmatrix4D& operator!=(const INDEXmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  INDEXmatrix4D operator+(const INDEXmatrix4D& matrix2) const;
  INDEXmatrix4D& operator+=(const INDEXmatrix4D& matrix2);
  INDEXmatrix4D operator-(const INDEXmatrix4D& matrix2) const;
  INDEXmatrix4D& operator-=(const INDEXmatrix4D& matrix2);
  INDEXmatrix4D operator*(const INDEXmatrix4D& matrix2) const;
  INDEXmatrix4D& operator*=(const INDEXmatrix4D& matrix2);
  // matrices and scalars
  INDEXmatrix4D operator*(const INDEX tMul) const;
  INDEXmatrix4D& operator*=(const INDEX tMul);
  INDEXmatrix4D operator/(const INDEX tMul) const;
  INDEXmatrix4D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX4D& v);

  // get main vectors of matrix
  INDEX4D GetRow(INDEX iRow) const;
  INDEX4D GetColumn(INDEX iColumn) const;

  INDEXmatrix4D InverseMatrix() const;

  /* Stream operations */
  SECPPAPI friend CTStream& operator>>(CTStream& strm, INDEXmatrix4D& matrix);
  SECPPAPI friend CTStream& operator<<(CTStream& strm, INDEXmatrix4D& matrix);

  inline INDEXmatrix4D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix4D_* () { return C_Handle(); }
  inline operator const INDEXmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix4D_* mp_matrix = nullptr;
};

// helper functions for converting between FLOAT and DOUBLE vectors
SECPPAPI DOUBLEmatrix3D FLOATtoDOUBLE(const FLOATmatrix3D& vf);
SECPPAPI FLOATmatrix3D DOUBLEtoFLOAT(const DOUBLEmatrix3D& vd);
