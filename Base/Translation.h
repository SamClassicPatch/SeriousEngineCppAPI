#pragma once
#include "Types.h"

// init translation routines with given translation table
SECAPI void InitTranslation();
// add given translation table
SECAPI void AddTranslationTable_t(const CTFileName& fnmTable); // throw char *
// add several tables from a directory using wildcards
SECAPI void AddTranslationTablesDir_t(const CTFileName& fnmDir, const CTFileName& fnmPattern); // throw char *
// finish translation table building
SECAPI void FinishTranslationTable();

// read given translation table from file - for internal use
SECAPI void ReadTranslationTable_t(
  CDynamicArray_CTranslationPair& atpPairs, const CTFileName& fnmTable); // throw char *

// translate a string
SECAPI char* Translate(char* str, INDEX iOffset = 0);
SECAPI const char* TranslateConst(const char* str, INDEX iOffset = 0);

// macro for inserting a string for translation into executables
#define TRANS(str) Translate("ETRS" str, 4)
// macro for translating a variable string (usually can be CTString)
#define TRANSV(str) TranslateConst(str, 0)
