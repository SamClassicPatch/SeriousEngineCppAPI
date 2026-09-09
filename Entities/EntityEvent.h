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
#include "../Base/Types.h"

class CEntityEvent
{
public:
  inline CEntityEvent(CEntityEvent_* p) : mp_handle(p) {}
  inline virtual ~CEntityEvent() = 0 {};

  inline CEntityEvent_* C_Handle() { return mp_handle; }
  inline const CEntityEvent_* C_Handle() const { return mp_handle; }
  inline operator CEntityEvent_* () { return C_Handle(); }
  inline operator const CEntityEvent_* () const { return C_Handle(); }

protected:
  CEntityEvent_* mp_handle = nullptr;
};
