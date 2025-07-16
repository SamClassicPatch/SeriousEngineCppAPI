#pragma once

__forceinline FLOAT3D avGouraudNormals(INDEX i)
{
  return FLOAT3D(avGouraudNormals_(i), false);
}

inline INDEX GouraudNormal(const FLOAT3D& vNormal)
{
  return GouraudNormal_(vNormal);
}

inline void CompressNormal_HQ(const FLOAT3D& vNormal, UBYTE& ubH, UBYTE& ubP)
{
  CompressNormal_HQ_(vNormal, &ubH, &ubP);
}

inline void DecompressNormal_HQ(FLOAT3D& vNormal, UBYTE ubH, UBYTE ubP)
{
  DecompressNormal_HQ_(vNormal, ubH, ubP);
}
