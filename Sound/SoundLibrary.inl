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
