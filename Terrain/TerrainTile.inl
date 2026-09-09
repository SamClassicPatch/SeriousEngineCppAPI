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

inline CTerrainTile::CTerrainTile(CTerrainTile_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tt_ctVtxX(*CTerrainTile_tt_ctVtxX(mp_handle))
  , tt_ctVtxY(*CTerrainTile_tt_ctVtxY(mp_handle))
  , tt_ctLodVtxX(*CTerrainTile_tt_ctLodVtxX(mp_handle))
  , tt_ctLodVtxY(*CTerrainTile_tt_ctLodVtxY(mp_handle))
  , tt_iIndex(*CTerrainTile_tt_iIndex(mp_handle))
  , tt_iLod(*CTerrainTile_tt_iLod(mp_handle))
  , tt_iRequestedLod(*CTerrainTile_tt_iRequestedLod(mp_handle))
  , tt_iArrayIndex(*CTerrainTile_tt_iArrayIndex(mp_handle))
  , tt_fLodLerpFactor(*CTerrainTile_tt_fLodLerpFactor(mp_handle))
  , tt_ulTileFlags(*CTerrainTile_tt_ulTileFlags(mp_handle))
  , tt_bUseOnlyGlobalTopMap(*CTerrainTile_tt_bUseOnlyGlobalTopMap(mp_handle))
  , tt_iOffsetX(*CTerrainTile_tt_iOffsetX(mp_handle))
  , tt_iOffsetZ(*CTerrainTile_tt_iOffsetZ(mp_handle))
{
}

inline CTerrainTile::CTerrainTile()
  : CTerrainTile(CTerrainTile_new(), true)
{
}

inline CTerrainTile::CTerrainTile(const CTerrainTile& o)
  : CTerrainTile(CTerrainTile_clone(o), true)
{
}

inline CTerrainTile::~CTerrainTile()
{
  if (m_owner)
    CTerrainTile_delete(mp_handle);
}

inline CTerrainTile& CTerrainTile::operator=(const CTerrainTile& o)
{
  CTerrainTile_copy(mp_handle, o);
  return *this;
}

inline void CTerrainTile::Render()
{
  CTerrainTile_Render(mp_handle);
}

inline void CTerrainTile::ReGenerate()
{
  CTerrainTile_ReGenerate(mp_handle);
}

inline void CTerrainTile::ReGenerateTileLayer(INDEX iTileLayer)
{
  CTerrainTile_ReGenerateTileLayer(mp_handle, iTileLayer);
}

inline void CTerrainTile::Clear()
{
  CTerrainTile_Clear(mp_handle);
}

__forceinline CStaticStackArray_GFXVertex4 CTerrainTile::GetVertices()
{
  return CStaticStackArray_GFXVertex4(CTerrainTile_GetVertices(mp_handle), false);
}

__forceinline CStaticStackArray_GFXTexCoord CTerrainTile::GetTexCoords()
{
  return CStaticStackArray_GFXTexCoord(CTerrainTile_GetTexCoords(mp_handle), false);
}

__forceinline CStaticStackArray_GFXTexCoord CTerrainTile::GetShadowMapTC()
{
  return CStaticStackArray_GFXTexCoord(CTerrainTile_GetShadowMapTC(mp_handle), false);
}

__forceinline CStaticStackArray_GFXTexCoord CTerrainTile::GetDetailTC()
{
  return CStaticStackArray_GFXTexCoord(CTerrainTile_GetDetailTC(mp_handle), false);
}

__forceinline CStaticStackArray_INDEX CTerrainTile::GetIndices()
{
  return CStaticStackArray_INDEX(CTerrainTile_GetIndices(mp_handle), false);
}

__forceinline CStaticStackArray_TileLayer CTerrainTile::GetTileLayers()
{
  return CStaticStackArray_TileLayer(CTerrainTile_GetTileLayers(mp_handle), false);
}

__forceinline CTextureDataPtr CTerrainTile::GetTopMap()
{
  return CTextureDataPtr(CTerrainTile_GetTopMap(mp_handle));
}

inline INDEX CTerrainTile::ChangeTileArrays(INDEX iRequestedArrayLod)
{
  return CTerrainTile_ChangeTileArrays(mp_handle, iRequestedArrayLod);
}

inline void CTerrainTile::ReleaseTileArrays()
{
  CTerrainTile_ReleaseTileArrays(mp_handle);
}

inline void CTerrainTile::EmptyTileArrays()
{
  CTerrainTile_EmptyTileArrays(mp_handle);
}

inline INDEX CTerrainTile::CalculateLOD()
{
  return CTerrainTile_CalculateLOD(mp_handle);
}

inline void CTerrainTile::UpdateQuadTreeNode()
{
  CTerrainTile_UpdateQuadTreeNode(mp_handle);
}

inline SLONG CTerrainTile::GetUsedMemory()
{
  return CTerrainTile_GetUsedMemory(mp_handle);
}

inline void CTerrainTile::AddTriangle(INDEX iind1, INDEX iind2, INDEX iind3)
{
  CTerrainTile_AddTriangle(mp_handle, iind1, iind2, iind3);
}

inline void CTerrainTile::AddVertex(INDEX ic, INDEX ir)
{
  CTerrainTile_AddVertex(mp_handle, ic, ir);
}

inline void CTerrainTile::LerpVertexPos(GFXVertex4& vtx, INDEX iVxTarget, INDEX iVxFirst, INDEX iVxLast)
{
  CTerrainTile_LerpVertexPos(mp_handle, vtx, iVxTarget, iVxFirst, iVxLast);
}

inline INDEX& CTerrainTile::tt_aiNeighbours(INDEX i)
{
  return *CTerrainTile_tt_aiNeighbours(mp_handle, i);
}

inline INDEX& CTerrainTile::tt_iFirstBorderVertex(INDEX i)
{
  return *CTerrainTile_tt_iFirstBorderVertex(mp_handle, i);
}

inline INDEX& CTerrainTile::tt_ctBorderVertices(INDEX i)
{
  return *CTerrainTile_tt_ctBorderVertices(mp_handle, i);
}
