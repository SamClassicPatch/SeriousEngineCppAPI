#pragma once
#include "Types.h"

// init translation routines with given translation table
void InitTranslation();
// add given translation table
void AddTranslationTable_t(const CTFileName& fnmTable); // throw char *
// add several tables from a directory using wildcards
void AddTranslationTablesDir_t(const CTFileName& fnmDir, const CTFileName& fnmPattern); // throw char *
// finish translation table building
void FinishTranslationTable();

// read given translation table from file - for internal use
void ReadTranslationTable_t(
  CDynamicArray_CTranslationPair& atpPairs, const CTFileName& fnmTable); // throw char *

// translate a string
char* Translate(char* str, INDEX iOffset = 0);
const char* TranslateConst(const char* str, INDEX iOffset = 0);

// macro for inserting a string for translation into executables
#define TRANS(str) Translate("ETRS" str, 4)
// macro for translating a variable string (usually can be CTString)
#define TRANSV(str) TranslateConst(str, 0)

#include "Translation.inl"
