#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Templates/Stock_CModelData.h>

inline CModelDataPtr _pModelStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pModelStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}
