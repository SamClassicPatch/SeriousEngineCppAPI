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
#include "Plane.h"
#include "AABBox.h"
#include <SeriousEngineCAPI/Math/OBBox.h>

class FLOATobbox3D
{
public:
  FLOATobbox3D(FLOATobbox3D_* p, bool owner = false);
  FLOATobbox3D();
  FLOATobbox3D(const FLOAT3D& vO,
    const FLOAT3D& vAxis0, const FLOAT3D& vAxis1, const FLOAT3D& vAxis2,
    FLOAT tSize0, FLOAT tSize1, FLOAT tSize2);
  /* Constructor from axis aligned box and placement. */
  FLOATobbox3D(const FLOATaabbox3D& aabbox,
    const FLOAT3D& vPos, const FLOATmatrix3D& mRot);
  /* Constructor from axis aligned box without placement. */
  FLOATobbox3D(const FLOATaabbox3D& aabbox);
  FLOATobbox3D(const FLOATobbox3D& o);
  ~FLOATobbox3D();

  FLOATobbox3D& operator=(const FLOATobbox3D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  // classify box with respect to a plane
  FLOAT TestAgainstPlane(const FLOATplane3D& pl) const;
  // check if two boxes intersect/touch
  BOOL HasContactWith(const FLOATobbox3D& boxB) const;

  /* Check if empty. */
  BOOL IsEmpty() const;

  inline FLOAT3D& box_avAxis(INDEX i) { if (i == 0) return box_avAxis_0; if (i == 1) return box_avAxis_1; return box_avAxis_2; }
  inline const FLOAT3D& box_avAxis(INDEX i) const { if (i == 0) return box_avAxis_0; if (i == 1) return box_avAxis_1; return box_avAxis_2; }

  inline FLOAT& box_atSize(INDEX i) { if (i == 0) return box_atSize_0; if (i == 1) return box_atSize_1; return box_atSize_2; }
  inline const FLOAT& box_atSize(INDEX i) const { if (i == 0) return box_atSize_0; if (i == 1) return box_atSize_1; return box_atSize_2; }

  inline FLOATobbox3D_* C_Handle() { return mp_handle; }
  inline const FLOATobbox3D_* C_Handle() const { return mp_handle; }
  inline operator FLOATobbox3D_* () { return C_Handle(); }
  inline operator const FLOATobbox3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  FLOATobbox3D_* mp_handle = nullptr;

public:
  FLOAT3D box_vO;          // center of the box
  FLOAT3D box_avAxis_0;    // axis direction vectors
  FLOAT3D box_avAxis_1;
  FLOAT3D box_avAxis_2;
  FLOAT& box_atSize_0;     // size on each of the axis (in both directions)
  FLOAT& box_atSize_1;
  FLOAT& box_atSize_2;
};

class DOUBLEobbox3D
{
public:
  DOUBLEobbox3D(DOUBLEobbox3D_* p, bool owner = false);
  DOUBLEobbox3D();
  DOUBLEobbox3D(const DOUBLE3D& vO,
    const DOUBLE3D& vAxis0, const DOUBLE3D& vAxis1, const DOUBLE3D& vAxis2,
    DOUBLE tSize0, DOUBLE tSize1, DOUBLE tSize2);
  /* Constructor from axis aligned box and placement. */
  DOUBLEobbox3D(const DOUBLEaabbox3D& aabbox,
    const DOUBLE3D& vPos, const DOUBLEmatrix3D& mRot);
  /* Constructor from axis aligned box without placement. */
  DOUBLEobbox3D(const DOUBLEaabbox3D& aabbox);
  DOUBLEobbox3D(const DOUBLEobbox3D& o);
  ~DOUBLEobbox3D();

  DOUBLEobbox3D& operator=(const DOUBLEobbox3D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  // classify box with respect to a plane
  DOUBLE TestAgainstPlane(const DOUBLEplane3D& pl) const;
  // check if two boxes intersect/touch
  BOOL HasContactWith(const DOUBLEobbox3D& boxB) const;

  /* Check if empty. */
  BOOL IsEmpty() const;

  inline DOUBLE3D& box_avAxis(INDEX i) { if (i == 0) return box_avAxis_0; if (i == 1) return box_avAxis_1; return box_avAxis_2; }
  inline const DOUBLE3D& box_avAxis(INDEX i) const { if (i == 0) return box_avAxis_0; if (i == 1) return box_avAxis_1; return box_avAxis_2; }

  inline DOUBLE& box_atSize(INDEX i) { if (i == 0) return box_atSize_0; if (i == 1) return box_atSize_1; return box_atSize_2; }
  inline const DOUBLE& box_atSize(INDEX i) const { if (i == 0) return box_atSize_0; if (i == 1) return box_atSize_1; return box_atSize_2; }

  inline DOUBLEobbox3D_* C_Handle() { return mp_handle; }
  inline const DOUBLEobbox3D_* C_Handle() const { return mp_handle; }
  inline operator DOUBLEobbox3D_* () { return C_Handle(); }
  inline operator const DOUBLEobbox3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  DOUBLEobbox3D_* mp_handle = nullptr;

public:
  DOUBLE3D box_vO;          // center of the box
  DOUBLE3D box_avAxis_0;    // axis direction vectors
  DOUBLE3D box_avAxis_1;
  DOUBLE3D box_avAxis_2;
  DOUBLE& box_atSize_0;     // size on each of the axis (in both directions)
  DOUBLE& box_atSize_1;
  DOUBLE& box_atSize_2;
};

// helper functions for converting between FLOAT and DOUBLE obboxes
DOUBLEobbox3D FLOATtoDOUBLE(const FLOATobbox3D& boxf);
FLOATobbox3D DOUBLEtoFLOAT(const DOUBLEobbox3D& boxd);

#include "OBBox.inl"
