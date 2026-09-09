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

inline CPlanarGradients::CPlanarGradients(CPlanarGradients_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , pg_f00(*CPlanarGradients_pg_f00(mp_handle))
  , pg_fDOverDI(*CPlanarGradients_pg_fDOverDI(mp_handle))
  , pg_fDOverDJ(*CPlanarGradients_pg_fDOverDJ(mp_handle))
{
}

inline CPlanarGradients::CPlanarGradients()
  : m_owner(true)
  , mp_handle(CPlanarGradients_new())
  , pg_f00(*CPlanarGradients_pg_f00(mp_handle))
  , pg_fDOverDI(*CPlanarGradients_pg_fDOverDI(mp_handle))
  , pg_fDOverDJ(*CPlanarGradients_pg_fDOverDJ(mp_handle))
{
}

inline CPlanarGradients::CPlanarGradients(const CPlanarGradients& o)
  : m_owner(true)
  , mp_handle(CPlanarGradients_clone(o))
  , pg_f00(*CPlanarGradients_pg_f00(mp_handle))
  , pg_fDOverDI(*CPlanarGradients_pg_fDOverDI(mp_handle))
  , pg_fDOverDJ(*CPlanarGradients_pg_fDOverDJ(mp_handle))
{
}

inline CPlanarGradients::~CPlanarGradients()
{
  if (m_owner)
    CPlanarGradients_delete(mp_handle);
}

inline CPlanarGradients& CPlanarGradients::operator=(const CPlanarGradients& o)
{
  CPlanarGradients_copy(mp_handle, o);
  return *this;
}

inline FLOAT CPlanarGradients::GetValue(FLOAT fI, FLOAT fJ)
{
  return CPlanarGradients_GetValue(mp_handle, fI, fJ);
}

inline void CPlanarGradients::Constant(FLOAT fConst)
{
  CPlanarGradients_Constant(mp_handle, fConst);
}

inline void CPlanarGradients::Multiply(FLOAT fMul)
{
  CPlanarGradients_Multiply(mp_handle, fMul);
}

inline void CPlanarGradients::Add(FLOAT fAdd)
{
  CPlanarGradients_Add(mp_handle, fAdd);
}

inline void CPlanarGradients::TranslateOnScreen(FLOAT fI, FLOAT fJ)
{
  CPlanarGradients_TranslateOnScreen(mp_handle, fI, fJ);
}

inline CMappingDefinitionUI::CMappingDefinitionUI(CMappingDefinitionUI_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mdui_aURotation(*CMappingDefinitionUI_mdui_aURotation(mp_handle))
  , mdui_aVRotation(*CMappingDefinitionUI_mdui_aVRotation(mp_handle))
  , mdui_fUStretch(*CMappingDefinitionUI_mdui_fUStretch(mp_handle))
  , mdui_fVStretch(*CMappingDefinitionUI_mdui_fVStretch(mp_handle))
  , mdui_fUOffset(*CMappingDefinitionUI_mdui_fUOffset(mp_handle))
  , mdui_fVOffset(*CMappingDefinitionUI_mdui_fVOffset(mp_handle))
{
}

inline CMappingDefinitionUI::CMappingDefinitionUI()
  : m_owner(true)
  , mp_handle(CMappingDefinitionUI_new())
  , mdui_aURotation(*CMappingDefinitionUI_mdui_aURotation(mp_handle))
  , mdui_aVRotation(*CMappingDefinitionUI_mdui_aVRotation(mp_handle))
  , mdui_fUStretch(*CMappingDefinitionUI_mdui_fUStretch(mp_handle))
  , mdui_fVStretch(*CMappingDefinitionUI_mdui_fVStretch(mp_handle))
  , mdui_fUOffset(*CMappingDefinitionUI_mdui_fUOffset(mp_handle))
  , mdui_fVOffset(*CMappingDefinitionUI_mdui_fVOffset(mp_handle))
{
}

inline CMappingDefinitionUI::CMappingDefinitionUI(const CMappingDefinitionUI& o)
  : m_owner(true)
  , mp_handle(CMappingDefinitionUI_clone(o))
  , mdui_aURotation(*CMappingDefinitionUI_mdui_aURotation(mp_handle))
  , mdui_aVRotation(*CMappingDefinitionUI_mdui_aVRotation(mp_handle))
  , mdui_fUStretch(*CMappingDefinitionUI_mdui_fUStretch(mp_handle))
  , mdui_fVStretch(*CMappingDefinitionUI_mdui_fVStretch(mp_handle))
  , mdui_fUOffset(*CMappingDefinitionUI_mdui_fUOffset(mp_handle))
  , mdui_fVOffset(*CMappingDefinitionUI_mdui_fVOffset(mp_handle))
{
}

inline CMappingDefinitionUI::~CMappingDefinitionUI()
{
  if (m_owner)
    CMappingDefinitionUI_delete(mp_handle);
}

inline CMappingDefinitionUI& CMappingDefinitionUI::operator=(const CMappingDefinitionUI& o)
{
  CMappingDefinitionUI_copy(mp_handle, o);
  return *this;
}

inline CMappingVectors::CMappingVectors(CMappingVectors_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , mv_vO(CMappingVectors_mv_vO(mp_handle), false)
  , mv_vU(CMappingVectors_mv_vU(mp_handle), false)
  , mv_vV(CMappingVectors_mv_vV(mp_handle), false)
{
}

inline CMappingVectors::CMappingVectors()
  : m_owner(true)
  , mp_handle(CMappingVectors_new())
  , mv_vO(CMappingVectors_mv_vO(mp_handle), false)
  , mv_vU(CMappingVectors_mv_vU(mp_handle), false)
  , mv_vV(CMappingVectors_mv_vV(mp_handle), false)
{
}

inline CMappingVectors::CMappingVectors(const CMappingVectors& o)
  : m_owner(true)
  , mp_handle(CMappingVectors_clone(o))
  , mv_vO(CMappingVectors_mv_vO(mp_handle), false)
  , mv_vU(CMappingVectors_mv_vU(mp_handle), false)
  , mv_vV(CMappingVectors_mv_vV(mp_handle), false)
{
}

inline CMappingVectors::~CMappingVectors()
{
  if (m_owner)
    CMappingVectors_delete(mp_handle);
}

inline CMappingVectors& CMappingVectors::operator=(const CMappingVectors& o)
{
  CMappingVectors_copy(mp_handle, o);
  return *this;
}

inline void CMappingVectors::FromPlane(const FLOATplane3D& plPlane)
{
  CMappingVectors_FromPlane(mp_handle, plPlane);
}

inline void CMappingVectors::FromPlane_DOUBLE(const DOUBLEplane3D& plPlane)
{
  CMappingVectors_FromPlane_DOUBLE(mp_handle, plPlane);
}

inline void CMappingVectors::ToPlane(FLOATplane3D& plPlane) const
{
  CMappingVectors_ToPlane(mp_handle, plPlane);
}

inline CMappingDefinition::CMappingDefinition(CMappingDefinition_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , md_fUoS(*CMappingDefinition_md_fUoS(mp_handle))
  , md_fUoT(*CMappingDefinition_md_fUoT(mp_handle))
  , md_fVoS(*CMappingDefinition_md_fVoS(mp_handle))
  , md_fVoT(*CMappingDefinition_md_fVoT(mp_handle))
  , md_fUOffset(*CMappingDefinition_md_fUOffset(mp_handle))
  , md_fVOffset(*CMappingDefinition_md_fVOffset(mp_handle))
{
}

inline CMappingDefinition::CMappingDefinition()
  : m_owner(true)
  , mp_handle(CMappingDefinition_new())
  , md_fUoS(*CMappingDefinition_md_fUoS(mp_handle))
  , md_fUoT(*CMappingDefinition_md_fUoT(mp_handle))
  , md_fVoS(*CMappingDefinition_md_fVoS(mp_handle))
  , md_fVoT(*CMappingDefinition_md_fVoT(mp_handle))
  , md_fUOffset(*CMappingDefinition_md_fUOffset(mp_handle))
  , md_fVOffset(*CMappingDefinition_md_fVOffset(mp_handle))
{
}

inline CMappingDefinition::CMappingDefinition(const CMappingDefinition& o)
  : m_owner(true)
  , mp_handle(CMappingDefinition_clone(o))
  , md_fUoS(*CMappingDefinition_md_fUoS(mp_handle))
  , md_fUoT(*CMappingDefinition_md_fUoT(mp_handle))
  , md_fVoS(*CMappingDefinition_md_fVoS(mp_handle))
  , md_fVoT(*CMappingDefinition_md_fVoT(mp_handle))
  , md_fUOffset(*CMappingDefinition_md_fUOffset(mp_handle))
  , md_fVOffset(*CMappingDefinition_md_fVOffset(mp_handle))
{
}

inline CMappingDefinition::~CMappingDefinition()
{
  if (m_owner)
    CMappingDefinition_delete(mp_handle);
}

inline CMappingDefinition& CMappingDefinition::operator=(const CMappingDefinition& o)
{
  CMappingDefinition_copy(mp_handle, o);
  return *this;
}

inline void CMappingDefinition::ToUI(CMappingDefinitionUI& mdui) const
{
  CMappingDefinition_ToUI(mp_handle, mdui);
}

inline void CMappingDefinition::FromUI(const CMappingDefinitionUI& mdui)
{
  CMappingDefinition_FromUI(mp_handle, mdui);
}

inline void CMappingDefinition::ToMappingVectors(const CMappingVectors& mvDefault, CMappingVectors& mvVectors) const
{
  CMappingDefinition_ToMappingVectors(mp_handle, mvDefault, mvVectors);
}

inline void CMappingDefinition::FromMappingVectors(const CMappingVectors& mvDefault, const CMappingVectors& mvVectors)
{
  CMappingDefinition_FromMappingVectors(mp_handle, mvDefault, mvVectors);
}

inline void CMappingDefinition::MakeMappingVectors(const CMappingVectors& mvSrc, CMappingVectors& mvDst) const
{
  CMappingDefinition_MakeMappingVectors(mp_handle, mvSrc, mvDst);
}

inline void CMappingDefinition::TransformMappingVectors(const CMappingVectors& mvSrc, CMappingVectors& mvDst) const
{
  CMappingDefinition_TransformMappingVectors(mp_handle, mvSrc, mvDst);
}

inline void CMappingDefinition::ProjectMapping(const FLOATplane3D& plOriginal, const CMappingDefinition& mdOriginal, const FLOATplane3D& pl)
{
  CMappingDefinition_ProjectMapping(mp_handle, plOriginal, mdOriginal, pl);
}

inline void CMappingDefinition::Translate(const CMappingVectors& mvDefault, const FLOAT3D& vTranslation)
{
  CMappingDefinition_Translate(mp_handle, mvDefault, vTranslation);
}

inline void CMappingDefinition::Rotate(const CMappingVectors& mvDefault, const FLOAT3D& vRotationOrigin, ANGLE aRotation)
{
  CMappingDefinition_Rotate(mp_handle, mvDefault, vRotationOrigin, aRotation);
}

inline void CMappingDefinition::Center(const CMappingVectors& mvDefault, const FLOAT3D& vNewOrigin)
{
  CMappingDefinition_Center(mp_handle, mvDefault, vNewOrigin);
}

inline void CMappingDefinition::Transform(const FLOATplane3D& plPlane, const CPlacement3D& plSource, const CPlacement3D& plTarget)
{
  CMappingDefinition_Transform(mp_handle, plPlane, plSource, plTarget);
}

inline void CMappingDefinition::GetTextureCoordinates(const CMappingVectors& mvDefault, const FLOAT3D& vSpace, MEX2D& vTexture) const
{
  CMappingDefinition_GetTextureCoordinates(mp_handle, mvDefault, vSpace, vTexture);
}

__forceinline FLOAT2D CMappingDefinition::GetTextureCoordinates(const CMappingVectors& mvDefault, const FLOAT3D& vSpace) const
{
  FLOAT3D vOffset = vSpace - mvDefault.mv_vO;
  FLOAT s = mvDefault.mv_vU % vOffset;
  FLOAT t = mvDefault.mv_vV % vOffset;
  FLOAT u = s * md_fUoS + t * md_fUoT;
  FLOAT v = s * md_fVoS + t * md_fVoT;

  return FLOAT2D(u + md_fUOffset, v + md_fVOffset);
}

inline void CMappingDefinition::GetSpaceCoordinates(const CMappingVectors& mvDefault, const MEX2D& vTexture, FLOAT3D& vSpace) const
{
  CMappingDefinition_GetSpaceCoordinates(mp_handle, mvDefault, vTexture, vSpace);
}

inline CTStream& operator>>(CTStream& strm, CMappingDefinition& md)
{
  CMappingDefinition_extract(strm, md);
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, const CMappingDefinition& md)
{
  CMappingDefinition_insert(strm, md);
  SECppAPI_CheckException();
  return strm;
}
