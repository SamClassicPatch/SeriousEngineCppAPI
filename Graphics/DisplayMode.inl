#pragma once

inline CDisplayMode::CDisplayMode(CDisplayMode_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , dm_pixSizeI(*CDisplayMode_dm_pixSizeI(mp_handle))
  , dm_pixSizeJ(*CDisplayMode_dm_pixSizeJ(mp_handle))
  , dm_ddDepth(*((DisplayDepth*)CDisplayMode_dm_ddDepth(mp_handle)))
{
}

inline CDisplayMode::CDisplayMode()
  : CDisplayMode(CDisplayMode_new(), true)
{
}

inline CDisplayMode::CDisplayMode(const CDisplayMode& o)
  : CDisplayMode(CDisplayMode_clone(o), true)
{
}

inline CDisplayMode::~CDisplayMode()
{
  if (m_owner)
    CDisplayMode_delete(mp_handle);
}

inline CDisplayMode& CDisplayMode::operator=(const CDisplayMode& o)
{
  CDisplayMode_copy(mp_handle, o);
  return *this;
}

__forceinline CTString CDisplayMode::DepthString() const
{
  return CTString(CDisplayMode_DepthString(mp_handle), true);
}

inline BOOL CDisplayMode::IsDualHead()
{
  return CDisplayMode_IsDualHead(mp_handle);
}

inline BOOL CDisplayMode::IsWideScreen()
{
  return CDisplayMode_IsWideScreen(mp_handle);
}

inline BOOL CDisplayMode::IsFullScreen()
{
  return CDisplayMode_IsFullScreen(mp_handle);
}
