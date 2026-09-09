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

inline CPlacement3D::CPlacement3D(CPlacement3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , pl_PositionVector(CPlacement3D_pl_PositionVector(p), false)
  , pl_OrientationAngle(CPlacement3D_pl_OrientationAngle(p), false)
{
}

inline CPlacement3D::CPlacement3D()
  : m_owner(true)
  , mp_handle(CPlacement3D_new())
  , pl_PositionVector(CPlacement3D_pl_PositionVector(mp_handle), false)
  , pl_OrientationAngle(CPlacement3D_pl_OrientationAngle(mp_handle), false)
{
}

inline CPlacement3D::CPlacement3D(const CPlacement3D& o)
  : m_owner(true)
  , mp_handle(CPlacement3D_clone(o))
  , pl_PositionVector(CPlacement3D_pl_PositionVector(mp_handle), false)
  , pl_OrientationAngle(CPlacement3D_pl_OrientationAngle(mp_handle), false)
{
}

inline CPlacement3D::CPlacement3D(const FLOAT3D& vPosition, const ANGLE3D& aOrientation)
  : m_owner(true)
  , mp_handle(CPlacement3D_new_args(vPosition, aOrientation))
  , pl_PositionVector(CPlacement3D_pl_PositionVector(mp_handle), false)
  , pl_OrientationAngle(CPlacement3D_pl_OrientationAngle(mp_handle), false)
{
}

inline CPlacement3D::~CPlacement3D()
{
  if (m_owner)
    CPlacement3D_delete(mp_handle);
}

inline CPlacement3D& CPlacement3D::operator=(const CPlacement3D& o)
{
  CPlacement3D_copy(mp_handle, o);
  return *this;
}

inline BOOL CPlacement3D::operator==(const CPlacement3D& plOther) const
{
  return CPlacement3D_equal(mp_handle, plOther);
}

inline void CPlacement3D::Rotate_TrackBall(const ANGLE3D& a3dRotation)
{
  CPlacement3D_Rotate_TrackBall(mp_handle, a3dRotation);
}

inline void CPlacement3D::Rotate_Airplane(const ANGLE3D& a3dRotation)
{
  CPlacement3D_Rotate_Airplane(mp_handle, a3dRotation);
}

inline void CPlacement3D::Rotate_HPB(const ANGLE3D& a3dRotation)
{
  CPlacement3D_Rotate_HPB(mp_handle, a3dRotation);
}

inline void CPlacement3D::Rotate_HPB_OwnSystem(const ANGLE3D& rot)
{
  CPlacement3D_Rotate_HPB_OwnSystem(mp_handle, rot);
}

inline void CPlacement3D::Translate_OwnSystem(const FLOAT3D& f3dRelativeTranslation)
{
  CPlacement3D_Translate_OwnSystem(mp_handle, f3dRelativeTranslation);
}

inline void CPlacement3D::Translate_AbsoluteSystem(const FLOAT3D& f3dAbsoluteTranslation)
{
  CPlacement3D_Translate_AbsoluteSystem(mp_handle, f3dAbsoluteTranslation);
}

inline void CPlacement3D::GetDirectionVector(FLOAT3D& vDirection)
{
  CPlacement3D_GetDirectionVector(mp_handle, vDirection);
}

inline void CPlacement3D::AbsoluteToRelative(const CPlacement3D& plSystem)
{
  CPlacement3D_AbsoluteToRelative(mp_handle, plSystem);
}

inline void CPlacement3D::AbsoluteToRelativeSmooth(const CPlacement3D& plSystem)
{
  CPlacement3D_AbsoluteToRelativeSmooth(mp_handle, plSystem);
}

inline void CPlacement3D::RelativeToAbsolute(const CPlacement3D& plSystem)
{
  CPlacement3D_RelativeToAbsolute(mp_handle, plSystem);
}

inline void CPlacement3D::RelativeToAbsoluteSmooth(const CPlacement3D& plSystem)
{
  CPlacement3D_RelativeToAbsoluteSmooth(mp_handle, plSystem);
}

inline void CPlacement3D::RelativeToRelative(const CPlacement3D& plSource, const CPlacement3D& plTarget)
{
  CPlacement3D_RelativeToRelative(mp_handle, plSource, plTarget);
}

inline void CPlacement3D::RelativeToRelativeSmooth(const CPlacement3D& plSource, const CPlacement3D& plTarget)
{
  CPlacement3D_RelativeToRelativeSmooth(mp_handle, plSource, plTarget);
}

inline void CPlacement3D::Lerp(const CPlacement3D& pl0, const CPlacement3D& pl1, FLOAT fFactor)
{
  CPlacement3D_Lerp(mp_handle, pl0, pl1, fFactor);
}

inline CTStream& operator>>(CTStream& strm, CPlacement3D& p3d)
{
  CPlacement3D_extract(strm, p3d);
  SECppAPI_CheckException();
  return strm;
}

inline CTStream& operator<<(CTStream& strm, const CPlacement3D& p3d)
{
  CPlacement3D_insert(strm, p3d);
  SECppAPI_CheckException();
  return strm;
}
