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
#include <SeriousEngineCAPI/Math/Float.h>

// FPU precision setting values
enum FPUPrecisionType : FPUPrecisionType_ {
  FPT_24BIT = FPT_24BIT_,
  FPT_53BIT = FPT_53BIT_,
  FPT_64BIT = FPT_64BIT_,
};

/*
 * Class that provides automatic saving/setting/restoring of FPU precision setting.
 */
class CSetFPUPrecision {
private:
  FPUPrecisionType sfp_fptOldPrecision;
  FPUPrecisionType sfp_fptNewPrecision;
public:
  /* Constructor with automatic setting of FPU precision. */
  CSetFPUPrecision(FPUPrecisionType fptNew);
  /* Destructor with automatic restoring of FPU precision. */
  ~CSetFPUPrecision();
};

#include "Float.inl"
