#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Templates/Stock_CEntityClass.h>

inline CEntityClassPtr _pEntityClassStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pEntityClassStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}
