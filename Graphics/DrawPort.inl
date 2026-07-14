#pragma once

inline CDrawPort::CDrawPort(CDrawPort_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , dp_Width(*CDrawPort_dp_Width(mp_handle))
  , dp_Height(*CDrawPort_dp_Height(mp_handle))
  , dp_MinI(*CDrawPort_dp_MinI(mp_handle))
  , dp_MinJ(*CDrawPort_dp_MinJ(mp_handle))
  , dp_MaxI(*CDrawPort_dp_MaxI(mp_handle))
  , dp_MaxJ(*CDrawPort_dp_MaxJ(mp_handle))
  , dp_ScissorMinI(*CDrawPort_dp_ScissorMinI(mp_handle))
  , dp_ScissorMinJ(*CDrawPort_dp_ScissorMinJ(mp_handle))
  , dp_ScissorMaxI(*CDrawPort_dp_ScissorMaxI(mp_handle))
  , dp_ScissorMaxJ(*CDrawPort_dp_ScissorMaxJ(mp_handle))
  , dp_pixTextCharSpacing(*CDrawPort_dp_pixTextCharSpacing(mp_handle))
  , dp_pixTextLineSpacing(*CDrawPort_dp_pixTextLineSpacing(mp_handle))
  , dp_fTextScaling(*CDrawPort_dp_fTextScaling(mp_handle))
  , dp_fTextAspect(*CDrawPort_dp_fTextAspect(mp_handle))
  , dp_iTextMode(*CDrawPort_dp_iTextMode(mp_handle))
  , dp_fWideAdjustment(*CDrawPort_dp_fWideAdjustment(mp_handle))
  , dp_bRenderingOverlay(*CDrawPort_dp_bRenderingOverlay(mp_handle))
  , dp_SizeIOverRasterSizeI(*CDrawPort_dp_SizeIOverRasterSizeI(mp_handle))
  , dp_SizeJOverRasterSizeJ(*CDrawPort_dp_SizeJOverRasterSizeJ(mp_handle))
  , dp_MinIOverRasterSizeI(*CDrawPort_dp_MinIOverRasterSizeI(mp_handle))
  , dp_MinJOverRasterSizeJ(*CDrawPort_dp_MinJOverRasterSizeJ(mp_handle))
  , dp_ulBlendingRA(*CDrawPort_dp_ulBlendingRA(mp_handle))
  , dp_ulBlendingGA(*CDrawPort_dp_ulBlendingGA(mp_handle))
  , dp_ulBlendingBA(*CDrawPort_dp_ulBlendingBA(mp_handle))
  , dp_ulBlendingA(*CDrawPort_dp_ulBlendingA(mp_handle))
{
}

inline CDrawPort::CDrawPort(CRaster_* praBase)
  : CDrawPort(CDrawPort_new(praBase), true)
{
}

inline CDrawPort::CDrawPort(CDrawPort_* pdpBase, DOUBLE rMinI, DOUBLE rMinJ, DOUBLE rSizeI, DOUBLE rSizeJ)
  : CDrawPort(CDrawPort_new_cloned(pdpBase, rMinI, rMinJ, rSizeI, rSizeJ), true)
{
}

inline CDrawPort::CDrawPort(CDrawPort_* pdpBase, const PIXaabbox2D& box)
  : CDrawPort(CDrawPort_new_cloned_box(pdpBase, box), true)
{
}

inline CDrawPort::CDrawPort(CDrawPort_* pdpBase, BOOL bLeft)
  : CDrawPort(CDrawPort_new_cloned_dualhead(pdpBase, bLeft), true)
{
}

inline CDrawPort::~CDrawPort()
{
  if (m_owner)
    CDrawPort_delete(mp_handle);
}

__forceinline CRaster CDrawPort::dp_Raster()
{
  return CRaster(CDrawPort_dp_Raster(mp_handle));
}

__forceinline const CRaster CDrawPort::dp_Raster() const
{
  return CRaster(CDrawPort_dp_Raster((CDrawPort_*)mp_handle));
}

__forceinline CFontDataPtr CDrawPort::dp_FontData()
{
  return CDrawPort_dp_FontData(mp_handle);
}

__forceinline const CFontDataPtr CDrawPort::dp_FontData() const
{
  return CDrawPort_dp_FontData((CDrawPort_*)mp_handle);
}

inline void CDrawPort::SetOrtho() const
{
  CDrawPort_SetOrtho(mp_handle);
}

inline void CDrawPort::SetProjection(CAnyProjection3D& apr) const
{
  CDrawPort_SetProjection(mp_handle, apr);
}

inline void CDrawPort::MakeWideScreen(CDrawPort_* pdp)
{
  CDrawPort_MakeWideScreen(mp_handle, pdp);
}

inline BOOL CDrawPort::IsDualHead()
{
  return CDrawPort_IsDualHead(mp_handle);
}

inline BOOL CDrawPort::IsWideScreen()
{
  return CDrawPort_IsWideScreen(mp_handle);
}

inline void CDrawPort::SetOverlappedRendering(BOOL bOverlay)
{
  dp_bRenderingOverlay = bOverlay;
}

inline BOOL CDrawPort::IsOverlappedRendering() const
{
  return dp_bRenderingOverlay;
}

inline ULONG CDrawPort::GetID()
{
  return CDrawPort_GetID(mp_handle);
}

inline PIX CDrawPort::GetWidth() const
{
  return dp_Width;
}

inline PIX CDrawPort::GetHeight() const
{
  return dp_Height;
}

inline void CDrawPort::SetFont(CFontDataPtr pfd)
{
  CDrawPort_SetFont(mp_handle, pfd.get_handle());
}

inline void CDrawPort::SetTextCharSpacing(PIX pixSpacing)
{
  dp_pixTextCharSpacing = pixSpacing;
}

inline void CDrawPort::SetTextLineSpacing(PIX pixSpacing)
{
  dp_pixTextLineSpacing = pixSpacing;
}

inline void CDrawPort::SetTextScaling(FLOAT fScalingFactor)
{
  dp_fTextScaling = fScalingFactor;
}

inline void CDrawPort::SetTextAspect(FLOAT fAspectRatio)
{
  dp_fTextAspect = fAspectRatio;
}

inline void CDrawPort::SetTextMode(INDEX iMode)
{
  dp_iTextMode = iMode;
}

inline ULONG CDrawPort::GetTextWidth(const CTString& strText) const
{
  return CDrawPort_GetTextWidth(mp_handle, strText);
}

inline void CDrawPort::PutText(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend) const
{
  CDrawPort_PutText(mp_handle, strText, pixX0, pixY0, colBlend);
}

inline void CDrawPort::PutTextC(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend) const
{
  CDrawPort_PutTextC(mp_handle, strText, pixX0, pixY0, colBlend);
}

inline void CDrawPort::PutTextCXY(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend) const
{
  CDrawPort_PutTextCXY(mp_handle, strText, pixX0, pixY0, colBlend);
}

inline void CDrawPort::PutTextR(const CTString& strText, PIX pixX0, PIX pixY0, const COLOR colBlend) const
{
  CDrawPort_PutTextR(mp_handle, strText, pixX0, pixY0, colBlend);
}

inline void CDrawPort::PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen, const COLOR colBlend) const
{
  CDrawPort_PutTexture_b(mp_handle, pTO, boxScreen, colBlend);
}

