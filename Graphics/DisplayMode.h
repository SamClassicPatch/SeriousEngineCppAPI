#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Graphics/DisplayMode.h>

enum DisplayDepth : INDEX
{
  DD_NODEPTH = DD_NODEPTH_,
  DD_DEFAULT = DD_DEFAULT_,
  DD_16BIT = DD_16BIT_,
  DD_32BIT = DD_32BIT_,
  DD_24BIT = DD_24BIT_, // for z-buffer
};

class CDisplayMode
{
public:
  CDisplayMode(CDisplayMode_* p, bool owner = false);
  CDisplayMode();
  CDisplayMode(const CDisplayMode& o);
  ~CDisplayMode();
  CDisplayMode& operator=(const CDisplayMode& o);

  // get depth string
  CTString DepthString() const;
  // check if mode is dualhead
  BOOL IsDualHead();
  // check if mode is widescreen
  BOOL IsWideScreen();
  // check if mode is fullscreen
  BOOL IsFullScreen();

  inline CDisplayMode_* C_Handle() { return mp_handle; }
  inline const CDisplayMode_* C_Handle() const { return mp_handle; }
  inline operator CDisplayMode_* () { return C_Handle(); }
  inline operator const CDisplayMode_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CDisplayMode_* mp_handle = nullptr;

public:
  PIX& dm_pixSizeI; // size of screen in pixels
  PIX& dm_pixSizeJ;
  DisplayDepth& dm_ddDepth;  // bits per pixel for color
};

#include "DisplayMode.inl"
