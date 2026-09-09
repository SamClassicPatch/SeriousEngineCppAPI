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
#include <SeriousEngineCAPI/Math/Object3D.h>

inline CObjectVertex::CObjectVertex(CObjectVertex_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ovx_Remap(*CObjectVertex_ovx_Remap(p))
  , ovx_Tag(*CObjectVertex_ovx_Tag(p))
  , ovx_Index(*CObjectVertex_ovx_Index(p))
  , ovx_ulFlags(*CObjectVertex_ovx_ulFlags(p))
  , value(CObjectVertex_value(p), false)
{
}

inline CObjectVertex::CObjectVertex()
  : CObjectVertex(CObjectVertex_new(), true)
{
}

inline CObjectVertex::CObjectVertex(const DOUBLE3D& o)
  : CObjectVertex(CObjectVertex_new_value(o), true)
{
}

inline CObjectVertex::CObjectVertex(const CObjectVertex& o)
  : CObjectVertex(CObjectVertex_clone(o), true)
{
}

inline CObjectVertex::~CObjectVertex()
{
  if (m_owner)
    CObjectVertex_delete(mp_handle);
}

inline CObjectVertex& CObjectVertex::operator=(const CObjectVertex& o)
{
  CObjectVertex_copy(mp_handle, o);
  return *this;
}

inline CObjectPlane::CObjectPlane(CObjectPlane_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , opl_Remap(*CObjectPlane_opl_Remap(p))
  , opl_Tag(*CObjectPlane_opl_Tag(p))
  , opl_Index(*CObjectPlane_opl_Index(p))
  , value(CObjectPlane_value(p), false)
{
}

inline CObjectPlane::CObjectPlane()
  : CObjectPlane(CObjectPlane_new(), true)
{
}

inline CObjectPlane::CObjectPlane(const DOUBLEplane3D& o)
  : CObjectPlane(CObjectPlane_new_value(o), true)
{
}

inline CObjectPlane::CObjectPlane(const CObjectPlane& o)
  : CObjectPlane(CObjectPlane_clone(o), true)
{
}

inline CObjectPlane::~CObjectPlane()
{
  if (m_owner)
    CObjectPlane_delete(mp_handle);
}

inline CObjectPlane& CObjectPlane::operator=(const CObjectPlane& o)
{
  CObjectPlane_copy(mp_handle, o);
  return *this;
}

inline CObjectEdge::CObjectEdge(CObjectEdge_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , oed_Tag(*CObjectEdge_oed_Tag(p))
  , oed_Index(*CObjectEdge_oed_Index(p))
  , optimize_oed_Remap(*CObjectEdge_optimize_oed_Remap(p))
  , optimize_oed_InverseEdge(*CObjectEdge_optimize_oed_InverseEdge(p))
  , colinear1_oed_FirstChild(*CObjectEdge_colinear1_oed_FirstChild(p))
  , colinear1_oed_NextSibling(*CObjectEdge_colinear1_oed_NextSibling(p))
  , colinear2_oed_pedxLine(*CObjectEdge_colinear2_oed_pedxLine(p))
  , oed_Vertex0(*CObjectEdge_oed_Vertex0(p))
  , oed_Vertex1(*CObjectEdge_oed_Vertex1(p))
{
}

inline CObjectEdge::CObjectEdge()
  : CObjectEdge(CObjectEdge_new(), true)
{
}

inline CObjectEdge::CObjectEdge(CObjectVertex& ovxVertex0, CObjectVertex& ovxVertex1)
  : CObjectEdge(CObjectEdge_new_v(ovxVertex0, ovxVertex1), true)
{
}

inline CObjectEdge::CObjectEdge(const CObjectEdge& o)
  : CObjectEdge(CObjectEdge_clone(o), true)
{
}

inline CObjectEdge::~CObjectEdge()
{
  if (m_owner)
    CObjectEdge_delete(mp_handle);
}

inline CObjectEdge& CObjectEdge::operator=(const CObjectEdge& o)
{
  CObjectEdge_copy(mp_handle, o);
  return *this;
}

inline CObjectMaterial::CObjectMaterial(CObjectMaterial_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , omt_Tag(*CObjectMaterial_omt_Tag(p))
  , omt_Index(*CObjectMaterial_omt_Index(p))
  , omt_Name(CObjectMaterial_omt_Name(p), false)
  , omt_strName2(CObjectMaterial_omt_strName2(p), false)
  , omt_strName3(CObjectMaterial_omt_strName3(p), false)
  , omt_Color(*CObjectMaterial_omt_Color(p))
{
}

inline CObjectMaterial::CObjectMaterial()
  : CObjectMaterial(CObjectMaterial_new(), true)
{
}

inline CObjectMaterial::CObjectMaterial(const CTString& o)
  : CObjectMaterial(CObjectMaterial_new_s(o), true)
{
}

inline CObjectMaterial::CObjectMaterial(const CObjectMaterial& o)
  : CObjectMaterial(CObjectMaterial_clone(o), true)
{
}

inline CObjectMaterial::~CObjectMaterial()
{
  if (m_owner)
    CObjectMaterial_delete(mp_handle);
}

inline CObjectMaterial& CObjectMaterial::operator=(const CObjectMaterial& o)
{
  CObjectMaterial_copy(mp_handle, o);
  return *this;
}

inline CObjectPolygonEdge::CObjectPolygonEdge(CObjectPolygonEdge_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ope_Edge(*CObjectPolygonEdge_ope_Edge(p))
  , ope_Backward(*CObjectPolygonEdge_ope_Backward(p))
{
}

inline CObjectPolygonEdge::CObjectPolygonEdge()
  : CObjectPolygonEdge(CObjectPolygonEdge_new(), true)
{
}

inline CObjectPolygonEdge::CObjectPolygonEdge(CObjectEdge_* poed)
  : CObjectPolygonEdge(CObjectPolygonEdge_new_edge(poed), true)
{
}

inline CObjectPolygonEdge::CObjectPolygonEdge(CObjectEdge_* poed, BOOL bReverse)
  : CObjectPolygonEdge(CObjectPolygonEdge_new_edge_rev(poed, bReverse), true)
{
}

inline CObjectPolygonEdge::CObjectPolygonEdge(const CObjectPolygonEdge& o)
  : CObjectPolygonEdge(CObjectPolygonEdge_clone(o), true)
{
}

inline CObjectPolygonEdge::~CObjectPolygonEdge()
{
  if (m_owner)
    CObjectPolygonEdge_delete(mp_handle);
}

inline CObjectPolygonEdge& CObjectPolygonEdge::operator=(const CObjectPolygonEdge& o)
{
  CObjectPolygonEdge_copy(mp_handle, o);
  return *this;
}

inline void CObjectPolygonEdge::GetVertices(CObjectVertex_*& povxStart, CObjectVertex_*& povxEnd)
{
  CObjectPolygonEdge_GetVertices(mp_handle, &povxStart, &povxEnd);
}

IMPL_CDynamicArray(CObjectEdge)
IMPL_CDynamicArray(CObjectPolygonEdge)

inline CObjectPolygon::CObjectPolygon(CObjectPolygon_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , opo_Tag(*CObjectPolygon_opo_Tag(p))
  , opo_Index(*CObjectPolygon_opo_Index(p))
  , opo_ubUserData(CObjectPolygon_opo_ubUserData(p))
  , opo_Plane(*CObjectPolygon_opo_Plane(p))
  , opo_PolygonEdges(CObjectPolygon_opo_PolygonEdges(p), false)
  , opo_Material(*CObjectPolygon_opo_Material(p))
  , opo_amdMappings{
     {CObjectPolygon_opo_amdMappings(p, 0), false},
     {CObjectPolygon_opo_amdMappings(p, 1), false},
     {CObjectPolygon_opo_amdMappings(p, 2), false},
     {CObjectPolygon_opo_amdMappings(p, 3), false}
  }
  , opo_ulFlags(*CObjectPolygon_opo_ulFlags(p))
  , opo_colorColor(*CObjectPolygon_opo_colorColor(p))
{
}

inline CObjectPolygon::CObjectPolygon()
  : CObjectPolygon(CObjectPolygon_new(), true)
{
}

inline CObjectPolygon::~CObjectPolygon()
{
  if (m_owner)
    CObjectPolygon_delete(mp_handle);
}

inline void CObjectPolygon::JoinContinuingEdges(CDynamicArray_CObjectEdge& oedEdges)
{
  CObjectPolygon_JoinContinuingEdges(mp_handle, oedEdges);
}

inline void CObjectPolygon::RemoveRedundantEdges()
{
  CObjectPolygon_RemoveRedundantEdges(mp_handle);
}

inline void CObjectPolygon::RemoveMarkedEdges(INDEX ctNonMarkedEdges)
{
  CObjectPolygon_RemoveMarkedEdges(mp_handle, ctNonMarkedEdges);
}

inline void CObjectPolygon::RemoveDummyEdgeReferences()
{
  CObjectPolygon_RemoveDummyEdgeReferences(mp_handle);
}

IMPL_CDynamicArray(CObjectVertex)
IMPL_CDynamicArray(CObjectPlane)
IMPL_CDynamicArray(CObjectMaterial)
IMPL_CDynamicArray(CObjectPolygon)

inline CObjectSector::CObjectSector(CObjectSector_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , osc_aovxVertices(CObjectSector_osc_aovxVertices(p), false)
  , osc_aoplPlanes(CObjectSector_osc_aoplPlanes(p), false)
  , osc_aomtMaterials(CObjectSector_osc_aomtMaterials(p), false)
  , osc_aoedEdges(CObjectSector_osc_aoedEdges(p), false)
  , osc_aopoPolygons(CObjectSector_osc_aopoPolygons(p), false)
  , osc_Tag(*CObjectSector_osc_Tag(p))
  , osc_Index(*CObjectSector_osc_Index(p))
  , osc_colColor(*CObjectSector_osc_colColor(p))
  , osc_colAmbient(*CObjectSector_osc_colAmbient(p))
  , osc_strName(CObjectSector_osc_strName(p), false)
{
}

inline CObjectSector::CObjectSector()
  : CObjectSector(CObjectSector_new(), true)
{
}

inline CObjectSector::CObjectSector(CObjectSector& o)
  : CObjectSector(CObjectSector_clone(o), true)
{
}

inline CObjectSector::~CObjectSector()
{
  if (m_owner)
    CObjectSector_delete(mp_handle);
}

inline CObjectSector& CObjectSector::operator=(CObjectSector& o)
{
  CObjectSector_copy(mp_handle, o);
  return *this;
}

inline ULONG CObjectSector::osc_ulFlags(INDEX i) const
{
  return *CObjectSector_osc_ulFlags(mp_handle, i);
}

inline ULONG& CObjectSector::osc_ulFlags(INDEX i)
{
  return *CObjectSector_osc_ulFlags(mp_handle, i);
}

__forceinline CObjectPolygonPtr CObjectSector::CreatePolygon(INDEX ctVertices, INDEX aivVertices[], CObjectMaterial& omaMaterial, ULONG ulFlags, BOOL bReverse)
{
  return CObjectSector_CreatePolygon_i(mp_handle, ctVertices, aivVertices, omaMaterial, ulFlags, bReverse);
}

__forceinline CObjectPolygonPtr CObjectSector::CreatePolygon(INDEX ctVertices, CStaticArray_DOUBLE3D& avVertices, CObjectMaterial& omaMaterial, ULONG ulFlags, BOOL bReverse)
{
  return CObjectSector_CreatePolygon(mp_handle, ctVertices, CStaticArray_DOUBLE3D_Element(avVertices, 0), omaMaterial, ulFlags, bReverse);
}

inline CEdgeEx::CEdgeEx(CEdgeEx_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , edx_poedEdge(*CEdgeEx_edx_poedEdge(p))
  , edx_vDirection(CEdgeEx_edx_vDirection(p), false)
  , edx_vReferencePoint(CEdgeEx_edx_vReferencePoint(p), false)
  , edx_bReverse(*CEdgeEx_edx_bReverse(p))
{
}

inline CEdgeEx::CEdgeEx()
  : CEdgeEx(CEdgeEx_new(), true)
{
}

inline CEdgeEx::CEdgeEx(const CEdgeEx& o)
  : CEdgeEx(CEdgeEx_clone(o), true)
{
}

inline CEdgeEx::~CEdgeEx()
{
  if (m_owner)
    CEdgeEx_delete(mp_handle);
}

inline CEdgeEx& CEdgeEx::operator=(const CEdgeEx& o)
{
  CEdgeEx_copy(mp_handle, o);
  return *this;
}

IMPL_CDynamicArrayNoClear(CObjectSector)

inline CObject3D::CObject3D(CObject3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ob_aoscSectors(CObject3D_ob_aoscSectors(p), false)
{
}

inline CObject3D::CObject3D()
  : CObject3D(CObject3D_new(), true)
{
}

inline CObject3D::CObject3D(CObject3D& o)
  : CObject3D(CObject3D_clone(o), true)
{
}

inline CObject3D::~CObject3D()
{
  if (m_owner)
    CObject3D_delete(mp_handle);
}

inline CObject3D& CObject3D::operator=(CObject3D& o)
{
  CObject3D_copy(mp_handle, o);
  return *this;
}

inline CObject3D& CObject3D::operator=(const CObject3D& o)
{
  CObject3D_copy(mp_handle, const_cast<CObject3D&>(o));
  return *this;
}

inline void CObject3D::RemoveEmptySectors()
{
  CObject3D_RemoveEmptySectors(mp_handle);
}

inline void CObject3D::CreateSectorIndices()
{
  CObject3D_CreateSectorIndices(mp_handle);
}

inline void CObject3D::Clear()
{
  CObject3D_Clear(mp_handle);
}

inline void CObject3D::Optimize()
{
  CObject3D_Optimize(mp_handle);
}

inline BOOL CObject3D::ArePolygonsPlanar()
{
  return CObject3D_ArePolygonsPlanar(mp_handle);
}

inline void CObject3D::CreateSectorBSPs()
{
  CObject3D_CreateSectorBSPs(mp_handle);
}

inline void CObject3D::Project(CSimpleProjection3D_DOUBLE& pr)
{
  CObject3D_Project(mp_handle, pr);
}

inline void CObject3D::Inverse()
{
  CObject3D_Inverse(mp_handle);
}

inline void CObject3D::RecalculatePlanes()
{
  CObject3D_RecalculatePlanes(mp_handle);
}

inline void CObject3D::CSGAddRooms(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGAddRooms(mp_handle, obA, obB);
}

inline void CObject3D::CSGAddMaterial(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGAddMaterial(mp_handle, obA, obB);
}

inline void CObject3D::CSGAddMaterialReverse(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGAddMaterialReverse(mp_handle, obA, obB);
}

inline void CObject3D::CSGRemoveMaterial(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGRemoveMaterial(mp_handle, obA, obB);
}

inline void CObject3D::CSGSplitSectors(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGSplitSectors(mp_handle, obA, obB);
}

inline void CObject3D::CSGJoinSectors(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGJoinSectors(mp_handle, obA, obB);
}

inline void CObject3D::CSGSplitPolygons(CObject3D& obA, CObject3D& obB)
{
  CObject3D_CSGSplitPolygons(mp_handle, obA, obB);
}

inline void CObject3D::TurnPortalsToWalls()
{
  CObject3D_TurnPortalsToWalls(mp_handle);
}

inline void CObject3D::GetBoundingBox(DOUBLEaabbox3D& boxObject)
{
  CObject3D_GetBoundingBox(mp_handle, boxObject);
}

inline void CObject3D::DebugDump()
{
  CObject3D_DebugDump(mp_handle);
}
