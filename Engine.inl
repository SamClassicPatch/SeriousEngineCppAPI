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
