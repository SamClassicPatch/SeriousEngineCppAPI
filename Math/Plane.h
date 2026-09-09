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
#include "Vector.h"
#include <SeriousEngineCAPI/Math/Plane.h>

class FLOATplane3D : public FLOAT3D
{
public:
  FLOATplane3D(FLOATplane3D_* p, bool owner = false);
  FLOATplane3D();
  FLOATplane3D(const FLOAT3D& normal, const FLOAT distance);
  FLOATplane3D(const FLOAT3D& normal, const FLOAT3D& point);
  FLOATplane3D(const FLOAT3D& point0, const FLOAT3D& point1, const FLOAT3D& point2);
  FLOATplane3D(const FLOATplane3D& o);
  ~FLOATplane3D();

  FLOATplane3D& operator=(const FLOATplane3D& o);

  /* Reference distance. */
  FLOAT& Distance();
  const FLOAT& Distance() const;
  /* Get a reference point on the plane. */
  FLOAT3D ReferencePoint() const;
  /* Get a reference point on the plane, if origin is at given vector. */
  FLOAT3D ReferencePoint(const FLOAT3D& vOrigin) const;

  /* Get distance of point from plane. */
  const FLOAT PointDistance(const FLOAT3D& point) const;
  /* Get missing coordinate value */
  void GetCoordinate(const INDEX iIndex, FLOAT3D& point) const;
  /* Get distance of plane from plane. */
  const FLOAT PlaneDistance(const FLOATplane3D& plOther) const;
  /* Project a point to the plane. */
  FLOAT3D ProjectPoint(const FLOAT3D& point) const;
  /* Project a direction vector to the plane. */
  FLOAT3D ProjectDirection(const FLOAT3D& direction) const;
  /* Get index of the greatest coordinate of normal. */
  INDEX GetMaxNormal() const;
  /* Deproject a point to the plane. */
  FLOAT3D DeprojectPoint(const FLOATplane3D& plOther, const FLOAT3D& point) const;
  /* Deproject a direction vector to the plane. */
  FLOAT3D DeprojectDirection(const FLOATplane3D& plOther, const FLOAT3D& point) const;

  /* Offset the plane forward for a given distance. */
  void Offset(const FLOAT offset);

  /* Mathematical operators. */
  // unary minus (fliping of the plane)
  FLOATplane3D operator-() const;
  // addition of vector (translation of the plane by the vector)
  FLOATplane3D operator+(const FLOAT3D& vector2) const;
  FLOATplane3D& operator+=(const FLOAT3D& vector2);
  FLOATplane3D operator-(const FLOAT3D& vector2) const;
  FLOATplane3D& operator-=(const FLOAT3D& vector2);
  // multiplication by a square matrix (sides swapped -- see implementation for notes)
  FLOATplane3D& operator*=(const FLOATmatrix3D& matrix2);
  FLOATplane3D operator*(const FLOATmatrix3D& matrix2) const;

  inline FLOATplane3D_* C_Handle() { return (FLOATplane3D_*)mp_vector; }
  inline const FLOATplane3D_* C_Handle() const { return (const FLOATplane3D_*)mp_vector; }
  inline operator FLOATplane3D_* () { return C_Handle(); }
  inline operator const FLOATplane3D_* () const { return C_Handle(); }
};

class DOUBLEplane3D : public DOUBLE3D
{
public:
  DOUBLEplane3D(DOUBLEplane3D_* p, bool owner = false);
  DOUBLEplane3D();
  DOUBLEplane3D(const DOUBLE3D& normal, const DOUBLE distance);
  DOUBLEplane3D(const DOUBLE3D& normal, const DOUBLE3D& point);
  DOUBLEplane3D(const DOUBLE3D& point0, const DOUBLE3D& point1, const DOUBLE3D& point2);
  DOUBLEplane3D(const DOUBLEplane3D& o);
  ~DOUBLEplane3D();

  DOUBLEplane3D& operator=(const DOUBLEplane3D& o);

  /* Reference distance. */
  DOUBLE& Distance();
  const DOUBLE& Distance() const;
  /* Get a reference point on the plane. */
  DOUBLE3D ReferencePoint() const;
  /* Get a reference point on the plane, if origin is at given vector. */
  DOUBLE3D ReferencePoint(const DOUBLE3D& vOrigin) const;

  /* Get distance of point from plane. */
  const DOUBLE PointDistance(const DOUBLE3D& point) const;
  /* Get missing coordinate value */
  void GetCoordinate(const INDEX iIndex, DOUBLE3D& point) const;
  /* Get distance of plane from plane. */
  const DOUBLE PlaneDistance(const DOUBLEplane3D& plOther) const;
  /* Project a point to the plane. */
  DOUBLE3D ProjectPoint(const DOUBLE3D& point) const;
  /* Project a direction vector to the plane. */
  DOUBLE3D ProjectDirection(const DOUBLE3D& direction) const;
  /* Get index of the greatest coordinate of normal. */
  INDEX GetMaxNormal() const;
  /* Deproject a point to the plane. */
  DOUBLE3D DeprojectPoint(const DOUBLEplane3D& plOther, const DOUBLE3D& point) const;
  /* Deproject a direction vector to the plane. */
  DOUBLE3D DeprojectDirection(const DOUBLEplane3D& plOther, const DOUBLE3D& point) const;

  /* Offset the plane forward for a given distance. */
  void Offset(const DOUBLE offset);

  /* Mathematical operators. */
  // unary minus (fliping of the plane)
  DOUBLEplane3D operator-() const;
  // addition of vector (translation of the plane by the vector)
  DOUBLEplane3D operator+(const DOUBLE3D& vector2) const;
  DOUBLEplane3D& operator+=(const DOUBLE3D& vector2);
  DOUBLEplane3D operator-(const DOUBLE3D& vector2) const;
  DOUBLEplane3D& operator-=(const DOUBLE3D& vector2);
  // multiplication by a square matrix (sides swapped -- see implementation for notes)
  DOUBLEplane3D& operator*=(const DOUBLEmatrix3D& matrix2);
  DOUBLEplane3D operator*(const DOUBLEmatrix3D& matrix2) const;

  inline DOUBLEplane3D_* C_Handle() { return (DOUBLEplane3D_*)mp_vector; }
  inline const DOUBLEplane3D_* C_Handle() const { return (const DOUBLEplane3D_*)mp_vector; }
  inline operator DOUBLEplane3D_* () { return C_Handle(); }
  inline operator const DOUBLEplane3D_* () const { return C_Handle(); }
};

// helper functions for converting between FLOAT and DOUBLE planes
DOUBLEplane3D FLOATtoDOUBLE(const FLOATplane3D& plf);
FLOATplane3D DOUBLEtoFLOAT(const DOUBLEplane3D& pld);

#include "Plane.inl"
