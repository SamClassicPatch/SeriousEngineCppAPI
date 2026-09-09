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
#include "DrawPort.h"
#include "ViewPort.h"
#include "DisplayMode.h"
#include <SeriousEngineCAPI/Graphics/GfxLibrary.h>

enum GfxAPIType : GfxAPIType_
{
  GAT_NONE = GAT_NONE_,     // no gfx API (gfx functions are disabled)
  GAT_OGL = GAT_OGL_,     // OpenGL
  GAT_D3D = GAT_D3D_,     // Direct3D
  GAT_CURRENT = GAT_CURRENT_,   // current API
};

CDisplayModePtr _pGfx_GetEnumeratedDisplayMode(CDisplayModeEnumerator_* p, INDEX i);
CDisplayModeEnumerator_* _pGfx_EnumDisplayModes(INDEX& ctModes, GfxAPIType eAPI = GAT_CURRENT, INDEX iAdapter = 0);
BOOL _pGfx_SetDisplayMode(GfxAPIType eAPI, INDEX iAdapter, PIX pixSizeI, PIX pixSizeJ, DisplayDepth eColorDepth);
BOOL _pGfx_ResetDisplayMode(GfxAPIType eAPI = GAT_CURRENT);
GfxAPIType _pGfx_GetCurrentAPI();
INDEX _pGfx_GetCurrentAdapter();
void _pGfx_GetCurrentDisplayMode(CDisplayMode& dmCurrent);
BOOL _pGfx_IsCurrentModeAccelerated();
BOOL _pGfx_HasAPI(GfxAPIType eAPI);
void _pGfx_CreateWindowCanvas(void* hWnd, CViewPortPtr& vp, CDrawPortPtr& dp);
void _pGfx_DestroyWindowCanvas(CViewPortPtr& pvpOld);
void _pGfx_CreateWorkCanvas(PIX pixWidth, PIX pixHeight, CDrawPortPtr& dp);
void _pGfx_DestroyWorkCanvas(CDrawPortPtr& pdpOld);

#define _iTexForcedQuality\
  (*_iTexForcedQuality_())

#include "GfxLibrary.inl"
