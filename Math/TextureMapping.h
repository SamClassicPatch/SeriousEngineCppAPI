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
#include "../Base/Stream.h"
#include "Vector.h"
#include "Plane.h"
#include "Placement.h"
#include <SeriousEngineCAPI/Math/TextureMapping.h>

/* General coordinate naming notes:
 * s,t are texture coordinates in default mapping on a plane
 *   +s=right
 *   +t=down
 * u,v are texture coordinates in mapping on a polygon
 *   +u=right
 *   +v=down
 * i,j are coordinates on screen
 *   +i=right
 *   +j=down
 * k is distance from screen normalized to be in interval [1,+inf>
 *   +1= near clip plane
 *   +inf= far away (infinity) (not normalized to far clip plane!)
 * x,y,z are coordinates in 3D
 *   +x=right
 *   +y=up
 *   -z=front
 */

 /*
  * Gradients for a variable lineary interpolated along the screen.
  */
class CPlanarGradients
{
public:
  CPlanarGradients(CPlanarGradients_* p, bool owner = false);
  CPlanarGradients();
  CPlanarGradients(const CPlanarGradients& o);
  ~CPlanarGradients();

  CPlanarGradients& operator=(const CPlanarGradients& o);

  // calculate value at some point on screen (i,j)
  FLOAT GetValue(FLOAT fI, FLOAT fJ);
  // set constant gradients
  void Constant(FLOAT fConst);
  // multiply gradients by given factor
  void Multiply(FLOAT fMul);
  // add given constant to gradients
  void Add(FLOAT fAdd);
  // translate gradients in screen space
  void TranslateOnScreen(FLOAT fI, FLOAT fJ);

  inline CPlanarGradients_* C_Handle() { return mp_handle; }
  inline const CPlanarGradients_* C_Handle() const { return mp_handle; }
  inline operator CPlanarGradients_* () { return C_Handle(); }
  inline operator const CPlanarGradients_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CPlanarGradients_* mp_handle = nullptr;

public:
  FLOAT& pg_f00;       // value at upper left corner
  FLOAT& pg_fDOverDI;  // horizontal gradient
  FLOAT& pg_fDOverDJ;  // vertical gradient
};

/*
 * Description of texture mapping on a polygon relative to default mapping for its plane,
 * version used to communicating information to user.
 */
class CMappingDefinitionUI
{
public:
  CMappingDefinitionUI(CMappingDefinitionUI_* p, bool owner = false);
  CMappingDefinitionUI();
  CMappingDefinitionUI(const CMappingDefinitionUI& o);
  ~CMappingDefinitionUI();

  CMappingDefinitionUI& operator=(const CMappingDefinitionUI& o);

  inline CMappingDefinitionUI_* C_Handle() { return mp_handle; }
  inline const CMappingDefinitionUI_* C_Handle() const { return mp_handle; }
  inline operator CMappingDefinitionUI_* () { return C_Handle(); }
  inline operator const CMappingDefinitionUI_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CMappingDefinitionUI_* mp_handle = nullptr;

public:
  ANGLE& mdui_aURotation;// rotation angle of u axis from s axis
  ANGLE& mdui_aVRotation;// rotation angle of v axis from t axis
  FLOAT& mdui_fUStretch; // stretch in u direction
  FLOAT& mdui_fVStretch; // stretch in v direction
  FLOAT& mdui_fUOffset;  // offset in u direction
  FLOAT& mdui_fVOffset;  // offset in v direction
};

/*
 * Vectors defining a transformed mapping on a plane.
 */
class CMappingVectors
{
public:
  CMappingVectors(CMappingVectors_* p, bool owner = false);
  CMappingVectors();
  CMappingVectors(const CMappingVectors& o);
  ~CMappingVectors();

  CMappingVectors& operator=(const CMappingVectors& o);

