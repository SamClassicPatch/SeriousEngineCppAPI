#pragma once
#include <SeriousEngineCAPI/Math/Projection_DOUBLE.h>

inline CSimpleProjection3D_DOUBLE::CSimpleProjection3D_DOUBLE(CSimpleProjection3D_DOUBLE_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , pr_ObjectPlacement(CSimpleProjection3D_DOUBLE_pr_ObjectPlacement(p), false)
  , pr_ViewerPlacement(CSimpleProjection3D_DOUBLE_pr_ViewerPlacement(p), false)
  , pr_ObjectStretch(CSimpleProjection3D_DOUBLE_pr_ObjectStretch(p), false)
  , pr_Prepared(*CSimpleProjection3D_DOUBLE_pr_Prepared(p))
  , pr_RotationMatrix(CSimpleProjection3D_DOUBLE_pr_RotationMatrix(p), false)
  , pr_ViewerRotationMatrix(CSimpleProjection3D_DOUBLE_pr_ViewerRotationMatrix(p), false)
  , pr_TranslationVector(CSimpleProjection3D_DOUBLE_pr_TranslationVector(p), false)
{
}

inline CSimpleProjection3D_DOUBLE::CSimpleProjection3D_DOUBLE()
  : CSimpleProjection3D_DOUBLE(CSimpleProjection3D_DOUBLE_new(), true)
{
}

inline CSimpleProjection3D_DOUBLE::CSimpleProjection3D_DOUBLE(const CSimpleProjection3D_DOUBLE& o)
  : CSimpleProjection3D_DOUBLE(CSimpleProjection3D_DOUBLE_clone(o), true)
{
}

inline CSimpleProjection3D_DOUBLE::~CSimpleProjection3D_DOUBLE()
{
  if (m_owner)
    CSimpleProjection3D_DOUBLE_delete(mp_handle);
}

inline CSimpleProjection3D_DOUBLE& CSimpleProjection3D_DOUBLE::operator=(const CSimpleProjection3D_DOUBLE& o)
{
  CSimpleProjection3D_DOUBLE_copy(mp_handle, o);
  return *this;
}

inline void CSimpleProjection3D_DOUBLE::Prepare()
{
  CSimpleProjection3D_DOUBLE_Prepare(mp_handle);
}

inline void CSimpleProjection3D_DOUBLE::ProjectCoordinate(const DOUBLE3D& v3dObjectPoint, DOUBLE3D& v3dViewPoint) const
{
  CSimpleProjection3D_DOUBLE_ProjectCoordinate(mp_handle, v3dObjectPoint, v3dViewPoint);
}

inline void CSimpleProjection3D_DOUBLE::ProjectDirection(const DOUBLE3D& v3dObjectPoint, DOUBLE3D& v3dViewPoint) const
{
  CSimpleProjection3D_DOUBLE_ProjectDirection(mp_handle, v3dObjectPoint, v3dViewPoint);
}

inline void CSimpleProjection3D_DOUBLE::ProjectPlacement(const CPlacement3D& plObject, CPlacement3D& plView) const
{
  CSimpleProjection3D_DOUBLE_ProjectPlacement(mp_handle, plObject, plView);
}

inline void CSimpleProjection3D_DOUBLE::ProjectMapping(const CMappingDefinition& mdObject, const DOUBLEplane3D& plObject, CMappingDefinition& mdView) const
{
  CSimpleProjection3D_DOUBLE_ProjectMapping(mp_handle, mdObject, plObject, mdView);
}

inline void CSimpleProjection3D_DOUBLE::ProjectAABBox(const DOUBLEaabbox3D& boxObject, DOUBLEaabbox3D& boxView) const
{
  CSimpleProjection3D_DOUBLE_ProjectAABBox(mp_handle, boxObject, boxView);
}

inline void CSimpleProjection3D_DOUBLE::Project(const DOUBLEplane3D& p3dObjectPlane, DOUBLEplane3D& v3dTransformedPlane) const
{
  CSimpleProjection3D_DOUBLE_Project(mp_handle, p3dObjectPlane, v3dTransformedPlane);
}
