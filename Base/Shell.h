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
