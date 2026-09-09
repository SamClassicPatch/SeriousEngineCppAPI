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

inline CEntityPointer::CEntityPointer(CEntityPointer_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CEntityPointer::CEntityPointer()
  : CEntityPointer(CEntityPointer_new(), true)
{
}

inline CEntityPointer::CEntityPointer(const CEntityPointer& o)
  : CEntityPointer(CEntityPointer_clone(o), true)
{
}

inline CEntityPointer::CEntityPointer(CEntity_* o)
  : CEntityPointer(CEntityPointer_new_e(o), true)
{
}

inline CEntityPointer::~CEntityPointer()
{
  if (m_owner)
    CEntityPointer_delete(C_Handle());
}

inline CEntityPointer& CEntityPointer::operator=(const CEntityPointer& o)
{
  CEntityPointer_copy(C_Handle(), o);
  return *this;
}

inline CEntityPointer& CEntityPointer::operator=(CEntity_* o)
{
  CEntityPointer_copy_e(C_Handle(), o);
  return *this;
}

inline bool CEntityPointer::operator==(const CEntityPointer& o) const
{
  return CEntityPointer_equal(C_Handle(), o) == TRUE;
}

inline bool CEntityPointer::operator==(const CEntity_* o) const
{
  return *CEntityPointer_ep_pen(C_Handle()) == o;
}

inline bool CEntityPointer::operator!=(const CEntityPointer& o) const
{
  return !((*this) == o);
}

inline bool CEntityPointer::operator!=(const CEntity_* o) const
{
  return !((*this) == o);
}

inline CEntityPointer::operator bool()
{
  return *CEntityPointer_ep_pen(C_Handle()) != nullptr;
}

inline CEntityPointer::operator bool() const
{
  return *CEntityPointer_ep_pen(C_Handle()) != nullptr;
}

__forceinline CEntityPtr CEntityPointer::ep_pen() const
{
  return *CEntityPointer_ep_pen(C_Handle());
}

__forceinline CEntityPtr CEntityPointer::operator->() const
{
  return ep_pen();
}

__forceinline CEntityPointer::operator CEntityPtr() const
{
  return ep_pen();
}

__forceinline CEntity& CEntityPointer::operator*() const
{
  mp_cache = ep_pen();
  return *mp_cache;
}
