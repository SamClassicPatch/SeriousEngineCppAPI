#pragma once

inline void MakeRotationMatrix(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeRotationMatrix_(t3dRotation, a3dAngles);
}

inline void MakeRotationMatrixFast(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeRotationMatrixFast_(t3dRotation, a3dAngles);
}

inline void MakeInverseRotationMatrix(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeInverseRotationMatrix_(t3dRotation, a3dAngles);
}

inline void MakeInverseRotationMatrixFast(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeInverseRotationMatrixFast_(t3dRotation, a3dAngles);
}

inline void DecomposeRotationMatrix(ANGLE3D& a3dAngles, const FLOATmatrix3D& t3dRotation)
{
  DecomposeRotationMatrix_(a3dAngles, t3dRotation);
}

inline void DecomposeRotationMatrixNoSnap(ANGLE3D& a3dAngles, const FLOATmatrix3D& t3dRotation)
{
  DecomposeRotationMatrixNoSnap_(a3dAngles, t3dRotation);
}

inline void AnglesToDirectionVector(const ANGLE3D& a3dAngles, FLOAT3D& vDirection)
{
  AnglesToDirectionVector_(a3dAngles, vDirection);
}

inline void DirectionVectorToAngles(const FLOAT3D& vDirection, ANGLE3D& a3dAngles)
{
  DirectionVectorToAngles_(vDirection, a3dAngles);
}

inline void DirectionVectorToAnglesNoSnap(const FLOAT3D& vDirection, ANGLE3D& a3dAngles)
{
  DirectionVectorToAnglesNoSnap_(vDirection, a3dAngles);
}

inline void UpVectorToAngles(const FLOAT3D& vUp, ANGLE3D& a3dAngles)
{
  UpVectorToAngles_(vUp, a3dAngles);
}

inline void operator^=(DOUBLEmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeRotationMatrixDOUBLE_(t3dRotation, a3dAngles);
}

inline void operator!=(DOUBLEmatrix3D& t3dRotation, const ANGLE3D& a3dAngles)
{
  MakeInverseRotationMatrixDOUBLE_(t3dRotation, a3dAngles);
}

inline void operator^=(ANGLE3D& a3dAngles, const DOUBLEmatrix3D& t3dRotation)
{
  DecomposeRotationMatrixDOUBLE_(a3dAngles, t3dRotation);
}
