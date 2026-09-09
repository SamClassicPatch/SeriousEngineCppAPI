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

inline CTStream& operator>>(CTStream& strm, FLOAT2D& vector)
{
  FLOAT2D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOAT2D& vector)
{
  FLOAT2D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, FLOAT3D& vector)
{
  FLOAT3D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOAT3D& vector)
{
  FLOAT3D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, FLOAT4D& vector)
{
  FLOAT4D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, FLOAT4D& vector)
{
  FLOAT4D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLE2D& vector)
{
  DOUBLE2D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLE2D& vector)
{
  DOUBLE2D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLE3D& vector)
{
  DOUBLE3D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLE3D& vector)
{
  DOUBLE3D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, DOUBLE4D& vector)
{
  DOUBLE4D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, DOUBLE4D& vector)
{
  DOUBLE4D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEX2D& vector)
{
  INDEX2D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEX2D& vector)
{
  INDEX2D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEX3D& vector)
{
  INDEX3D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEX3D& vector)
{
  INDEX3D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator>>(CTStream& strm, INDEX4D& vector)
{
  INDEX4D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, INDEX4D& vector)
{
  INDEX4D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

__forceinline FLOAT2D FLOAT2D::operator*(const FLOATmatrix2D& matrix) const
{
  return FLOAT2D(FLOAT2D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline FLOAT3D FLOAT3D::operator*(const FLOATmatrix3D& matrix) const
{
  return FLOAT3D(FLOAT3D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline FLOAT4D FLOAT4D::operator*(const FLOATmatrix4D& matrix) const
{
  return FLOAT4D(FLOAT4D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline DOUBLE2D DOUBLE2D::operator*(const DOUBLEmatrix2D& matrix) const
{
  return DOUBLE2D(DOUBLE2D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline DOUBLE3D DOUBLE3D::operator*(const DOUBLEmatrix3D& matrix) const
{
  return DOUBLE3D(DOUBLE3D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline DOUBLE4D DOUBLE4D::operator*(const DOUBLEmatrix4D& matrix) const
{
  return DOUBLE4D(DOUBLE4D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline INDEX2D INDEX2D::operator*(const INDEXmatrix2D& matrix) const
{
  return INDEX2D(INDEX2D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline INDEX3D INDEX3D::operator*(const INDEXmatrix3D& matrix) const
{
  return INDEX3D(INDEX3D_Multiply_matrix(mp_vector, matrix), true);
}

__forceinline INDEX4D INDEX4D::operator*(const INDEXmatrix4D& matrix) const
{
  return INDEX4D(INDEX4D_Multiply_matrix(mp_vector, matrix), true);
}

inline FLOAT2D& FLOAT2D::operator=(const FLOAT2D& o)
{
  FLOAT2D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator=(const FLOAT3D& o)
{
  FLOAT3D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator=(const FLOAT4D& o)
{
  FLOAT4D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator=(const DOUBLE2D& o)
{
  DOUBLE2D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator=(const DOUBLE3D& o)
{
  DOUBLE3D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator=(const DOUBLE4D& o)
{
  DOUBLE4D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::operator=(const INDEX2D& o)
{
  INDEX2D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::operator=(const INDEX3D& o)
{
  INDEX3D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::operator=(const INDEX4D& o)
{
  INDEX4D_copy(mp_vector, o.mp_vector);
  return *this;
}

inline FLOAT2D::FLOAT2D(FLOAT2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline FLOAT2D::FLOAT2D()
  : m_owner(true)
  , mp_vector(FLOAT2D_new())
{
}

inline FLOAT2D::FLOAT2D(FLOAT x, FLOAT y)
  : m_owner(true)
  , mp_vector(FLOAT2D_new_xy(x, y))
{
}

inline FLOAT2D::FLOAT2D(const FLOAT2D& o)
  : m_owner(true)
  , mp_vector(FLOAT2D_clone(o.mp_vector))
{
}

inline FLOAT2D::~FLOAT2D()
{
  if (m_owner)
    FLOAT2D_delete(mp_vector);
}

inline void FLOAT2D::Clear()
{
  FLOAT2D_Clear(mp_vector);
}

inline FLOAT FLOAT2D::Length() const
{
  return FLOAT2D_Length(mp_vector);
}

inline FLOAT FLOAT2D::ManhattanNorm() const
{
  return FLOAT2D_ManhattanNorm(mp_vector);
}

inline FLOAT FLOAT2D::MaxNorm() const
{
  return FLOAT2D_MaxNorm(mp_vector);
}

inline FLOAT& FLOAT2D::operator()(INDEX i)
{
  return *FLOAT2D_Element(mp_vector, i);
}

inline FLOAT FLOAT2D::operator()(INDEX i) const
{
  return FLOAT2D_Element_const(mp_vector, i);
}

inline FLOAT2D& FLOAT2D::Normalize()
{
  FLOAT2D_Normalize(mp_vector);
  return *this;
}

inline FLOAT2D& FLOAT2D::SafeNormalize()
{
  FLOAT2D_SafeNormalize(mp_vector);
  return *this;
}

inline FLOAT2D& FLOAT2D::Flip()
{
  FLOAT2D_Flip(mp_vector);
  return *this;
}

inline FLOAT2D& FLOAT2D::operator+=(const FLOAT2D& vector2)
{
  FLOAT2D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT2D& FLOAT2D::operator-=(const FLOAT2D& vector2)
{
  FLOAT2D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT2D& FLOAT2D::operator*=(const FLOAT scalar)
{
  FLOAT2D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT2D& FLOAT2D::operator/=(const FLOAT scalar)
{
  FLOAT2D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT2D& FLOAT2D::operator*=(const FLOATmatrix2D& matrix2)
{
  FLOAT2D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline FLOAT FLOAT2D::operator%(const FLOAT2D& vector2) const
{
  return FLOAT2D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL FLOAT2D::operator==(const FLOAT2D& vector2) const
{
  return FLOAT2D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL FLOAT2D::operator!=(const FLOAT2D& vector2) const
{
  return FLOAT2D_notequal(mp_vector, vector2.mp_vector);
}

inline FLOAT3D::FLOAT3D(FLOAT3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline FLOAT3D::FLOAT3D()
  : m_owner(true)
  , mp_vector(FLOAT3D_new())
{
}

inline FLOAT3D::FLOAT3D(FLOAT x, FLOAT y, FLOAT z)
  : m_owner(true)
  , mp_vector(FLOAT3D_new_xyz(x, y, z))
{
}

inline FLOAT3D::FLOAT3D(const FLOAT3D& o)
  : m_owner(true)
  , mp_vector(FLOAT3D_clone(o.mp_vector))
{
}

inline FLOAT3D::~FLOAT3D()
{
  if (m_owner)
    FLOAT3D_delete(mp_vector);
}

inline void FLOAT3D::Clear()
{
  FLOAT3D_Clear(mp_vector);
}

inline FLOAT FLOAT3D::Length() const
{
  return FLOAT3D_Length(mp_vector);
}

inline FLOAT FLOAT3D::ManhattanNorm() const
{
  return FLOAT3D_ManhattanNorm(mp_vector);
}

inline FLOAT FLOAT3D::MaxNorm() const
{
  return FLOAT3D_MaxNorm(mp_vector);
}

inline FLOAT& FLOAT3D::operator()(INDEX i)
{
  return *FLOAT3D_Element(mp_vector, i);
}

inline FLOAT FLOAT3D::operator()(INDEX i) const
{
  return FLOAT3D_Element_const(mp_vector, i);
}

inline FLOAT3D& FLOAT3D::Normalize()
{
  FLOAT3D_Normalize(mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::SafeNormalize()
{
  FLOAT3D_SafeNormalize(mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::Flip()
{
  FLOAT3D_Flip(mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator+=(const FLOAT3D& vector2)
{
  FLOAT3D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator-=(const FLOAT3D& vector2)
{
  FLOAT3D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator*=(const FLOAT scalar)
{
  FLOAT3D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator/=(const FLOAT scalar)
{
  FLOAT3D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT3D& FLOAT3D::operator*=(const FLOATmatrix3D& matrix2)
{
  FLOAT3D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline FLOAT FLOAT3D::operator%(const FLOAT3D& vector2) const
{
  return FLOAT3D_Dot(mp_vector, vector2.mp_vector);
}

inline FLOAT3D& FLOAT3D::operator*=(const FLOAT3D& vector2)
{
  FLOAT3D_MultiplyInplace_vector(mp_vector, vector2.mp_vector);
  return *this;
}

inline BOOL FLOAT3D::operator==(const FLOAT3D& vector2) const
{
  return FLOAT3D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL FLOAT3D::operator!=(const FLOAT3D& vector2) const
{
  return FLOAT3D_notequal(mp_vector, vector2.mp_vector);
}

inline FLOAT4D::FLOAT4D(FLOAT4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline FLOAT4D::FLOAT4D()
  : m_owner(true)
  , mp_vector(FLOAT4D_new())
{
}

inline FLOAT4D::FLOAT4D(FLOAT x, FLOAT y, FLOAT z, FLOAT w)
  : m_owner(true)
  , mp_vector(FLOAT4D_new_xyzw(x, y, z, w))
{
}

inline FLOAT4D::FLOAT4D(const FLOAT4D& o)
  : m_owner(true)
  , mp_vector(FLOAT4D_clone(o.mp_vector))
{
}

inline FLOAT4D::~FLOAT4D()
{
  if (m_owner)
    FLOAT4D_delete(mp_vector);
}

inline void FLOAT4D::Clear()
{
  FLOAT4D_Clear(mp_vector);
}

inline FLOAT FLOAT4D::Length() const
{
  return FLOAT4D_Length(mp_vector);
}

inline FLOAT FLOAT4D::ManhattanNorm() const
{
  return FLOAT4D_ManhattanNorm(mp_vector);
}

inline FLOAT FLOAT4D::MaxNorm() const
{
  return FLOAT4D_MaxNorm(mp_vector);
}

inline FLOAT& FLOAT4D::operator()(INDEX i)
{
  return *FLOAT4D_Element(mp_vector, i);
}

inline FLOAT FLOAT4D::operator()(INDEX i) const
{
  return FLOAT4D_Element_const(mp_vector, i);
}

inline FLOAT4D& FLOAT4D::Normalize()
{
  FLOAT4D_Normalize(mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::SafeNormalize()
{
  FLOAT4D_SafeNormalize(mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::Flip()
{
  FLOAT4D_Flip(mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator+=(const FLOAT4D& vector2)
{
  FLOAT4D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator-=(const FLOAT4D& vector2)
{
  FLOAT4D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator*=(const FLOAT scalar)
{
  FLOAT4D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator/=(const FLOAT scalar)
{
  FLOAT4D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline FLOAT4D& FLOAT4D::operator*=(const FLOATmatrix4D& matrix2)
{
  FLOAT4D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline FLOAT FLOAT4D::operator%(const FLOAT4D& vector2) const
{
  return FLOAT4D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL FLOAT4D::operator==(const FLOAT4D& vector2) const
{
  return FLOAT4D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL FLOAT4D::operator!=(const FLOAT4D& vector2) const
{
  return FLOAT4D_notequal(mp_vector, vector2.mp_vector);
}

inline DOUBLE2D::DOUBLE2D(DOUBLE2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline DOUBLE2D::DOUBLE2D()
  : m_owner(true)
  , mp_vector(DOUBLE2D_new())
{
}

inline DOUBLE2D::DOUBLE2D(DOUBLE x, DOUBLE y)
  : m_owner(true)
  , mp_vector(DOUBLE2D_new_xy(x, y))
{
}

inline DOUBLE2D::DOUBLE2D(const DOUBLE2D& o)
  : m_owner(true)
  , mp_vector(DOUBLE2D_clone(o.mp_vector))
{
}

inline DOUBLE2D::~DOUBLE2D()
{
  if (m_owner)
    DOUBLE2D_delete(mp_vector);
}

inline void DOUBLE2D::Clear()
{
  DOUBLE2D_Clear(mp_vector);
}

inline DOUBLE DOUBLE2D::Length() const
{
  return DOUBLE2D_Length(mp_vector);
}

inline DOUBLE DOUBLE2D::ManhattanNorm() const
{
  return DOUBLE2D_ManhattanNorm(mp_vector);
}

inline DOUBLE DOUBLE2D::MaxNorm() const
{
  return DOUBLE2D_MaxNorm(mp_vector);
}

inline DOUBLE& DOUBLE2D::operator()(INDEX i)
{
  return *DOUBLE2D_Element(mp_vector, i);
}

inline DOUBLE DOUBLE2D::operator()(INDEX i) const
{
  return DOUBLE2D_Element_const(mp_vector, i);
}

inline DOUBLE2D& DOUBLE2D::Normalize()
{
  DOUBLE2D_Normalize(mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::SafeNormalize()
{
  DOUBLE2D_SafeNormalize(mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::Flip()
{
  DOUBLE2D_Flip(mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator+=(const DOUBLE2D& vector2)
{
  DOUBLE2D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator-=(const DOUBLE2D& vector2)
{
  DOUBLE2D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator*=(const DOUBLE scalar)
{
  DOUBLE2D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator/=(const DOUBLE scalar)
{
  DOUBLE2D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE2D& DOUBLE2D::operator*=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLE2D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline DOUBLE DOUBLE2D::operator%(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL DOUBLE2D::operator==(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL DOUBLE2D::operator!=(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_notequal(mp_vector, vector2.mp_vector);
}

inline DOUBLE3D::DOUBLE3D(DOUBLE3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline DOUBLE3D::DOUBLE3D()
  : m_owner(true)
  , mp_vector(DOUBLE3D_new())
{
}

inline DOUBLE3D::DOUBLE3D(DOUBLE x, DOUBLE y, DOUBLE z)
  : m_owner(true)
  , mp_vector(DOUBLE3D_new_xyz(x, y, z))
{
}

inline DOUBLE3D::DOUBLE3D(const DOUBLE3D& o)
  : m_owner(true)
  , mp_vector(DOUBLE3D_clone(o.mp_vector))
{
}

inline DOUBLE3D::~DOUBLE3D()
{
  if (m_owner)
    DOUBLE3D_delete(mp_vector);
}

inline void DOUBLE3D::Clear()
{
  DOUBLE3D_Clear(mp_vector);
}

inline DOUBLE DOUBLE3D::Length() const
{
  return DOUBLE3D_Length(mp_vector);
}

inline DOUBLE DOUBLE3D::ManhattanNorm() const
{
  return DOUBLE3D_ManhattanNorm(mp_vector);
}

inline DOUBLE DOUBLE3D::MaxNorm() const
{
  return DOUBLE3D_MaxNorm(mp_vector);
}

inline DOUBLE& DOUBLE3D::operator()(INDEX i)
{
  return *DOUBLE3D_Element(mp_vector, i);
}

inline DOUBLE DOUBLE3D::operator()(INDEX i) const
{
  return DOUBLE3D_Element_const(mp_vector, i);
}

inline DOUBLE3D& DOUBLE3D::Normalize()
{
  DOUBLE3D_Normalize(mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::SafeNormalize()
{
  DOUBLE3D_SafeNormalize(mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::Flip()
{
  DOUBLE3D_Flip(mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator+=(const DOUBLE3D& vector2)
{
  DOUBLE3D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator-=(const DOUBLE3D& vector2)
{
  DOUBLE3D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator*=(const DOUBLE scalar)
{
  DOUBLE3D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator/=(const DOUBLE scalar)
{
  DOUBLE3D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE3D& DOUBLE3D::operator*=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLE3D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline DOUBLE DOUBLE3D::operator%(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_Dot(mp_vector, vector2.mp_vector);
}

inline DOUBLE3D& DOUBLE3D::operator*=(const DOUBLE3D& vector2)
{
  DOUBLE3D_MultiplyInplace_vector(mp_vector, vector2.mp_vector);
  return *this;
}

inline BOOL DOUBLE3D::operator==(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL DOUBLE3D::operator!=(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_notequal(mp_vector, vector2.mp_vector);
}

inline DOUBLE4D::DOUBLE4D(DOUBLE4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline DOUBLE4D::DOUBLE4D()
  : m_owner(true)
  , mp_vector(DOUBLE4D_new())
{
}

inline DOUBLE4D::DOUBLE4D(DOUBLE x, DOUBLE y, DOUBLE z, DOUBLE w)
  : m_owner(true)
  , mp_vector(DOUBLE4D_new_xyzw(x, y, z, w))
{
}

inline DOUBLE4D::DOUBLE4D(const DOUBLE4D& o)
  : m_owner(true)
  , mp_vector(DOUBLE4D_clone(o.mp_vector))
{
}

inline DOUBLE4D::~DOUBLE4D()
{
  if (m_owner)
    DOUBLE4D_delete(mp_vector);
}

inline void DOUBLE4D::Clear()
{
  DOUBLE4D_Clear(mp_vector);
}

inline DOUBLE DOUBLE4D::Length() const
{
  return DOUBLE4D_Length(mp_vector);
}

inline DOUBLE DOUBLE4D::ManhattanNorm() const
{
  return DOUBLE4D_ManhattanNorm(mp_vector);
}

inline DOUBLE DOUBLE4D::MaxNorm() const
{
  return DOUBLE4D_MaxNorm(mp_vector);
}

inline DOUBLE& DOUBLE4D::operator()(INDEX i)
{
  return *DOUBLE4D_Element(mp_vector, i);
}

inline DOUBLE DOUBLE4D::operator()(INDEX i) const
{
  return DOUBLE4D_Element_const(mp_vector, i);
}

inline DOUBLE4D& DOUBLE4D::Normalize()
{
  DOUBLE4D_Normalize(mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::SafeNormalize()
{
  DOUBLE4D_SafeNormalize(mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::Flip()
{
  DOUBLE4D_Flip(mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator+=(const DOUBLE4D& vector2)
{
  DOUBLE4D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator-=(const DOUBLE4D& vector2)
{
  DOUBLE4D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator*=(const DOUBLE scalar)
{
  DOUBLE4D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator/=(const DOUBLE scalar)
{
  DOUBLE4D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline DOUBLE4D& DOUBLE4D::operator*=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLE4D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline DOUBLE DOUBLE4D::operator%(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL DOUBLE4D::operator==(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL DOUBLE4D::operator!=(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_notequal(mp_vector, vector2.mp_vector);
}

inline INDEX2D::INDEX2D(INDEX2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline INDEX2D::INDEX2D()
  : m_owner(true)
  , mp_vector(INDEX2D_new())
{
}

inline INDEX2D::INDEX2D(INDEX x, INDEX y)
  : m_owner(true)
  , mp_vector(INDEX2D_new_xy(x, y))
{
}

inline INDEX2D::INDEX2D(const INDEX2D& o)
  : m_owner(true)
  , mp_vector(INDEX2D_clone(o.mp_vector))
{
}

inline INDEX2D::~INDEX2D()
{
  if (m_owner)
    INDEX2D_delete(mp_vector);
}

inline void INDEX2D::Clear()
{
  INDEX2D_Clear(mp_vector);
}

inline INDEX INDEX2D::Length() const
{
  return INDEX2D_Length(mp_vector);
}

inline INDEX INDEX2D::ManhattanNorm() const
{
  return INDEX2D_ManhattanNorm(mp_vector);
}

inline INDEX INDEX2D::MaxNorm() const
{
  return INDEX2D_MaxNorm(mp_vector);
}

inline INDEX& INDEX2D::operator()(INDEX i)
{
  return *INDEX2D_Element(mp_vector, i);
}

inline INDEX INDEX2D::operator()(INDEX i) const
{
  return INDEX2D_Element_const(mp_vector, i);
}

inline INDEX2D& INDEX2D::Normalize()
{
  INDEX2D_Normalize(mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::SafeNormalize()
{
  INDEX2D_SafeNormalize(mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::Flip()
{
  INDEX2D_Flip(mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::operator+=(const INDEX2D& vector2)
{
  INDEX2D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::operator-=(const INDEX2D& vector2)
{
  INDEX2D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX2D& INDEX2D::operator*=(const INDEX scalar)
{
  INDEX2D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline INDEX2D& INDEX2D::operator/=(const INDEX scalar)
{
  INDEX2D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline INDEX2D& INDEX2D::operator*=(const INDEXmatrix2D& matrix2)
{
  INDEX2D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline INDEX INDEX2D::operator%(const INDEX2D& vector2) const
{
  return INDEX2D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL INDEX2D::operator==(const INDEX2D& vector2) const
{
  return INDEX2D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL INDEX2D::operator!=(const INDEX2D& vector2) const
{
  return INDEX2D_notequal(mp_vector, vector2.mp_vector);
}

inline INDEX3D::INDEX3D(INDEX3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline INDEX3D::INDEX3D()
  : m_owner(true)
  , mp_vector(INDEX3D_new())
{
}

inline INDEX3D::INDEX3D(INDEX x, INDEX y, INDEX z)
  : m_owner(true)
  , mp_vector(INDEX3D_new_xyz(x, y, z))
{
}

inline INDEX3D::INDEX3D(const INDEX3D& o)
  : m_owner(true)
  , mp_vector(INDEX3D_clone(o.mp_vector))
{
}

inline INDEX3D::~INDEX3D()
{
  if (m_owner)
    INDEX3D_delete(mp_vector);
}

inline void INDEX3D::Clear()
{
  INDEX3D_Clear(mp_vector);
}

inline INDEX INDEX3D::Length() const
{
  return INDEX3D_Length(mp_vector);
}

inline INDEX INDEX3D::ManhattanNorm() const
{
  return INDEX3D_ManhattanNorm(mp_vector);
}

inline INDEX INDEX3D::MaxNorm() const
{
  return INDEX3D_MaxNorm(mp_vector);
}

inline INDEX& INDEX3D::operator()(INDEX i)
{
  return *INDEX3D_Element(mp_vector, i);
}

inline INDEX INDEX3D::operator()(INDEX i) const
{
  return INDEX3D_Element_const(mp_vector, i);
}

inline INDEX3D& INDEX3D::Normalize()
{
  INDEX3D_Normalize(mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::SafeNormalize()
{
  INDEX3D_SafeNormalize(mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::Flip()
{
  INDEX3D_Flip(mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::operator+=(const INDEX3D& vector2)
{
  INDEX3D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::operator-=(const INDEX3D& vector2)
{
  INDEX3D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX3D& INDEX3D::operator*=(const INDEX scalar)
{
  INDEX3D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline INDEX3D& INDEX3D::operator/=(const INDEX scalar)
{
  INDEX3D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline INDEX3D& INDEX3D::operator*=(const INDEXmatrix3D& matrix2)
{
  INDEX3D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline INDEX INDEX3D::operator%(const INDEX3D& vector2) const
{
  return INDEX3D_Dot(mp_vector, vector2.mp_vector);
}

inline INDEX3D& INDEX3D::operator*=(const INDEX3D& vector2)
{
  INDEX3D_MultiplyInplace_vector(mp_vector, vector2.mp_vector);
  return *this;
}

inline BOOL INDEX3D::operator==(const INDEX3D& vector2) const
{
  return INDEX3D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL INDEX3D::operator!=(const INDEX3D& vector2) const
{
  return INDEX3D_notequal(mp_vector, vector2.mp_vector);
}

inline INDEX4D::INDEX4D(INDEX4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline INDEX4D::INDEX4D()
  : m_owner(true)
  , mp_vector(INDEX4D_new())
{
}

inline INDEX4D::INDEX4D(INDEX x, INDEX y, INDEX z, INDEX w)
  : m_owner(true)
  , mp_vector(INDEX4D_new_xyzw(x, y, z, w))
{
}

inline INDEX4D::INDEX4D(const INDEX4D& o)
  : m_owner(true)
  , mp_vector(INDEX4D_clone(o.mp_vector))
{
}

inline INDEX4D::~INDEX4D()
{
  if (m_owner)
    INDEX4D_delete(mp_vector);
}

inline void INDEX4D::Clear()
{
  INDEX4D_Clear(mp_vector);
}

inline INDEX INDEX4D::Length() const
{
  return INDEX4D_Length(mp_vector);
}

inline INDEX INDEX4D::ManhattanNorm() const
{
  return INDEX4D_ManhattanNorm(mp_vector);
}

inline INDEX INDEX4D::MaxNorm() const
{
  return INDEX4D_MaxNorm(mp_vector);
}

inline INDEX& INDEX4D::operator()(INDEX i)
{
  return *INDEX4D_Element(mp_vector, i);
}

inline INDEX INDEX4D::operator()(INDEX i) const
{
  return INDEX4D_Element_const(mp_vector, i);
}

inline INDEX4D& INDEX4D::Normalize()
{
  INDEX4D_Normalize(mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::SafeNormalize()
{
  INDEX4D_SafeNormalize(mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::Flip()
{
  INDEX4D_Flip(mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::operator+=(const INDEX4D& vector2)
{
  INDEX4D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::operator-=(const INDEX4D& vector2)
{
  INDEX4D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline INDEX4D& INDEX4D::operator*=(const INDEX scalar)
{
  INDEX4D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline INDEX4D& INDEX4D::operator/=(const INDEX scalar)
{
  INDEX4D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline INDEX4D& INDEX4D::operator*=(const INDEXmatrix4D& matrix2)
{
  INDEX4D_MultiplyInplace_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

inline INDEX INDEX4D::operator%(const INDEX4D& vector2) const
{
  return INDEX4D_Dot(mp_vector, vector2.mp_vector);
}

inline BOOL INDEX4D::operator==(const INDEX4D& vector2) const
{
  return INDEX4D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL INDEX4D::operator!=(const INDEX4D& vector2) const
{
  return INDEX4D_notequal(mp_vector, vector2.mp_vector);
}


inline SWORD3D::SWORD3D(SWORD3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline SWORD3D::SWORD3D()
  : m_owner(true)
  , mp_vector(SWORD3D_new())
{
}

inline SWORD3D::SWORD3D(SWORD x, SWORD y, SWORD z)
  : m_owner(true)
  , mp_vector(SWORD3D_new_xyz(x, y, z))
{
}

inline SWORD3D::SWORD3D(const SWORD3D& o)
  : m_owner(true)
  , mp_vector(SWORD3D_clone(o.mp_vector))
{
}

inline SWORD3D::~SWORD3D()
{
  if (m_owner)
    SWORD3D_delete(mp_vector);
}

inline void SWORD3D::Clear()
{
  SWORD3D_Clear(mp_vector);
}

inline SWORD SWORD3D::Length() const
{
  return SWORD3D_Length(mp_vector);
}

inline SWORD SWORD3D::ManhattanNorm() const
{
  return SWORD3D_ManhattanNorm(mp_vector);
}

inline SWORD SWORD3D::MaxNorm() const
{
  return SWORD3D_MaxNorm(mp_vector);
}

inline SWORD& SWORD3D::operator()(SWORD i)
{
  return *SWORD3D_Element(mp_vector, i);
}

inline SWORD SWORD3D::operator()(SWORD i) const
{
  return SWORD3D_Element_const(mp_vector, i);
}

inline SWORD3D& SWORD3D::Normalize()
{
  SWORD3D_Normalize(mp_vector);
  return *this;
}

inline SWORD3D& SWORD3D::SafeNormalize()
{
  SWORD3D_SafeNormalize(mp_vector);
  return *this;
}

inline SWORD3D& SWORD3D::Flip()
{
  SWORD3D_Flip(mp_vector);
  return *this;
}

inline SWORD3D& SWORD3D::operator+=(const SWORD3D& vector2)
{
  SWORD3D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline SWORD3D& SWORD3D::operator-=(const SWORD3D& vector2)
{
  SWORD3D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline SWORD3D& SWORD3D::operator*=(const SWORD scalar)
{
  SWORD3D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline SWORD3D& SWORD3D::operator/=(const SWORD scalar)
{
  SWORD3D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline SWORD SWORD3D::operator%(const SWORD3D& vector2) const
{
  return SWORD3D_Dot(mp_vector, vector2.mp_vector);
}

inline SWORD3D& SWORD3D::operator*=(const SWORD3D& vector2)
{
  SWORD3D_MultiplyInplace_vector(mp_vector, vector2.mp_vector);
  return *this;
}

inline BOOL SWORD3D::operator==(const SWORD3D& vector2) const
{
  return SWORD3D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL SWORD3D::operator!=(const SWORD3D& vector2) const
{
  return SWORD3D_notequal(mp_vector, vector2.mp_vector);
}

inline CTStream& operator>>(CTStream& strm, SWORD3D& vector)
{
  SWORD3D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, SWORD3D& vector)
{
  SWORD3D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline SWORD3D& SWORD3D::operator=(const SWORD3D& o)
{
  SWORD3D_copy(mp_vector, o.mp_vector);
  return *this;
}


inline SBYTE3D::SBYTE3D(SBYTE3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

inline SBYTE3D::SBYTE3D()
  : m_owner(true)
  , mp_vector(SBYTE3D_new())
{
}

inline SBYTE3D::SBYTE3D(SBYTE x, SBYTE y, SBYTE z)
  : m_owner(true)
  , mp_vector(SBYTE3D_new_xyz(x, y, z))
{
}

inline SBYTE3D::SBYTE3D(const SBYTE3D& o)
  : m_owner(true)
  , mp_vector(SBYTE3D_clone(o.mp_vector))
{
}

inline SBYTE3D::~SBYTE3D()
{
  if (m_owner)
    SBYTE3D_delete(mp_vector);
}

inline void SBYTE3D::Clear()
{
  SBYTE3D_Clear(mp_vector);
}

inline SBYTE SBYTE3D::Length() const
{
  return SBYTE3D_Length(mp_vector);
}

inline SBYTE SBYTE3D::ManhattanNorm() const
{
  return SBYTE3D_ManhattanNorm(mp_vector);
}

inline SBYTE SBYTE3D::MaxNorm() const
{
  return SBYTE3D_MaxNorm(mp_vector);
}

inline SBYTE& SBYTE3D::operator()(SBYTE i)
{
  return *SBYTE3D_Element(mp_vector, i);
}

inline SBYTE SBYTE3D::operator()(SBYTE i) const
{
  return SBYTE3D_Element_const(mp_vector, i);
}

inline SBYTE3D& SBYTE3D::Normalize()
{
  SBYTE3D_Normalize(mp_vector);
  return *this;
}

inline SBYTE3D& SBYTE3D::SafeNormalize()
{
  SBYTE3D_SafeNormalize(mp_vector);
  return *this;
}

inline SBYTE3D& SBYTE3D::Flip()
{
  SBYTE3D_Flip(mp_vector);
  return *this;
}

inline SBYTE3D& SBYTE3D::operator+=(const SBYTE3D& vector2)
{
  SBYTE3D_PlusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline SBYTE3D& SBYTE3D::operator-=(const SBYTE3D& vector2)
{
  SBYTE3D_MinusInplace(mp_vector, vector2.mp_vector);
  return *this;
}

inline SBYTE3D& SBYTE3D::operator*=(const SBYTE scalar)
{
  SBYTE3D_MultiplyInplace(mp_vector, scalar);
  return *this;
}

inline SBYTE3D& SBYTE3D::operator/=(const SBYTE scalar)
{
  SBYTE3D_DivideInplace(mp_vector, scalar);
  return *this;
}

inline SBYTE SBYTE3D::operator%(const SBYTE3D& vector2) const
{
  return SBYTE3D_Dot(mp_vector, vector2.mp_vector);
}

inline SBYTE3D& SBYTE3D::operator*=(const SBYTE3D& vector2)
{
  SBYTE3D_MultiplyInplace_vector(mp_vector, vector2.mp_vector);
  return *this;
}

inline BOOL SBYTE3D::operator==(const SBYTE3D& vector2) const
{
  return SBYTE3D_equal(mp_vector, vector2.mp_vector);
}

inline BOOL SBYTE3D::operator!=(const SBYTE3D& vector2) const
{
  return SBYTE3D_notequal(mp_vector, vector2.mp_vector);
}

inline CTStream& operator>>(CTStream& strm, SBYTE3D& vector)
{
  SBYTE3D_extract(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, SBYTE3D& vector)
{
  SBYTE3D_insert(strm.C_Handle(), vector.C_Handle());
  SECppAPI_CheckException();
  return strm;
}

inline SBYTE3D& SBYTE3D::operator=(const SBYTE3D& o)
{
  SBYTE3D_copy(mp_vector, o.mp_vector);
  return *this;
}