inline void CDrawPort::PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR) const
{
  CDrawPort_PutTexture_cols(mp_handle, pTO, boxScreen, colUL, colUR, colDL, colDR);
}

inline void CDrawPort::PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen, const MEXaabbox2D& boxTexture, const COLOR colBlend) const
{
  CDrawPort_PutTexture_box_b(mp_handle, pTO, boxScreen, boxTexture, colBlend);
}

inline void CDrawPort::PutTexture(CTextureObject_* pTO, const PIXaabbox2D& boxScreen, const MEXaabbox2D& boxTexture, const COLOR colUL, const COLOR colUR, const COLOR colDL, const COLOR colDR) const
{
  CDrawPort_PutTexture_box_cols(mp_handle, pTO, boxScreen, boxTexture, colUL, colUR, colDL, colDR);
}

inline void CDrawPort::InitTexture(CTextureObject_* pTO, const BOOL bClamp) const
{
  CDrawPort_InitTexture(mp_handle, pTO, bClamp);
}

inline void CDrawPort::AddTexture(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const COLOR col) const
{
  CDrawPort_AddTexture_1(mp_handle, fI0, fJ0, fI1, fJ1, col);
}

inline void CDrawPort::AddTexture(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fU0, const FLOAT fV0, const FLOAT fU1, const FLOAT fV1, const COLOR col) const
{
  CDrawPort_AddTexture_2(mp_handle, fI0, fJ0, fI1, fJ1, fU0, fV0, fU1, fV1, col);
}

