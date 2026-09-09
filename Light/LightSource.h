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
#include <SeriousEngineCAPI/Light/LightSource.h>

class CLightSource
{
public:
  CLightSource(CLightSource_* p, bool dummy = false);
  ~CLightSource();
  CLightSource(const CLightSource& ln) = delete;
  CLightSource& operator=(const CLightSource& ln) = delete;

  inline CLightSource_* C_Handle() { return mp_handle; }
  inline const CLightSource_* C_Handle() const { return mp_handle; }
  inline operator CLightSource_* () { return C_Handle(); }
  inline operator const CLightSource_* () const { return C_Handle(); }
private:
  CLightSource_* mp_handle = nullptr;

public:
  ULONG& ls_ulFlags; // various flags
  CEntity_*& ls_penEntity; // the entity of this light source
};

#include "LightSource.inl"
