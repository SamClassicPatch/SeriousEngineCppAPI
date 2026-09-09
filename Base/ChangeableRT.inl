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

inline CChangeableRT::CChangeableRT(CChangeableRT_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CChangeableRT::CChangeableRT()
  : m_owner(true)
  , mp_handle(CChangeableRT_new())
{
}

inline CChangeableRT::CChangeableRT(const CChangeableRT& o)
  : m_owner(true)
  , mp_handle(CChangeableRT_clone(o))
{
}

inline CChangeableRT::~CChangeableRT()
{
  if (m_owner)
    CChangeableRT_delete(mp_handle);
}

inline CChangeableRT& CChangeableRT::operator=(const CChangeableRT& o)
{
  CChangeableRT_copy(mp_handle, o);
  return *this;
}

inline void CChangeableRT::MarkChanged()
{
  CChangeableRT_MarkChanged(mp_handle);
}

inline BOOL CChangeableRT::IsUpToDate(const CUpdateableRT& ud) const
{
  return CChangeableRT_IsUpToDate(mp_handle, ud);
}
