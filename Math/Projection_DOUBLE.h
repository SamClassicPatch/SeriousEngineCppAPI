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
#include "Vector.h"
#include "Plane.h"
#include "AABBox.h"
#include "Placement.h"
#include "TextureMapping.h"

/*
 * Geometric projection of one 3D space onto another 3D space
 */
class CSimpleProjection3D_DOUBLE
{
public:
  CSimpleProjection3D_DOUBLE(CSimpleProjection3D_DOUBLE_* p, bool owner = false);
  CSimpleProjection3D_DOUBLE();
  CSimpleProjection3D_DOUBLE(const CSimpleProjection3D_DOUBLE& o);
  ~CSimpleProjection3D_DOUBLE();
  CSimpleProjection3D_DOUBLE& operator=(const CSimpleProjection3D_DOUBLE& o);

  // member referencing
  /* Reference viewer placement. */
  inline CPlacement3D& ViewerPlacementL() {
    return pr_ViewerPlacement;
  }
  inline const CPlacement3D& ViewerPlacementR() const {
    return pr_ViewerPlacement;
  }

  /* Reference object placement. */
  inline CPlacement3D& ObjectPlacementL() {
    return pr_ObjectPlacement;
  }
  inline const CPlacement3D& ObjectPlacementR() const {
    return pr_ObjectPlacement;
  }
  /* Reference target object stretching. */
  inline FLOAT3D& ObjectStretchL() {
    return pr_ObjectStretch;
  }
  inline const FLOAT3D& ObjectStretchR() const {
    return pr_ObjectStretch;
  }

  /* Prepare for projecting. */
  void Prepare();

  /* Project 3D object point into 3D view space. */
  void ProjectCoordinate(const DOUBLE3D& v3dObjectPoint, DOUBLE3D& v3dViewPoint) const;
  /* Project 3D object direction vector into 3D view space. */
  void ProjectDirection(const DOUBLE3D& v3dObjectPoint, DOUBLE3D& v3dViewPoint) const;
  /* Project 3D object placement into 3D view space. */
  void ProjectPlacement(const CPlacement3D& plObject, CPlacement3D& plView) const;
  /* Project 3D object mapping into 3D view space. */
  void ProjectMapping(const CMappingDefinition& mdObject, const DOUBLEplane3D& plObject,
    CMappingDefinition& mdView) const;
  /* Project 3D object axis aligned bounding box into 3D view space. */
  void ProjectAABBox(const DOUBLEaabbox3D& boxObject, DOUBLEaabbox3D& boxView) const;
  /* Project 3D object plane into 3D view space. */
  void Project(const DOUBLEplane3D& p3dObjectPlane, DOUBLEplane3D& v3dTransformedPlane) const;

  inline CSimpleProjection3D_DOUBLE_* C_Handle() { return mp_handle; }
  inline const CSimpleProjection3D_DOUBLE_* C_Handle() const { return mp_handle; }
  inline operator CSimpleProjection3D_DOUBLE_* () { return C_Handle(); }
  inline operator const CSimpleProjection3D_DOUBLE_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CSimpleProjection3D_DOUBLE_* mp_handle = nullptr;

public:
  // factors set by user
  CPlacement3D pr_ObjectPlacement;  // placement of the projected object
  CPlacement3D pr_ViewerPlacement;  // placement of the viewer
  FLOAT3D pr_ObjectStretch;         // stretching coeficients for target object space

  // internal variables
  BOOL& pr_Prepared;                  // set if all precalculated variables are prepared
  DOUBLEmatrix3D pr_RotationMatrix;  // matrix for rotating when projecting
  DOUBLEmatrix3D pr_ViewerRotationMatrix;  // viewer part of rotation matrix
  DOUBLE3D pr_TranslationVector;     // vector for translating when projecting
};

#include "Projection_DOUBLE.inl"
