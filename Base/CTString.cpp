#include "CTString.h"
#include "Stream.h"
#include "FileName.h"
#include <SeriousEngineCAPI/Base/CTString.h>
#include <stdio.h>
#include <stdarg.h>

CTString::CTString(CTString_* p, bool owner)
  : m_owner(owner)
  , mp_string(p)
{
}

CTString::CTString()
  : m_owner(true)
  , mp_string(CTString_new())
{
}

CTString::CTString(const CTString& strOriginal)
  : m_owner(true)
  , mp_string(CTString_clone(strOriginal.mp_string))
{
}

CTString::CTString(const char* pString)
  : m_owner(true)
  , mp_string(CTString_new_str(pString))
{
}

CTString::CTString(INDEX iDummy, const char* strFormat, ...)
  : m_owner(true)
{
  va_list arg;
  va_start(arg, strFormat);
  mp_string = CTString_new_fmt(iDummy, strFormat, arg);
  va_end(arg);
}

CTString::~CTString()
{
  if (m_owner)
    CTString_delete(mp_string);
}

CTString::TStrType& CTString::str_String()
{
  return *CTString_access_string(mp_string);
}

const CTString::TStrType& CTString::str_String() const
{
  return *CTString_access_string_const(mp_string);
}

void CTString::Clear()
{
  CTString_Clear(mp_string);
}

CTString::operator const char* () const
{
  return CTString_CStr(mp_string);
}

CTString& CTString::operator=(const char* strCharString)
{
  CTString_Assign_str(mp_string, strCharString);
  return *this;
}

CTString& CTString::operator=(const CTString& strOther)
{
  CTString_Assign(mp_string, strOther.mp_string);
  return *this;
}

INDEX CTString::Length() const
{
  return CTString_Length(mp_string);
}

INDEX CTString::LengthNaked() const
{
  return CTString_LengthNaked(mp_string);
}

CTString CTString::Undecorated() const
{
  return CTString(CTString_Undecorated(mp_string), true);
}

INDEX CTString::FindSubstr(const CTString& strSub)
{
  return CTString_FindSubstr(mp_string, strSub.mp_string);
}

BOOL CTString::ReplaceSubstr(const CTString& strSub, const CTString& strNewSub)
{
  return CTString_ReplaceSubstr(mp_string, strSub.mp_string, strNewSub.mp_string);
}

BOOL CTString::HasPrefix(const CTString& strPrefix) const
{
  return CTString_HasPrefix(mp_string, strPrefix.mp_string);
}

BOOL CTString::RemovePrefix(const CTString& strPrefix)
{
  return CTString_RemovePrefix(mp_string, strPrefix.mp_string);
}

INDEX CTString::TrimLeft(INDEX ctCharacters)
{
  return CTString_TrimLeft(mp_string, ctCharacters);
}

INDEX CTString::TrimRight(INDEX ctCharacters)
{
  return CTString_TrimRight(mp_string, ctCharacters);
}

INDEX CTString::TrimSpacesLeft()
{
  return CTString_TrimSpacesLeft(mp_string);
}

INDEX CTString::TrimSpacesRight()
{
  return CTString_TrimSpacesRight(mp_string);
}

ULONG CTString::GetHash() const
{
  return CTString_GetHash(mp_string);
}

void CTString::OnlyFirstLine()
{
  CTString_OnlyFirstLine(mp_string);
}

BOOL CTString::operator==(const CTString& strOther) const
{
  return CTString_equal(mp_string, strOther.mp_string);
}

BOOL CTString::operator==(const char* strOther) const
{
  return CTString_equal_str(mp_string, strOther);
}

BOOL CTString::operator!=(const CTString& strOther) const
{
  return CTString_notequal(mp_string, strOther.mp_string);
}

BOOL CTString::operator!=(const char* strOther) const
{
  return CTString_notequal_str(mp_string, strOther);
}

BOOL CTString::Matches(const CTString& strOther) const
{
  return CTString_Matches(mp_string, strOther.mp_string);
}

BOOL CTString::Matches(const char* strOther) const
{
  return CTString_Matches_str(mp_string, strOther);
}

CTString CTString::operator+(const CTString& strSecond) const
{
  return CTString(CTString_Concatenate(mp_string, strSecond.mp_string), true);
}

