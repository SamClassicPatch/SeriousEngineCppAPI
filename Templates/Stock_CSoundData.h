#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Templates/Stock_CSoundData.h>

inline CSoundDataPtr _pSoundStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pSoundStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}
