#pragma once
#include "../Base/Types.h"
#include "DrawPort.h"
#include "ViewPort.h"
#include <SeriousEngineCAPI/Graphics/GfxLibrary.h>

enum GfxAPIType : INDEX
{
  GAT_NONE = GAT_NONE_,     // no gfx API (gfx functions are disabled)
  GAT_OGL = GAT_OGL_,     // OpenGL
  GAT_D3D = GAT_D3D_,     // Direct3D
  GAT_CURRENT = GAT_CURRENT_,   // current API
};

enum DisplayDepth : INDEX
{
  DD_NODEPTH = DD_NODEPTH_,
  DD_DEFAULT = DD_DEFAULT_,
  DD_16BIT = DD_16BIT_,
  DD_32BIT = DD_32BIT_,
  DD_24BIT = DD_24BIT_, // for z-buffer
};

BOOL _pGfx_SetDisplayMode(GfxAPIType eAPI, INDEX iAdapter, PIX pixSizeI, PIX pixSizeJ, DisplayDepth eColorDepth);
BOOL _pGfx_ResetDisplayMode(GfxAPIType eAPI);
GfxAPIType _pGfx_GetCurrentAPI();
INDEX _pGfx_GetCurrentAdapter();
BOOL _pGfx_IsCurrentModeAccelerated();
BOOL _pGfx_HasAPI(GfxAPIType eAPI);
void _pGfx_CreateWindowCanvas(void* hWnd, CViewPortPtr& vp, CDrawPortPtr& dp);
void _pGfx_DestroyWindowCanvas(CViewPortPtr& pvpOld);
void _pGfx_CreateWorkCanvas(PIX pixWidth, PIX pixHeight, CDrawPortPtr& dp);
void _pGfx_DestroyWorkCanvas(CDrawPortPtr& pdpOld);

#include "GfxLibrary.inl"
