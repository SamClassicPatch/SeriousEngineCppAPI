#pragma once
#include "Types.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Console.h>

// Print formated text to the main console.
void CPrintF(const char* s, ...);
// Add a string of text to console
void CPutString(const char* s);

BOOL REG_GetString(const CTString& strKey, CTString& strString);

#include "Console.inl"
