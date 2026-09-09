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
#include "TerrainTile.h"
#include "TerrainLayer.h"
#include "ArrayHolder.h"
#include "../Templates/StaticArray.h"
#include "../Templates/StaticStackArray.h"
#include "../Templates/DynamicContainer.h"
#include <SeriousEngineCAPI/Terrain/Terrain.h>

class QuadTreeNode
{
public:
  QuadTreeNode(QuadTreeNode_* p, bool owner = false);
  QuadTreeNode();
  QuadTreeNode(const QuadTreeNode& o);
  ~QuadTreeNode();
  QuadTreeNode& operator=(const QuadTreeNode& o);

  INDEX& qtn_iChild(INDEX i);

  inline QuadTreeNode_* C_Handle() { return mp_handle; }
  inline const QuadTreeNode_* C_Handle() const { return mp_handle; }
  inline operator QuadTreeNode_* () { return C_Handle(); }
  inline operator const QuadTreeNode_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  QuadTreeNode_* mp_handle = nullptr;

public:
  FLOATaabbox3D qtn_aabbox;    // Bounding box for this quadtree node
  INDEX&        qtn_iTileIndex;// Index of tile that this node represents
};

class QuadTreeLevel
{
public:
  QuadTreeLevel(QuadTreeLevel_* p, bool owner = false);
  QuadTreeLevel();
  QuadTreeLevel(const QuadTreeLevel& o);
  ~QuadTreeLevel();
  QuadTreeLevel& operator=(const QuadTreeLevel& o);

  inline QuadTreeLevel_* C_Handle() { return mp_handle; }
  inline const QuadTreeLevel_* C_Handle() const { return mp_handle; }
  inline operator QuadTreeLevel_* () { return C_Handle(); }
  inline operator const QuadTreeLevel_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  QuadTreeLevel_* mp_handle = nullptr;

public:
  INDEX& qtl_iFirstNode; // Index of first quadtree node in this level
  INDEX& qtl_ctNodes;    // Count of nodes in this level
  INDEX& qtl_ctNodesCol; // Count of nodes in col
  INDEX& qtl_ctNodesRow; // Count of nodes in row
};

class Rect
{
public:
  Rect(Rect_* p, bool owner = false);
  Rect();
  Rect(INDEX iLeft, INDEX iTop, INDEX iRight, INDEX iBottom);
  Rect(const Rect& o);
  ~Rect();
  Rect& operator=(const Rect& o);

  INDEX Width();
  INDEX Height();

  inline Rect_* C_Handle() { return mp_handle; }
  inline const Rect_* C_Handle() const { return mp_handle; }
  inline operator Rect_* () { return C_Handle(); }
  inline operator const Rect_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  Rect_* mp_handle = nullptr;

public:
  INDEX& rc_iLeft;
  INDEX& rc_iRight;
  INDEX& rc_iTop;
  INDEX& rc_iBottom;
};

DECLARE_CStaticArray(QuadTreeNode)
DECLARE_CStaticArray(QuadTreeLevel)
DECLARE_CStaticArray(CTerrainTile)
DECLARE_CStaticArray(CArrayHolder)
DECLARE_CStaticArray(CTerrainLayer)

DECLARE_CStaticStackArray(QuadTreeNode)
DECLARE_CStaticStackArray(QuadTreeLevel)
DECLARE_CStaticStackArray(CTerrainLayer)

class CTerrain
{
public:
  CTerrain(CTerrain_* p, bool owner = false);
  CTerrain();
  ~CTerrain();

  // Render terrain tiles
  void Render(CAnyProjection3D& apr, CDrawPort& pdp);
  // Render terrain tiles in wireframe
  void RenderWireFrame(CAnyProjection3D& apr, CDrawPort& pdp, COLOR colEdges);