inline void CDrawPort::AddTexture(
  const FLOAT fI0, const FLOAT fJ0, const FLOAT fU0, const FLOAT fV0, const COLOR col0,
  const FLOAT fI1, const FLOAT fJ1, const FLOAT fU1, const FLOAT fV1, const COLOR col1,
  const FLOAT fI2, const FLOAT fJ2, const FLOAT fU2, const FLOAT fV2, const COLOR col2,
  const FLOAT fI3, const FLOAT fJ3, const FLOAT fU3, const FLOAT fV3, const COLOR col3) const
{
  CDrawPort_AddTexture_3(mp_handle,
    fI0, fJ0, fU0, fV0, col0,
    fI1, fJ1, fU1, fV1, col1,
    fI2, fJ2, fU2, fV2, col2,
    fI3, fJ3, fU3, fV3, col3);
}

inline void CDrawPort::AddTriangle(const FLOAT fI0, const FLOAT fJ0, const FLOAT fI1, const FLOAT fJ1, const FLOAT fI2, const FLOAT fJ2, const COLOR col) const
{
  CDrawPort_AddTriangle(mp_handle, fI0, fJ0, fI1, fJ1, fI2, fJ2, col);
}

inline void CDrawPort::FlushRenderingQueue() const
{
  CDrawPort_FlushRenderingQueue(mp_handle);
}

inline BOOL CDrawPort::Lock()
{
  return CDrawPort_Lock(mp_handle);
}

inline void CDrawPort::Unlock()
{
  CDrawPort_Unlock(mp_handle);
}

inline void CDrawPort::DrawPoint(PIX pixI, PIX pixJ, COLOR col, PIX pixRadius) const
{
  CDrawPort_DrawPoint(mp_handle, pixI, pixJ, col, pixRadius);
}

inline void CDrawPort::DrawPoint3D(FLOAT3D v, COLOR col, FLOAT fRadius) const
{
  CDrawPort_DrawPoint3D(mp_handle, v, col, fRadius);
}

inline void CDrawPort::DrawLine(PIX pixI0, PIX pixJ0, PIX pixI1, PIX pixJ1, COLOR col, ULONG typ) const
{
  CDrawPort_DrawLine(mp_handle, pixI0, pixJ0, pixI1, pixJ1, col, typ);
}

inline void CDrawPort::DrawLine3D(FLOAT3D v0, FLOAT3D v1, COLOR col) const
{
  CDrawPort_DrawLine3D(mp_handle, v0, v1, col);
}

inline void CDrawPort::DrawBorder(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col, ULONG typ) const
{
  CDrawPort_DrawBorder(mp_handle, pixI, pixJ, pixWidth, pixHeight, col, typ);
}

inline void CDrawPort::Fill(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR col) const
{
  CDrawPort_Fill_1(mp_handle, pixI, pixJ, pixWidth, pixHeight, col);
}

inline void CDrawPort::Fill(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, COLOR colUL, COLOR colUR, COLOR colDL, COLOR colDR) const
{
  CDrawPort_Fill_2(mp_handle, pixI, pixJ, pixWidth, pixHeight, colUL, colUR, colDL, colDR);
}

