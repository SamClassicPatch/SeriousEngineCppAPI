#pragma once
#include "../Base/Types.h"
#include "../Base/Stream.h"
#include "Vector.h"
#include <SeriousEngineCAPI/Math/Placement.h>

class CPlacement3D
{
public:
  CPlacement3D(CPlacement3D_* p, bool owner = false);
  CPlacement3D();
  CPlacement3D(const CPlacement3D& o);
  CPlacement3D(const FLOAT3D& vPosition, const ANGLE3D& aOrientation);
  ~CPlacement3D();

  CPlacement3D& operator=(const CPlacement3D& o);

  BOOL operator==(const CPlacement3D& plOther) const;

  /* Rotate using trackball method. */
  void Rotate_TrackBall(const ANGLE3D& a3dRotation);
  /* Rotate using airplane method. */
  void Rotate_Airplane(const ANGLE3D& a3dRotation);
  /* Rotate using HPB method. */
  void Rotate_HPB(const ANGLE3D& a3dRotation);
  /* Rotate using HPB in own coordinate system. */
  void Rotate_HPB_OwnSystem(const ANGLE3D& rot);
  /* Translate in own coordinate system. */
  void Translate_OwnSystem(const FLOAT3D& f3dRelativeTranslation);
  /* Translate in absolute coordinate system. */
  void Translate_AbsoluteSystem(const FLOAT3D& f3dAbsoluteTranslation);

  /* Get the direction vector in the direction of this placement. */
  void GetDirectionVector(FLOAT3D& vDirection);

  /* Project this placement from absolute system to coordinate system of another placement. */
  void AbsoluteToRelative(const CPlacement3D& plSystem);
  void AbsoluteToRelativeSmooth(const CPlacement3D& plSystem);
  /* Project this placement from coordinate system of another placement to absolute system. */
  void RelativeToAbsolute(const CPlacement3D& plSystem);
  void RelativeToAbsoluteSmooth(const CPlacement3D& plSystem);
  /* Project this placement from system of one placement to system of another placement. */
  void RelativeToRelative(const CPlacement3D& plSource, const CPlacement3D& plTarget);
  void RelativeToRelativeSmooth(const CPlacement3D& plSource, const CPlacement3D& plTarget);

  /* Make this placement be a linear interpolation between given two placements. */
  void Lerp(const CPlacement3D& pl0, const CPlacement3D& pl1, FLOAT fFactor);


  inline CPlacement3D_* C_Handle() { return mp_handle; }
  inline const CPlacement3D_* C_Handle() const { return mp_handle; }
  inline operator CPlacement3D_* () { return C_Handle(); }
  inline operator const CPlacement3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CPlacement3D_* mp_handle = nullptr;

public:
  FLOAT3D pl_PositionVector;    // position in space
  ANGLE3D pl_OrientationAngle;  // angles of orientation
};

/* Stream operations */
CTStream& operator>>(CTStream& strm, CPlacement3D& p3d);
CTStream& operator<<(CTStream& strm, const CPlacement3D& p3d);

#define _plOrigin\
  CPlacement3D(_plOrigin_(), false)

#include "Placement.inl"
