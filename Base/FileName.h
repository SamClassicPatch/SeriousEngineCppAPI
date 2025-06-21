#pragma once
#include "CTString.h"

class SECPPAPI CTFileName : public CTString
{
public:
  explicit CTFileName(CTFileName_* p, bool owner = false);
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
  CTFileName FileDir() const;
  /* Get name part of a filename. */
  CTFileName FileName() const;
  /* Get extension part of a filename. */
  CTFileName FileExt() const;
  /* Get path and file name without extension. */
  CTFileName NoExt() const;
  /* Set path to the absolute path, taking \.. and /.. into account. */
  void SetAbsolutePath();
  /* Remove application path from a file name. */
  void RemoveApplicationPath_t(); // throw char *

  // filename is its own name (used for storing in nametable)
  inline const CTFileName& GetName() { return *this; };

  void ReadFromText_t(CTStream& strmStream, const char* strKeyword = nullptr); // throw char *

  /* Read from stream. */
  SECPPAPI friend CTStream& operator>>(CTStream& strmStream, CTFileName& fnmFileName);
  /* Write to stream. */
  SECPPAPI friend CTStream& operator<<(CTStream& strmStream, const CTFileName& fnmFileName);

  inline CTFileName_* C_Handle() { return (CTFileName_*)mp_string; }
  inline const CTFileName_* C_Handle() const { return (const CTFileName_*)mp_string; }
  inline operator CTFileName_* () { return C_Handle(); }
  inline operator const CTFileName_* () const { return C_Handle(); }
};

// macro for defining a literal filename in code (EFNM = exe-filename)
#define CTFILENAME(string) CTFileName("EFNM" string, 4)
#define DECLARE_CTFILENAME(name, string) CTFileName name("EFNM" string, 4)
