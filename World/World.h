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
#include "../Templates/StaticArray.h"
#include "../Entities/Entity.h"
#include "WorldSettings.h"
#include "WorldRayCasting.h"
#include <SeriousEngineCAPI/World/World.h>

DECLARE_CStaticArray(CTextureTransformation)
IMPL_CStaticArray(CTextureTransformation)
DECLARE_CStaticArray(CTextureBlending)
IMPL_CStaticArray(CTextureBlending)
DECLARE_CStaticArray(CSurfaceType)
IMPL_CStaticArray(CSurfaceType)
DECLARE_CStaticArray(CContentType)
IMPL_CStaticArray(CContentType)
DECLARE_CStaticArray(CEnvironmentType)
IMPL_CStaticArray(CEnvironmentType)
DECLARE_CStaticArray(CIlluminationType)
IMPL_CStaticArray(CIlluminationType)

// mirroring types for mirror and stretch
enum WorldMirrorType : WorldMirrorType_ {
  WMT_NONE = WMT_NONE_,
  WMT_X = WMT_X_,
  WMT_Y = WMT_Y_,
  WMT_Z = WMT_Z_,
};

class CWorld
{
public:
  CWorld(CWorld_* p, bool owner = false);
  CWorld();
  ~CWorld();
  CWorld(const CWorld& ln) = delete;
  CWorld& operator=(const CWorld& ln) = delete;

  /* Clear all entity pointers that point to this entity. */
  void UntargetEntity(CEntity_* penToUntarget);
  // triangularize selected polygons
  void TriangularizePolygons(CDynamicContainer_CBrushPolygon& dcPolygons);
  /* Clear all arrays. */
  void Clear();
  /* Create a new entity of given class. */
  CEntityPtr CreateEntity_t(const CPlacement3D& plPlacement, const CTFileName& fnmClass); // throw char *
  /* Copy one entity from another world into this one. */
  CEntityPtr CopyOneEntity(CEntity& enToCopy, const CPlacement3D& plOtherSystem);
  /* Copy container of entities from another world to this one and select them. */
  void CopyEntities(CWorld& woOther, CDynamicContainer_CEntity& cenToCopy, CEntitySelection& senCopied, const CPlacement3D& plOtherSystem);
  /* Copy entity in world. */
  CEntityPtr CopyEntityInWorld(CEntity& enOriginal, const CPlacement3D& plOtherEntity, BOOL bWithDescendants = TRUE);
  /* Destroy a selection of entities - reserved for use in WEd only! */
  void DestroyEntities(CEntitySelection& senToDestroy);
  /* Destroy given entity - reserved for use in WEd only! */
  void DestroyOneEntity(CEntity_* penToDestroy);
  /* Cast a ray and see what it hits. */
  void CastRay(CCastRay& crRay);
  /* Continue to cast already cast ray */
  void ContinueCast(CCastRay& crRay);
  /* Set background color for this world. */
  void SetBackgroundColor(COLOR colBackground);
  /* Get background color for this world. */
  COLOR GetBackgroundColor();
  /* Get background viewer entity for this world. */
  CEntityPtr GetBackgroundViewer();
  /* Set description for this world. */
  void SetDescription(const CTString& strDescription);
  /* Get description for this world. */
  CTString GetDescription();
  // get/set name of the world
  void SetName(const CTString& strName);
  CTString GetName();
  // get/set spawn flags for the world
  void SetSpawnFlags(ULONG ulFlags);
  ULONG GetSpawnFlags();
  /* Save entire world (both brushes and current state). */
  void Save_t(const CTFileName& fnmWorld); // throw char *
  /* Load entire world (both brushes and current state). */
  void Load_t(const CTFileName& fnmWorld); // throw char *
  /* Reinitialize entities from their properties. (use only in WEd!) */
  void ReinitializeEntities();
  /* Read entire world (both brushes and current state). */
  void Read_t(CTStream* pistrm); // throw char *
  /* Write entire world (both brushes and current state). */
  void Write_t(CTStream* postrm); // throw char *
  /* Update sectors after brush vertex moving */
  void UpdateSectorsAfterVertexChange(CBrushVertexSelection& selVertex);
  /* Update sectors during brush vertex moving */
  void UpdateSectorsDuringVertexChange(CBrushVertexSelection& selVertex);
  /* Triangularize polygons that contain vertices from given selection */
  void TriangularizeForVertices(CBrushVertexSelection& selVertex);
  // CSG operations for editing worlds
  /* Add a brush from another world to a brush in this world, other entities get copied. */
  void CSGAdd(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther);
  void CSGAddReverse(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther);
  /* Substract a brush from another world to a brush in this world. */
  void CSGRemove(CEntity& enThis, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther);
  /* Split selected sectors in a brush in this world with one brush in other world.
   * (other brush must have only one sector.)
   */
  void SplitSectors(CEntity& enThis, CBrushSectorSelection& selbscSectorsToSplit, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther);
  /* If two or more sectors can be joined. */
  BOOL CanJoinSectors(CBrushSectorSelection& selbscSectorsToJoin);
  /* Join two or more sectors from one brush-mip together. */
  void JoinSectors(CBrushSectorSelection& selbscSectorsToJoin);
  /* Split selected polygons in a brush in this world with one brush in other world.
   * (other brush must have only one sector.)
   */
  void SplitPolygons(CEntity& enThis, CBrushPolygonSelection& selbpoPolygonsToSplit, CWorld& woOther, CEntity& enOther, const CPlacement3D& plOther);
  /* Join two or more polygons from one brush-sector together. */
  void JoinPolygons(CBrushPolygonSelection& selbpoPolygonsToJoin);
  /* Test if a polygon selection can be joined. */
  BOOL CanJoinPolygons(CBrushPolygonSelection& selbpoPolygonsToJoin);
  /* Join all selected polygons that can be joined. */
  void JoinAllPossiblePolygons(CBrushPolygonSelection& selbpoPolygonsToJoin,
    BOOL bPreserveTextures, INDEX iTexture);
  /* Test if a polygon selection can be joined. */
  BOOL CanJoinAllPossiblePolygons(CBrushPolygonSelection& selbpoPolygonsToJoin);
  /* Copy selected sectors from one brush to a new entity in another world. */
  BOOL CanCopySectors(CBrushSectorSelection& selbscSectorsToCopy);
  void CopySectors(CBrushSectorSelection& selbscSectorsToCopy, CEntity_* penTarget, BOOL bWithEntities);
  /* Delete selected sectors. */
  void DeleteSectors(CBrushSectorSelection& selbscSectorsToDelete, BOOL bClearPortalFlags);
  void CopyPolygonInWorld(CBrushPolygon& bpoSrc, CBrushSector& bsc, INDEX iPol, INDEX& iEdg, INDEX& iVtx);
  void CopyPolygonsToBrush(CBrushPolygonSelection& selPolygons, CEntity_* penbr);
  void DeletePolygons(CDynamicContainer_CBrushPolygon& dcPolygons);
  void CreatePolygon(CBrushVertexSelection& selVtx);
  void FlipPolygon(CBrushPolygon& bpo);
  // mirror and stretch another world into this one
  void MirrorAndStretch(CWorld& woOriginal, FLOAT fStretch, WorldMirrorType wmt);
  // hide/show functions
  /* Hide entities contained in given selection. */
  void HideSelectedEntities(CDynamicContainer_CEntity& selenEntitiesToHide);
  /* Hide all unselected entities. */
  void HideUnselectedEntities();
  /* Show all entities. */
  void ShowAllEntities();
  /* Hide sectors contained in given selection. */
  void HideSelectedSectors(CBrushSectorSelection& selbscSectorsToHide);
  /* Hide all unselected sectors. */
  void HideUnselectedSectors();
  /* Show all sectors. */
  void ShowAllSectors();
  // shadow manipulation functions
  /* Recalculate all shadow maps that are not valid or of smaller precision. */
  void CalculateDirectionalShadows();
  void CalculateNonDirectionalShadows();
  /* Find all shadow layers near a certain position. */
  void FindShadowLayers(const FLOATaabbox3D& boxNear, BOOL bSelectedOnly = FALSE, BOOL bDirectional = TRUE);
  /* Discard shadows on all brush polygons in the world. */
  void DiscardAllShadows();
  // rebuild all links in world
  void RebuildLinks();

