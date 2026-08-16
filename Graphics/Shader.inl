#pragma once

inline void shaEnableBlend()
{
  shaEnableBlend_();
}

inline void shaDisableBlend()
{
  shaDisableBlend_();
}

inline void shaBlendFunc(GfxBlend eSrc, GfxBlend eDst)
{
  shaBlendFunc_(static_cast<GfxBlend_>(eSrc), static_cast<GfxBlend_>(eDst));
}

inline GfxBlendEquation shaGetBlendEquation()
{
  return static_cast<GfxBlendEquation>(shaGetBlendEquation_());
}

inline void shaBlendEquation(GfxBlendEquation blend_equation)
{
  shaBlendEquation_(static_cast<GfxBlendEquation_>(blend_equation));
}
