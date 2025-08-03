#pragma once
#include "../Base/Types.h"
#include "../Base/CTString.h"
#include "../Base/FileName.h"
#include "../Base/Stream.h"
#include "../Graphics/Texture.h"
#include <SeriousEngineCAPI/Terrain/TerrainLayer.h>

enum LayerType : LayerType_ {
  LT_NORMAL = LayerType_LT_NORMAL,
  LT_TILE = LayerType_LT_TILE,
};

class CTerrainLayer
{
public:
  CTerrainLayer(CTerrainLayer_* p, bool owner = false);
  CTerrainLayer();
  ~CTerrainLayer();
  CTerrainLayer& operator=(const CTerrainLayer& o);

  // Import layer mask from targa file
  void ImportLayerMask_t(CTFileName fnLayerMask);
  // Export layer mask to targa file
  void ExportLayerMask_t(CTFileName fnLayerMask);
  // Set layer size
  void SetLayerSize(INDEX iTerrainWidth, INDEX iTerrainHeight);
  // Set layer texture
  void SetLayerTexture_t(CTFileName fnTexture);
  // Set num of tiles in one row
  void SetTilesPerRow(INDEX ctTilesInRow);
  // Get num of tiles in one row
  INDEX GetTilesPerRow();
  // Get thumbnail
  CTextureDataPtr GetThumbnail(INDEX iWidth, INDEX iHeight);
  // Reset layer mask
  void ResetLayerMask(UBYTE ubMaskFill);
  // Reset layer params
  void ResetLayerParams();
  // Read from stream.
  void Read_t(CTStream* istrFile, INDEX iSavedVersion); // throw char *
  // Write to stream.
  void Write_t(CTStream* ostrFile);  // throw char *
  // Clear layer
  void Clear();
  // Count used memory
  SLONG GetUsedMemory();

  inline CTerrainLayer_* C_Handle() { return mp_handle; }
  inline const CTerrainLayer_* C_Handle() const { return mp_handle; }
  inline operator CTerrainLayer_* () { return C_Handle(); }
  inline operator const CTerrainLayer_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTerrainLayer_* mp_handle = nullptr;

public:
  CTextureData_*& tl_ptdTexture;  // Texture this layer is using
  UBYTE*&         tl_aubColors;   // Array of vertex alpha colors for this layer
  CTextureData    tl_tdThumbNail; // Mask thumbnail (used only in we)
  INDEX&          tl_iMaskWidth;  // Width of terrain layer mask
  INDEX&          tl_iMaskHeight; // Height of terrain layer mask

  CTString        tl_strName;     // Layer name
  BOOL&           tl_bVisible;    // Is layer visible
  COLOR&          tl_colMultiply; // Color of layer
  FLOAT&          tl_fSmoothness; // Layer smoothness
  LayerType&      tl_ltType;      // Layer type

  FLOAT&          tl_fRotateX;
  FLOAT&          tl_fRotateY;
  FLOAT&          tl_fStretchX;
  FLOAT&          tl_fStretchY;
  FLOAT&          tl_fOffsetX;
  FLOAT&          tl_fOffsetY;

  BOOL&           tl_bAutoRegenerated;
  FLOAT&          tl_fCoverage;
  FLOAT&          tl_fCoverageNoise;
  FLOAT&          tl_fCoverageRandom;

  BOOL&           tl_bApplyMinAltitude;
  FLOAT&          tl_fMinAltitude;
  FLOAT&          tl_fMinAltitudeFade;
  FLOAT&          tl_fMinAltitudeNoise;
  FLOAT&          tl_fMinAltitudeRandom;

  BOOL&           tl_bApplyMaxAltitude;
  FLOAT&          tl_fMaxAltitude;
  FLOAT&          tl_fMaxAltitudeFade;
  FLOAT&          tl_fMaxAltitudeNoise;
  FLOAT&          tl_fMaxAltitudeRandom;

  BOOL&           tl_bApplyMinSlope;
  FLOAT&          tl_fMinSlope;
  FLOAT&          tl_fMinSlopeFade;
  FLOAT&          tl_fMinSlopeNoise;
  FLOAT&          tl_fMinSlopeRandom;

  BOOL&           tl_bApplyMaxSlope;
  FLOAT&          tl_fMaxSlope;
  FLOAT&          tl_fMaxSlopeFade;
  FLOAT&          tl_fMaxSlopeNoise;
  FLOAT&          tl_fMaxSlopeRandom;

  INDEX&          tl_ctTilesInRow;  // Number of tiles in one row (used if this is tile layer)
  INDEX&          tl_ctTilesInCol;
  INDEX&          tl_iSelectedTile; // GUI variable, selected tile for this layer
  PIX&            tl_pixTileWidth;
  PIX&            tl_pixTileHeight;
  FLOAT&          tl_fTileU;
  FLOAT&          tl_fTileV;
};

#include "TerrainLayer.inl"
