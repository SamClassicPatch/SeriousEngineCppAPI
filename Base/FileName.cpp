#include "FileName.h"
#include "Stream.h"
#include <SeriousEngineCAPI/Base/FileName.h>

CTFileName::CTFileName(CTFileName_* p, bool owner)
  : CTString((CTString_*)p, owner)
{
}

CTFileName::CTFileName()
  : CTFileName(CTFileName_new(), true)
{
}

CTFileName::CTFileName(const CTFileName& o)
  : CTFileName(CTFileName_clone(o.C_Handle()), true)
{
}

CTFileName::CTFileName(const CTString& o)
  : CTFileName(CTFileName_new_str(o.C_Handle()), true)
{
}

CTFileName::CTFileName(const char* pString, int i)
  : CTFileName(CTFileName_new_stri(pString, i), true)
{
}

CTFileName::~CTFileName()
{
  if (m_owner)
    CTFileName_delete((CTFileName_*)mp_string);
  m_owner = false;
  mp_string = nullptr;
}

CTFileName& CTFileName::operator=(const CTFileName& o)
{
  CTFileName_copy(C_Handle(), o.C_Handle());
  return *this;
}

CTFileName& CTFileName::operator=(const char* strCharString)
{
  CTFileName_assign_str(C_Handle(), strCharString);
  return *this;
}

void CTFileName::operator=(const CTString& strOther)
{
  CTFileName_assign(C_Handle(), strOther.C_Handle());
}

CTFileName CTFileName::FileDir() const
{
  return CTFileName(CTFileName_FileDir(C_Handle()), true);
}

CTFileName CTFileName::FileName() const
{
  return CTFileName(CTFileName_FileName(C_Handle()), true);
}

CTFileName CTFileName::FileExt() const
{
  return CTFileName(CTFileName_FileExt(C_Handle()), true);
}

CTFileName CTFileName::NoExt() const
{
  return CTFileName(CTFileName_NoExt(C_Handle()), true);
}

void CTFileName::SetAbsolutePath()
{
  CTFileName_SetAbsolutePath(C_Handle());
}

void CTFileName::RemoveApplicationPath_t()
{
  CTFileName_RemoveApplicationPath_t(C_Handle());
  SECppAPI_CheckException();
}

void CTFileName::ReadFromText_t(CTStream& strmStream, const char* strKeyword)
{
  CTFileName_ReadFromText_t(C_Handle(), strmStream.C_Handle(), strKeyword);
  SECppAPI_CheckException();
}

CTStream& operator>>(CTStream& strmStream, CTFileName& fnmFileName)
{
  CTFileName_extract(strmStream.C_Handle(), fnmFileName.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}

CTStream& operator<<(CTStream& strmStream, const CTFileName& fnmFileName)
{
  CTFileName_insert(strmStream.C_Handle(), fnmFileName.C_Handle());
  SECppAPI_CheckException();
  return strmStream;
}
