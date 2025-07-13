#pragma once

inline void ThrowF_t [[noreturn]] (char* strFormat, ...)
{
  const SLONG slBufferSize = 256;
  char strBuffer[slBufferSize + 1];
  // format the message in buffer
  va_list arg;
  va_start(arg, strFormat); // variable arguments start after this argument
  _vsnprintf(strBuffer, slBufferSize, strFormat, arg);
  va_end(arg);
  ThrowF_t_(strBuffer);
  SECppAPI_CheckException();
}

inline void FatalError [[noreturn]] (const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  FatalError_(strBuffer);
}

inline void WarningMessage(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  WarningMessage_(strBuffer);
}

inline void InfoMessage(const char* strFormat, ...)
{
  va_list arg;
  va_start(arg, strFormat);
  CTString strBuffer;
  strBuffer.VPrintF(strFormat, arg);
  va_end(arg);
  InfoMessage_(strBuffer);
}

__forceinline const CTString GetWindowsError(DWORD dwWindowsErrorCode)
{
  return CTString(GetWindowsError_(dwWindowsErrorCode), true);
}
