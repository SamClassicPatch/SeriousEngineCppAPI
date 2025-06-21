#include "Translation.h"
#include "FileName.h"
#include "../Templates/DynamicArray.h"
#include <SeriousEngineCAPI/Base/Translation.h>

void InitTranslation()
{
  InitTranslation_();
}

void AddTranslationTable_t(const CTFileName& fnmTable)
{
  AddTranslationTable_t(fnmTable);
  SECppAPI_CheckException();
}

void AddTranslationTablesDir_t(const CTFileName& fnmDir, const CTFileName& fnmPattern)
{
  AddTranslationTablesDir_t_(fnmDir, fnmPattern);
  SECppAPI_CheckException();
}

void FinishTranslationTable()
{
  FinishTranslationTable_();
}

void ReadTranslationTable_t(CDynamicArray_CTranslationPair& atpPairs, const CTFileName& fnmTable)
{
  ReadTranslationTable_t_(atpPairs, fnmTable);
  SECppAPI_CheckException();
}

char* Translate(char* str, INDEX iOffset)
{
  return Translate_(str, iOffset);
}

const char* TranslateConst(const char* str, INDEX iOffset)
{
  return TranslateConst_(str, iOffset);
}
