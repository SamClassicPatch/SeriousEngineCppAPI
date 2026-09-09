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

inline CUpdateable::CUpdateable(CUpdateable_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CUpdateable::CUpdateable()
  : m_owner(true)
  , mp_handle(CUpdateable_new())
{
}

inline CUpdateable::CUpdateable(const CUpdateable& o)
  : m_owner(true)
  , mp_handle(CUpdateable_clone(o))
{
}

inline CUpdateable::~CUpdateable()
{
  if (m_owner)
    CUpdateable_delete(mp_handle);
}

inline CUpdateable& CUpdateable::operator=(const CUpdateable& o)
{
  CUpdateable_copy(mp_handle, o);
  return *this;
}

inline TIME CUpdateable::LastUpdateTime() const
{
  return CUpdateable_LastUpdateTime(mp_handle);
}

inline void CUpdateable::MarkUpdated()
{
  CUpdateable_MarkUpdated(mp_handle);
}

inline void CUpdateable::Invalidate()
{
  CUpdateable_Invalidate(mp_handle);
}
