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

inline CViewPort::CViewPort(CViewPort_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , vp_hWnd(*CViewPort_vp_hWnd(mp_handle))
  , vp_hWndParent(*CViewPort_vp_hWndParent(mp_handle))
  , vp_Raster(CViewPort_vp_Raster(mp_handle))
{
}

inline CViewPort::CViewPort(PIX width, PIX height, HWND hwnd)
  : CViewPort(CViewPort_new(width, height, hwnd), true)
{
}

inline CViewPort::~CViewPort()
{
  if (m_owner)
    CViewPort_delete(mp_handle);
}

inline void CViewPort::OpenCanvas()
{
  CViewPort_OpenCanvas(mp_handle);
}

inline void CViewPort::CloseCanvas(BOOL bRelease)
{
  CViewPort_CloseCanvas(mp_handle, bRelease);
}

inline void CViewPort::SwapBuffers()
{
  CViewPort_SwapBuffers(mp_handle);
}

inline void CViewPort::Resize()
{
  CViewPort_Resize(mp_handle);
}
