/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

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
char* Translate(const char* str, INDEX iOffset = 0);
const char* TranslateConst(const char* str, INDEX iOffset = 0);

// macro for inserting a string for translation into executables
#define TRANS(str) Translate("ETRS" str, 4)
// macro for translating a variable string (usually can be CTString)
#define TRANSV(str) TranslateConst(str, 0)

#include "Translation.inl"
