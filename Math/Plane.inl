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

inline FLOATplane3D::FLOATplane3D(FLOATplane3D_* p, bool owner)
  : FLOAT3D((FLOAT3D_*)p, owner)
{
}

inline FLOATplane3D::FLOATplane3D()
  : FLOATplane3D(FLOATplane3D_new(), true)
{
}

inline FLOATplane3D::FLOATplane3D(const FLOAT3D& normal, const FLOAT distance)
  : FLOATplane3D(FLOATplane3D_new_nd(normal, distance), true)
{
}
inline FLOATplane3D::FLOATplane3D(const FLOAT3D& normal, const FLOAT3D& point)
  : FLOATplane3D(FLOATplane3D_new_np(normal, point), true)
{
}

inline FLOATplane3D::FLOATplane3D(const FLOAT3D& point0, const FLOAT3D& point1, const FLOAT3D& point2)
  : FLOATplane3D(FLOATplane3D_new_ppp(point0, point1, point2), true)
{
}

inline FLOATplane3D::FLOATplane3D(const FLOATplane3D& o)
  : FLOATplane3D(FLOATplane3D_clone(o), true)
{
}

inline FLOATplane3D::~FLOATplane3D()
{
  if (m_owner)
    FLOATplane3D_delete(C_Handle());
  m_owner = false;
  mp_vector = nullptr;
}

inline FLOATplane3D& FLOATplane3D::operator=(const FLOATplane3D& o)
{
  FLOATplane3D_copy(C_Handle(), o);
  return *this;
}

inline FLOAT& FLOATplane3D::Distance()
{
  return *FLOATplane3D_Distance(C_Handle());
}

inline const FLOAT& FLOATplane3D::Distance() const
{
  return *FLOATplane3D_Distance_const(C_Handle());
}

__forceinline FLOAT3D FLOATplane3D::ReferencePoint() const
{
  return FLOAT3D(FLOATplane3D_ReferencePoint(C_Handle()), true);
}

__forceinline FLOAT3D FLOATplane3D::ReferencePoint(const FLOAT3D& vOrigin) const
{
  return FLOAT3D(FLOATplane3D_ReferencePoint_origin(C_Handle(), vOrigin), true);
}

inline const FLOAT FLOATplane3D::PointDistance(const FLOAT3D& point) const
{
  return FLOATplane3D_PointDistance(C_Handle(), point);
}

inline void FLOATplane3D::GetCoordinate(const INDEX iIndex, FLOAT3D& point) const
{
  FLOATplane3D_GetCoordinate(C_Handle(), iIndex, point);
}

inline const FLOAT FLOATplane3D::PlaneDistance(const FLOATplane3D& plOther) const
{
  return FLOATplane3D_PlaneDistance(C_Handle(), plOther);
}

__forceinline FLOAT3D FLOATplane3D::ProjectPoint(const FLOAT3D& point) const
{
  return FLOAT3D(FLOATplane3D_ProjectPoint(C_Handle(), point), true);
}

__forceinline FLOAT3D FLOATplane3D::ProjectDirection(const FLOAT3D& direction) const
{
  return FLOAT3D(FLOATplane3D_ProjectDirection(C_Handle(), direction), true);
}

inline INDEX FLOATplane3D::GetMaxNormal() const
{
  return FLOATplane3D_GetMaxNormal(C_Handle());
}

__forceinline FLOAT3D FLOATplane3D::DeprojectPoint(const FLOATplane3D& plOther, const FLOAT3D& point) const
{
  return FLOAT3D(FLOATplane3D_DeprojectPoint(C_Handle(), plOther, point), true);
}

__forceinline FLOAT3D FLOATplane3D::DeprojectDirection(const FLOATplane3D& plOther, const FLOAT3D& point) const
{
  return FLOAT3D(FLOATplane3D_DeprojectDirection(C_Handle(), plOther, point), true);
}

