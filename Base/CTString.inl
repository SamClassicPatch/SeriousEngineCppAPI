#pragma once
#include "Stream.h"
#include "FileName.h"
#include <stdio.h>
#include <stdarg.h>

inline CTString::CTString(CTString_* p, bool owner)
  : m_owner(owner)
  , mp_string(p)
{
}

inline CTString::CTString()
  : m_owner(true)
  , mp_string(CTString_new())
{
}

inline CTString::CTString(const CTString& strOriginal)
  : m_owner(true)
  , mp_string(CTString_clone(strOriginal.mp_string))
{
}

inline CTString::CTString(const char* pString)
  : m_owner(true)
  , mp_string(CTString_new_str(pString))
{
}

inline CTString::CTString(INDEX iDummy, const char* strFormat, ...)
  : m_owner(true)
{
  va_list arg;
  va_start(arg, strFormat);
  mp_string = CTString_new_fmt(iDummy, strFormat, arg);
  va_end(arg);
}

inline CTString::~CTString()
{
  if (m_owner)
    CTString_delete(mp_string);
}

inline void CTString::Clear()
{
  CTString_Clear(mp_string);
}

inline CTString::operator const char* () const
{
  return CTString_CStr(mp_string);
}

inline CTString& CTString::operator=(const char* strCharString)
{
  CTString_Assign_str(mp_string, strCharString);
  return *this;
}

inline CTString& CTString::operator=(const CTString& strOther)
{
  CTString_Assign(mp_string, strOther.mp_string);
  return *this;
}

inline INDEX CTString::Length() const
{
  return CTString_Length(mp_string);
}

inline INDEX CTString::LengthNaked() const
{
  return CTString_LengthNaked(mp_string);
}

inline INDEX CTString::FindSubstr(const CTString& strSub)
{
  return CTString_FindSubstr(mp_string, strSub.mp_string);
}

inline BOOL CTString::ReplaceSubstr(const CTString& strSub, const CTString& strNewSub)
{
  return CTString_ReplaceSubstr(mp_string, strSub.mp_string, strNewSub.mp_string);
}

inline BOOL CTString::HasPrefix(const CTString& strPrefix) const
{
  return CTString_HasPrefix(mp_string, strPrefix.mp_string);
}

inline BOOL CTString::RemovePrefix(const CTString& strPrefix)
{
  return CTString_RemovePrefix(mp_string, strPrefix.mp_string);
}

inline INDEX CTString::TrimLeft(INDEX ctCharacters)
{
  return CTString_TrimLeft(mp_string, ctCharacters);
}

inline INDEX CTString::TrimRight(INDEX ctCharacters)
{
  return CTString_TrimRight(mp_string, ctCharacters);
}

inline INDEX CTString::TrimSpacesLeft()
{
  return CTString_TrimSpacesLeft(mp_string);
}

inline INDEX CTString::TrimSpacesRight()
{
  return CTString_TrimSpacesRight(mp_string);
}

inline ULONG CTString::GetHash() const
{
  return CTString_GetHash(mp_string);
}

inline void CTString::OnlyFirstLine()
{
  CTString_OnlyFirstLine(mp_string);
}

inline BOOL CTString::operator==(const CTString& strOther) const
{
  return CTString_equal(mp_string, strOther.mp_string);
}

inline BOOL CTString::operator==(const char* strOther) const
{
  return CTString_equal_str(mp_string, strOther);
}

inline BOOL CTString::operator!=(const CTString& strOther) const
{
  return CTString_notequal(mp_string, strOther.mp_string);
}

inline BOOL CTString::operator!=(const char* strOther) const
{
  return CTString_notequal_str(mp_string, strOther);
}

inline BOOL CTString::Matches(const CTString& strOther) const
{
  return CTString_Matches(mp_string, strOther.mp_string);
}

inline BOOL CTString::Matches(const char* strOther) const
{
  return CTString_Matches_str(mp_string, strOther);
}

