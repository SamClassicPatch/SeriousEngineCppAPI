#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Templates/Stock_CAnimData.h>

inline CAnimData_* _pAnimStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pAnimStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}
