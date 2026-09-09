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
#include "../Entities/EntityEvent.h"
#include <SeriousEngineCAPI/Classes/BaseEvents.h>

class EFirstWorldBase : public CEntityEvent
{
public:
  EFirstWorldBase(EFirstWorldBase_* p, bool owner = false);
  EFirstWorldBase();
  EFirstWorldBase(const EFirstWorldBase& o);
  ~EFirstWorldBase();
  EFirstWorldBase& operator=(const EFirstWorldBase& o);

  inline EFirstWorldBase_* C_Handle() { return CEntityEvent_to_EFirstWorldBase(mp_handle); }
  inline const EFirstWorldBase_* C_Handle() const { return CEntityEvent_to_EFirstWorldBase_const(mp_handle); }
  inline operator EFirstWorldBase_* () { return C_Handle(); }
  inline operator const EFirstWorldBase_* () const { return C_Handle(); }

private:
  bool m_owner = true;
};

#include "BaseEvents.inl"
