#pragma once
#include "Raster.h"
#include <SeriousEngineCAPI/Graphics/ViewPort.h>

// base class for viewport
class CViewPort
{
public:
  CViewPort(CViewPort_* p, bool owner = false);
  CViewPort(PIX width, PIX height, HWND hwnd);
  ~CViewPort();

  // open/close canvas window
  void OpenCanvas();
  void CloseCanvas(BOOL bRelease = FALSE);
  /* Display the back buffer on screen. */
  void SwapBuffers();
  // change size of this viewport, it's raster and all it's drawports to fit it window
  void Resize();

  inline CViewPort_* C_Handle() { return mp_handle; }
  inline const CViewPort_* C_Handle() const { return mp_handle; }
  inline operator CViewPort_* () { return C_Handle(); }
  inline operator const CViewPort_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CViewPort_* mp_handle = nullptr;

public:
  HWND& vp_hWnd;                 // canvas (child) window
  HWND& vp_hWndParent;           // window of the viewport
  CRaster vp_Raster;            // the used Raster
};

#include "ViewPort.inl"
