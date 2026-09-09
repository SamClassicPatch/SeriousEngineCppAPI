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

inline CTCriticalSection::CTCriticalSection(CTCriticalSection_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CTCriticalSection::CTCriticalSection()
  : m_owner(true)
  , mp_handle(CTCriticalSection_new())
{
}

inline CTCriticalSection::~CTCriticalSection()
{
  if (m_owner)
    CTCriticalSection_delete(mp_handle);
}

inline CTSingleLock::CTSingleLock(CTSingleLock_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CTSingleLock::CTSingleLock(CTCriticalSection_* pcs, BOOL bLock)
  : m_owner(true)
  , mp_handle(CTSingleLock_new(pcs, bLock))
{
}

inline CTSingleLock::~CTSingleLock()
{
  if (m_owner)
    CTSingleLock_delete(mp_handle);
}

inline void CTSingleLock::Lock()
{
  CTSingleLock_Lock(mp_handle);
}

inline BOOL CTSingleLock::TryToLock()
{
  return CTSingleLock_TryToLock(mp_handle);
}

inline BOOL CTSingleLock::IsLocked()
{
  return CTSingleLock_IsLocked(mp_handle);
}

inline void CTSingleLock::Unlock()
{
  CTSingleLock_Unlock(mp_handle);
}

