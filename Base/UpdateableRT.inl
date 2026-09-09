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

inline CUpdateableRT::CUpdateableRT(CUpdateableRT_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CUpdateableRT::CUpdateableRT()
  : m_owner(true)
  , mp_handle(CUpdateableRT_new())
{
}

inline CUpdateableRT::CUpdateableRT(const CUpdateableRT& o)
  : m_owner(true)
  , mp_handle(CUpdateableRT_clone(o))
{
}

inline CUpdateableRT::~CUpdateableRT()
{
  if (m_owner)
    CUpdateableRT_delete(mp_handle);
}

inline CUpdateableRT& CUpdateableRT::operator=(const CUpdateableRT& o)
{
  CUpdateableRT_copy(mp_handle, o);
  return *this;
}

inline TIME CUpdateableRT::LastUpdateTime() const
{
  return CUpdateableRT_LastUpdateTime(mp_handle);
}

inline void CUpdateableRT::MarkUpdated()
{
  CUpdateableRT_MarkUpdated(mp_handle);
}

inline void CUpdateableRT::Invalidate()
{
  CUpdateableRT_Invalidate(mp_handle);
}
