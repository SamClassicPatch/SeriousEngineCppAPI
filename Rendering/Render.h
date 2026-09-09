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
#include "../Models/ModelObject.h"
#include "../Entities/Entity.h"
#include "../World/World.h"
#include <SeriousEngineCAPI/Rendering/Render.h>

/*
 * Preferences for rendering world (another class is used for rendering models).
 */
class CWorldRenderPrefs
{
public:
  enum FillType : FillType_ {
    FT_NONE = FillType_FT_NONE,                 // do not draw this element
    FT_INKCOLOR = FillType_FT_INKCOLOR,         // draw all in same color
    FT_POLYGONCOLOR = FillType_FT_POLYGONCOLOR, // draw in colors of corresponding polygons
    FT_SECTORCOLOR = FillType_FT_SECTORCOLOR,   // draw in colors of corresponding sectors
    FT_TEXTURE = FillType_FT_TEXTURE,           // draw with texture
  };
  enum SelectionType : SelectionType_ {
    ST_NONE = SelectionType_ST_NONE,         // no selection is drawn
    ST_ENTITIES = SelectionType_ST_ENTITIES, // selected entities are marked
    ST_POLYGONS = SelectionType_ST_POLYGONS, // selected polygons are marked
    ST_SECTORS = SelectionType_ST_SECTORS,   // selected sectors are marked
    ST_VERTICES = SelectionType_ST_VERTICES, // selected vertices are marked
  };
  enum ShadowsType : ShadowsType_ {
    SHT_NONE = ShadowsType_SHT_NONE,                       // do not use any shadows
    SHT_NOAUTOCALCULATE = ShadowsType_SHT_NOAUTOCALCULATE, // use shadows, but don't auto recalculate
    SHT_FULL = ShadowsType_SHT_FULL,                       // use full shadows
  };
  enum LensFlaresType : LensFlaresType_ {
    LFT_NONE = LensFlaresType_LFT_NONE,                                   // do not render lens flares at all
    LFT_SINGLE_FLARE = LensFlaresType_LFT_SINGLE_FLARE,                   // render only single flare without reflections
    LFT_REFLECTIONS = LensFlaresType_LFT_REFLECTIONS,                     // render flares and reflections
    LFT_REFLECTIONS_AND_GLARE = LensFlaresType_LFT_REFLECTIONS_AND_GLARE, // render flare, reflections and glare
  };

  CWorldRenderPrefs(CWorldRenderPrefs_* p, bool owner = false);
  CWorldRenderPrefs();
  CWorldRenderPrefs(const CWorldRenderPrefs& o);
  ~CWorldRenderPrefs();
  CWorldRenderPrefs& operator=(const CWorldRenderPrefs& o);

  /* Test if drawing of hidden edges is turned on. */
  BOOL IsHiddenLinesOn();
  /* Set drawing of hidden edges on or off. */
  void SetHiddenLinesOn(BOOL bOn);

  /* Test if drawing of lines to target entities is turned on. */
  BOOL IsShowTargetsOn();
  /* Set drawing of lines to target entities on or off. */
  void SetShowTargetsOn(BOOL bOn);

  /* Test if typing of entity names is turned on. */
  BOOL IsShowEntityNamesOn();
  /* Set typing of entity names on or off. */
  void SetShowEntityNamesOn(BOOL bOn);

  /* Test if drawing of editor models is turned on. */
  BOOL IsEditorModelsOn();
  /* Set drawing of editor models on or off. */
  void SetEditorModelsOn(BOOL bOn);
  /* Test if drawing of editor models is turned on. */
  BOOL IsFieldBrushesOn();
  /* Set drawing of editor models on or off. */
  void SetFieldBrushesOn(BOOL bOn);

  /* Test if drawing background texture is on. */
  BOOL IsBackgroundTextureOn();
  /* Set drawing of background texture on or off. */
  void SetBackgroundTextureOn(BOOL bOn);

  /* Test if drawing visibility tweaks for selected sectors is on. */
  BOOL IsVisTweaksOn();
  /* Set drawing of visibility tweaks for selected sectors on or off. */
  void SetVisTweaksOn(BOOL bOn);

  /* Test if visibility tweaks are off. */
  BOOL IsVisTweaksDisabled();
  /* Set disabling of visibility tweaks on or off. */
  void DisableVisTweaks(BOOL bOn);

  /* Test if drawing fog is on. */
  BOOL IsFogOn();
  /* Set drawing of fog on or off. */
  void SetFogOn(BOOL bOn);
  /* Test if drawing haze is on. */
  BOOL IsHazeOn();
  /* Set drawing of haze on or off. */
  void SetHazeOn(BOOL bOn);
  /* Test if drawing mirrors is on. */
  BOOL IsMirrorsOn();
  /* Set drawing of mirrors on or off. */
  void SetMirrorsOn(BOOL bOn);

