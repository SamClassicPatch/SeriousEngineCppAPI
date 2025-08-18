#pragma once
#include "../Base/Types.h"
#include "Terrain.h"
#include <SeriousEngineCAPI/Terrain/TerrainMisc.h>

// Get value from layer at given point
UBYTE GetValueFromMask(CTerrain& terrain, INDEX iLayer, FLOAT3D vHitPoint);
// Calculate 2d relative point in terrain from absolute 3d point in world
INDEX2D Calculate2dHitPoint(CTerrain& terrain, FLOAT3D& vHitPoint);

#include "TerrainMisc.inl"
