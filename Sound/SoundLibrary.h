#pragma once
#include "../Base/Types.h"
#include "SoundData.h"
#include <SeriousEngineCAPI/Sound/SoundLibrary.h>

namespace CSoundLibrary
{
  enum SoundFormat : SoundFormat_
  {
    SF_NONE = SF_NONE_,
    SF_11025_16 = SF_11025_16_,
    SF_22050_16 = SF_22050_16_,
    SF_44100_16 = SF_44100_16_,
    SF_ILLEGAL = SF_ILLEGAL_
  };
} // namespace CSoundLibrary

  /* Set Format */
CSoundLibrary::SoundFormat _pSound_SetFormat(CSoundLibrary::SoundFormat EsfNew, BOOL bReport = FALSE);
/* Get Format */
CSoundLibrary::SoundFormat _pSound_GetFormat();

/* Update all 3d effects and copy internal data. */
void _pSound_UpdateSounds();
/* Update Mixer */
void _pSound_MixSounds();
/* Mute output until next UpdateSounds() */
void _pSound_Mute();

/* Set listener enviroment properties (EAX) */
BOOL _pSound_SetEnvironment(INDEX iEnvNo, FLOAT fEnvSize = 0);

/* Add sound in sound aware list */
void _pSound_AddSoundAware(CSoundData& CsdAdd);
/* Remove a sound mode aware object */
void _pSound_RemoveSoundAware(CSoundData& CsdRemove);

#include "SoundLibrary.inl"
