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

inline CSoundLibrary::SoundFormat _pSound_SetFormat(CSoundLibrary::SoundFormat EsfNew, BOOL bReport)
{
  return (CSoundLibrary::SoundFormat)_pSound_SetFormat_((SoundFormat_)EsfNew, bReport);
}

inline CSoundLibrary::SoundFormat _pSound_GetFormat()
{
  return (CSoundLibrary::SoundFormat)_pSound_GetFormat_();
}

inline void _pSound_UpdateSounds()
{
  _pSound_UpdateSounds_();
}

inline void _pSound_MixSounds()
{
  _pSound_MixSounds_();
}

inline void _pSound_Mute()
{
  _pSound_Mute_();
}

inline BOOL _pSound_SetEnvironment(INDEX iEnvNo, FLOAT fEnvSize)
{
  return _pSound_SetEnvironment_(iEnvNo, fEnvSize);
}

inline void _pSound_AddSoundAware(CSoundData& CsdAdd)
{
  _pSound_AddSoundAware_(CsdAdd);
}

inline void _pSound_RemoveSoundAware(CSoundData& CsdRemove)
{
  _pSound_RemoveSoundAware_(CsdRemove);
}

inline void _pSound_Listen(CSoundListener& sl)
{
  _pSound_Listen_(sl);
}
