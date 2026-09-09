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

__forceinline CDisplayModePtr _pGfx_GetEnumeratedDisplayMode(CDisplayModeEnumerator_* p, INDEX i)
{
  return _pGfx_GetEnumeratedDisplayMode_(p, i);
}

inline CDisplayModeEnumerator_* _pGfx_EnumDisplayModes(INDEX& ctModes, GfxAPIType eAPI, INDEX iAdapter)
{
  return _pGfx_EnumDisplayModes_(&ctModes, (GfxAPIType_)eAPI, iAdapter);
}

inline BOOL _pGfx_SetDisplayMode(GfxAPIType eAPI, INDEX iAdapter, PIX pixSizeI, PIX pixSizeJ, DisplayDepth eColorDepth)
{
  return _pGfx_SetDisplayMode_((GfxAPIType_)eAPI, iAdapter, pixSizeI, pixSizeJ, (DisplayDepth_)eColorDepth);
}

inline BOOL _pGfx_ResetDisplayMode(GfxAPIType eAPI)
{
  return _pGfx_ResetDisplayMode_((GfxAPIType_)eAPI);
}

inline GfxAPIType _pGfx_GetCurrentAPI()
{
  return (GfxAPIType)_pGfx_GetCurrentAPI_();
}

inline INDEX _pGfx_GetCurrentAdapter()
{
  return _pGfx_GetCurrentAdapter_();
}

inline BOOL _pGfx_IsCurrentModeAccelerated()
{
  return _pGfx_IsCurrentModeAccelerated_();
}

inline void _pGfx_GetCurrentDisplayMode(CDisplayMode& dmCurrent)
{
  _pGfx_GetCurrentDisplayMode_(dmCurrent);
}

inline BOOL _pGfx_HasAPI(GfxAPIType eAPI)
{
  return _pGfx_HasAPI_((GfxAPIType_)eAPI);
}

inline void _pGfx_CreateWindowCanvas(void* hWnd, CViewPortPtr& vp, CDrawPortPtr& dp)
{
  CViewPort_* pvp = nullptr;
  CDrawPort_* pdp = nullptr;
  _pGfx_CreateWindowCanvas_(hWnd, &pvp, &pdp);
  vp = pvp;
  dp = pdp;
}

inline void _pGfx_DestroyWindowCanvas(CViewPortPtr& pvpOld)
{
  _pGfx_DestroyWindowCanvas_(pvpOld.get_handle());
  pvpOld.Reset();
}

inline void _pGfx_CreateWorkCanvas(PIX pixWidth, PIX pixHeight, CDrawPortPtr& dp)
{
  CDrawPort_* pdp = nullptr;
  _pGfx_CreateWorkCanvas_(pixWidth, pixHeight, &pdp);
  dp = pdp;
}

inline void _pGfx_DestroyWorkCanvas(CDrawPortPtr& pdpOld)
{
  _pGfx_DestroyWorkCanvas_(pdpOld.get_handle());
  pdpOld.Reset();
}
