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
#include "ArrayHolder.h"
#include <SeriousEngineCAPI/Terrain/TerrainTile.h>

class CTerrainTile
{
public:
  CTerrainTile(CTerrainTile_* p, bool owner = false);
  CTerrainTile();
  CTerrainTile(const CTerrainTile& o);
  ~CTerrainTile();
  CTerrainTile& operator=(const CTerrainTile& o);

  // Render tile
  void Render();
  // Regenerate tile
  void ReGenerate();
  // Regenerate tile layer 
  void ReGenerateTileLayer(INDEX iTileLayer);
  // Release tile
  void Clear();
  // Terrain tile flags handling
  inline ULONG& GetFlags() { return tt_ulTileFlags; }
  inline void SetFlags(ULONG ulFlags) { tt_ulTileFlags = ulFlags; }
  inline void AddFlag(ULONG ulFlag) { tt_ulTileFlags |= ulFlag; }
  inline void RemoveFlag(ULONG ulFlag) { tt_ulTileFlags &= ~ulFlag; }

  CStaticStackArray_GFXVertex4 GetVertices();
  CStaticStackArray_GFXTexCoord GetTexCoords();
  CStaticStackArray_GFXTexCoord GetShadowMapTC();
  CStaticStackArray_GFXTexCoord GetDetailTC();
  CStaticStackArray_INDEX GetIndices();
  CStaticStackArray_TileLayer GetTileLayers();
  CTextureDataPtr GetTopMap();

  INDEX ChangeTileArrays(INDEX iRequestedArrayLod);
  void ReleaseTileArrays();
  void EmptyTileArrays();

  // Calculate lod of tile 
  INDEX CalculateLOD();
  // Update quad tree node
  void UpdateQuadTreeNode();
  // Count used memory
  SLONG GetUsedMemory();

  void AddTriangle(INDEX iind1, INDEX iind2, INDEX iind3);
  void AddVertex(INDEX ic, INDEX ir);
  void LerpVertexPos(GFXVertex4& vtx, INDEX iVxTarget, INDEX iVxFirst, INDEX iVxLast);

  INDEX& tt_aiNeighbours(INDEX i); // Array of tile neighbours
  INDEX& tt_iFirstBorderVertex(INDEX i);// Index of first border vertex inserted
  INDEX& tt_ctBorderVertices(INDEX i);  // Number of vertices inserted for each border

  inline CTerrainTile_* C_Handle() { return mp_handle; }
  inline const CTerrainTile_* C_Handle() const { return mp_handle; }
  inline operator CTerrainTile_* () { return C_Handle(); }
  inline operator const CTerrainTile_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTerrainTile_* mp_handle = nullptr;

public:
  INDEX& tt_ctVtxX;    // Number of vertices in row 
  INDEX& tt_ctVtxY;    // Number of vertices in col
  INDEX& tt_ctLodVtxX; // Number of vertices in row for current lod
  INDEX& tt_ctLodVtxY; // Number of vertices in col for current lod

  INDEX& tt_iIndex;    // Index of this tile 
  INDEX& tt_iLod;      // Current lod of tile
  INDEX& tt_iRequestedLod;   // Requested lod for tile
  INDEX& tt_iArrayIndex;     // Index of array holder this tile uses

  FLOAT& tt_fLodLerpFactor;  // Lod lerp factor
  ULONG& tt_ulTileFlags;
  BOOL&  tt_bUseOnlyGlobalTopMap; // Allways use global top map

  INDEX& tt_iOffsetX;  // Offset of this tile in world
  INDEX& tt_iOffsetZ;  // Offset of this tile in world
};

#include "TerrainTile.inl"
