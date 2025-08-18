#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Entities/ShadingInfo.h>

class CShadingInfo
{
public:
  explicit CShadingInfo(CShadingInfo_* p);

  inline CShadingInfo_* C_Handle() { return mp_handle; }
  inline const CShadingInfo_* C_Handle() const { return mp_handle; }
  inline operator CShadingInfo_* () { return C_Handle(); }
  inline operator const CShadingInfo_* () const { return C_Handle(); }

private:
  CShadingInfo_* mp_handle = nullptr;

public:
  CBrushPolygon_*& si_pbpoPolygon; // the polygon that entity is above
  CTerrain_*& si_ptrTerrain; // terrain that entity is above
  FLOAT3D si_vNearPoint; // the relevant point in absolute space
  PIX& si_pixShadowU; // the relevant point in the polygon shadow map
  PIX& si_pixShadowV;
  FLOAT& si_fUDRatio; // fraction between pixels
  FLOAT& si_fLRRatio;
  CEntity_*& si_penEntity; // the entity which uses this shading info
};

#include "ShadingInfo.inl"