  // Create empty terrain with given size
  void CreateEmptyTerrain_t(PIX pixWidth, PIX pixHeight);
  // Import height map from targa file
  void ImportHeightMap_t(CTFileName fnHeightMap, BOOL bUse16b = TRUE);
  // Export height map to targa file
  void ExportHeightMap_t(CTFileName fnHeightMap, BOOL bUse16b = TRUE);
  // Rebuild all terrain
  void ReBuildTerrain(BOOL bDelayTileRegen = FALSE);
  // Refresh terrain
  void RefreshTerrain();

  // Set height map size
  void AllocateHeightMap(PIX pixWidth, PIX pixHeight);
  // Change height map size
  void ReAllocateHeightMap(PIX pixWidth, PIX pixHeight);
  // Set terrain size
  void SetTerrainSize(FLOAT3D vSize);
  // Set shadow map size aspect (relative to height map size) and shading map aspect (relative to shadow map size)
  void SetShadowMapsSize(INDEX iShadowMapAspect, INDEX iShadingMapAspect);

  // Set size of top map texture
  void SetGlobalTopMapSize(PIX pixTopMapSize);
  // Set size of top map texture for tiles in lower lods
  void SetTileTopMapSize(PIX pixLodTopMapSize);
  // Set lod distance factor
  void SetLodDistanceFactor(FLOAT fLodDistance);

  // Get shadow map size
  PIX GetShadowMapWidth();
  PIX GetShadowMapHeight();
  // Get shading map size
  PIX GetShadingMapWidth();
  PIX GetShadingMapHeight();

  // Get reference to layer
  CTerrainLayer GetLayer(INDEX iLayer);
  // Add new layer
  CTerrainLayer AddLayer_t(CTFileName fnTexture, LayerType ltType = LT_NORMAL, BOOL bUpdateTerrain = TRUE);
  // Remove one layer
  void RemoveLayer(INDEX iLayer, BOOL bUpdateTerrain = TRUE);
  // Move layer to new position
  INDEX SetLayerIndex(INDEX iLayer, INDEX iNewIndex, BOOL bUpdateTerrain = TRUE);

  // Add tile to reqen queue
  void AddTileToRegenQueue(INDEX iTileIndex);
  // Add all tiles to regen queue
  void AddAllTilesToRegenQueue(void);
  // Clear current regen list
  void ClearRegenList(void);

  // Update shadow map
  void UpdateShadowMap(FLOATaabbox3D* pbboxUpdate = nullptr, BOOL bAbsoluteSpace = FALSE);
  // Update top map
  void UpdateTopMap(INDEX iTileIndex, Rect_* prcDest = nullptr);

  // Terrain flags handling
  inline ULONG& GetFlags() { return tr_ulTerrainFlags; }
  inline void SetFlags(ULONG ulFlags) { tr_ulTerrainFlags = ulFlags; }
  inline void AddFlag(ULONG ulFlag) { tr_ulTerrainFlags |= ulFlag; }
  inline void RemoveFlag(ULONG ulFlag) { tr_ulTerrainFlags &= ~ulFlag; }

  // get first quad tree node bounding box (all tiles box)
  void GetAllTerrainBBox(FLOATaabbox3D& bbox);

  // Get shading color from tex coords in shading map
  COLOR GetShadeColor(CShadingInfo_* psi);
  // Get plane from given point
  FLOATplane3D GetPlaneFromPoint(FLOAT3D& vAbsPoint);


  // Sets number of quads in row of one tile
  void SetQuadsPerTileRow(INDEX ctQuadsPerTileRow);
  INDEX GetQuadsPerTileRow();
  INDEX GetVerticesPerTileRow();

  // Read from stream.
  void ReadVersion_t(CTStream* istrFile, INDEX iSavedVersion);
  // Read from stream.
  void Read_t(CTStream* istrFile); // throw char *
  // Write to stream.
  void Write_t(CTStream* ostrFile);  // throw char *
  // Copy terrain data from other terrain
  void Copy(CTerrain& trOther);
  // Clean terrain data (does not remove layers)
  void Clean(BOOL bCleanLayers = TRUE);
  // Clean terrain data
  void Clear();


