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

inline CSerial::CSerial(CSerial_* p, bool owner)
  : CChangeable(CChangeable_From_CSerial(p), owner)
  , m_name((CTFileName_*)CSerial_GetName(C_Handle()), false)
{
}

inline CSerial::~CSerial()
{
}

inline const CTFileName& CSerial::GetName()
{
  return m_name;
}

__forceinline CTString CSerial::GetDescription()
{
  return CTString(CSerial_GetDescription(C_Handle()), true);
}

inline void CSerial::Load_t(const CTFileName fnFileName)
{
  CSerial_Load_t(C_Handle(), fnFileName);
  SECppAPI_CheckException();
}

inline void CSerial::Save_t(const CTFileName fnFileName)
{
  CSerial_Save_t(C_Handle(), fnFileName);
  SECppAPI_CheckException();
}

inline void CSerial::Reload()
{
  CSerial_Reload(C_Handle());
  SECppAPI_CheckException();
}

inline void CSerial::MarkUsed()
{
  CSerial_MarkUsed(C_Handle());
}

inline void CSerial::MarkUnused()
{
  CSerial_MarkUnused(C_Handle());
}

inline BOOL CSerial::IsUsed()
{
  return CSerial_IsUsed(C_Handle());
}

inline INDEX CSerial::GetUsedCount()
{
  return CSerial_GetUsedCount(C_Handle());
}

inline void CSerial::Clear()
{
  CSerial_Clear(C_Handle());
  SECppAPI_CheckException();
}

inline void CSerial::Read_t(CTStream* istrFile)
{
  CSerial_Read_t(C_Handle(), *istrFile);
  SECppAPI_CheckException();
}

inline void CSerial::Write_t(CTStream* ostrFile)
{
  CSerial_Write_t(C_Handle(), *ostrFile);
  SECppAPI_CheckException();
}

inline BOOL CSerial::IsAutoFreed()
{
  return CSerial_IsAutoFreed(C_Handle());
}

inline SLONG CSerial::GetUsedMemory()
{
  return CSerial_GetUsedMemory(C_Handle());
}

inline void CSerial::AddToCRCTable()
{
  CSerial_AddToCRCTable(C_Handle());
  SECppAPI_CheckException();
}
