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

inline EFirstWorldBase::EFirstWorldBase(EFirstWorldBase_* p, bool owner)
  : CEntityEvent(EFirstWorldBase_to_CEntityEvent(p))
  , m_owner(owner)
{
}

inline EFirstWorldBase::EFirstWorldBase()
  : EFirstWorldBase(EFirstWorldBase_new(), true)
{
}

inline EFirstWorldBase::EFirstWorldBase(const EFirstWorldBase& o)
  : EFirstWorldBase(EFirstWorldBase_clone(o), true)
{
}

inline EFirstWorldBase::~EFirstWorldBase()
{
  if (m_owner)
    EFirstWorldBase_delete(C_Handle());
}

inline EFirstWorldBase& EFirstWorldBase::operator=(const EFirstWorldBase& o)
{
  EFirstWorldBase_copy(C_Handle(), o);
  return *this;
}
