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
#include "../Base/Stream.h"

inline CTStream& operator>>(CTStream& strm, FLOATmatrix2D& matrix)
{
  FLOATmatrix2D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOATmatrix2D& matrix)
{
  FLOATmatrix2D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, FLOATmatrix3D& matrix)
{
  FLOATmatrix3D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOATmatrix3D& matrix)
{
  FLOATmatrix3D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, FLOATmatrix4D& matrix)
{
  FLOATmatrix4D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOATmatrix4D& matrix)
{
  FLOATmatrix4D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLEmatrix2D& matrix)
{
  DOUBLEmatrix2D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLEmatrix2D& matrix)
{
  DOUBLEmatrix2D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLEmatrix3D& matrix)
{
  DOUBLEmatrix3D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLEmatrix3D& matrix)
{
  DOUBLEmatrix3D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLEmatrix4D& matrix)
{
  DOUBLEmatrix4D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLEmatrix4D& matrix)
{
  DOUBLEmatrix4D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEXmatrix2D& matrix)
{
  INDEXmatrix2D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEXmatrix2D& matrix)
{
  INDEXmatrix2D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEXmatrix3D& matrix)
{
  INDEXmatrix3D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEXmatrix3D& matrix)
{
  INDEXmatrix3D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEXmatrix4D& matrix)
{
  INDEXmatrix4D_extract(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEXmatrix4D& matrix)
{
  INDEXmatrix4D_insert(strm.C_Handle(), matrix.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator=(const FLOATmatrix2D& o)
{
  FLOATmatrix2D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator=(const FLOATmatrix3D& o)
{
  FLOATmatrix3D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator=(const FLOATmatrix4D& o)
{
  FLOATmatrix4D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator=(const DOUBLEmatrix2D& o)
{
  DOUBLEmatrix2D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator=(const DOUBLEmatrix3D& o)
{
  DOUBLEmatrix3D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator=(const DOUBLEmatrix4D& o)
{
  DOUBLEmatrix4D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator=(const INDEXmatrix2D& o)
{
  INDEXmatrix2D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator=(const INDEXmatrix3D& o)
{
  INDEXmatrix3D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator=(const INDEXmatrix4D& o)
{
  INDEXmatrix4D_copy(mp_matrix, o.mp_matrix);
  return *this;
}

inline FLOATmatrix2D::FLOATmatrix2D(FLOATmatrix2D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline FLOATmatrix2D::FLOATmatrix2D()
  : m_owner(true)
  , mp_matrix(FLOATmatrix2D_new())
{
}

inline FLOATmatrix2D::FLOATmatrix2D(FLOAT x)
  : m_owner(true)
  , mp_matrix(FLOATmatrix2D_new_x(x))
{
}

inline FLOATmatrix2D::FLOATmatrix2D(const FLOATmatrix2D& o)
  : m_owner(true)
  , mp_matrix(FLOATmatrix2D_clone(o.mp_matrix))
{
}

inline FLOATmatrix2D::~FLOATmatrix2D()
{
  if (m_owner)
    FLOATmatrix2D_delete(mp_matrix);
}

inline FLOAT& FLOATmatrix2D::operator()(INDEX iRow, INDEX iColumn)
{
  return *FLOATmatrix2D_Element(mp_matrix, iRow, iColumn);
}

inline FLOAT FLOATmatrix2D::operator()(INDEX iRow, INDEX iColumn) const
{
  return FLOATmatrix2D_Element_const(mp_matrix, iRow, iColumn);
}

inline FLOATmatrix2D& FLOATmatrix2D::operator!=(const FLOATmatrix2D& matrix2)
{
  FLOATmatrix2D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator+=(const FLOATmatrix2D& matrix2)
{
  FLOATmatrix2D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator-=(const FLOATmatrix2D& matrix2)
{
  FLOATmatrix2D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator*=(const FLOATmatrix2D& matrix2)
{
  FLOATmatrix2D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator*=(const FLOAT tMul)
{
  FLOATmatrix2D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline FLOATmatrix2D& FLOATmatrix2D::operator/=(const FLOAT tMul)
{
  FLOATmatrix2D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void FLOATmatrix2D::Diagonal(FLOAT x)
{
  FLOATmatrix2D_Diagonal_scalar(mp_matrix, x);
}

inline void FLOATmatrix2D::Diagonal(const FLOAT2D& v)
{
  FLOATmatrix2D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline FLOAT2D FLOATmatrix2D::GetRow(INDEX iRow) const
{
  return FLOAT2D(FLOATmatrix2D_GetRow(mp_matrix, iRow), true);
}

__forceinline FLOAT2D FLOATmatrix2D::GetColumn(INDEX iColumn) const
{
  return FLOAT2D(FLOATmatrix2D_GetColumn(mp_matrix, iColumn), true);
}

inline FLOATmatrix3D::FLOATmatrix3D(FLOATmatrix3D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline FLOATmatrix3D::FLOATmatrix3D()
  : m_owner(true)
  , mp_matrix(FLOATmatrix3D_new())
{
}

inline FLOATmatrix3D::FLOATmatrix3D(FLOAT x)
  : m_owner(true)
  , mp_matrix(FLOATmatrix3D_new_x(x))
{
}

inline FLOATmatrix3D::FLOATmatrix3D(const FLOATmatrix3D& o)
  : m_owner(true)
  , mp_matrix(FLOATmatrix3D_clone(o.mp_matrix))
{
}

inline FLOATmatrix3D::~FLOATmatrix3D()
{
  if (m_owner)
    FLOATmatrix3D_delete(mp_matrix);
}

inline FLOAT& FLOATmatrix3D::operator()(INDEX iRow, INDEX iColumn)
{
  return *FLOATmatrix3D_Element(mp_matrix, iRow, iColumn);
}

inline FLOAT FLOATmatrix3D::operator()(INDEX iRow, INDEX iColumn) const
{
  return FLOATmatrix3D_Element_const(mp_matrix, iRow, iColumn);
}

inline FLOATmatrix3D& FLOATmatrix3D::operator!=(const FLOATmatrix3D& matrix2)
{
  FLOATmatrix3D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator+=(const FLOATmatrix3D& matrix2)
{
  FLOATmatrix3D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator-=(const FLOATmatrix3D& matrix2)
{
  FLOATmatrix3D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator*=(const FLOATmatrix3D& matrix2)
{
  FLOATmatrix3D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator*=(const FLOAT tMul)
{
  FLOATmatrix3D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline FLOATmatrix3D& FLOATmatrix3D::operator/=(const FLOAT tMul)
{
  FLOATmatrix3D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void FLOATmatrix3D::Diagonal(FLOAT x)
{
  FLOATmatrix3D_Diagonal_scalar(mp_matrix, x);
}

inline void FLOATmatrix3D::Diagonal(const FLOAT3D& v)
{
  FLOATmatrix3D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline FLOAT3D FLOATmatrix3D::GetRow(INDEX iRow) const
{
  return FLOAT3D(FLOATmatrix3D_GetRow(mp_matrix, iRow), true);
}

__forceinline FLOAT3D FLOATmatrix3D::GetColumn(INDEX iColumn) const
{
  return FLOAT3D(FLOATmatrix3D_GetColumn(mp_matrix, iColumn), true);
}

inline FLOAT FLOATmatrix3D::Determinant() const
{
  return FLOATmatrix3D_Determinant(mp_matrix);
}

inline FLOATmatrix4D::FLOATmatrix4D(FLOATmatrix4D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline FLOATmatrix4D::FLOATmatrix4D()
  : m_owner(true)
  , mp_matrix(FLOATmatrix4D_new())
{
}

inline FLOATmatrix4D::FLOATmatrix4D(FLOAT x)
  : m_owner(true)
  , mp_matrix(FLOATmatrix4D_new_x(x))
{
}

inline FLOATmatrix4D::FLOATmatrix4D(const FLOATmatrix4D& o)
  : m_owner(true)
  , mp_matrix(FLOATmatrix4D_clone(o.mp_matrix))
{
}

inline FLOATmatrix4D::~FLOATmatrix4D()
{
  if (m_owner)
    FLOATmatrix4D_delete(mp_matrix);
}

inline FLOAT& FLOATmatrix4D::operator()(INDEX iRow, INDEX iColumn)
{
  return *FLOATmatrix4D_Element(mp_matrix, iRow, iColumn);
}

inline FLOAT FLOATmatrix4D::operator()(INDEX iRow, INDEX iColumn) const
{
  return FLOATmatrix4D_Element_const(mp_matrix, iRow, iColumn);
}

inline FLOATmatrix4D& FLOATmatrix4D::operator!=(const FLOATmatrix4D& matrix2)
{
  FLOATmatrix4D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator+=(const FLOATmatrix4D& matrix2)
{
  FLOATmatrix4D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator-=(const FLOATmatrix4D& matrix2)
{
  FLOATmatrix4D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator*=(const FLOATmatrix4D& matrix2)
{
  FLOATmatrix4D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator*=(const FLOAT tMul)
{
  FLOATmatrix4D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline FLOATmatrix4D& FLOATmatrix4D::operator/=(const FLOAT tMul)
{
  FLOATmatrix4D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void FLOATmatrix4D::Diagonal(FLOAT x)
{
  FLOATmatrix4D_Diagonal_scalar(mp_matrix, x);
}

inline void FLOATmatrix4D::Diagonal(const FLOAT4D& v)
{
  FLOATmatrix4D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline FLOAT4D FLOATmatrix4D::GetRow(INDEX iRow) const
{
  return FLOAT4D(FLOATmatrix4D_GetRow(mp_matrix, iRow), true);
}

__forceinline FLOAT4D FLOATmatrix4D::GetColumn(INDEX iColumn) const
{
  return FLOAT4D(FLOATmatrix4D_GetColumn(mp_matrix, iColumn), true);
}

inline DOUBLEmatrix2D::DOUBLEmatrix2D(DOUBLEmatrix2D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline DOUBLEmatrix2D::DOUBLEmatrix2D()
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix2D_new())
{
}

inline DOUBLEmatrix2D::DOUBLEmatrix2D(DOUBLE x)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix2D_new_x(x))
{
}

inline DOUBLEmatrix2D::DOUBLEmatrix2D(const DOUBLEmatrix2D& o)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix2D_clone(o.mp_matrix))
{
}

inline DOUBLEmatrix2D::~DOUBLEmatrix2D()
{
  if (m_owner)
    DOUBLEmatrix2D_delete(mp_matrix);
}

inline DOUBLE& DOUBLEmatrix2D::operator()(INDEX iRow, INDEX iColumn)
{
  return *DOUBLEmatrix2D_Element(mp_matrix, iRow, iColumn);
}

inline DOUBLE DOUBLEmatrix2D::operator()(INDEX iRow, INDEX iColumn) const
{
  return DOUBLEmatrix2D_Element_const(mp_matrix, iRow, iColumn);
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator!=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLEmatrix2D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator+=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLEmatrix2D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator-=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLEmatrix2D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator*=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLEmatrix2D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator*=(const DOUBLE tMul)
{
  DOUBLEmatrix2D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline DOUBLEmatrix2D& DOUBLEmatrix2D::operator/=(const DOUBLE tMul)
{
  DOUBLEmatrix2D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void DOUBLEmatrix2D::Diagonal(DOUBLE x)
{
  DOUBLEmatrix2D_Diagonal_scalar(mp_matrix, x);
}

inline void DOUBLEmatrix2D::Diagonal(const DOUBLE2D& v)
{
  DOUBLEmatrix2D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline DOUBLE2D DOUBLEmatrix2D::GetRow(INDEX iRow) const
{
  return DOUBLE2D(DOUBLEmatrix2D_GetRow(mp_matrix, iRow), true);
}

__forceinline DOUBLE2D DOUBLEmatrix2D::GetColumn(INDEX iColumn) const
{
  return DOUBLE2D(DOUBLEmatrix2D_GetColumn(mp_matrix, iColumn), true);
}

inline DOUBLEmatrix3D::DOUBLEmatrix3D(DOUBLEmatrix3D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline DOUBLEmatrix3D::DOUBLEmatrix3D()
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix3D_new())
{
}

inline DOUBLEmatrix3D::DOUBLEmatrix3D(DOUBLE x)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix3D_new_x(x))
{
}

inline DOUBLEmatrix3D::DOUBLEmatrix3D(const DOUBLEmatrix3D& o)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix3D_clone(o.mp_matrix))
{
}

inline DOUBLEmatrix3D::~DOUBLEmatrix3D()
{
  if (m_owner)
    DOUBLEmatrix3D_delete(mp_matrix);
}

inline DOUBLE& DOUBLEmatrix3D::operator()(INDEX iRow, INDEX iColumn)
{
  return *DOUBLEmatrix3D_Element(mp_matrix, iRow, iColumn);
}

inline DOUBLE DOUBLEmatrix3D::operator()(INDEX iRow, INDEX iColumn) const
{
  return DOUBLEmatrix3D_Element_const(mp_matrix, iRow, iColumn);
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator!=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLEmatrix3D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator+=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLEmatrix3D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator-=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLEmatrix3D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator*=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLEmatrix3D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator*=(const DOUBLE tMul)
{
  DOUBLEmatrix3D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline DOUBLEmatrix3D& DOUBLEmatrix3D::operator/=(const DOUBLE tMul)
{
  DOUBLEmatrix3D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void DOUBLEmatrix3D::Diagonal(DOUBLE x)
{
  DOUBLEmatrix3D_Diagonal_scalar(mp_matrix, x);
}

inline void DOUBLEmatrix3D::Diagonal(const DOUBLE3D& v)
{
  DOUBLEmatrix3D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline DOUBLE3D DOUBLEmatrix3D::GetRow(INDEX iRow) const
{
  return DOUBLE3D(DOUBLEmatrix3D_GetRow(mp_matrix, iRow), true);
}

__forceinline DOUBLE3D DOUBLEmatrix3D::GetColumn(INDEX iColumn) const
{
  return DOUBLE3D(DOUBLEmatrix3D_GetColumn(mp_matrix, iColumn), true);
}

inline DOUBLE DOUBLEmatrix3D::Determinant() const
{
  return DOUBLEmatrix3D_Determinant(mp_matrix);
}

inline DOUBLEmatrix4D::DOUBLEmatrix4D(DOUBLEmatrix4D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline DOUBLEmatrix4D::DOUBLEmatrix4D()
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix4D_new())
{
}

inline DOUBLEmatrix4D::DOUBLEmatrix4D(DOUBLE x)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix4D_new_x(x))
{
}

inline DOUBLEmatrix4D::DOUBLEmatrix4D(const DOUBLEmatrix4D& o)
  : m_owner(true)
  , mp_matrix(DOUBLEmatrix4D_clone(o.mp_matrix))
{
}

inline DOUBLEmatrix4D::~DOUBLEmatrix4D()
{
  if (m_owner)
    DOUBLEmatrix4D_delete(mp_matrix);
}

inline DOUBLE& DOUBLEmatrix4D::operator()(INDEX iRow, INDEX iColumn)
{
  return *DOUBLEmatrix4D_Element(mp_matrix, iRow, iColumn);
}

inline DOUBLE DOUBLEmatrix4D::operator()(INDEX iRow, INDEX iColumn) const
{
  return DOUBLEmatrix4D_Element_const(mp_matrix, iRow, iColumn);
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator!=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLEmatrix4D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator+=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLEmatrix4D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator-=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLEmatrix4D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator*=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLEmatrix4D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator*=(const DOUBLE tMul)
{
  DOUBLEmatrix4D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline DOUBLEmatrix4D& DOUBLEmatrix4D::operator/=(const DOUBLE tMul)
{
  DOUBLEmatrix4D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void DOUBLEmatrix4D::Diagonal(DOUBLE x)
{
  DOUBLEmatrix4D_Diagonal_scalar(mp_matrix, x);
}

inline void DOUBLEmatrix4D::Diagonal(const DOUBLE4D& v)
{
  DOUBLEmatrix4D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline DOUBLE4D DOUBLEmatrix4D::GetRow(INDEX iRow) const
{
  return DOUBLE4D(DOUBLEmatrix4D_GetRow(mp_matrix, iRow), true);
}

__forceinline DOUBLE4D DOUBLEmatrix4D::GetColumn(INDEX iColumn) const
{
  return DOUBLE4D(DOUBLEmatrix4D_GetColumn(mp_matrix, iColumn), true);
}

inline INDEXmatrix2D::INDEXmatrix2D(INDEXmatrix2D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline INDEXmatrix2D::INDEXmatrix2D()
  : m_owner(true)
  , mp_matrix(INDEXmatrix2D_new())
{
}

inline INDEXmatrix2D::INDEXmatrix2D(INDEX x)
  : m_owner(true)
  , mp_matrix(INDEXmatrix2D_new_x(x))
{
}

inline INDEXmatrix2D::INDEXmatrix2D(const INDEXmatrix2D& o)
  : m_owner(true)
  , mp_matrix(INDEXmatrix2D_clone(o.mp_matrix))
{
}

inline INDEXmatrix2D::~INDEXmatrix2D()
{
  if (m_owner)
    INDEXmatrix2D_delete(mp_matrix);
}

inline INDEX& INDEXmatrix2D::operator()(INDEX iRow, INDEX iColumn)
{
  return *INDEXmatrix2D_Element(mp_matrix, iRow, iColumn);
}

inline INDEX INDEXmatrix2D::operator()(INDEX iRow, INDEX iColumn) const
{
  return INDEXmatrix2D_Element_const(mp_matrix, iRow, iColumn);
}

inline INDEXmatrix2D& INDEXmatrix2D::operator!=(const INDEXmatrix2D& matrix2)
{
  INDEXmatrix2D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator+=(const INDEXmatrix2D& matrix2)
{
  INDEXmatrix2D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator-=(const INDEXmatrix2D& matrix2)
{
  INDEXmatrix2D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator*=(const INDEXmatrix2D& matrix2)
{
  INDEXmatrix2D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator*=(const INDEX tMul)
{
  INDEXmatrix2D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline INDEXmatrix2D& INDEXmatrix2D::operator/=(const INDEX tMul)
{
  INDEXmatrix2D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void INDEXmatrix2D::Diagonal(INDEX x)
{
  INDEXmatrix2D_Diagonal_scalar(mp_matrix, x);
}

inline void INDEXmatrix2D::Diagonal(const INDEX2D& v)
{
  INDEXmatrix2D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline INDEX2D INDEXmatrix2D::GetRow(INDEX iRow) const
{
  return INDEX2D(INDEXmatrix2D_GetRow(mp_matrix, iRow), true);
}

__forceinline INDEX2D INDEXmatrix2D::GetColumn(INDEX iColumn) const
{
  return INDEX2D(INDEXmatrix2D_GetColumn(mp_matrix, iColumn), true);
}

inline INDEXmatrix3D::INDEXmatrix3D(INDEXmatrix3D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline INDEXmatrix3D::INDEXmatrix3D()
  : m_owner(true)
  , mp_matrix(INDEXmatrix3D_new())
{
}

inline INDEXmatrix3D::INDEXmatrix3D(INDEX x)
  : m_owner(true)
  , mp_matrix(INDEXmatrix3D_new_x(x))
{
}

inline INDEXmatrix3D::INDEXmatrix3D(const INDEXmatrix3D& o)
  : m_owner(true)
  , mp_matrix(INDEXmatrix3D_clone(o.mp_matrix))
{
}

inline INDEXmatrix3D::~INDEXmatrix3D()
{
  if (m_owner)
    INDEXmatrix3D_delete(mp_matrix);
}

inline INDEX& INDEXmatrix3D::operator()(INDEX iRow, INDEX iColumn)
{
  return *INDEXmatrix3D_Element(mp_matrix, iRow, iColumn);
}

inline INDEX INDEXmatrix3D::operator()(INDEX iRow, INDEX iColumn) const
{
  return INDEXmatrix3D_Element_const(mp_matrix, iRow, iColumn);
}

inline INDEXmatrix3D& INDEXmatrix3D::operator!=(const INDEXmatrix3D& matrix2)
{
  INDEXmatrix3D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator+=(const INDEXmatrix3D& matrix2)
{
  INDEXmatrix3D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator-=(const INDEXmatrix3D& matrix2)
{
  INDEXmatrix3D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator*=(const INDEXmatrix3D& matrix2)
{
  INDEXmatrix3D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator*=(const INDEX tMul)
{
  INDEXmatrix3D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline INDEXmatrix3D& INDEXmatrix3D::operator/=(const INDEX tMul)
{
  INDEXmatrix3D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void INDEXmatrix3D::Diagonal(INDEX x)
{
  INDEXmatrix3D_Diagonal_scalar(mp_matrix, x);
}

inline void INDEXmatrix3D::Diagonal(const INDEX3D& v)
{
  INDEXmatrix3D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline INDEX3D INDEXmatrix3D::GetRow(INDEX iRow) const
{
  return INDEX3D(INDEXmatrix3D_GetRow(mp_matrix, iRow), true);
}

__forceinline INDEX3D INDEXmatrix3D::GetColumn(INDEX iColumn) const
{
  return INDEX3D(INDEXmatrix3D_GetColumn(mp_matrix, iColumn), true);
}

inline INDEX INDEXmatrix3D::Determinant() const
{
  return INDEXmatrix3D_Determinant(mp_matrix);
}

inline INDEXmatrix4D::INDEXmatrix4D(INDEXmatrix4D_* p, bool owner)
  : m_owner(owner)
  , mp_matrix(p)
{
}

inline INDEXmatrix4D::INDEXmatrix4D()
  : m_owner(true)
  , mp_matrix(INDEXmatrix4D_new())
{
}

inline INDEXmatrix4D::INDEXmatrix4D(INDEX x)
  : m_owner(true)
  , mp_matrix(INDEXmatrix4D_new_x(x))
{
}

inline INDEXmatrix4D::INDEXmatrix4D(const INDEXmatrix4D& o)
  : m_owner(true)
  , mp_matrix(INDEXmatrix4D_clone(o.mp_matrix))
{
}

inline INDEXmatrix4D::~INDEXmatrix4D()
{
  if (m_owner)
    INDEXmatrix4D_delete(mp_matrix);
}

inline INDEX& INDEXmatrix4D::operator()(INDEX iRow, INDEX iColumn)
{
  return *INDEXmatrix4D_Element(mp_matrix, iRow, iColumn);
}

inline INDEX INDEXmatrix4D::operator()(INDEX iRow, INDEX iColumn) const
{
  return INDEXmatrix4D_Element_const(mp_matrix, iRow, iColumn);
}

inline INDEXmatrix4D& INDEXmatrix4D::operator!=(const INDEXmatrix4D& matrix2)
{
  INDEXmatrix4D_AssignTransposed(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator+=(const INDEXmatrix4D& matrix2)
{
  INDEXmatrix4D_PlusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator-=(const INDEXmatrix4D& matrix2)
{
  INDEXmatrix4D_MinusInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator*=(const INDEXmatrix4D& matrix2)
{
  INDEXmatrix4D_MultiplyInplace(mp_matrix, matrix2.mp_matrix);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator*=(const INDEX tMul)
{
  INDEXmatrix4D_MultiplyInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline INDEXmatrix4D& INDEXmatrix4D::operator/=(const INDEX tMul)
{
  INDEXmatrix4D_DivideInplace_scalar(mp_matrix, tMul);
  return *this;
}

inline void INDEXmatrix4D::Diagonal(INDEX x)
{
  INDEXmatrix4D_Diagonal_scalar(mp_matrix, x);
}

inline void INDEXmatrix4D::Diagonal(const INDEX4D& v)
{
  INDEXmatrix4D_Diagonal(mp_matrix, v.C_Handle());
}

__forceinline INDEX4D INDEXmatrix4D::GetRow(INDEX iRow) const
{
  return INDEX4D(INDEXmatrix4D_GetRow(mp_matrix, iRow), true);
}

__forceinline INDEX4D INDEXmatrix4D::GetColumn(INDEX iColumn) const
{
  return INDEX4D(INDEXmatrix4D_GetColumn(mp_matrix, iColumn), true);
}
