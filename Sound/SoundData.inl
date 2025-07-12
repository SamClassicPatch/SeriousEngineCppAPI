#pragma once

inline CSoundData::CSoundData(CSoundData_* p, bool owner)
  : CSerial((CSerial_*)p, owner)
{
}

inline CSoundData::CSoundData()
  : CSoundData(CSoundData_new(), true)
{
}

inline CSoundData::~CSoundData()
{
  if (m_owner)
    CSoundData_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline DOUBLE CSoundData::GetSecondsLength()
{
  return CSoundData_GetSecondsLength(C_Handle());
}
