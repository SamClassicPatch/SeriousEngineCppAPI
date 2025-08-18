#pragma once

inline CShadingInfo::CShadingInfo(CShadingInfo_* p)
  : mp_handle(p)
  , si_pbpoPolygon(*CShadingInfo_si_pbpoPolygon(mp_handle))
  , si_ptrTerrain(*CShadingInfo_si_ptrTerrain(mp_handle))
  , si_vNearPoint(CShadingInfo_si_vNearPoint(mp_handle), false)
  , si_pixShadowU(*CShadingInfo_si_pixShadowU(mp_handle))
  , si_pixShadowV(*CShadingInfo_si_pixShadowV(mp_handle))
  , si_fUDRatio(*CShadingInfo_si_fUDRatio(mp_handle))
  , si_fLRRatio(*CShadingInfo_si_fLRRatio(mp_handle))
  , si_penEntity(*CShadingInfo_si_penEntity(mp_handle))
{
}