  /* Test if mip brushing should be automatic. */
  BOOL IsAutoMipBrushingOn();
  /* Set mip brushing should to automatic or manual. */
  void SetAutoMipBrushingOn(BOOL bOn);
  /* Set/get mip factor for manual mip brushing. */
  void SetManualMipBrushingFactor(FLOAT fFactor);
  FLOAT GetManualMipBrushingFactor();

  /* Test if texture layer is shown. */
  BOOL IsTextureLayerOn(INDEX iTexture);
  /* Set texture layer shown/hidden. */
  void SetTextureLayerOn(BOOL bOn, INDEX iTexture);

  // Get mip brushing factor relevant for given distance mip factor
  FLOAT GetCurrentMipBrushingFactor(FLOAT fDistanceMipFactor);

  /* Set/get the fill type for vertices. */
  void SetVerticesFillType(FillType ft);
  FillType GetVerticesFillType();
  /* Set/get the ink color for vertices. */
  void SetVerticesInkColor(COLOR color);
  COLOR GetVerticesInkColor();

  /* Set/get the fill type for edges. */
  void SetEdgesFillType(FillType ft);
  FillType GetEdgesFillType();
  /* Set/get the ink color for edges. */
  void SetEdgesInkColor(COLOR color);
  COLOR GetEdgesInkColor();

  /* Set/get the fill type for polygons. */
  void SetPolygonsFillType(FillType ft);
  FillType GetPolygonsFillType();
  /* Set/get the ink color for polygons. */
  void SetPolygonsInkColor(COLOR color);
  COLOR GetPolygonsInkColor();

  /* Set/get the brush shadow quality. */
  void SetShadowsType(ShadowsType sht);
  ShadowsType GetShadowsType();

  /* Set/get the lens flare quality. */
  void SetLensFlaresType(LensFlaresType lft);
  LensFlaresType GetLensFlares();

  /* Set/get range (in meters) around viewer that is always drawn. */
  void SetMinimumRenderRange(FLOAT fRange);
  FLOAT GetMinimumRenderRange();

  /* Set/get model object used for marking selected models. */
  void SetSelectedEntityModel(CModelObject_* pmoSelection);
  CModelObjectPtr GetSelectedEntityModel();

  /* Set/get model object used for marking selected portals. */
  void SetSelectedPortalModel(CModelObject_* pmoSelection);
  CModelObjectPtr GetSelectedPortalModel();

  /* Set/get model object used for marking empty brushes. */
  void SetEmptyBrushModel(CModelObject_* pmoBrush);
  CModelObjectPtr GetEmptyBrushModel();

  /* Set/get the selection type. */
  void SetSelectionType(SelectionType st);
  SelectionType GetSelectionType();

  /* Set/get the far clip plane. */
  void SetFarClipPlane(FLOAT f);
  FLOAT GetFarClipPlane();

  /* Set far clip plane in isometric projection on or off. */
  void EnableFarClipPlaneInIsometricProjection(BOOL bOn);
  /* Test if far clip plane in isometric projection is on. */
  BOOL IsFarClipPlaneInIsometricProjectionOn();

  void Read_t(CTStream* istrFile);   // throw char * // read and
  void Write_t(CTStream* ostrFile);  // throw char * // write functions

  inline CWorldRenderPrefs_* C_Handle() { return mp_handle; }
  inline const CWorldRenderPrefs_* C_Handle() const { return mp_handle; }
  inline operator CWorldRenderPrefs_* () { return C_Handle(); }
  inline operator const CWorldRenderPrefs_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CWorldRenderPrefs_* mp_handle = nullptr;

public:
  FLOAT& wrp_fFarClipPlane;                          // far clip plane
  BOOL& wrp_bApplyFarClipPlaneInIsometricProjection; // if far clip plane should be applied in isometric projections
};

// global instance used in rendering
#define _wrpWorldRenderPrefs\
  CWorldRenderPrefs(_wrpWorldRenderPrefs_(), false)

#define _pselbvxtSelectOnRender\
  (*_pselbvxtSelectOnRender_())

#define _pavpixSelectLasso\
  (*_pavpixSelectLasso_())

#define _vpixSelectNearPoint\
  PIX2D(_vpixSelectNearPoint_(), false)

#define _bSelectAlternative\
  (*_bSelectAlternative_())

#define _pixDeltaAroundVertex\
  (*_pixDeltaAroundVertex_())

#define _pselbscVisTweaks\
  (*_pselbscVisTweaks_())

/*
 * Rendering interface
 */
 // Render a world with some viewer, projection and drawport.
void RenderView(CWorld& woWorld, CEntity_* enViewer, CAnyProjection3D& prProjection, CDrawPort& dpDrawport);

#include "Render.inl"
