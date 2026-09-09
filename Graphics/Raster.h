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
#include <SeriousEngineCAPI/Graphics/Raster.h>

class CRaster
{
public:
  CRaster(CRaster_* p);

  inline CRaster_* C_Handle() { return mp_handle; }
  inline const CRaster_* C_Handle() const { return mp_handle; }
  inline operator CRaster_* () { return C_Handle(); }
  inline operator const CRaster_* () const { return C_Handle(); }

private:
  CRaster_* mp_handle;

public:
  CViewPort_*& ra_pvpViewPort;
};

#include "Raster.inl"