inline void CDrawPort::FillZBuffer(PIX pixI, PIX pixJ, PIX pixWidth, PIX pixHeight, FLOAT zval) const
{
  CDrawPort_FillZBuffer_1(mp_handle, pixI, pixJ, pixWidth, pixHeight, zval);
}

inline void CDrawPort::Fill(COLOR col) const
{
  CDrawPort_Fill_3(mp_handle, col);
}

inline void CDrawPort::FillZBuffer(FLOAT zval) const
{
  CDrawPort_FillZBuffer_2(mp_handle, zval);
}

inline void CDrawPort::GrabScreen(CImageInfo& iiGrabbedImage, INDEX iGrabZBuffer) const
{
  CDrawPort_GrabScreen(mp_handle, iiGrabbedImage, iGrabZBuffer);
}

inline BOOL CDrawPort::IsPointVisible(PIX pixI, PIX pixJ, FLOAT fOoK, INDEX iID, INDEX iMirrorLevel) const
{
  return CDrawPort_IsPointVisible(mp_handle, pixI, pixJ, fOoK, iID, iMirrorLevel);
}

inline void CDrawPort::RenderLensFlare(CTextureObject* pto, FLOAT fI, FLOAT fJ, FLOAT fSizeI, FLOAT fSizeJ, ANGLE aRotation, COLOR colLight) const
{
  CDrawPort_RenderLensFlare(mp_handle, *pto, fI, fJ, fSizeI, fSizeJ, aRotation, colLight);
}

inline void CDrawPort::BlendScreen()
{
  CDrawPort_BlendScreen(mp_handle);
}


inline void Particle_PrepareSystem(CDrawPort_* pdpDrawPort, CAnyProjection3D& prProjection)
{
  Particle_PrepareSystem_(pdpDrawPort, prProjection);
}

inline void Particle_PrepareEntity(FLOAT fMipFactor, BOOL bHasFog, BOOL bHasHaze, CEntity_* penViewer)
{
  Particle_PrepareEntity_(fMipFactor, bHasFog, bHasHaze, penViewer);
}

inline void Particle_EndSystem(BOOL bRestoreOrtho)
{
  Particle_EndSystem_(bRestoreOrtho);
}

inline FLOAT Particle_GetMipFactor()
{
  return Particle_GetMipFactor_();
}

inline INDEX Particle_GetDrawPortID()
{
  return Particle_GetDrawPortID_();
}

inline CEntity_* Particle_GetViewer()
{
  return Particle_GetViewer_();
}

__forceinline CProjection3DPtr Particle_GetProjection()
{
  return Particle_GetProjection_();
}

inline void Particle_PrepareTexture(CTextureObject_* pto, ParticleBlendType pbt)
{
  Particle_PrepareTexture_(pto, (ParticleBlendType_)pbt);
}

inline void Particle_SetTexturePart(MEX mexWidth, MEX mexHeight, INDEX iCol, INDEX iRow)
{
  Particle_SetTexturePart_(mexWidth, mexHeight, iCol, iRow);
}

inline void Particle_RenderSquare(const FLOAT3D& vPos, FLOAT fSize, ANGLE aRotation, COLOR col, FLOAT fYRatio)
{
  Particle_RenderSquare_(vPos, fSize, aRotation, col, fYRatio);
}

inline void Particle_RenderQuad3D(const FLOAT3D& vPos0, const FLOAT3D& vPos1, const FLOAT3D& vPos2, const FLOAT3D& vPos3, COLOR col)
{
  Particle_RenderQuad3D_(vPos0, vPos1, vPos2, vPos3, col);
}

inline void Particle_RenderLine(const FLOAT3D& vPos0, const FLOAT3D& vPos1, FLOAT fWidth, COLOR col)
{
  Particle_RenderLine_(vPos0, vPos1, fWidth, col);
}

inline void Particle_Sort(BOOL b3D)
{
  Particle_Sort_(b3D);
}

inline void Particle_Flush()
{
  Particle_Flush_();
}
