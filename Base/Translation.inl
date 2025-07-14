#pragma once
#include "FileName.h"
#include "../Templates/DynamicArray.h"
#include <SeriousEngineCAPI/Base/Translation.h>

inline void InitTranslation()
{
  InitTranslation_();
}

inline void AddTranslationTable_t(const CTFileName& fnmTable)
{
  AddTranslationTable_t(fnmTable);
  SECppAPI_CheckException();
}

inline void AddTranslationTablesDir_t(const CTFileName& fnmDir, const CTFileName& fnmPattern)
{
  AddTranslationTablesDir_t_(fnmDir, fnmPattern);
  SECppAPI_CheckException();
}

inline void FinishTranslationTable()
{
  FinishTranslationTable_();
}

inline void ReadTranslationTable_t(CDynamicArray_CTranslationPair& atpPairs, const CTFileName& fnmTable)
{
  ReadTranslationTable_t_(atpPairs, fnmTable);
  SECppAPI_CheckException();
}

inline char* Translate(const char* str, INDEX iOffset)
{
  return Translate_((char*)str, iOffset);
}

inline const char* TranslateConst(const char* str, INDEX iOffset)
{
  return TranslateConst_(str, iOffset);
}