  inline CWorld_* C_Handle() { return mp_handle; }
  inline const CWorld_* C_Handle() const { return mp_handle; }
  inline operator CWorld_* () { return C_Handle(); }
  inline operator const CWorld_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  CWorld_* mp_handle = nullptr;

public:
  // current transformations for animating texture mapping
  CStaticArray_CTextureTransformation wo_attTextureTransformations;
  // current blendings for animating texture blending
  CStaticArray_CTextureBlending wo_atbTextureBlendings;
  // polygon surface types
  CStaticArray_CSurfaceType wo_astSurfaceTypes;
  // sector content types
  CStaticArray_CContentType wo_actContentTypes;
  // sector environment types
  CStaticArray_CEnvironmentType wo_aetEnvironmentTypes;
  // illumination types (0 is not used)
  CStaticArray_CIlluminationType wo_aitIlluminationTypes;
  COLOR& wo_colBackground;    // background color of this world
  CTString wo_strBackdropUp;  // upper backdrop image
  CTString wo_strBackdropFt;  // front backdrop image
  CTString wo_strBackdropRt;  // right backdrop image
  CTString wo_strBackdropObject; // 3d object that is rendered as backdrop
  FLOAT& wo_fUpW;   // size and position of upper backdrop image
  FLOAT& wo_fUpL;
  FLOAT& wo_fUpCX;
  FLOAT& wo_fUpCZ;
  FLOAT& wo_fFtW;   // size and position of front backdrop image
  FLOAT& wo_fFtH;
  FLOAT& wo_fFtCX;
  FLOAT& wo_fFtCY;
  FLOAT& wo_fRtL;   // size and position of right backdrop image
  FLOAT& wo_fRtH;
  FLOAT& wo_fRtCZ;
  FLOAT& wo_fRtCY;
  CPlacement3D wo_plFocus; // focus placement in WED at the moment of world saving
  FLOAT& wo_fTargetDistance;// target distance in WED at the moment of world saving
  CPlacement3D wo_plThumbnailFocus; // focus placement for thumbnail in WED
  FLOAT& wo_fThumbnailTargetDistance;// target distance for thumbnail in WED
  CTFileName wo_fnmFileName;  // the file that the world was loaded from
  CDynamicContainer_CEntity wo_cenEntities; // all entities in the world
};

#include "World.inl"
