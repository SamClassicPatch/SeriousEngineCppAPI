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
