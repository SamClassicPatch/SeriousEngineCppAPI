#pragma once

inline void CPrintF(const char* s, ...)
{
  va_list arg;
  va_start(arg, s);
  CTString strBuffer;
  strBuffer.VPrintF(s, arg);
  CPutString_(static_cast<const char*>(strBuffer));
  va_end(arg);
}

inline void CPutString(const char* s)
{
  CPutString_(s);
}

inline BOOL REG_GetString(const CTString& strKey, CTString& strString)
{
  return REG_GetString_(strKey, strString);
}
