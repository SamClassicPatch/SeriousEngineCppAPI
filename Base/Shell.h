#pragma once
#include "Types.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Shell.h>

void _pShell_DeclareSymbol(const CTString& s, void* val);
void _pShell_Execute(const CTString& s);
void _pShell_StorePersistentSymbols(const CTFileName& f);
FLOAT _pShell_GetFLOAT(const CTString& strName);
void _pShell_SetFLOAT(const CTString& strName, FLOAT fValue);
INDEX _pShell_GetINDEX(const CTString& strName);
void _pShell_SetINDEX(const CTString& strName, INDEX iValue);
CTString _pShell_GetString(const CTString& strName);
void _pShell_SetString(const CTString& strName, const CTString& strValue);
CTString _pShell_GetValue(const CTString& strName);
void _pShell_SetValue(const CTString& strName, const CTString& strValue);

#include "Shell.inl"
