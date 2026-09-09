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
