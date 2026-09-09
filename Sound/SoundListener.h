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
#include "../Math/Vector.h"
#include "../Math/Matrix.h"
#include <SeriousEngineCAPI/Sound/SoundListener.h>

class CSoundListener
{
public:
  CSoundListener(CSoundListener_* p, bool owner = false);
  CSoundListener();
  CSoundListener(const CSoundListener& o);
  ~CSoundListener();
  CSoundListener& operator=(const CSoundListener& o);

  inline CSoundListener_* C_Handle() { return mp_handle; }
  inline const CSoundListener_* C_Handle() const { return mp_handle; }
  inline operator CSoundListener_* () { return C_Handle(); }
  inline operator const CSoundListener_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CSoundListener_* mp_handle = nullptr;

public:
  FLOAT3D sli_vPosition;          // listener position
  FLOATmatrix3D sli_mRotation;    // listener rotation matrix
  FLOAT3D sli_vSpeed;             // speed of the listener
  FLOAT& sli_fVolume;              // listener volume (i.e. deaf factor)
  FLOAT& sli_fFilter;              // global filter for all sounds on this listener
  CEntity_*& sli_penEntity;         // listener entity (for listener local sounds)
  INDEX& sli_iEnvironmentType;     // EAX environment predefine
  FLOAT& sli_fEnvironmentSize;     // EAX environment size
};

#include "SoundListener.inl"
