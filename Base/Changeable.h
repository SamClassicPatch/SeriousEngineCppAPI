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
#include "Updateable.h"
#include <SeriousEngineCAPI/Base/Changeable.h>

/*
 * Object that can change in time.
 */
class CChangeable
{
public:
  CChangeable(CChangeable_* p, bool owner = false);
  CChangeable();
  CChangeable(const CChangeable& o);
  virtual ~CChangeable();

  CChangeable& operator=(const CChangeable& o);

  /* Mark that something has changed in this object. */
  void MarkChanged();
  /* Test if some updateable object is up to date with this changeable. */
  BOOL IsUpToDate(const CUpdateable& ud) const;

  inline CChangeable_* C_Handle() { return mp_handle; }
  inline const CChangeable_* C_Handle() const { return mp_handle; }
  inline operator CChangeable_* () { return C_Handle(); }
  inline operator const CChangeable_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  CChangeable_* mp_handle = nullptr;
};

#include "Changeable.inl"
