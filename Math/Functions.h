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
#include <SeriousEngineCAPI/Math/Functions.h>

template<class Type>
inline Type Abs(const Type x)
{
  return (x >= Type(0) ? x : -x);
}

template<class Type>
inline Type Max(const Type a, const Type b)
{
  return (a < b ? b : a);
}

template<class Type>
inline Type Min(const Type a, const Type b)
{
  return (a > b ? b : a);
}

// linear interpolation
template<class Type>
inline Type Lerp(const Type x0, const Type x1, const FLOAT fRatio)
{
  if (fRatio == 0) return x0;
  else if (fRatio == 1) return x1;
  else return x0 + (x1 - x0) * fRatio;
}

template<class Type>
inline Type Sgn(const Type x)
{
  return (x) > Type(0) ? Type(1) : (x < 0 ? Type(-1) : Type(0));
}

template<class Type>
inline Type SgnNZ(const Type x)
{
  return (x) >= Type(0) ? Type(1) : Type(-1);
}

template<class Type>
inline void Swap(Type& a, Type& b)
{
  Type t = a; a = b;  b = t;
}

template<class Type>
inline Type ClampUp(const Type x, const Type uplimit)
{
  return (x <= uplimit ? x : uplimit);
}

template<class Type>
inline Type ClampDn(const Type x, const Type dnlimit)
{
  return (x >= dnlimit ? x : dnlimit);
}

template<class Type>
inline Type Clamp(const Type x, const Type dnlimit, const Type uplimit)
{
  return (x >= dnlimit ? (x <= uplimit ? x : uplimit) : dnlimit);
}

template<class Type>
void HashCombine(size_t& seed, Type v)
{
  std::hash<Type> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

ULONG NormFloatToByte(const FLOAT f);
FLOAT NormByteToFloat(const ULONG ul);
SLONG FloatToInt(FLOAT f);
FLOAT Log2(FLOAT f);
FLOAT Sqrt(FLOAT x);
ANGLE WrapAngle(ANGLE a);
ANGLE NormalizeAngle(ANGLE a);
ANGLE AngleDeg(FLOAT fDegrees);
ANGLE AngleRad(DOUBLE dRadians);
FLOAT DegAngle(ANGLE aAngle);
FLOAT RadAngle(ANGLE aAngle);
FLOAT Sin(ANGLE a);
FLOAT Cos(ANGLE a);
FLOAT Tan(ANGLE a);
FLOAT SinFast(ANGLE a);
FLOAT CosFast(ANGLE a);
FLOAT TanFast(ANGLE a);
ANGLE ASin(DOUBLE y);
ANGLE ACos(DOUBLE x);
ANGLE ATan(DOUBLE z);
ANGLE ATan2(DOUBLE y, DOUBLE x);
void Snap(DOUBLE& dest, DOUBLE step);
void Snap(FLOAT& dest, FLOAT step);
FLOAT LerpFLOAT(FLOAT f0, FLOAT f1, FLOAT fFactor);
ANGLE LerpANGLE(ANGLE a0, ANGLE a1, FLOAT fFactor);
FLOAT CalculateRatio(FLOAT fCurr, FLOAT fMin, FLOAT fMax, FLOAT fFadeInRatio, FLOAT fFadeOutRatio);

#include "Functions.inl"
