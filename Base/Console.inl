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

inline void CPrintF(const char* s, ...)
{
  va_list arg;
  va_start(arg, s);
  CTString strBuffer;
  strBuffer.VPrintF(s, arg);
  CPutString_(static_cast<const char*>(strBuffer));
  va_end(arg);
}

inline void CPutString(const char* s)
{
  CPutString_(s);
}

inline BOOL REG_GetString(const CTString& strKey, CTString& strString)
{
  return REG_GetString_(strKey, strString);
}
