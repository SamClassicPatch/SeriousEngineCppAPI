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
#include "../Math/Vector.h"
#include <SeriousEngineCAPI/Models/Normals.h>

FLOAT3D avGouraudNormals(INDEX i);

INDEX GouraudNormal(const FLOAT3D& vNormal);
void CompressNormal_HQ(const FLOAT3D& vNormal, UBYTE& ubH, UBYTE& ubP);
void DecompressNormal_HQ(FLOAT3D& vNormal, UBYTE ubH, UBYTE ubP);

#include "Normals.inl"
