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

inline CChangeable::CChangeable(CChangeable_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CChangeable::CChangeable()
  : m_owner(true)
  , mp_handle(CChangeable_new())
{
}

inline CChangeable::CChangeable(const CChangeable& o)
  : m_owner(true)
  , mp_handle(CChangeable_clone(o))
{
}

inline CChangeable::~CChangeable()
{
  if (m_owner)
    CChangeable_delete(mp_handle);
}

inline CChangeable& CChangeable::operator=(const CChangeable& o)
{
  CChangeable_copy(mp_handle, o);
  return *this;
}

inline void CChangeable::MarkChanged()
{
  CChangeable_MarkChanged(mp_handle);
}

inline BOOL CChangeable::IsUpToDate(const CUpdateable& ud) const
{
  return CChangeable_IsUpToDate(mp_handle, ud);
}
