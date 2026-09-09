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
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Profiling.h>

class CProfileForm
{
public:
  CProfileForm(CProfileForm_* p);
  ~CProfileForm();

  /* Reset all profiling values. */
  void Reset();

  /* Report profiling results. */
  void Report(CTString& strReport);

private:
  CProfileForm_* mp_handle;
};

#define _pfGfxProfile\
  CProfileForm(_pfGfxProfile_())

#define _pfModelProfile\
  CProfileForm(_pfModelProfile_())

#define _pfSoundProfile\
  CProfileForm(_pfSoundProfile_())

#define _pfNetworkProfile\
  CProfileForm(_pfNetworkProfile_())

#define _pfRenderProfile\
  CProfileForm(_pfRenderProfile_())

#define _pfWorldEditingProfile\
  CProfileForm(_pfWorldEditingProfile_())

#define _pfPhysicsProfile\
  CProfileForm(_pfPhysicsProfile_())

#include "Profiling.inl"
