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
#include <SeriousEngineCAPI/World/WorldRayCasting.h>

class CCastRay
{
public:
  CCastRay(CCastRay_* p, bool owner = false);
  CCastRay(CEntity_* penOrigin, const CPlacement3D& plOrigin); // target is very far away
  CCastRay(CEntity_* penOrigin, const CPlacement3D& plOrigin, FLOAT fMaxTestDistance);
  CCastRay(CEntity_* penOrigin, const FLOAT3D& vOrigin, const FLOAT3D& vTarget);
  CCastRay(const CCastRay& o);
  ~CCastRay();
  CCastRay& operator=(const CCastRay& o);

  // diferent types of testing
  enum TestType : TestType_ {
    TT_NONE = TT_NONE_,                     // do not test at all
    TT_SIMPLE = TT_SIMPLE_,                 // do approximate testing
    TT_COLLISIONBOX = TT_COLLISIONBOX_,     // do testing by collision box
    TT_FULL = TT_FULL_,                     // do full testing
    TT_FULLSEETHROUGH = TT_FULLSEETHROUGH_, // do full testing without entities marked as see through
  };

  /* Do the ray casting. */
  void Cast(CWorld* pwoWorld);
  /* Continue cast. */
  void ContinueCast(CWorld* pwoWorld);

  inline CCastRay_* C_Handle() { return mp_handle; }
  inline const CCastRay_* C_Handle() const { return mp_handle; }
  inline operator CCastRay_* () { return C_Handle(); }
  inline operator const CCastRay_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CCastRay_* mp_handle = nullptr;

public:
  BOOL& cr_bAllowOverHit;   // set if the ray can hit behind its target
  BOOL& cr_bHitPortals;     // don't pass through portals (off by default)
  TestType& cr_ttHitModels; // type of testing against models (simple by default)
  BOOL& cr_bHitFields;      // don't pass thrugh field brushes (off by default)
  BOOL& cr_bHitBrushes;     // don't pass thrugh brushes (on by default)

  // these are filled by casting algorithm:
  CEntity_*& cr_penHit;         // entity hit by ray, NULL if ray was cast in void
  FLOAT3D cr_vHit;              // coordinate where the ray hit the entity
  CBrushPolygon_*& cr_pbpoBrushPolygon; // polygon that was hit (if brush entity hit)
  CBrushSector_*& cr_pbscBrushSector;   // sector that was hit (if brush entity hit)
};

#include "WorldRayCasting.inl"
