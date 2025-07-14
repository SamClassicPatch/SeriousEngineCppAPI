#pragma once

inline ULONG NormFloatToByte(const FLOAT f)
{
  return NormFloatToByte_(f);
}

inline FLOAT NormByteToFloat(const ULONG ul)
{
  return NormByteToFloat_(ul);
}

inline SLONG FloatToInt(FLOAT f)
{
  return FloatToInt_(f);
}

inline FLOAT Log2(FLOAT f)
{
  return Log2_(f);
}

inline FLOAT Sqrt(FLOAT x)
{
  return Sqrt_(x);
}

inline ANGLE WrapAngle(ANGLE a)
{
  return WrapAngle_(a);
}

inline ANGLE NormalizeAngle(ANGLE a)
{
  return NormalizeAngle_(a);
}

inline ANGLE AngleDeg(FLOAT fDegrees)
{
  return AngleDeg_(fDegrees);
}

inline ANGLE AngleRad(DOUBLE dRadians)
{
  return AngleRad_(dRadians);
}

inline FLOAT DegAngle(ANGLE aAngle)
{
  return DegAngle_(aAngle);
}

inline FLOAT RadAngle(ANGLE aAngle)
{
  return RadAngle_(aAngle);
}

inline FLOAT Sin(ANGLE a)
{
  return Sin_(a);
}

inline FLOAT Cos(ANGLE a)
{
  return Cos_(a);
}

inline FLOAT Tan(ANGLE a)
{
  return Tan_(a);
}

inline FLOAT SinFast(ANGLE a)
{
  return SinFast_(a);
}

inline FLOAT CosFast(ANGLE a)
{
  return CosFast_(a);
}

inline FLOAT TanFast(ANGLE a)
{
  return TanFast_(a);
}

inline ANGLE ASin(DOUBLE y)
{
  return ASin_(y);
}

inline ANGLE ACos(DOUBLE x)
{
  return ACos_(x);
}

inline ANGLE ATan(DOUBLE z)
{
  return ATan_(z);
}

inline ANGLE ATan2(DOUBLE y, DOUBLE x)
{
  return ATan2_(y, x);
}

inline void Snap(DOUBLE& dest, DOUBLE step)
{
  Snap_(&dest, step);
}

inline void Snap(FLOAT& dest, FLOAT step)
{
  Snap_f(&dest, step);
}

inline FLOAT LerpFLOAT(FLOAT f0, FLOAT f1, FLOAT fFactor)
{
  return LerpFLOAT_(f0, f1, fFactor);
}

inline ANGLE LerpANGLE(ANGLE a0, ANGLE a1, FLOAT fFactor)
{
  return LerpANGLE_(a0, a1, fFactor);
}

inline FLOAT CalculateRatio(FLOAT fCurr, FLOAT fMin, FLOAT fMax, FLOAT fFadeInRatio, FLOAT fFadeOutRatio)
{
  return CalculateRatio_(fCurr, fMin, fMax, fFadeInRatio, fFadeOutRatio);
}
