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
#include "Vector.h"
#include "Matrix.h"
#include <SeriousEngineCAPI/Math/Geometry.h>

/*
 * General geometry functions
 */

 /* Calculate rotation matrix from angles in 3D. */
void MakeRotationMatrix(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
void MakeRotationMatrixFast(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
/* Calculate inverse rotation matrix from angles in 3D. */
void MakeInverseRotationMatrix(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
void MakeInverseRotationMatrixFast(FLOATmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
/* Decompose rotation matrix into angles in 3D. */
void DecomposeRotationMatrix(ANGLE3D& a3dAngles, const FLOATmatrix3D& t3dRotation);
void DecomposeRotationMatrixNoSnap(ANGLE3D& a3dAngles, const FLOATmatrix3D& t3dRotation);

/* Create direction vector from angles in 3D (ignoring banking). */
void AnglesToDirectionVector(const ANGLE3D& a3dAngles, FLOAT3D& vDirection);
/* Create angles in 3D from direction vector(ignoring banking).
   (direction must be normalized!)*/
void DirectionVectorToAngles(const FLOAT3D& vDirection, ANGLE3D& a3dAngles);
void DirectionVectorToAnglesNoSnap(const FLOAT3D& vDirection, ANGLE3D& a3dAngles);
/* Create angles in 3D from up vector (ignoring objects relative heading).
   (up vector must be normalized!)*/
void UpVectorToAngles(const FLOAT3D& vUp, ANGLE3D& a3dAngles);

/* Calculate rotation matrix from angles in 3D. */
void operator^=(DOUBLEmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
/* Calculate inverse rotation matrix from angles in 3D. */
void operator!=(DOUBLEmatrix3D& t3dRotation, const ANGLE3D& a3dAngles);
/* Decompose rotation matrix into angles in 3D. */
void operator^=(ANGLE3D& a3dAngles, const DOUBLEmatrix3D& t3dRotation);

#include "Geometry.inl"
