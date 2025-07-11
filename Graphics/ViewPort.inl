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
