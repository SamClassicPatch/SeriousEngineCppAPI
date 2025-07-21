#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Templates/Stock_CTextureData.h>

inline CTextureData_* _pTextureStock_Obtain_t(const CTFileName_* f)
{
  auto res = _pTextureStock_Obtain_t_(f);
  SECppAPI_CheckException();
  return res;
}
