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

inline UBYTE GetValueFromMask(CTerrain& terrain, INDEX iLayer, FLOAT3D vHitPoint)
{
  return GetValueFromMask_(terrain, iLayer, vHitPoint);
}

__forceinline INDEX2D Calculate2dHitPoint(CTerrain& terrain, FLOAT3D& vHitPoint)
{
  return INDEX2D(Calculate2dHitPoint_(terrain, vHitPoint), true);
}
