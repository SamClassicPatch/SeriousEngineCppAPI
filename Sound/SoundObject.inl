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

inline CSoundObject::CSoundObject(CSoundObject_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CSoundObject::CSoundObject()
  : m_owner(true)
  , mp_handle(CSoundObject_new())
{
}

inline CSoundObject::~CSoundObject()
{
  if (m_owner)
    CSoundObject_delete(mp_handle);
}

inline void CSoundObject::Copy(CSoundObject& soOther)
{
  CSoundObject_Copy(mp_handle, soOther);
}

inline void CSoundObject::Play(CSoundData_* pCsdLink, SLONG slFlags)
{
  CSoundObject_Play(mp_handle, pCsdLink, slFlags);
}

inline void CSoundObject::Stop()
{
  CSoundObject_Stop(mp_handle);
}

inline void CSoundObject::Stop_internal()
{
  CSoundObject_Stop_internal(mp_handle);
}

inline void CSoundObject::Pause()
{
  CSoundObject_Pause(mp_handle);
}

inline void CSoundObject::Resume()
{
  CSoundObject_Resume(mp_handle);
}

inline BOOL CSoundObject::IsPlaying()
{
  return CSoundObject_IsPlaying(mp_handle);
}

inline BOOL CSoundObject::IsPaused()
{
  return CSoundObject_IsPaused(mp_handle);
}

inline BOOL CSoundObject::IsHooked() const
{
  return CSoundObject_IsHooked(mp_handle);
}

inline void CSoundObject::SetVolume(FLOAT fLeftVolume, FLOAT fRightVolume)
{
  CSoundObject_SetVolume(mp_handle, fLeftVolume, fRightVolume);
}

inline void CSoundObject::SetFilter(FLOAT fLeftFilter, FLOAT fRightFilter)
{
  CSoundObject_SetFilter(mp_handle, fLeftFilter, fRightFilter);
}

inline void CSoundObject::SetPitch(FLOAT fPitch)
{
  CSoundObject_SetPitch(mp_handle, fPitch);
}

inline void CSoundObject::SetPhase(FLOAT fPhase)
{
  CSoundObject_SetPhase(mp_handle, fPhase);
}

inline void CSoundObject::SetDelay(FLOAT fDelay)
{
  CSoundObject_SetDelay(mp_handle, fDelay);
}

inline void CSoundObject::SetOwner(CEntity_* pen)
{
  CSoundObject_SetOwner(mp_handle, pen);
}

inline void CSoundObject::Set3DParameters(FLOAT fMaxDistance, FLOAT fMinDistance, FLOAT fMaxVolume, FLOAT fPitch)
{
  CSoundObject_Set3DParameters(mp_handle, fMaxDistance, fMinDistance, fMaxVolume, fPitch);
}

inline void CSoundObject::Read_t(CTStream* pistr)
{
  CSoundObject_Read_t(mp_handle, *pistr);
  SECppAPI_CheckException();
}

inline void CSoundObject::Write_t(CTStream* postr)
{
  CSoundObject_Write_t(mp_handle, *postr);
  SECppAPI_CheckException();
}

inline void CSoundObject::Play_t(const CTFileName& fnmSound, SLONG slFlags)
{
  CSoundObject_Play_t(mp_handle, fnmSound, slFlags);
  SECppAPI_CheckException();
}

inline void CSoundObject::SetOffset(FLOAT fOffset)
{
  CSoundObject_SetOffset(mp_handle, fOffset);
}
