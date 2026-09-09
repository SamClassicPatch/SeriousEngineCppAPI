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
#include "Types.h"
#include <SeriousEngineCAPI/Base/UpdateableRT.h>

/*
 * Object that can be updated to reflect changes in some changeable object(s).
 */
class CUpdateableRT
{
public:
  CUpdateableRT(CUpdateableRT_* p, bool owner = false);
  CUpdateableRT();
  CUpdateableRT(const CUpdateableRT& o);
  ~CUpdateableRT();

  CUpdateableRT& operator=(const CUpdateableRT& o);

  /* Get time when last updated. */
  TIME LastUpdateTime() const;
  /* Mark that the object has been updated. */
  void MarkUpdated();
  /* Mark that the object has become invalid in spite of its time stamp. */
  void Invalidate();

  inline CUpdateableRT_* C_Handle() { return mp_handle; }
  inline const CUpdateableRT_* C_Handle() const { return mp_handle; }
  inline operator CUpdateableRT_* () { return C_Handle(); }
  inline operator const CUpdateableRT_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CUpdateableRT_* mp_handle = nullptr;
};

#include "UpdateableRT.inl"
