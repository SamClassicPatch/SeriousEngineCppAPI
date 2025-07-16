#pragma once
#include "../Base/Types.h"
#include "../Math/Vector.h"
#include <SeriousEngineCAPI/Models/Normals.h>

FLOAT3D avGouraudNormals(INDEX i);

INDEX GouraudNormal(const FLOAT3D& vNormal);
void CompressNormal_HQ(const FLOAT3D& vNormal, UBYTE& ubH, UBYTE& ubP);
void DecompressNormal_HQ(FLOAT3D& vNormal, UBYTE ubH, UBYTE ubP);

#include "Normals.inl"
