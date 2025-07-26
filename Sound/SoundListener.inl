#pragma once

inline CSoundListener::CSoundListener(CSoundListener_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , sli_vPosition(CSoundListener_sli_vPosition(mp_handle), false)
  , sli_mRotation(CSoundListener_sli_mRotation(mp_handle), false)
  , sli_vSpeed(CSoundListener_sli_vSpeed(mp_handle), false)
  , sli_fVolume(*CSoundListener_sli_fVolume(mp_handle))
  , sli_fFilter(*CSoundListener_sli_fFilter(mp_handle))
  , sli_penEntity(*CSoundListener_sli_penEntity(mp_handle))
  , sli_iEnvironmentType(*CSoundListener_sli_iEnvironmentType(mp_handle))
  , sli_fEnvironmentSize(*CSoundListener_sli_fEnvironmentSize(mp_handle))
{
}

inline CSoundListener::CSoundListener()
  : CSoundListener(CSoundListener_new(), true)
{
}

inline CSoundListener::CSoundListener(const CSoundListener& o)
  : CSoundListener(CSoundListener_clone(o), true)
{
}

inline CSoundListener::~CSoundListener()
{
  if (m_owner)
    CSoundListener_delete(mp_handle);
}

inline CSoundListener& CSoundListener::operator=(const CSoundListener& o)
{
  CSoundListener_copy(mp_handle, o);
  return *this;
}