CTString& CTString::operator+=(const CTString& strSecond)
{
  CTString_ConcatenateInplace(mp_string, strSecond.mp_string);
  return *this;
}

void CTString::Split(INDEX iPos, CTString& str1, CTString& str2)
{
  CTString_Split(mp_string, iPos, str1.mp_string, str2.mp_string);
}

void CTString::InsertChar(INDEX iPos, char cChr)
{
  CTString_InsertChar(mp_string, iPos, cChr);
}

void CTString::DeleteChar(INDEX iPos)
{
  CTString_DeleteChar(mp_string, iPos);
}

void CTString::Throw_t()
{
  CTString_Throw_t(mp_string);
  SECppAPI_CheckException();
}

void CTString::ReadFromText_t(CTStream& strmStream, const CTString& strKeyword)
{
  CTString_ReadFromText_t(mp_string, strmStream.C_Handle(), strKeyword.mp_string);
  SECppAPI_CheckException();
}

void CTString::Load_t(const CTFileName& fnmFile)
{
  CTString_Load_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

void CTString::LoadKeepCRLF_t(const CTFileName& fnmFile)
{
  CTString_LoadKeepCRLF_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

void CTString::ReadUntilEOF_t(CTStream& strmStream)
{
  CTString_ReadUntilEOF_t(mp_string, strmStream.C_Handle());
  SECppAPI_CheckException();
}

void CTString::Save_t(const CTFileName& fnmFile)
{
  CTString_Save_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

void CTString::SaveKeepCRLF_t(const CTFileName& fnmFile)
{
  CTString_SaveKeepCRLF_t(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

INDEX CTString::PrintF(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  INDEX result = VPrintF(strFormat, arg);
  va_end(arg);
  return result;
}

INDEX CTString::VPrintF(const char* strFormat, va_list arg)
{
  return CTString_VPrintF(mp_string, strFormat, arg);
}

INDEX CTString::ScanF(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  INDEX result = vsscanf(CTString_CStr(mp_string), strFormat, arg);
  va_end(arg);
  return result;
}

void CTString::LoadVar(const CTFileName& fnmFile)
{
  CTString_LoadVar(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

void CTString::SaveVar(const CTFileName& fnmFile)
{
  CTString_SaveVar(mp_string, fnmFile.C_Handle());
  SECppAPI_CheckException();
}

void LoadStringVar(const CTFileName& fnmVar, CTString& strVar)
{
  CTString_LoadStringVar(fnmVar.C_Handle(), strVar.C_Handle());
  SECppAPI_CheckException();
}

void SaveStringVar(const CTFileName& fnmVar, CTString& strVar)
{
  CTString_SaveStringVar(fnmVar.C_Handle(), strVar.C_Handle());
  SECppAPI_CheckException();
}

void LoadIntVar(const CTFileName& fnmVar, INDEX& iVar)
{
  CTString_LoadIntVar(fnmVar.C_Handle(), &iVar);
  SECppAPI_CheckException();
}

void SaveIntVar(const CTFileName& fnmVar, INDEX iVar)
{
  CTString_SaveIntVar(fnmVar.C_Handle(), iVar);
  SECppAPI_CheckException();
}

CTString RemoveSpecialCodes(const CTString& str)
{
  return CTString(CTString_RemoveSpecialCodes(str.C_Handle()), true);
}

BOOL operator==(const char* strThis, const CTString& strOther)
{
  return CTString_equal_str(strOther.C_Handle(), strThis);
}

BOOL operator!=(const char* strThis, const CTString& strOther)
{
  return CTString_notequal_str(strOther.C_Handle(), strThis);
}

CTString operator+(const char* strFirst, const CTString& strSecond)
{
  CTString_* pFirst = CTString_new_str(strFirst);
  CTString_ConcatenateInplace(pFirst, strSecond.C_Handle());
  return CTString(pFirst, true);
}

CTStream& operator>>(CTStream& strmStream, CTString& strString)
{
  CTString_extract(strmStream.C_Handle(), strString.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}

CTStream& operator<<(CTStream& strmStream, const CTString& strString)
{
  CTString_insert(strmStream.C_Handle(), strString.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}
