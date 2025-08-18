#pragma once

inline UBYTE GetValueFromMask(CTerrain& terrain, INDEX iLayer, FLOAT3D vHitPoint)
{
  return GetValueFromMask_(terrain, iLayer, vHitPoint);
}

__forceinline INDEX2D Calculate2dHitPoint(CTerrain& terrain, FLOAT3D& vHitPoint)
{
  return INDEX2D(Calculate2dHitPoint_(terrain, vHitPoint), true);
}