  // calculate default texture mapping control points from a plane
  void FromPlane(const FLOATplane3D& plPlane);
  void FromPlane_DOUBLE(const DOUBLEplane3D& plPlane);
  // calculate plane from default mapping vectors
  void ToPlane(FLOATplane3D& plPlane) const;

  inline CMappingVectors_* C_Handle() { return mp_handle; }
  inline const CMappingVectors_* C_Handle() const { return mp_handle; }
  inline operator CMappingVectors_* () { return C_Handle(); }
  inline operator const CMappingVectors_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CMappingVectors_* mp_handle = nullptr;

public:
  FLOAT3D mv_vO;  // origin
  FLOAT3D mv_vU;  // u axis direction
  FLOAT3D mv_vV;  // v axis direction
};

/*
 * Description of texture mapping on a polygon relative to default mapping for its plane.
 */
class CMappingDefinition
{
public:
  CMappingDefinition(CMappingDefinition_* p, bool owner = false);
  CMappingDefinition();
  CMappingDefinition(const CMappingDefinition& o);
  ~CMappingDefinition();

  CMappingDefinition& operator=(const CMappingDefinition& o);

  // convert to human-friendly format
  void ToUI(CMappingDefinitionUI& mdui) const;
  // convert from human-friendly format
  void FromUI(const CMappingDefinitionUI& mdui);

  // convert to mapping vectors
  void ToMappingVectors(const CMappingVectors& mvDefault, CMappingVectors& mvVectors) const;
  // convert from mapping vectors
  void FromMappingVectors(const CMappingVectors& mvDefault, const CMappingVectors& mvVectors);
  // make mapping vectors for this mapping
  void MakeMappingVectors(const CMappingVectors& mvSrc, CMappingVectors& mvDst) const;
  // transform default mapping vectors to mapping vectors for this mapping
  void TransformMappingVectors(const CMappingVectors& mvSrc, CMappingVectors& mvDst) const;

  // project another mapping on this one
  void ProjectMapping(const FLOATplane3D& plOriginal, const CMappingDefinition& mdOriginal,
    const FLOATplane3D& pl);

  // translate mapping in 3D
  void Translate(const CMappingVectors& mvDefault, const FLOAT3D& vTranslation);
  // rotate mapping in 3D
  void Rotate(const CMappingVectors& mvDefault, const FLOAT3D& vRotationOrigin, ANGLE aRotation);
  // center mapping to given point in 3D
  void Center(const CMappingVectors& mvDefault, const FLOAT3D& vNewOrigin);
  // transform mapping from one placement to another
  void Transform(const FLOATplane3D& plPlane,
    const CPlacement3D& plSource, const CPlacement3D& plTarget);

  // find texture coordinates for an object-space point
  void GetTextureCoordinates(
    const CMappingVectors& mvDefault, const FLOAT3D& vSpace, MEX2D& vTexture) const;
  FLOAT2D GetTextureCoordinates(const CMappingVectors& mvDefault, const FLOAT3D& vSpace) const;
  // find object-space coordinates for a texture point
  void GetSpaceCoordinates(
    const CMappingVectors& mvDefault, const MEX2D& vTexture, FLOAT3D& vSpace) const;

  inline CMappingDefinition_* C_Handle() { return mp_handle; }
  inline const CMappingDefinition_* C_Handle() const { return mp_handle; }
  inline operator CMappingDefinition_* () { return C_Handle(); }
  inline operator const CMappingDefinition_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CMappingDefinition_* mp_handle = nullptr;

public:
  FLOAT& md_fUoS; // u vector relative to default mapping
  FLOAT& md_fUoT;
  FLOAT& md_fVoS; // v vector relative to default mapping
  FLOAT& md_fVoT;
  FLOAT& md_fUOffset;  // offset in u direction
  FLOAT& md_fVOffset;  // offset in v direction
};

// stream operations
CTStream& operator>>(CTStream& strm, CMappingDefinition& md);  // throw char *
CTStream& operator<<(CTStream& strm, const CMappingDefinition& md);  // throw char *

#include "TextureMapping.inl"