  // Generate terrain tiles 
  void ReGenerate();
  // Build terrain data
  void BuildTerrainData();
  // Build quadtree for terrain
  void BuildQuadTree();
  // Update quadtree for terrain
  void UpdateQuadTree();
  // Generate terrain top map
  void GenerateTerrainTopMap();
  // Set Terrain stretch
  void SetTerrainStretch(FLOAT3D vStretch);
  // Add default layer
  void AddDefaultLayer_t();

  // Discard all cached shading info for models
  void DiscardShadingInfos();

  // Clear height map
  void ClearHeightMap();
  // Clear shadow map
  void ClearShadowMap();
  // Clear edge map
  void ClearEdgeMap();
  // Clear all topmaps
  void ClearTopMaps();
  // Clear tiles
  void ClearTiles();
  // Clear arrays
  void ClearArrays();
  // Clear quadtree
  void ClearQuadTree();
  // Clear layers
  void ClearLayers();

  inline CTerrain_* C_Handle() { return mp_handle; }
  inline const CTerrain_* C_Handle() const { return mp_handle; }
  inline operator CTerrain_* () { return C_Handle(); }
  inline operator const CTerrain_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTerrain_* mp_handle = nullptr;

public:
  CEntity_*& tr_penEntity;           // pointer to entity that holds this terrain

  INDEX&   tr_ctTiles;     // Terrain tiles count
  INDEX&   tr_ctTilesX;    // Terrain tiles count in row
  INDEX&   tr_ctTilesY;    // Terrain tiles count in col
  INDEX&   tr_iMaxTileLod; // Maximum lod in witch one tile can be

  FLOAT3D tr_vStretch;    // Terrain stretch
  FLOAT&   tr_fDistFactor; // Distance for lod switching

  CStaticStackArray_QuadTreeNode  tr_aqtnQuadTreeNodes;  // Array of quadtree nodes
  CStaticStackArray_QuadTreeLevel tr_aqtlQuadTreeLevels; // Array of quadtree levels
  CStaticArray_CTerrainTile       tr_attTiles;           // Array of terrain tiles for terrain
  CStaticArray_CArrayHolder       tr_aArrayHolders;      // Array of memory holders for each lod
  CStaticStackArray_CTerrainLayer tr_atlLayers;          // Array of terrain layers
  CDynamicContainer_CTextureData  tr_atdTopMaps;         // Array of top maps for each tile array (used by ArrayHolder)
  CStaticStackArray_INDEX         tr_auiRegenList;       // List of tiles that need to be regenerated

  /* Do not change any of this params directly */
  UWORD*& tr_auwHeightMap;        // Terrain height map
  UWORD*& tr_auwShadingMap;       // Terrain shading map
  UBYTE*& tr_aubEdgeMap;          // Terrain edge map
  CTextureData tr_tdTopMap;       // Terrain top map
  CTextureData tr_tdShadowMap;    // Terrain shadow map
  CTextureData_*& tr_ptdDetailMap;  // Terrain detail map

  PIX&     tr_pixHeightMapWidth;   // Terrain height map widht
  PIX&     tr_pixHeightMapHeight;  // Terrain height map height

  PIX&     tr_pixTopMapWidth;         // Width  of terrain top map
  PIX&     tr_pixTopMapHeight;        // Height of terrain top map
  PIX&     tr_pixFirstMipTopMapWidth; // Width  of tile first mip top map
  PIX&     tr_pixFirstMipTopMapHeight;// Height of tile first mip top map

  INDEX&   tr_iShadowMapSizeAspect;   // Size of shadow map (relative to height map size)
  INDEX&   tr_iShadingMapSizeAspect;  // Size of shading map (relative to shadow map)

  INDEX&   tr_ctQuadsInTileRow;    // Count of quads in one row in tile
  INDEX&   tr_ctVerticesInTileRow; // Count of vertices in one row in tile
  ULONG&   tr_ulTerrainFlags;      // Terrain flags
  FLOAT3D  tr_vTerrainSize;        // Terrain size in metars

  INDEX&   tr_iSelectedLayer;      // Selected layer in we
};

#include "Terrain.inl"
