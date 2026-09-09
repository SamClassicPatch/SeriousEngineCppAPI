/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#pragma once
#include "../Base/Types.h"
#include "VectorDecl.h"
#include <SeriousEngineCAPI/Math/Matrix.h>

class FLOATmatrix2D
{
public:
  FLOATmatrix2D(FLOATmatrix2D_* p, bool owner = false);
  FLOATmatrix2D();
  explicit FLOATmatrix2D(FLOAT x);
  FLOATmatrix2D(const FLOATmatrix2D& o);
  ~FLOATmatrix2D();

  FLOATmatrix2D& operator=(const FLOATmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline FLOATmatrix2D operator!() const { return FLOATmatrix2D(FLOATmatrix2D_Transposed(mp_matrix), true); }
  FLOATmatrix2D& operator!=(const FLOATmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline FLOATmatrix2D operator+(const FLOATmatrix2D& matrix2) const { return FLOATmatrix2D(FLOATmatrix2D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix2D& operator+=(const FLOATmatrix2D& matrix2);
  __forceinline FLOATmatrix2D operator-(const FLOATmatrix2D& matrix2) const { return FLOATmatrix2D(FLOATmatrix2D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix2D& operator-=(const FLOATmatrix2D& matrix2);
  __forceinline FLOATmatrix2D operator*(const FLOATmatrix2D& matrix2) const { return FLOATmatrix2D(FLOATmatrix2D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix2D& operator*=(const FLOATmatrix2D& matrix2);
  // matrices and scalars
  __forceinline FLOATmatrix2D operator*(const FLOAT tMul) const { return FLOATmatrix2D(FLOATmatrix2D_Multiply_scalar(mp_matrix, tMul), true); }
  FLOATmatrix2D& operator*=(const FLOAT tMul);
  __forceinline FLOATmatrix2D operator/(const FLOAT tMul) const { return FLOATmatrix2D(FLOATmatrix2D_Divide_scalar(mp_matrix, tMul), true); }
  FLOATmatrix2D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT2D& v);

  // get main vectors of matrix
  FLOAT2D GetRow(INDEX iRow) const;
  FLOAT2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOATmatrix2D& matrix);
  friend CTStream& operator<<(CTStream& strm, FLOATmatrix2D& matrix);

  inline FLOATmatrix2D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix2D_* () { return C_Handle(); }
  inline operator const FLOATmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix2D_* mp_matrix = nullptr;
};

class FLOATmatrix3D
{
public:
  FLOATmatrix3D(FLOATmatrix3D_* p, bool owner = false);
  FLOATmatrix3D();
  explicit FLOATmatrix3D(FLOAT x);
  FLOATmatrix3D(const FLOATmatrix3D& o);
  ~FLOATmatrix3D();

  FLOATmatrix3D& operator=(const FLOATmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline FLOATmatrix3D operator!() const { return FLOATmatrix3D(FLOATmatrix3D_Transposed(mp_matrix), true); }
  FLOATmatrix3D& operator!=(const FLOATmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline FLOATmatrix3D operator+(const FLOATmatrix3D& matrix2) const { return FLOATmatrix3D(FLOATmatrix3D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix3D& operator+=(const FLOATmatrix3D& matrix2);
  __forceinline FLOATmatrix3D operator-(const FLOATmatrix3D& matrix2) const { return FLOATmatrix3D(FLOATmatrix3D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix3D& operator-=(const FLOATmatrix3D& matrix2);
  __forceinline FLOATmatrix3D operator*(const FLOATmatrix3D& matrix2) const { return FLOATmatrix3D(FLOATmatrix3D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix3D& operator*=(const FLOATmatrix3D& matrix2);
  // matrices and scalars
  __forceinline FLOATmatrix3D operator*(const FLOAT tMul) const { return FLOATmatrix3D(FLOATmatrix3D_Multiply_scalar(mp_matrix, tMul), true); }
  FLOATmatrix3D& operator*=(const FLOAT tMul);
  __forceinline FLOATmatrix3D operator/(const FLOAT tMul) const { return FLOATmatrix3D(FLOATmatrix3D_Divide_scalar(mp_matrix, tMul), true); }
  FLOATmatrix3D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT3D& v);

  // get main vectors of matrix
  FLOAT3D GetRow(INDEX iRow) const;
  FLOAT3D GetColumn(INDEX iColumn) const;

  FLOAT Determinant() const;
  __forceinline FLOATmatrix3D InverseMatrix() const { return FLOATmatrix3D(FLOATmatrix3D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOATmatrix3D& matrix);
  friend CTStream& operator<<(CTStream& strm, FLOATmatrix3D& matrix);

  inline FLOATmatrix3D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix3D_* () { return C_Handle(); }
  inline operator const FLOATmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix3D_* mp_matrix = nullptr;
};

class FLOATmatrix4D
{
public:
  FLOATmatrix4D(FLOATmatrix4D_* p, bool owner = false);
  FLOATmatrix4D();
  explicit FLOATmatrix4D(FLOAT x);
  FLOATmatrix4D(const FLOATmatrix4D& o);
  ~FLOATmatrix4D();

  FLOATmatrix4D& operator=(const FLOATmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  FLOAT& operator()(INDEX iRow, INDEX iColumn);
  FLOAT operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline FLOATmatrix4D operator!() const { return FLOATmatrix4D(FLOATmatrix4D_Transposed(mp_matrix), true); }
  FLOATmatrix4D& operator!=(const FLOATmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline FLOATmatrix4D operator+(const FLOATmatrix4D& matrix2) const { return FLOATmatrix4D(FLOATmatrix4D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix4D& operator+=(const FLOATmatrix4D& matrix2);
  __forceinline FLOATmatrix4D operator-(const FLOATmatrix4D& matrix2) const { return FLOATmatrix4D(FLOATmatrix4D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix4D& operator-=(const FLOATmatrix4D& matrix2);
  __forceinline FLOATmatrix4D operator*(const FLOATmatrix4D& matrix2) const { return FLOATmatrix4D(FLOATmatrix4D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  FLOATmatrix4D& operator*=(const FLOATmatrix4D& matrix2);
  // matrices and scalars
  __forceinline FLOATmatrix4D operator*(const FLOAT tMul) const { return FLOATmatrix4D(FLOATmatrix4D_Multiply_scalar(mp_matrix, tMul), true); }
  FLOATmatrix4D& operator*=(const FLOAT tMul);
  __forceinline FLOATmatrix4D operator/(const FLOAT tMul) const { return FLOATmatrix4D(FLOATmatrix4D_Divide_scalar(mp_matrix, tMul), true); }
  FLOATmatrix4D& operator/=(const FLOAT tMul);

  /* Set matrix main diagonal. */
  void Diagonal(FLOAT x);
  void Diagonal(const FLOAT4D& v);

  // get main vectors of matrix
  FLOAT4D GetRow(INDEX iRow) const;
  FLOAT4D GetColumn(INDEX iColumn) const;

  __forceinline FLOATmatrix4D InverseMatrix() const { return FLOATmatrix4D(FLOATmatrix4D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, FLOATmatrix4D& matrix);
  friend CTStream& operator<<(CTStream& strm, FLOATmatrix4D& matrix);

  inline FLOATmatrix4D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator FLOATmatrix4D_* () { return C_Handle(); }
  inline operator const FLOATmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  FLOATmatrix4D_* mp_matrix = nullptr;
};

class DOUBLEmatrix2D
{
public:
  DOUBLEmatrix2D(DOUBLEmatrix2D_* p, bool owner = false);
  DOUBLEmatrix2D();
  explicit DOUBLEmatrix2D(DOUBLE x);
  DOUBLEmatrix2D(const DOUBLEmatrix2D& o);
  ~DOUBLEmatrix2D();

  DOUBLEmatrix2D& operator=(const DOUBLEmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline DOUBLEmatrix2D operator!() const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Transposed(mp_matrix), true); }
  DOUBLEmatrix2D& operator!=(const DOUBLEmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline DOUBLEmatrix2D operator+(const DOUBLEmatrix2D& matrix2) const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix2D& operator+=(const DOUBLEmatrix2D& matrix2);
  __forceinline DOUBLEmatrix2D operator-(const DOUBLEmatrix2D& matrix2) const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix2D& operator-=(const DOUBLEmatrix2D& matrix2);
  __forceinline DOUBLEmatrix2D operator*(const DOUBLEmatrix2D& matrix2) const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix2D& operator*=(const DOUBLEmatrix2D& matrix2);
  // matrices and scalars
  __forceinline DOUBLEmatrix2D operator*(const DOUBLE tMul) const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Multiply_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix2D& operator*=(const DOUBLE tMul);
  __forceinline DOUBLEmatrix2D operator/(const DOUBLE tMul) const { return DOUBLEmatrix2D(DOUBLEmatrix2D_Divide_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix2D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE2D& v);

  // get main vectors of matrix
  DOUBLE2D GetRow(INDEX iRow) const;
  DOUBLE2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix2D& matrix);
  friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix2D& matrix);

  inline DOUBLEmatrix2D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix2D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix2D_* mp_matrix = nullptr;
};

class DOUBLEmatrix3D
{
public:
  DOUBLEmatrix3D(DOUBLEmatrix3D_* p, bool owner = false);
  DOUBLEmatrix3D();
  explicit DOUBLEmatrix3D(DOUBLE x);
  DOUBLEmatrix3D(const DOUBLEmatrix3D& o);
  ~DOUBLEmatrix3D();

  DOUBLEmatrix3D& operator=(const DOUBLEmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline DOUBLEmatrix3D operator!() const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Transposed(mp_matrix), true); }
  DOUBLEmatrix3D& operator!=(const DOUBLEmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline DOUBLEmatrix3D operator+(const DOUBLEmatrix3D& matrix2) const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix3D& operator+=(const DOUBLEmatrix3D& matrix2);
  __forceinline DOUBLEmatrix3D operator-(const DOUBLEmatrix3D& matrix2) const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix3D& operator-=(const DOUBLEmatrix3D& matrix2);
  __forceinline DOUBLEmatrix3D operator*(const DOUBLEmatrix3D& matrix2) const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix3D& operator*=(const DOUBLEmatrix3D& matrix2);
  // matrices and scalars
  __forceinline DOUBLEmatrix3D operator*(const DOUBLE tMul) const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Multiply_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix3D& operator*=(const DOUBLE tMul);
  __forceinline DOUBLEmatrix3D operator/(const DOUBLE tMul) const { return DOUBLEmatrix3D(DOUBLEmatrix3D_Divide_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix3D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE3D& v);

  // get main vectors of matrix
  DOUBLE3D GetRow(INDEX iRow) const;
  DOUBLE3D GetColumn(INDEX iColumn) const;

  DOUBLE Determinant() const;
  __forceinline DOUBLEmatrix3D InverseMatrix() const { return DOUBLEmatrix3D(DOUBLEmatrix3D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix3D& matrix);
  friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix3D& matrix);

  inline DOUBLEmatrix3D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix3D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix3D_* mp_matrix = nullptr;
};

class DOUBLEmatrix4D
{
public:
  DOUBLEmatrix4D(DOUBLEmatrix4D_* p, bool owner = false);
  DOUBLEmatrix4D();
  explicit DOUBLEmatrix4D(DOUBLE x);
  DOUBLEmatrix4D(const DOUBLEmatrix4D& o);
  ~DOUBLEmatrix4D();

  DOUBLEmatrix4D& operator=(const DOUBLEmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  DOUBLE& operator()(INDEX iRow, INDEX iColumn);
  DOUBLE operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline DOUBLEmatrix4D operator!() const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Transposed(mp_matrix), true); }
  DOUBLEmatrix4D& operator!=(const DOUBLEmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline DOUBLEmatrix4D operator+(const DOUBLEmatrix4D& matrix2) const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix4D& operator+=(const DOUBLEmatrix4D& matrix2);
  __forceinline DOUBLEmatrix4D operator-(const DOUBLEmatrix4D& matrix2) const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix4D& operator-=(const DOUBLEmatrix4D& matrix2);
  __forceinline DOUBLEmatrix4D operator*(const DOUBLEmatrix4D& matrix2) const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  DOUBLEmatrix4D& operator*=(const DOUBLEmatrix4D& matrix2);
  // matrices and scalars
  __forceinline DOUBLEmatrix4D operator*(const DOUBLE tMul) const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Multiply_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix4D& operator*=(const DOUBLE tMul);
  __forceinline DOUBLEmatrix4D operator/(const DOUBLE tMul) const { return DOUBLEmatrix4D(DOUBLEmatrix4D_Divide_scalar(mp_matrix, tMul), true); }
  DOUBLEmatrix4D& operator/=(const DOUBLE tMul);

  /* Set matrix main diagonal. */
  void Diagonal(DOUBLE x);
  void Diagonal(const DOUBLE4D& v);

  // get main vectors of matrix
  DOUBLE4D GetRow(INDEX iRow) const;
  DOUBLE4D GetColumn(INDEX iColumn) const;

  __forceinline DOUBLEmatrix4D InverseMatrix() const { return DOUBLEmatrix4D(DOUBLEmatrix4D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, DOUBLEmatrix4D& matrix);
  friend CTStream& operator<<(CTStream& strm, DOUBLEmatrix4D& matrix);

  inline DOUBLEmatrix4D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator DOUBLEmatrix4D_* () { return C_Handle(); }
  inline operator const DOUBLEmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  DOUBLEmatrix4D_* mp_matrix = nullptr;
};

class INDEXmatrix2D
{
public:
  INDEXmatrix2D(INDEXmatrix2D_* p, bool owner = false);
  INDEXmatrix2D();
  explicit INDEXmatrix2D(INDEX x);
  INDEXmatrix2D(const INDEXmatrix2D& o);
  ~INDEXmatrix2D();

  INDEXmatrix2D& operator=(const INDEXmatrix2D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline INDEXmatrix2D operator!() const { return INDEXmatrix2D(INDEXmatrix2D_Transposed(mp_matrix), true); }
  INDEXmatrix2D& operator!=(const INDEXmatrix2D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline INDEXmatrix2D operator+(const INDEXmatrix2D& matrix2) const { return INDEXmatrix2D(INDEXmatrix2D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix2D& operator+=(const INDEXmatrix2D& matrix2);
  __forceinline INDEXmatrix2D operator-(const INDEXmatrix2D& matrix2) const { return INDEXmatrix2D(INDEXmatrix2D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix2D& operator-=(const INDEXmatrix2D& matrix2);
  __forceinline INDEXmatrix2D operator*(const INDEXmatrix2D& matrix2) const { return INDEXmatrix2D(INDEXmatrix2D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix2D& operator*=(const INDEXmatrix2D& matrix2);
  // matrices and scalars
  __forceinline INDEXmatrix2D operator*(const INDEX tMul) const { return INDEXmatrix2D(INDEXmatrix2D_Multiply_scalar(mp_matrix, tMul), true); }
  INDEXmatrix2D& operator*=(const INDEX tMul);
  __forceinline INDEXmatrix2D operator/(const INDEX tMul) const { return INDEXmatrix2D(INDEXmatrix2D_Divide_scalar(mp_matrix, tMul), true); }
  INDEXmatrix2D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX2D& v);

  // get main vectors of matrix
  INDEX2D GetRow(INDEX iRow) const;
  INDEX2D GetColumn(INDEX iColumn) const;

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEXmatrix2D& matrix);
  friend CTStream& operator<<(CTStream& strm, INDEXmatrix2D& matrix);

  inline INDEXmatrix2D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix2D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix2D_* () { return C_Handle(); }
  inline operator const INDEXmatrix2D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix2D_* mp_matrix = nullptr;
};

class INDEXmatrix3D
{
public:
  INDEXmatrix3D(INDEXmatrix3D_* p, bool owner = false);
  INDEXmatrix3D();
  explicit INDEXmatrix3D(INDEX x);
  INDEXmatrix3D(const INDEXmatrix3D& o);
  ~INDEXmatrix3D();

  INDEXmatrix3D& operator=(const INDEXmatrix3D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline INDEXmatrix3D operator!() const { return INDEXmatrix3D(INDEXmatrix3D_Transposed(mp_matrix), true); }
  INDEXmatrix3D& operator!=(const INDEXmatrix3D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline INDEXmatrix3D operator+(const INDEXmatrix3D& matrix2) const { return INDEXmatrix3D(INDEXmatrix3D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix3D& operator+=(const INDEXmatrix3D& matrix2);
  __forceinline INDEXmatrix3D operator-(const INDEXmatrix3D& matrix2) const { return INDEXmatrix3D(INDEXmatrix3D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix3D& operator-=(const INDEXmatrix3D& matrix2);
  __forceinline INDEXmatrix3D operator*(const INDEXmatrix3D& matrix2) const { return INDEXmatrix3D(INDEXmatrix3D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix3D& operator*=(const INDEXmatrix3D& matrix2);
  // matrices and scalars
  __forceinline INDEXmatrix3D operator*(const INDEX tMul) const { return INDEXmatrix3D(INDEXmatrix3D_Multiply_scalar(mp_matrix, tMul), true); }
  INDEXmatrix3D& operator*=(const INDEX tMul);
  __forceinline INDEXmatrix3D operator/(const INDEX tMul) const { return INDEXmatrix3D(INDEXmatrix3D_Divide_scalar(mp_matrix, tMul), true); }
  INDEXmatrix3D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX3D& v);

  // get main vectors of matrix
  INDEX3D GetRow(INDEX iRow) const;
  INDEX3D GetColumn(INDEX iColumn) const;

  INDEX Determinant() const;
  __forceinline INDEXmatrix3D InverseMatrix() const { return INDEXmatrix3D(INDEXmatrix3D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEXmatrix3D& matrix);
  friend CTStream& operator<<(CTStream& strm, INDEXmatrix3D& matrix);

  inline INDEXmatrix3D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix3D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix3D_* () { return C_Handle(); }
  inline operator const INDEXmatrix3D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix3D_* mp_matrix = nullptr;
};

class INDEXmatrix4D
{
public:
  INDEXmatrix4D(INDEXmatrix4D_* p, bool owner = false);
  INDEXmatrix4D();
  explicit INDEXmatrix4D(INDEX x);
  INDEXmatrix4D(const INDEXmatrix4D& o);
  ~INDEXmatrix4D();

  INDEXmatrix4D& operator=(const INDEXmatrix4D& o);

  /* Reference matrix member by it's row and column indices (1-based indices!). */
  INDEX& operator()(INDEX iRow, INDEX iColumn);
  INDEX operator()(INDEX iRow, INDEX iColumn) const;

  /* Make a transposed matrix. */
  __forceinline INDEXmatrix4D operator!() const { return INDEXmatrix4D(INDEXmatrix4D_Transposed(mp_matrix), true); }
  INDEXmatrix4D& operator!=(const INDEXmatrix4D& matrix2);

  /* Mathematical operators. */
  // between matrices
  __forceinline INDEXmatrix4D operator+(const INDEXmatrix4D& matrix2) const { return INDEXmatrix4D(INDEXmatrix4D_Plus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix4D& operator+=(const INDEXmatrix4D& matrix2);
  __forceinline INDEXmatrix4D operator-(const INDEXmatrix4D& matrix2) const { return INDEXmatrix4D(INDEXmatrix4D_Minus(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix4D& operator-=(const INDEXmatrix4D& matrix2);
  __forceinline INDEXmatrix4D operator*(const INDEXmatrix4D& matrix2) const { return INDEXmatrix4D(INDEXmatrix4D_Multiply(mp_matrix, matrix2.mp_matrix), true); }
  INDEXmatrix4D& operator*=(const INDEXmatrix4D& matrix2);
  // matrices and scalars
  __forceinline INDEXmatrix4D operator*(const INDEX tMul) const { return INDEXmatrix4D(INDEXmatrix4D_Multiply_scalar(mp_matrix, tMul), true); }
  INDEXmatrix4D& operator*=(const INDEX tMul);
  __forceinline INDEXmatrix4D operator/(const INDEX tMul) const { return INDEXmatrix4D(INDEXmatrix4D_Divide_scalar(mp_matrix, tMul), true); }
  INDEXmatrix4D& operator/=(const INDEX tMul);

  /* Set matrix main diagonal. */
  void Diagonal(INDEX x);
  void Diagonal(const INDEX4D& v);

  // get main vectors of matrix
  INDEX4D GetRow(INDEX iRow) const;
  INDEX4D GetColumn(INDEX iColumn) const;

  __forceinline INDEXmatrix4D InverseMatrix() const { return INDEXmatrix4D(INDEXmatrix4D_InverseMatrix(mp_matrix), true); }

  /* Stream operations */
  friend CTStream& operator>>(CTStream& strm, INDEXmatrix4D& matrix);
  friend CTStream& operator<<(CTStream& strm, INDEXmatrix4D& matrix);

  inline INDEXmatrix4D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix4D_* C_Handle() const { return mp_matrix; }
  inline operator INDEXmatrix4D_* () { return C_Handle(); }
  inline operator const INDEXmatrix4D_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  INDEXmatrix4D_* mp_matrix = nullptr;
};

// helper functions for converting between FLOAT and DOUBLE vectors
__forceinline DOUBLEmatrix3D FLOATtoDOUBLE(const FLOATmatrix3D& vf) { return DOUBLEmatrix3D(FLOAT2DOUBLEmx(vf.C_Handle()), true); }
__forceinline FLOATmatrix3D DOUBLEtoFLOAT(const DOUBLEmatrix3D& vd) { return FLOATmatrix3D(DOUBLE2FLOATmx(vd.C_Handle()), true); }
