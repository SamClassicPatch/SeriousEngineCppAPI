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

inline CCastRay::CCastRay(CCastRay_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , cr_bAllowOverHit(*CCastRay_cr_bAllowOverHit(p))
  , cr_bHitPortals(*CCastRay_cr_bHitPortals(p))
  , cr_ttHitModels(*((TestType*)CCastRay_cr_ttHitModels(p)))
  , cr_bHitFields(*CCastRay_cr_bHitFields(p))
  , cr_bHitBrushes(*CCastRay_cr_bHitBrushes(p))
  , cr_penHit(*CCastRay_cr_penHit(p))
  , cr_vHit(CCastRay_cr_vHit(p), false)
  , cr_pbpoBrushPolygon(*CCastRay_cr_pbpoBrushPolygon(p))
  , cr_pbscBrushSector(*CCastRay_cr_pbscBrushSector(p))
{
}

inline CCastRay::CCastRay(CEntity_* penOrigin, const CPlacement3D& plOrigin)
  : CCastRay(CCastRay_new_pl(penOrigin, plOrigin), true)
{
}

inline CCastRay::CCastRay(CEntity_* penOrigin, const CPlacement3D& plOrigin, FLOAT fMaxTestDistance)
  : CCastRay(CCastRay_new_plf(penOrigin, plOrigin, fMaxTestDistance), true)
{
}

inline CCastRay::CCastRay(CEntity_* penOrigin, const FLOAT3D& vOrigin, const FLOAT3D& vTarget)
  : CCastRay(CCastRay_new_vv(penOrigin, vOrigin, vTarget), true)
{
}

inline CCastRay::CCastRay(const CCastRay& o)
  : CCastRay(CCastRay_clone(o), true)
{
}

inline CCastRay::~CCastRay()
{
  if (m_owner)
    CCastRay_delete(mp_handle);
}

inline CCastRay& CCastRay::operator=(const CCastRay& o)
{
  CCastRay_copy(mp_handle, o);
  return *this;
}
