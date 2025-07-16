#pragma once

inline COLOR RGBToColor(UBYTE ubR, UBYTE ubG, UBYTE ubB)
{
  return RGBToColor_(ubR, ubG, ubB);
}

inline void ColorToRGB(COLOR col, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB)
{
  ColorToRGB_(col, &ubR, &ubG, &ubB);
}

inline COLOR RGBAToColor(UBYTE ubR, UBYTE ubG, UBYTE ubB, UBYTE ubA)
{
  return RGBAToColor_(ubR, ubG, ubB, ubA);
}

inline void ColorToRGBA(COLOR col, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB, UBYTE& ubA)
{
  ColorToRGBA_(col, &ubR, &ubG, &ubB, &ubA);
}

inline COLOR HSVToColor(UBYTE ubH, UBYTE ubS, UBYTE ubV)
{
  return HSVToColor_(ubH, ubS, ubV);
}

inline void ColorToHSV(COLOR colSrc, UBYTE& ubH, UBYTE& ubS, UBYTE& ubV)
{
  ColorToHSV_(colSrc, &ubH, &ubS, &ubV);
}

inline COLOR HSVAToColor(UBYTE ubH, UBYTE ubS, UBYTE ubV, UBYTE ubA)
{
  return HSVAToColor_(ubH, ubS, ubV, ubA);
}

inline void ColorToHSVA(COLOR colSrc, UBYTE& ubH, UBYTE& ubS, UBYTE& ubV, UBYTE& ubA)
{
  ColorToHSVA_(colSrc, &ubH, &ubS, &ubV, &ubA);
}

inline BOOL IsGray(COLOR col)
{
  return IsGray_(col);
}

inline BOOL IsBlack(COLOR col)
{
  return IsBlack_(col);
}

inline BOOL IsWhite(COLOR col)
{
  return IsWhite_(col);
}

inline COLOR DesaturateColor(COLOR col)
{
  return DesaturateColor_(col);
}

inline BOOL IsBigger(COLOR col1, COLOR col2)
{
  return IsBigger_(col1, col2);
}

inline BOOL CompareChroma(COLOR col1, COLOR col2)
{
  return CompareChroma_(col1, col2);
}

inline COLOR AdjustColor(COLOR col, SLONG slHueShift, SLONG slSaturation)
{
  return AdjustColor_(col, slHueShift, slSaturation);
}

inline COLOR AdjustGamma(COLOR col, FLOAT fGamma)
{
  return AdjustGamma_(col, fGamma);
}

inline COLOR LerpColor(COLOR col0, COLOR col1, FLOAT fRatio)
{
  return LerpColor_(col0, col1, fRatio);
}

inline void LerpColor(COLOR col0, COLOR col1, FLOAT fRatio, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB)
{
  LerpColor_b(col0, col1, fRatio, &ubR, &ubG, &ubB);
}

inline COLOR MulColors(COLOR col1, COLOR col2)
{
  return MulColors_(col1, col2);
}

inline COLOR AddColors(COLOR col1, COLOR col2)
{
  return AddColors_(col1, col2);
}

inline ULONG ByteSwap(ULONG ul)
{
  return ByteSwap_(ul);
}
