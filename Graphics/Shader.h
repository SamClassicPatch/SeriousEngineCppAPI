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
#include <SeriousEngineCAPI/Graphics/Shader.h>

enum GfxBlend : GfxBlend_
{
  GFX_ONE = GFX_ONE_,
  GFX_ZERO = GFX_ZERO_,
  GFX_SRC_COLOR = GFX_SRC_COLOR_,
  GFX_INV_SRC_COLOR = GFX_INV_SRC_COLOR_,
  GFX_DST_COLOR = GFX_DST_COLOR_,
  GFX_INV_DST_COLOR = GFX_INV_DST_COLOR_,
  GFX_SRC_ALPHA = GFX_SRC_ALPHA_,
  GFX_INV_SRC_ALPHA = GFX_INV_SRC_ALPHA_,
};

enum GfxBlendEquation : GfxBlendEquation_
{
  GFX_BLENDEQ_ADD = GFX_BLENDEQ_ADD_,
  GFX_BLENDEQ_SUBTRACT = GFX_BLENDEQ_SUBTRACT_,
  GFX_BLENDEQ_REVSUBTRACT = GFX_BLENDEQ_REVSUBTRACT_,
  GFX_BLENDEQ_MIN = GFX_BLENDEQ_MIN_,
  GFX_BLENDEQ_MAX = GFX_BLENDEQ_MAX_,
};

void shaEnableBlend();
void shaDisableBlend();
void shaBlendFunc(GfxBlend eSrc, GfxBlend eDst);
GfxBlendEquation shaGetBlendEquation();
void shaBlendEquation(GfxBlendEquation blend_equation);

#include "Shader.inl"
