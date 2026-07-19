#pragma once

inline CWorldRenderPrefs::CWorldRenderPrefs(CWorldRenderPrefs_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , wrp_fFarClipPlane(*CWorldRenderPrefs_wrp_fFarClipPlane(p))
  , wrp_bApplyFarClipPlaneInIsometricProjection(*CWorldRenderPrefs_wrp_bApplyFarClipPlaneInIsometricProjection(p))
{
}

inline CWorldRenderPrefs::CWorldRenderPrefs()
  : CWorldRenderPrefs(CWorldRenderPrefs_new(), true)
{
}

inline CWorldRenderPrefs::CWorldRenderPrefs(const CWorldRenderPrefs& o)
  : CWorldRenderPrefs(CWorldRenderPrefs_clone(o), true)
{
}

inline CWorldRenderPrefs::~CWorldRenderPrefs()
{
  if (m_owner)
    CWorldRenderPrefs_delete(mp_handle);
}

inline CWorldRenderPrefs& CWorldRenderPrefs::operator=(const CWorldRenderPrefs& o)
{
  CWorldRenderPrefs_copy(mp_handle, o);
  return *this;
}

inline BOOL CWorldRenderPrefs::IsHiddenLinesOn()
{
  return CWorldRenderPrefs_IsHiddenLinesOn(mp_handle);
}

inline void CWorldRenderPrefs::SetHiddenLinesOn(BOOL bOn)
{
  CWorldRenderPrefs_SetHiddenLinesOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsShowTargetsOn()
{
  return CWorldRenderPrefs_IsShowTargetsOn(mp_handle);
}

inline void CWorldRenderPrefs::SetShowTargetsOn(BOOL bOn)
{
  CWorldRenderPrefs_SetShowTargetsOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsShowEntityNamesOn()
{
  return CWorldRenderPrefs_IsShowEntityNamesOn(mp_handle);
}

inline void CWorldRenderPrefs::SetShowEntityNamesOn(BOOL bOn)
{
  CWorldRenderPrefs_SetShowEntityNamesOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsEditorModelsOn()
{
  return CWorldRenderPrefs_IsEditorModelsOn(mp_handle);
}

inline void CWorldRenderPrefs::SetEditorModelsOn(BOOL bOn)
{
  CWorldRenderPrefs_SetEditorModelsOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsFieldBrushesOn()
{
  return CWorldRenderPrefs_IsFieldBrushesOn(mp_handle);
}

inline void CWorldRenderPrefs::SetFieldBrushesOn(BOOL bOn)
{
  CWorldRenderPrefs_SetFieldBrushesOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsBackgroundTextureOn()
{
  return CWorldRenderPrefs_IsBackgroundTextureOn(mp_handle);
}

inline void CWorldRenderPrefs::SetBackgroundTextureOn(BOOL bOn)
{
  CWorldRenderPrefs_SetBackgroundTextureOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsVisTweaksOn()
{
  return CWorldRenderPrefs_IsVisTweaksOn(mp_handle);
}

inline void CWorldRenderPrefs::SetVisTweaksOn(BOOL bOn)
{
  CWorldRenderPrefs_SetVisTweaksOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsVisTweaksDisabled()
{
  return CWorldRenderPrefs_IsVisTweaksDisabled(mp_handle);
}

inline void CWorldRenderPrefs::DisableVisTweaks(BOOL bOn)
{
  CWorldRenderPrefs_DisableVisTweaks(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsFogOn()
{
  return CWorldRenderPrefs_IsFogOn(mp_handle);
}

inline void CWorldRenderPrefs::SetFogOn(BOOL bOn)
{
  CWorldRenderPrefs_SetFogOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsHazeOn()
{
  return CWorldRenderPrefs_IsHazeOn(mp_handle);
}

inline void CWorldRenderPrefs::SetHazeOn(BOOL bOn)
{
  CWorldRenderPrefs_SetHazeOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsMirrorsOn()
{
  return CWorldRenderPrefs_IsMirrorsOn(mp_handle);
}

inline void CWorldRenderPrefs::SetMirrorsOn(BOOL bOn)
{
  CWorldRenderPrefs_SetMirrorsOn(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsAutoMipBrushingOn()
{
  return CWorldRenderPrefs_IsAutoMipBrushingOn(mp_handle);
}

inline void CWorldRenderPrefs::SetAutoMipBrushingOn(BOOL bOn)
{
  CWorldRenderPrefs_SetAutoMipBrushingOn(mp_handle, bOn);
}

inline void CWorldRenderPrefs::SetManualMipBrushingFactor(FLOAT fFactor)
{
  CWorldRenderPrefs_SetManualMipBrushingFactor(mp_handle, fFactor);
}

inline FLOAT CWorldRenderPrefs::GetManualMipBrushingFactor()
{
  return CWorldRenderPrefs_GetManualMipBrushingFactor(mp_handle);
}

inline BOOL CWorldRenderPrefs::IsTextureLayerOn(INDEX iTexture)
{
  return CWorldRenderPrefs_IsTextureLayerOn(mp_handle, iTexture);
}

inline void CWorldRenderPrefs::SetTextureLayerOn(BOOL bOn, INDEX iTexture)
{
  CWorldRenderPrefs_SetTextureLayerOn(mp_handle, bOn, iTexture);
}

inline FLOAT CWorldRenderPrefs::GetCurrentMipBrushingFactor(FLOAT fDistanceMipFactor)
{
  return CWorldRenderPrefs_GetCurrentMipBrushingFactor(mp_handle, fDistanceMipFactor);
}

inline void CWorldRenderPrefs::SetVerticesFillType(FillType ft)
{
  CWorldRenderPrefs_SetVerticesFillType(mp_handle, static_cast<FillType_>(ft));
}

inline CWorldRenderPrefs::FillType CWorldRenderPrefs::GetVerticesFillType()
{
  return static_cast<FillType>(CWorldRenderPrefs_GetVerticesFillType(mp_handle));
}

inline void CWorldRenderPrefs::SetVerticesInkColor(COLOR color)
{
  CWorldRenderPrefs_SetVerticesInkColor(mp_handle, color);
}

inline COLOR CWorldRenderPrefs::GetVerticesInkColor()
{
  return CWorldRenderPrefs_GetVerticesInkColor(mp_handle);
}

inline void CWorldRenderPrefs::SetEdgesFillType(FillType ft)
{
  CWorldRenderPrefs_SetEdgesFillType(mp_handle, static_cast<FillType_>(ft));
}

inline CWorldRenderPrefs::FillType CWorldRenderPrefs::GetEdgesFillType()
{
  return static_cast<FillType>(CWorldRenderPrefs_GetEdgesFillType(mp_handle));
}

inline void CWorldRenderPrefs::SetEdgesInkColor(COLOR color)
{
  CWorldRenderPrefs_SetEdgesInkColor(mp_handle, color);
}

inline COLOR CWorldRenderPrefs::GetEdgesInkColor()
{
  return CWorldRenderPrefs_GetEdgesInkColor(mp_handle);
}

inline void CWorldRenderPrefs::SetPolygonsFillType(FillType ft)
{
  CWorldRenderPrefs_SetPolygonsFillType(mp_handle, static_cast<FillType_>(ft));
}

inline CWorldRenderPrefs::FillType CWorldRenderPrefs::GetPolygonsFillType()
{
  return static_cast<FillType>(CWorldRenderPrefs_GetPolygonsFillType(mp_handle));
}

inline void CWorldRenderPrefs::SetPolygonsInkColor(COLOR color)
{
  CWorldRenderPrefs_SetPolygonsInkColor(mp_handle, color);
}

inline COLOR CWorldRenderPrefs::GetPolygonsInkColor()
{
  return CWorldRenderPrefs_GetPolygonsInkColor(mp_handle);
}

inline void CWorldRenderPrefs::SetShadowsType(ShadowsType sht)
{
  CWorldRenderPrefs_SetShadowsType(mp_handle, static_cast<ShadowsType_>(sht));
}

inline CWorldRenderPrefs::ShadowsType CWorldRenderPrefs::GetShadowsType()
{
  return static_cast<ShadowsType>(CWorldRenderPrefs_GetShadowsType(mp_handle));
}

inline void CWorldRenderPrefs::SetLensFlaresType(LensFlaresType lft)
{
  CWorldRenderPrefs_SetLensFlaresType(mp_handle, static_cast<LensFlaresType_>(lft));
}

inline CWorldRenderPrefs::LensFlaresType CWorldRenderPrefs::GetLensFlares()
{
  return static_cast<LensFlaresType>(CWorldRenderPrefs_GetLensFlares(mp_handle));
}

inline void CWorldRenderPrefs::SetMinimumRenderRange(FLOAT fRange)
{
  CWorldRenderPrefs_SetMinimumRenderRange(mp_handle, fRange);
}

inline FLOAT CWorldRenderPrefs::GetMinimumRenderRange()
{
  return CWorldRenderPrefs_GetMinimumRenderRange(mp_handle);
}

inline void CWorldRenderPrefs::SetSelectedEntityModel(CModelObject_* pmoSelection)
{
  CWorldRenderPrefs_SetSelectedEntityModel(mp_handle, pmoSelection);
}

inline CModelObjectPtr CWorldRenderPrefs::GetSelectedEntityModel()
{
  return CWorldRenderPrefs_GetSelectedEntityModel(mp_handle);
}

inline void CWorldRenderPrefs::SetSelectedPortalModel(CModelObject_* pmoSelection)
{
  CWorldRenderPrefs_SetSelectedPortalModel(mp_handle, pmoSelection);
}

inline CModelObjectPtr CWorldRenderPrefs::GetSelectedPortalModel()
{
  return CWorldRenderPrefs_GetSelectedPortalModel(mp_handle);
}

inline void CWorldRenderPrefs::SetEmptyBrushModel(CModelObject_* pmoBrush)
{
  CWorldRenderPrefs_SetEmptyBrushModel(mp_handle, pmoBrush);
}

inline CModelObjectPtr CWorldRenderPrefs::GetEmptyBrushModel()
{
  return CWorldRenderPrefs_GetEmptyBrushModel(mp_handle);
}

inline void CWorldRenderPrefs::SetSelectionType(SelectionType st)
{
  CWorldRenderPrefs_SetSelectionType(mp_handle, static_cast<SelectionType_>(st));
}

inline CWorldRenderPrefs::SelectionType CWorldRenderPrefs::GetSelectionType()
{
  return static_cast<SelectionType>(CWorldRenderPrefs_GetSelectionType(mp_handle));
}

inline void CWorldRenderPrefs::SetFarClipPlane(FLOAT f)
{
  CWorldRenderPrefs_SetFarClipPlane(mp_handle, f);
}

inline FLOAT CWorldRenderPrefs::GetFarClipPlane()
{
  return CWorldRenderPrefs_GetFarClipPlane(mp_handle);
}

inline void CWorldRenderPrefs::EnableFarClipPlaneInIsometricProjection(BOOL bOn)
{
  CWorldRenderPrefs_EnableFarClipPlaneInIsometricProjection(mp_handle, bOn);
}

inline BOOL CWorldRenderPrefs::IsFarClipPlaneInIsometricProjectionOn()
{
  return CWorldRenderPrefs_IsFarClipPlaneInIsometricProjectionOn(mp_handle);
}

inline void CWorldRenderPrefs::Read_t(CTStream* inFile)
{
  CWorldRenderPrefs_Read_t(mp_handle, *inFile);
  SECppAPI_CheckException();
}

inline void CWorldRenderPrefs::Write_t(CTStream* outFile)
{
  CWorldRenderPrefs_Write_t(mp_handle, *outFile);
  SECppAPI_CheckException();
}

inline void RenderView(CWorld& woWorld, CEntity_* enViewer, CAnyProjection3D& prProjection, CDrawPort& dpDrawport)
{
  RenderView_(woWorld, enViewer, prProjection, dpDrawport);
  SECppAPI_CheckException();
}
