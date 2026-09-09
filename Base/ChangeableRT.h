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
#include "UpdateableRT.h"
#include <SeriousEngineCAPI/Base/ChangeableRT.h>

/*
 * Object that can change in time.
 */
class CChangeableRT
{
public:
  CChangeableRT(CChangeableRT_* p, bool owner = false);
  CChangeableRT();
  CChangeableRT(const CChangeableRT& o);
  virtual ~CChangeableRT();

  CChangeableRT& operator=(const CChangeableRT& o);

  /* Mark that something has changed in this object. */
  void MarkChanged();
  /* Test if some updateable object is up to date with this changeable. */
  BOOL IsUpToDate(const CUpdateableRT& ud) const;

  inline CChangeableRT_* C_Handle() { return mp_handle; }
  inline const CChangeableRT_* C_Handle() const { return mp_handle; }
  inline operator CChangeableRT_* () { return C_Handle(); }
  inline operator const CChangeableRT_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  CChangeableRT_* mp_handle = nullptr;
};

#include "ChangeableRT.inl"