inline CTString& CTString::operator+=(const CTString& strSecond)
{
  CTString_ConcatenateInplace(mp_string, strSecond.mp_string);
  return *this;
}

inline void CTString::Split(INDEX iPos, CTString& str1, CTString& str2)
{
  CTString_Split(mp_string, iPos, str1.mp_string, str2.mp_string);
}

inline void CTString::InsertChar(INDEX iPos, char cChr)
{
  CTString_InsertChar(mp_string, iPos, cChr);
}

inline void CTString::DeleteChar(INDEX iPos)
{
  CTString_DeleteChar(mp_string, iPos);
}

inline void CTString::Throw_t()
{
  CTString_Throw_t(mp_string);
  SECppAPI_CheckException();
}

inline void CTString::ReadFromText_t(CTStream& strmStream, const CTString& strKeyword)
{
  CTString_ReadFromText_t(mp_string, strmStream.C_Handle(), strKeyword.mp_string);
  SECppAPI_CheckException();
}

inline void CTString::Load_t(const CTFileName& fnmFile)
{
  CTString_Load_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline void CTString::LoadKeepCRLF_t(const CTFileName& fnmFile)
{
  CTString_LoadKeepCRLF_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline void CTString::ReadUntilEOF_t(CTStream& strmStream)
{
  CTString_ReadUntilEOF_t(mp_string, strmStream.C_Handle());
  SECppAPI_CheckException();
}

inline void CTString::Save_t(const CTFileName& fnmFile)
{
  CTString_Save_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline void CTString::SaveKeepCRLF_t(const CTFileName& fnmFile)
{
  CTString_SaveKeepCRLF_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline INDEX CTString::PrintF(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  INDEX result = VPrintF(strFormat, arg);
  va_end(arg);
  return result;
}

inline INDEX CTString::VPrintF(const char* strFormat, va_list arg)
{
  return CTString_VPrintF(mp_string, strFormat, arg);
}

inline INDEX CTString::ScanF(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  INDEX result = vsscanf(CTString_CStr(mp_string), strFormat, arg);
  va_end(arg);
  return result;
}

inline void CTString::LoadVar(const CTFileName& fnmFile)
{
  CTString_LoadVar(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline void CTString::SaveVar(const CTFileName& fnmFile)
{
  CTString_SaveVar(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

inline void LoadStringVar(const CTFileName& fnmVar, CTString& strVar)
{
  CTString_LoadStringVar(fnmVar.C_Handle(), strVar.C_Handle());
  SECppAPI_CheckException();
}

inline void SaveStringVar(const CTFileName& fnmVar, CTString& strVar)
{
  CTString_SaveStringVar(fnmVar.C_Handle(), strVar.C_Handle());
  SECppAPI_CheckException();
}

inline void LoadIntVar(const CTFileName& fnmVar, INDEX& iVar)
{
  CTString_LoadIntVar(fnmVar.C_Handle(), &iVar);
  SECppAPI_CheckException();
}

inline void SaveIntVar(const CTFileName& fnmVar, INDEX iVar)
{
  CTString_SaveIntVar(fnmVar.C_Handle(), iVar);
  SECppAPI_CheckException();
}

inline CTString RemoveSpecialCodes(const CTString& str)
{
  return CTString(CTString_RemoveSpecialCodes(str.C_Handle()), true);
}

inline BOOL operator==(const char* strThis, const CTString& strOther)
{
  return CTString_equal_str(strOther.C_Handle(), strThis);
}

inline BOOL operator!=(const char* strThis, const CTString& strOther)
{
  return CTString_notequal_str(strOther.C_Handle(), strThis);
}

inline CTStream& operator>>(CTStream& strmStream, CTString& strString)
{
  CTString_extract(strmStream.C_Handle(), strString.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}

inline CTStream& operator<<(CTStream& strmStream, const CTString& strString)
{
  CTString_insert(strmStream.C_Handle(), strString.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}
