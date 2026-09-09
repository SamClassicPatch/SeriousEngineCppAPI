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

inline QuadTreeNode::QuadTreeNode(QuadTreeNode_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , qtn_aabbox(QuadTreeNode_qtn_aabbox(mp_handle), false)
  , qtn_iTileIndex(*QuadTreeNode_qtn_iTileIndex(mp_handle))
{
}

inline QuadTreeNode::QuadTreeNode()
  : QuadTreeNode(QuadTreeNode_new(), true)
{
}

inline QuadTreeNode::QuadTreeNode(const QuadTreeNode& o)
  : QuadTreeNode(QuadTreeNode_clone(o), true)
{
}

inline QuadTreeNode::~QuadTreeNode()
{
  if (m_owner)
    QuadTreeNode_delete(mp_handle);
}

inline QuadTreeNode& QuadTreeNode::operator=(const QuadTreeNode& o)
{
  QuadTreeNode_copy(mp_handle, o);
  return *this;
}

inline INDEX& QuadTreeNode::qtn_iChild(INDEX i)
{
  return *QuadTreeNode_qtn_iChild(mp_handle, i);
}

inline QuadTreeLevel::QuadTreeLevel(QuadTreeLevel_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , qtl_iFirstNode(*QuadTreeLevel_qtl_iFirstNode(mp_handle))
  , qtl_ctNodes(*QuadTreeLevel_qtl_ctNodes(mp_handle))
  , qtl_ctNodesCol(*QuadTreeLevel_qtl_ctNodesCol(mp_handle))
  , qtl_ctNodesRow(*QuadTreeLevel_qtl_ctNodesRow(mp_handle))
{
}

inline QuadTreeLevel::QuadTreeLevel()
  : QuadTreeLevel(QuadTreeLevel_new(), true)
{
}

inline QuadTreeLevel::QuadTreeLevel(const QuadTreeLevel& o)
  : QuadTreeLevel(QuadTreeLevel_clone(o), true)
{
}

inline QuadTreeLevel::~QuadTreeLevel()
{
  if (m_owner)
    QuadTreeLevel_delete(mp_handle);
}

inline QuadTreeLevel& QuadTreeLevel::operator=(const QuadTreeLevel& o)
{
  QuadTreeLevel_copy(mp_handle, o);
  return *this;
}

inline Rect::Rect(Rect_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , rc_iLeft(*Rect_rc_iLeft(mp_handle))
  , rc_iRight(*Rect_rc_iRight(mp_handle))
  , rc_iTop(*Rect_rc_iTop(mp_handle))
  , rc_iBottom(*Rect_rc_iBottom(mp_handle))
{
}

inline Rect::Rect()
  : Rect(Rect_new(), true)
{
}

inline Rect::Rect(INDEX iLeft, INDEX iTop, INDEX iRight, INDEX iBottom)
  : Rect(Rect_new_i(iLeft, iTop, iRight, iBottom), true)
{
}

inline Rect::Rect(const Rect& o)
  : Rect(Rect_clone(o), true)
{
}

inline Rect::~Rect()
{
  if (m_owner)
    Rect_delete(mp_handle);
}

inline Rect& Rect::operator=(const Rect& o)
{
  Rect_copy(mp_handle, o);
  return *this;
}

inline INDEX Rect::Width()
{
  return Rect_Width(mp_handle);
}

inline INDEX Rect::Height()
{
  return Rect_Height(mp_handle);
}

IMPL_CStaticArray(QuadTreeNode)
IMPL_CStaticArray(QuadTreeLevel)
IMPL_CStaticArray(CTerrainTile)
IMPL_CStaticArray(CArrayHolder)
IMPL_CStaticArray(CTerrainLayer)

IMPL_CStaticStackArray(QuadTreeNode)
IMPL_CStaticStackArray(QuadTreeLevel)
IMPL_CStaticStackArray(CTerrainLayer)

inline CTerrain::CTerrain(CTerrain_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tr_penEntity(*CTerrain_tr_penEntity(mp_handle))
  , tr_ctTiles(*CTerrain_tr_ctTiles(mp_handle))
  , tr_ctTilesX(*CTerrain_tr_ctTilesX(mp_handle))
  , tr_ctTilesY(*CTerrain_tr_ctTilesY(mp_handle))
  , tr_iMaxTileLod(*CTerrain_tr_iMaxTileLod(mp_handle))
  , tr_vStretch(CTerrain_tr_vStretch(mp_handle), false)
  , tr_fDistFactor(*CTerrain_tr_fDistFactor(mp_handle))
  , tr_aqtnQuadTreeNodes(CTerrain_tr_aqtnQuadTreeNodes(mp_handle), false)
  , tr_aqtlQuadTreeLevels(CTerrain_tr_aqtlQuadTreeLevels(mp_handle), false)
  , tr_attTiles(CTerrain_tr_attTiles(mp_handle), false)
  , tr_aArrayHolders(CTerrain_tr_aArrayHolders(mp_handle), false)
  , tr_atlLayers(CTerrain_tr_atlLayers(mp_handle), false)
  , tr_atdTopMaps(CTerrain_tr_atdTopMaps(mp_handle), false)
  , tr_auiRegenList(CTerrain_tr_auiRegenList(mp_handle), false)
  , tr_auwHeightMap(*CTerrain_tr_auwHeightMap(mp_handle))
  , tr_auwShadingMap(*CTerrain_tr_auwShadingMap(mp_handle))
  , tr_aubEdgeMap(*CTerrain_tr_aubEdgeMap(mp_handle))
  , tr_tdTopMap(CTerrain_tr_tdTopMap(mp_handle), false)
  , tr_tdShadowMap(CTerrain_tr_tdShadowMap(mp_handle), false)
  , tr_ptdDetailMap(*CTerrain_tr_ptdDetailMap(mp_handle))
  , tr_pixHeightMapWidth(*CTerrain_tr_pixHeightMapWidth(mp_handle))
  , tr_pixHeightMapHeight(*CTerrain_tr_pixHeightMapHeight(mp_handle))
  , tr_pixTopMapWidth(*CTerrain_tr_pixTopMapWidth(mp_handle))
  , tr_pixTopMapHeight(*CTerrain_tr_pixTopMapHeight(mp_handle))
  , tr_pixFirstMipTopMapWidth(*CTerrain_tr_pixFirstMipTopMapWidth(mp_handle))
  , tr_pixFirstMipTopMapHeight(*CTerrain_tr_pixFirstMipTopMapHeight(mp_handle))
  , tr_iShadowMapSizeAspect(*CTerrain_tr_iShadowMapSizeAspect(mp_handle))
  , tr_iShadingMapSizeAspect(*CTerrain_tr_iShadingMapSizeAspect(mp_handle))
  , tr_ctQuadsInTileRow(*CTerrain_tr_ctQuadsInTileRow(mp_handle))
  , tr_ctVerticesInTileRow(*CTerrain_tr_ctVerticesInTileRow(mp_handle))
  , tr_ulTerrainFlags(*CTerrain_tr_ulTerrainFlags(mp_handle))
  , tr_vTerrainSize(CTerrain_tr_vTerrainSize(mp_handle), false)
  , tr_iSelectedLayer(*CTerrain_tr_iSelectedLayer(mp_handle))
{
}

inline CTerrain::CTerrain()
  : CTerrain(CTerrain_new(), true)
{
}

inline CTerrain::~CTerrain()
{
  if (m_owner)
    CTerrain_delete(mp_handle);
}

inline void CTerrain::Render(CAnyProjection3D& apr, CDrawPort& pdp)
{
  CTerrain_Render(mp_handle, apr, pdp);
}

inline void CTerrain::RenderWireFrame(CAnyProjection3D& apr, CDrawPort& pdp, COLOR colEdges)
{
  CTerrain_RenderWireFrame(mp_handle, apr, pdp, colEdges);
}

inline void CTerrain::CreateEmptyTerrain_t(PIX pixWidth, PIX pixHeight)
{
  CTerrain_CreateEmptyTerrain_t(mp_handle, pixWidth, pixHeight);
  SECppAPI_CheckException();
}

inline void CTerrain::ImportHeightMap_t(CTFileName fnHeightMap, BOOL bUse16b)
{
  CTerrain_ImportHeightMap_t(mp_handle, fnHeightMap, bUse16b);
  SECppAPI_CheckException();
}

inline void CTerrain::ExportHeightMap_t(CTFileName fnHeightMap, BOOL bUse16b)
{
  CTerrain_ExportHeightMap_t(mp_handle, fnHeightMap, bUse16b);
  SECppAPI_CheckException();
}

inline void CTerrain::ReBuildTerrain(BOOL bDelayTileRegen)
{
  CTerrain_ReBuildTerrain(mp_handle, bDelayTileRegen);
}

inline void CTerrain::RefreshTerrain()
{
  CTerrain_RefreshTerrain(mp_handle);
}

inline void CTerrain::AllocateHeightMap(PIX pixWidth, PIX pixHeight)
{
  CTerrain_AllocateHeightMap(mp_handle, pixWidth, pixHeight);
}

inline void CTerrain::ReAllocateHeightMap(PIX pixWidth, PIX pixHeight)
{
  CTerrain_ReAllocateHeightMap(mp_handle, pixWidth, pixHeight);
}

inline void CTerrain::SetTerrainSize(FLOAT3D vSize)
{
  CTerrain_SetTerrainSize(mp_handle, vSize);
}

inline void CTerrain::SetShadowMapsSize(INDEX iShadowMapAspect, INDEX iShadingMapAspect)
{
  CTerrain_SetShadowMapsSize(mp_handle, iShadowMapAspect, iShadingMapAspect);
}

inline void CTerrain::SetGlobalTopMapSize(PIX pixTopMapSize)
{
  CTerrain_SetGlobalTopMapSize(mp_handle, pixTopMapSize);
}

inline void CTerrain::SetTileTopMapSize(PIX pixLodTopMapSize)
{
  CTerrain_SetTileTopMapSize(mp_handle, pixLodTopMapSize);
}

inline void CTerrain::SetLodDistanceFactor(FLOAT fLodDistance)
{
  CTerrain_SetLodDistanceFactor(mp_handle, fLodDistance);
}

inline PIX CTerrain::GetShadowMapWidth()
{
  return CTerrain_GetShadowMapWidth(mp_handle);
}

inline PIX CTerrain::GetShadowMapHeight()
{
  return CTerrain_GetShadowMapHeight(mp_handle);
}

inline PIX CTerrain::GetShadingMapWidth()
{
  return CTerrain_GetShadingMapWidth(mp_handle);
}

inline PIX CTerrain::GetShadingMapHeight()
{
  return CTerrain_GetShadingMapHeight(mp_handle);
}

__forceinline CTerrainLayer CTerrain::GetLayer(INDEX iLayer)
{
  return CTerrainLayer(CTerrain_GetLayer(mp_handle, iLayer), false);
}

__forceinline CTerrainLayer CTerrain::AddLayer_t(CTFileName fnTexture, LayerType ltType, BOOL bUpdateTerrain)
{
  auto* ptr = CTerrain_AddLayer_t(mp_handle, fnTexture, ltType, bUpdateTerrain);
  SECppAPI_CheckException();
  return CTerrainLayer(ptr, false);
}

inline void CTerrain::RemoveLayer(INDEX iLayer, BOOL bUpdateTerrain)
{
  CTerrain_RemoveLayer(mp_handle, iLayer, bUpdateTerrain);
}

inline INDEX CTerrain::SetLayerIndex(INDEX iLayer, INDEX iNewIndex, BOOL bUpdateTerrain)
{
  return CTerrain_SetLayerIndex(mp_handle, iLayer, iNewIndex, bUpdateTerrain);
}

inline void CTerrain::AddTileToRegenQueue(INDEX iTileIndex)
{
  CTerrain_AddTileToRegenQueue(mp_handle, iTileIndex);
}

inline void CTerrain::AddAllTilesToRegenQueue()
{
  CTerrain_AddAllTilesToRegenQueue(mp_handle);
}

inline void CTerrain::ClearRegenList()
{
  CTerrain_ClearRegenList(mp_handle);
}

inline void CTerrain::UpdateShadowMap(FLOATaabbox3D* pbboxUpdate, BOOL bAbsoluteSpace)
{
  CTerrain_UpdateShadowMap(mp_handle, pbboxUpdate ? (*pbboxUpdate) : nullptr, bAbsoluteSpace);
}

inline void CTerrain::UpdateTopMap(INDEX iTileIndex, Rect_* prcDest)
{
  CTerrain_UpdateTopMap(mp_handle, iTileIndex, prcDest);
}

inline void CTerrain::GetAllTerrainBBox(FLOATaabbox3D& bbox)
{
  CTerrain_GetAllTerrainBBox(mp_handle, bbox);
}

inline COLOR CTerrain::GetShadeColor(CShadingInfo_* psi)
{
  return CTerrain_GetShadeColor(mp_handle, psi);
}

__forceinline FLOATplane3D CTerrain::GetPlaneFromPoint(FLOAT3D& vAbsPoint)
{
  return FLOATplane3D(CTerrain_GetPlaneFromPoint(mp_handle, vAbsPoint), true);
}

inline void CTerrain::SetQuadsPerTileRow(INDEX ctQuadsPerTileRow)
{
  CTerrain_SetQuadsPerTileRow(mp_handle, ctQuadsPerTileRow);
}

inline INDEX CTerrain::GetQuadsPerTileRow()
{
  return CTerrain_GetQuadsPerTileRow(mp_handle);
}

inline INDEX CTerrain::GetVerticesPerTileRow()
{
  return CTerrain_GetVerticesPerTileRow(mp_handle);
}

inline void CTerrain::ReadVersion_t(CTStream* istrFile, INDEX iSavedVersion)
{
  CTerrain_ReadVersion_t(mp_handle, *istrFile, iSavedVersion);
  SECppAPI_CheckException();
}

inline void CTerrain::Read_t(CTStream* istrFile)
{
  CTerrain_Read_t(mp_handle, *istrFile);
  SECppAPI_CheckException();
}

inline void CTerrain::Write_t(CTStream* ostrFile)
{
  CTerrain_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}

inline void CTerrain::Copy(CTerrain& trOther)
{
  CTerrain_Copy(mp_handle, trOther);
}

inline void CTerrain::Clean(BOOL bCleanLayers)
{
  CTerrain_Clean(mp_handle, bCleanLayers);
}

inline void CTerrain::Clear()
{
  CTerrain_Clear(mp_handle);
}

inline void CTerrain::ReGenerate()
{
  CTerrain_ReGenerate(mp_handle);
}

inline void CTerrain::BuildTerrainData()
{
  CTerrain_BuildTerrainData(mp_handle);
}

inline void CTerrain::BuildQuadTree()
{
  CTerrain_BuildQuadTree(mp_handle);
}

inline void CTerrain::UpdateQuadTree()
{
  CTerrain_UpdateQuadTree(mp_handle);
}

inline void CTerrain::GenerateTerrainTopMap()
{
  CTerrain_GenerateTerrainTopMap(mp_handle);
}

inline void CTerrain::SetTerrainStretch(FLOAT3D vStretch)
{
  CTerrain_SetTerrainStretch(mp_handle, vStretch);
}

inline void CTerrain::AddDefaultLayer_t()
{
  CTerrain_AddDefaultLayer_t(mp_handle);
  SECppAPI_CheckException();
}

inline void CTerrain::DiscardShadingInfos()
{
  CTerrain_DiscardShadingInfos(mp_handle);
}

inline void CTerrain::ClearHeightMap()
{
  CTerrain_ClearHeightMap(mp_handle);
}

inline void CTerrain::ClearShadowMap()
{
  CTerrain_ClearShadowMap(mp_handle);
}

inline void CTerrain::ClearEdgeMap()
{
  CTerrain_ClearEdgeMap(mp_handle);
}

inline void CTerrain::ClearTopMaps()
{
  CTerrain_ClearTopMaps(mp_handle);
}

inline void CTerrain::ClearTiles()
{
  CTerrain_ClearTiles(mp_handle);
}

inline void CTerrain::ClearArrays()
{
  CTerrain_ClearArrays(mp_handle);
}

inline void CTerrain::ClearQuadTree()
{
  CTerrain_ClearQuadTree(mp_handle);
}

inline void CTerrain::ClearLayers()
{
  CTerrain_ClearLayers(mp_handle);
}