inline void FLOATplane3D::Offset(const FLOAT offset)
{
  FLOATplane3D_Offset(C_Handle(), offset);
}

__forceinline FLOATplane3D FLOATplane3D::operator-() const
{
  return FLOATplane3D(FLOATplane3D_Flip(C_Handle()), true);
}

__forceinline FLOATplane3D FLOATplane3D::operator+(const FLOAT3D& vector2) const
{
  return FLOATplane3D(FLOATplane3D_Plus(C_Handle(), vector2), true);
}

inline FLOATplane3D& FLOATplane3D::operator+=(const FLOAT3D& vector2)
{
  FLOATplane3D_PlusInplace(C_Handle(), vector2);
  return *this;
}

__forceinline FLOATplane3D FLOATplane3D::operator-(const FLOAT3D& vector2) const
{
  return FLOATplane3D(FLOATplane3D_Minus(C_Handle(), vector2), true);
}

inline FLOATplane3D& FLOATplane3D::operator-=(const FLOAT3D& vector2)
{
  FLOATplane3D_MinusInplace(C_Handle(), vector2);
  return *this;
}

inline FLOATplane3D& FLOATplane3D::operator*=(const FLOATmatrix3D& matrix2)
{
  FLOATplane3D_MultiplyInplace(C_Handle(), matrix2);
  return *this;
}

__forceinline FLOATplane3D FLOATplane3D::operator*(const FLOATmatrix3D& matrix2) const
{
  return FLOATplane3D(FLOATplane3D_Multiply(C_Handle(), matrix2), true);
}

inline DOUBLEplane3D::DOUBLEplane3D(DOUBLEplane3D_* p, bool owner)
  : DOUBLE3D((DOUBLE3D_*)p, owner)
{
}

inline DOUBLEplane3D::DOUBLEplane3D()
  : DOUBLEplane3D(DOUBLEplane3D_new(), true)
{
}

inline DOUBLEplane3D::DOUBLEplane3D(const DOUBLE3D& normal, const DOUBLE distance)
  : DOUBLEplane3D(DOUBLEplane3D_new_nd(normal, distance), true)
{
}
inline DOUBLEplane3D::DOUBLEplane3D(const DOUBLE3D& normal, const DOUBLE3D& point)
  : DOUBLEplane3D(DOUBLEplane3D_new_np(normal, point), true)
{
}

inline DOUBLEplane3D::DOUBLEplane3D(const DOUBLE3D& point0, const DOUBLE3D& point1, const DOUBLE3D& point2)
  : DOUBLEplane3D(DOUBLEplane3D_new_ppp(point0, point1, point2), true)
{
}

inline DOUBLEplane3D::DOUBLEplane3D(const DOUBLEplane3D& o)
  : DOUBLEplane3D(DOUBLEplane3D_clone(o), true)
{
}

inline DOUBLEplane3D::~DOUBLEplane3D()
{
  if (m_owner)
    DOUBLEplane3D_delete(C_Handle());
  m_owner = false;
  mp_vector = nullptr;
}

inline DOUBLEplane3D& DOUBLEplane3D::operator=(const DOUBLEplane3D& o)
{
  DOUBLEplane3D_copy(C_Handle(), o);
  return *this;
}

inline DOUBLE& DOUBLEplane3D::Distance()
{
  return *DOUBLEplane3D_Distance(C_Handle());
}

inline const DOUBLE& DOUBLEplane3D::Distance() const
{
  return *DOUBLEplane3D_Distance_const(C_Handle());
}

__forceinline DOUBLE3D DOUBLEplane3D::ReferencePoint() const
{
  return DOUBLE3D(DOUBLEplane3D_ReferencePoint(C_Handle()), true);
}

__forceinline DOUBLE3D DOUBLEplane3D::ReferencePoint(const DOUBLE3D& vOrigin) const
{
  return DOUBLE3D(DOUBLEplane3D_ReferencePoint_origin(C_Handle(), vOrigin), true);
}

