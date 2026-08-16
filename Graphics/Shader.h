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
