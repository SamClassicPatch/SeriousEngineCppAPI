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
#include <SeriousEngineCAPI/Engine.h>

inline void SE_InitEngine(CTString strGameID)
{
  SE_InitEngine_(strGameID);
  SECppAPI_CheckException();
}

inline void SE_InitEngineAtDirectory(CTString strGameID, const CTFileName& fnAppPath, const CTFileName& fnExePath)
{
  SE_InitEngineAtDirectory_(strGameID, fnAppPath, fnExePath);
  SECppAPI_CheckException();
}

inline void SE_EndEngine()
{
  SE_EndEngine_();
  SECppAPI_CheckException();
}

inline void SE_LoadDefaultFonts()
{
  SE_LoadDefaultFonts_();
  SECppAPI_CheckException();
}

inline void SE_UpdateWindowHandle(HWND hwndWindowed)
{
  SE_UpdateWindowHandle_(hwndWindowed);
  SECppAPI_CheckException();
}

inline void SE_PretouchIfNeeded()
{
  SE_PretouchIfNeeded_();
  SECppAPI_CheckException();
}