inline const DOUBLE DOUBLEplane3D::PointDistance(const DOUBLE3D& point) const
{
  return DOUBLEplane3D_PointDistance(C_Handle(), point);
}

inline void DOUBLEplane3D::GetCoordinate(const INDEX iIndex, DOUBLE3D& point) const
{
  DOUBLEplane3D_GetCoordinate(C_Handle(), iIndex, point);
}

inline const DOUBLE DOUBLEplane3D::PlaneDistance(const DOUBLEplane3D& plOther) const
{
  return DOUBLEplane3D_PlaneDistance(C_Handle(), plOther);
}

__forceinline DOUBLE3D DOUBLEplane3D::ProjectPoint(const DOUBLE3D& point) const
{
  return DOUBLE3D(DOUBLEplane3D_ProjectPoint(C_Handle(), point), true);
}

__forceinline DOUBLE3D DOUBLEplane3D::ProjectDirection(const DOUBLE3D& direction) const
{
  return DOUBLE3D(DOUBLEplane3D_ProjectDirection(C_Handle(), direction), true);
}

inline INDEX DOUBLEplane3D::GetMaxNormal() const
{
  return DOUBLEplane3D_GetMaxNormal(C_Handle());
}

__forceinline DOUBLE3D DOUBLEplane3D::DeprojectPoint(const DOUBLEplane3D& plOther, const DOUBLE3D& point) const
{
  return DOUBLE3D(DOUBLEplane3D_DeprojectPoint(C_Handle(), plOther, point), true);
}

__forceinline DOUBLE3D DOUBLEplane3D::DeprojectDirection(const DOUBLEplane3D& plOther, const DOUBLE3D& point) const
{
  return DOUBLE3D(DOUBLEplane3D_DeprojectDirection(C_Handle(), plOther, point), true);
}

inline void DOUBLEplane3D::Offset(const DOUBLE offset)
{
  DOUBLEplane3D_Offset(C_Handle(), offset);
}

__forceinline DOUBLEplane3D DOUBLEplane3D::operator-() const
{
  return DOUBLEplane3D(DOUBLEplane3D_Flip(C_Handle()), true);
}

__forceinline DOUBLEplane3D DOUBLEplane3D::operator+(const DOUBLE3D& vector2) const
{
  return DOUBLEplane3D(DOUBLEplane3D_Plus(C_Handle(), vector2), true);
}

inline DOUBLEplane3D& DOUBLEplane3D::operator+=(const DOUBLE3D& vector2)
{
  DOUBLEplane3D_PlusInplace(C_Handle(), vector2);
  return *this;
}

__forceinline DOUBLEplane3D DOUBLEplane3D::operator-(const DOUBLE3D& vector2) const
{
  return DOUBLEplane3D(DOUBLEplane3D_Minus(C_Handle(), vector2), true);
}

inline DOUBLEplane3D& DOUBLEplane3D::operator-=(const DOUBLE3D& vector2)
{
  DOUBLEplane3D_MinusInplace(C_Handle(), vector2);
  return *this;
}

inline DOUBLEplane3D& DOUBLEplane3D::operator*=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLEplane3D_MultiplyInplace(C_Handle(), matrix2);
  return *this;
}

__forceinline DOUBLEplane3D DOUBLEplane3D::operator*(const DOUBLEmatrix3D& matrix2) const
{
  return DOUBLEplane3D(DOUBLEplane3D_Multiply(C_Handle(), matrix2), true);
}

__forceinline DOUBLEplane3D FLOATtoDOUBLE(const FLOATplane3D& plf)
{
  return DOUBLEplane3D(FLOATtoDOUBLEplane(plf), true);
}

__forceinline FLOATplane3D DOUBLEtoFLOAT(const DOUBLEplane3D& pld)
{
  return FLOATplane3D(DOUBLEtoFLOATplane(pld), true);
}
