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

inline CCastRay::CCastRay(CEntity* penOrigin, const CPlacement3D& plOrigin)
  : CCastRay(CCastRay_new_pl(penOrigin ? penOrigin->C_Handle() : nullptr, plOrigin), true)
{
}

inline CCastRay::CCastRay(CEntity* penOrigin, const CPlacement3D& plOrigin, FLOAT fMaxTestDistance)
  : CCastRay(CCastRay_new_plf(penOrigin ? penOrigin->C_Handle() : nullptr, plOrigin, fMaxTestDistance), true)
{
}

inline CCastRay::CCastRay(CEntity* penOrigin, const FLOAT3D& vOrigin, const FLOAT3D& vTarget)
  : CCastRay(CCastRay_new_vv(penOrigin ? penOrigin->C_Handle() : nullptr, vOrigin, vTarget), true)
{
}

inline CCastRay::~CCastRay()
{
  if (m_owner)
    CCastRay_delete(mp_handle);
}
