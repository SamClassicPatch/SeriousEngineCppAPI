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
