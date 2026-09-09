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

inline CTerrainLayer::CTerrainLayer(CTerrainLayer_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tl_ptdTexture(*CTerrainLayer_tl_ptdTexture(mp_handle))
  , tl_aubColors(*CTerrainLayer_tl_aubColors(mp_handle))
  , tl_tdThumbNail(CTerrainLayer_tl_tdThumbNail(mp_handle), false)
  , tl_iMaskWidth(*CTerrainLayer_tl_iMaskWidth(mp_handle))
  , tl_iMaskHeight(*CTerrainLayer_tl_iMaskHeight(mp_handle))
  , tl_strName(CTerrainLayer_tl_strName(mp_handle), false)
  , tl_bVisible(*CTerrainLayer_tl_bVisible(mp_handle))
  , tl_colMultiply(*CTerrainLayer_tl_colMultiply(mp_handle))
  , tl_fSmoothness(*CTerrainLayer_tl_fSmoothness(mp_handle))
  , tl_ltType(*((LayerType*)CTerrainLayer_tl_ltType(mp_handle)))
  , tl_fRotateX(*CTerrainLayer_tl_fRotateX(mp_handle))
  , tl_fRotateY(*CTerrainLayer_tl_fRotateY(mp_handle))
  , tl_fStretchX(*CTerrainLayer_tl_fStretchX(mp_handle))
  , tl_fStretchY(*CTerrainLayer_tl_fStretchY(mp_handle))
  , tl_fOffsetX(*CTerrainLayer_tl_fOffsetX(mp_handle))
  , tl_fOffsetY(*CTerrainLayer_tl_fOffsetY(mp_handle))
  , tl_bAutoRegenerated(*CTerrainLayer_tl_bAutoRegenerated(mp_handle))
  , tl_fCoverage(*CTerrainLayer_tl_fCoverage(mp_handle))
  , tl_fCoverageNoise(*CTerrainLayer_tl_fCoverageNoise(mp_handle))
  , tl_fCoverageRandom(*CTerrainLayer_tl_fCoverageRandom(mp_handle))
  , tl_bApplyMinAltitude(*CTerrainLayer_tl_bApplyMinAltitude(mp_handle))
  , tl_fMinAltitude(*CTerrainLayer_tl_fMinAltitude(mp_handle))
  , tl_fMinAltitudeFade(*CTerrainLayer_tl_fMinAltitudeFade(mp_handle))
  , tl_fMinAltitudeNoise(*CTerrainLayer_tl_fMinAltitudeNoise(mp_handle))
  , tl_fMinAltitudeRandom(*CTerrainLayer_tl_fMinAltitudeRandom(mp_handle))
  , tl_bApplyMaxAltitude(*CTerrainLayer_tl_bApplyMaxAltitude(mp_handle))
  , tl_fMaxAltitude(*CTerrainLayer_tl_fMaxAltitude(mp_handle))
  , tl_fMaxAltitudeFade(*CTerrainLayer_tl_fMaxAltitudeFade(mp_handle))
  , tl_fMaxAltitudeNoise(*CTerrainLayer_tl_fMaxAltitudeNoise(mp_handle))
  , tl_fMaxAltitudeRandom(*CTerrainLayer_tl_fMaxAltitudeRandom(mp_handle))
  , tl_bApplyMinSlope(*CTerrainLayer_tl_bApplyMinSlope(mp_handle))
  , tl_fMinSlope(*CTerrainLayer_tl_fMinSlope(mp_handle))
  , tl_fMinSlopeFade(*CTerrainLayer_tl_fMinSlopeFade(mp_handle))
  , tl_fMinSlopeNoise(*CTerrainLayer_tl_fMinSlopeNoise(mp_handle))
  , tl_fMinSlopeRandom(*CTerrainLayer_tl_fMinSlopeRandom(mp_handle))
  , tl_bApplyMaxSlope(*CTerrainLayer_tl_bApplyMaxSlope(mp_handle))
  , tl_fMaxSlope(*CTerrainLayer_tl_fMaxSlope(mp_handle))
  , tl_fMaxSlopeFade(*CTerrainLayer_tl_fMaxSlopeFade(mp_handle))
  , tl_fMaxSlopeNoise(*CTerrainLayer_tl_fMaxSlopeNoise(mp_handle))
  , tl_fMaxSlopeRandom(*CTerrainLayer_tl_fMaxSlopeRandom(mp_handle))
  , tl_ctTilesInRow(*CTerrainLayer_tl_ctTilesInRow(mp_handle))
  , tl_ctTilesInCol(*CTerrainLayer_tl_ctTilesInCol(mp_handle))
  , tl_iSelectedTile(*CTerrainLayer_tl_iSelectedTile(mp_handle))
  , tl_pixTileWidth(*CTerrainLayer_tl_pixTileWidth(mp_handle))
  , tl_pixTileHeight(*CTerrainLayer_tl_pixTileHeight(mp_handle))
  , tl_fTileU(*CTerrainLayer_tl_fTileU(mp_handle))
  , tl_fTileV(*CTerrainLayer_tl_fTileV(mp_handle))
{
}

inline CTerrainLayer::CTerrainLayer()
  : CTerrainLayer(CTerrainLayer_new(), true)
{
}

inline CTerrainLayer::~CTerrainLayer()
{
  if (m_owner)
    CTerrainLayer_delete(mp_handle);
}

inline CTerrainLayer& CTerrainLayer::operator=(const CTerrainLayer& o)
{
  CTerrainLayer_copy(mp_handle, o);
  return *this;
}

inline void CTerrainLayer::ImportLayerMask_t(CTFileName fnLayerMask)
{
  CTerrainLayer_ImportLayerMask_t(mp_handle, fnLayerMask);
  SECppAPI_CheckException();
}

inline void CTerrainLayer::ExportLayerMask_t(CTFileName fnLayerMask)
{
  CTerrainLayer_ExportLayerMask_t(mp_handle, fnLayerMask);
  SECppAPI_CheckException();
}

inline void CTerrainLayer::SetLayerSize(INDEX iTerrainWidth, INDEX iTerrainHeight)
{
  CTerrainLayer_SetLayerSize(mp_handle, iTerrainWidth, iTerrainHeight);
}

inline void CTerrainLayer::SetLayerTexture_t(CTFileName fnTexture)
{
  CTerrainLayer_SetLayerTexture_t(mp_handle, fnTexture);
  SECppAPI_CheckException();
}

inline void CTerrainLayer::SetTilesPerRow(INDEX ctTilesInRow)
{
  CTerrainLayer_SetTilesPerRow(mp_handle, ctTilesInRow);
}

inline INDEX CTerrainLayer::GetTilesPerRow()
{
  return CTerrainLayer_GetTilesPerRow(mp_handle);
}

inline CTextureDataPtr CTerrainLayer::GetThumbnail(INDEX iWidth, INDEX iHeight)
{
  return CTerrainLayer_GetThumbnail(mp_handle, iWidth, iHeight);
}

inline void CTerrainLayer::ResetLayerMask(UBYTE ubMaskFill)
{
  CTerrainLayer_ResetLayerMask(mp_handle, ubMaskFill);
}

inline void CTerrainLayer::ResetLayerParams()
{
  CTerrainLayer_ResetLayerParams(mp_handle);
}

inline void CTerrainLayer::Read_t(CTStream* istrFile, INDEX iSavedVersion)
{
  CTerrainLayer_Read_t(mp_handle, *istrFile, iSavedVersion);
  SECppAPI_CheckException();
}

inline void CTerrainLayer::Write_t(CTStream* ostrFile)
{
  CTerrainLayer_Write_t(mp_handle, *ostrFile);
  SECppAPI_CheckException();
}

inline void CTerrainLayer::Clear()
{
  CTerrainLayer_Clear(mp_handle);
}

inline SLONG CTerrainLayer::GetUsedMemory()
{
  return CTerrainLayer_GetUsedMemory(mp_handle);
}
