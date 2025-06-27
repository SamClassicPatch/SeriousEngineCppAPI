#pragma once
#include "Stream.h"

inline CTFileName::CTFileName(CTFileName_* p, bool owner)
  : CTString((CTString_*)p, owner)
{
}

inline CTFileName::CTFileName()
  : CTFileName(CTFileName_new(), true)
{
}

inline CTFileName::CTFileName(const CTFileName& o)
  : CTFileName(CTFileName_clone(o.C_Handle()), true)
{
}

inline CTFileName::CTFileName(const CTString& o)
  : CTFileName(CTFileName_new_str(o.C_Handle()), true)
{
}

inline CTFileName::CTFileName(const char* pString, int i)
  : CTFileName(CTFileName_new_stri(pString, i), true)
{
}

inline CTFileName::~CTFileName()
{
  if (m_owner)
    CTFileName_delete((CTFileName_*)mp_string);
  m_owner = false;
  mp_string = nullptr;
}

inline CTFileName& CTFileName::operator=(const CTFileName& o)
{
  CTFileName_copy(C_Handle(), o.C_Handle());
  return *this;
}

inline CTFileName& CTFileName::operator=(const char* strCharString)
{
  CTFileName_assign_str(C_Handle(), strCharString);
  return *this;
}

inline void CTFileName::operator=(const CTString& strOther)
{
  CTFileName_assign(C_Handle(), strOther.C_Handle());
}

inline void CTFileName::SetAbsolutePath()
{
  CTFileName_SetAbsolutePath(C_Handle());
}

inline void CTFileName::RemoveApplicationPath_t()
{
  CTFileName_RemoveApplicationPath_t(C_Handle());
  SECppAPI_CheckException();
}

inline void CTFileName::ReadFromText_t(CTStream& strmStream, const char* strKeyword)
{
  CTFileName_ReadFromText_t(C_Handle(), strmStream.C_Handle(), strKeyword);
  SECppAPI_CheckException();
}

inline CTStream& operator>>(CTStream& strmStream, CTFileName& fnmFileName)
{
  CTFileName_extract(strmStream.C_Handle(), fnmFileName.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}

inline CTStream& operator<<(CTStream& strmStream, const CTFileName& fnmFileName)
{
  CTFileName_insert(strmStream.C_Handle(), fnmFileName.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}
