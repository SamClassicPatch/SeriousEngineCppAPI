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
#include "CTStringDecl.h"
#include <SeriousEngineCAPI/Base/FileName.h>

class CTFileName : public CTString
{
public:
  CTFileName(CTFileName_* p, bool owner = false);
  CTFileName();
  CTFileName(const CTFileName& o);
  CTFileName(const CTString& o);
  CTFileName(const char* pString, int i);
  ~CTFileName();

  CTFileName& operator=(const CTFileName& o);

  /* Assignment. */
  CTFileName& operator=(const char* strCharString);
  void operator=(const CTString& strOther);

  /* Get directory part of a filename. */
  __forceinline CTFileName FileDir() const { return CTFileName(CTFileName_FileDir(C_Handle()), true); }
  /* Get name part of a filename. */
  __forceinline CTFileName FileName() const { return CTFileName(CTFileName_FileName(C_Handle()), true); }
  /* Get extension part of a filename. */
  __forceinline CTFileName FileExt() const { return CTFileName(CTFileName_FileExt(C_Handle()), true); }
  /* Get path and file name without extension. */
  __forceinline CTFileName NoExt() const { return CTFileName(CTFileName_NoExt(C_Handle()), true); }
  /* Set path to the absolute path, taking \.. and /.. into account. */
  void SetAbsolutePath();
  /* Remove application path from a file name. */
  void RemoveApplicationPath_t(); // throw char *

  // filename is its own name (used for storing in nametable)
  inline const CTFileName& GetName() { return *this; };

  void ReadFromText_t(CTStream& strmStream, const char* strKeyword = nullptr); // throw char *

  /* Read from stream. */
  friend CTStream& operator>>(CTStream& strmStream, CTFileName& fnmFileName);
  /* Write to stream. */
  friend CTStream& operator<<(CTStream& strmStream, const CTFileName& fnmFileName);

  inline CTFileName_* C_Handle() { return (CTFileName_*)mp_string; }
  inline const CTFileName_* C_Handle() const { return (const CTFileName_*)mp_string; }
  inline operator CTFileName_* () { return C_Handle(); }
  inline operator const CTFileName_* () const { return C_Handle(); }
};

// macro for defining a literal filename in code (EFNM = exe-filename)
#define CTFILENAME(string) CTFileName("EFNM" string, 4)
#define DECLARE_CTFILENAME(name, string) CTFileName name("EFNM" string, 4)
