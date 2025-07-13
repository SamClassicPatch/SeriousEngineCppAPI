#pragma once

inline void _pShell_DeclareSymbol(const CTString& s, void* val)
{
  _pShell_DeclareSymbol_(s, val);
}

inline void _pShell_Execute(const CTString& s)
{
  _pShell_Execute_(s);
}

inline void _pShell_StorePersistentSymbols(const CTFileName& f)
{
  _pShell_StorePersistentSymbols_(f);
}

inline FLOAT _pShell_GetFLOAT(const CTString& strName)
{
  return _pShell_GetFLOAT_(strName);
}

inline void _pShell_SetFLOAT(const CTString& strName, FLOAT fValue)
{
  _pShell_SetFLOAT_(strName, fValue);
}

inline INDEX _pShell_GetINDEX(const CTString& strName)
{
  return _pShell_GetINDEX_(strName);
}

inline void _pShell_SetINDEX(const CTString& strName, INDEX iValue)
{
  _pShell_SetINDEX_(strName, iValue);
}

__forceinline CTString _pShell_GetString(const CTString& strName)
{
  return CTString(_pShell_GetString_(strName), true);
}

inline void _pShell_SetString(const CTString& strName, const CTString& strValue)
{
  _pShell_SetString_(strName, strValue);
}

__forceinline CTString _pShell_GetValue(const CTString& strName)
{
  return CTString(_pShell_GetValue_(strName), true);
}

inline void _pShell_SetValue(const CTString& strName, const CTString& strValue)
{
  _pShell_SetValue_(strName, strValue);
}

