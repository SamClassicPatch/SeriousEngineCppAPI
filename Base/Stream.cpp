#define _CRT_SECURE_NO_WARNINGS
#include "Stream.h"
#include "FileName.h"
#include "../Templates/DynamicStackArray.h"
#include <stdarg.h>

CChunkID::CChunkID(CChunkID_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

CChunkID::CChunkID(const char* strString)
  : m_owner(true)
  , mp_handle(CChunkID_new(strString))
{
}

CChunkID::~CChunkID()
{
  if (m_owner)
    CChunkID_delete(mp_handle);
}

BOOL CChunkID::operator==(const CChunkID& cidOther) const
{
  return CChunkID_equal(mp_handle, cidOther);
}

BOOL CChunkID::operator!=(const CChunkID& cidOther) const
{
  return CChunkID_notequal(mp_handle, cidOther);
}

CChunkID::operator const char* () const
{
  return CChunkID_str_const(mp_handle);
}

CChunkID::operator char* ()
{
  return CChunkID_str(mp_handle);
}

void CTStream::ExecuteWithStreamHandling(const std::function<void()>& func)
{
  static const std::function<void()>* p_func = nullptr;
  p_func = &func;
  CTStream_ExecuteWithStreamHandling([] { (*p_func)(); });
}

void CTStream::Read_t(void* pvBuffer, SLONG slSize)
{
  CTStream_Read_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::Write_t(const void* pvBuffer, SLONG slSize)
{
  CTStream_Write_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::Seek_t(SLONG slOffset, enum SeekDir sd)
{
  CTStream_Seek_t(mp_stream, slOffset, (INDEX)sd);
  SECppAPI_CheckException();
}

void CTStream::SetPos_t(SLONG slPosition)
{
  CTStream_SetPos_t(mp_stream, slPosition);
  SECppAPI_CheckException();
}

SLONG CTStream::GetPos_t()
{
  const auto res = CTStream_GetPos_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

SLONG CTStream::GetStreamSize()
{
  return CTStream_GetStreamSize(mp_stream);
}

ULONG CTStream::GetStreamCRC32_t()
{
  const auto res = CTStream_GetStreamCRC32_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

BOOL CTStream::AtEOF()
{
  return CTStream_AtEOF(mp_stream);
}

void CTStream::PutLine_t(const char* strBuffer)
{
  CTStream_PutLine_t(mp_stream, strBuffer);
  SECppAPI_CheckException();
}

void CTStream::PutString_t(const char* strString)
{
  CTStream_PutString_t(mp_stream, strString);
  SECppAPI_CheckException();
}

void CTStream::FPrintF_t(const char* strFormat, ...)
{
  const SLONG slBufferSize = 2048;
  char strBuffer[slBufferSize];
  // format the message in buffer
  va_list arg;
  va_start(arg, strFormat); // variable arguments start after this argument
  _vsnprintf(strBuffer, slBufferSize, strFormat, arg);
  va_end(arg);
  // print the buffer
  PutString_t(strBuffer);
}

void CTStream::GetLine_t(char* strBuffer, SLONG slBufferSize, char cDelimiter)
{
  CTStream_GetLine_t(mp_stream, strBuffer, slBufferSize, cDelimiter);
  SECppAPI_CheckException();
}

void CTStream::GetLine_t(CTString& strLine, char cDelimiter)
{
  CTStream_GetLine_t_str(mp_stream, strLine, cDelimiter);
  SECppAPI_CheckException();
}

void CTStream::ExpectID_t(const CChunkID& cidExpected)
{
  CTStream_ExpectID_t(mp_stream, cidExpected);
  SECppAPI_CheckException();
}

void CTStream::ExpectKeyword_t(const CTString& strKeyword)
{
  CTStream_ExpectKeyword_t(mp_stream, strKeyword);
  SECppAPI_CheckException();
}

SLONG CTStream::GetSize_t()
{
  const auto res = CTStream_GetSize_t(mp_stream);
  SECppAPI_CheckException();
  return res;
}

void CTStream::ReadRawChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_ReadRawChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::ReadChunk_t(void* pvBuffer, SLONG slExpectedSize)
{
  CTStream_ReadChunk_t(mp_stream, pvBuffer, slExpectedSize);
  SECppAPI_CheckException();
}

void CTStream::ReadFullChunk_t(const CChunkID& cidExpected, void* pvBuffer, SLONG slExpectedSize)
{
  CTStream_ReadFullChunk_t(mp_stream, cidExpected, pvBuffer, slExpectedSize);
  SECppAPI_CheckException();
}

void CTStream::WriteID_t(const CChunkID& cidSave)
{
  CTStream_WriteID_t(mp_stream, cidSave);
  SECppAPI_CheckException();
}

void CTStream::WriteSize_t(SLONG slSize)
{
  CTStream_WriteSize_t(mp_stream, slSize);
  SECppAPI_CheckException();
}

void CTStream::WriteRawChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_WriteRawChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::WriteChunk_t(void* pvBuffer, SLONG slSize)
{
  CTStream_WriteChunk_t(mp_stream, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::WriteFullChunk_t(const CChunkID& cidSave, void* pvBuffer, SLONG slSize)
{
  CTStream_WriteFullChunk_t(mp_stream, cidSave, pvBuffer, slSize);
  SECppAPI_CheckException();
}

void CTStream::DictionaryWriteBegin_t(const CTFileName& fnmImportFrom, SLONG slImportOffset)
{
  CTStream_DictionaryWriteBegin_t(mp_stream, fnmImportFrom, slImportOffset);
  SECppAPI_CheckException();
}

void CTStream::DictionaryWriteEnd_t()
{
  CTStream_DictionaryWriteEnd_t(mp_stream);
  SECppAPI_CheckException();
}

SLONG CTStream::DictionaryReadBegin_t()
{
  CTStream_DictionaryReadBegin_t(mp_stream);
  SECppAPI_CheckException();
}

void CTStream::DictionaryReadEnd_t()
{
  CTStream_DictionaryReadEnd_t(mp_stream);
  SECppAPI_CheckException();
}

void CTStream::DictionaryPreload_t()
{
  CTStream_DictionaryPreload_t(mp_stream);
  SECppAPI_CheckException();
}

CTStream::CTStream(CTStream_* p, bool owner)
  : m_owner(owner)
  , mp_stream(p)
{
}

CTFileStream::CTFileStream(CTFileStream_* p, bool owner)
  : CTStream((CTStream_*)p, owner)
{
}

CTFileStream::CTFileStream()
  : CTFileStream(CTFileStream_new(), true)
{
}

CTFileStream::~CTFileStream()
{
  if (m_owner)
    CTFileStream_delete(C_Handle());
  m_owner = false;
  mp_stream = nullptr;
}

void CTFileStream::Open_t(const CTFileName& fnFileName, enum CTStream::OpenMode om)
{
  CTFileStream_Open_t(C_Handle(), fnFileName, (INDEX)om);
  SECppAPI_CheckException();
}

void CTFileStream::Create_t(const CTFileName& fnFileName)
{
  CTFileStream_Create_t(C_Handle(), fnFileName);
  SECppAPI_CheckException();
}

void CTFileStream::Close()
{
  CTFileStream_Close(C_Handle());
}

CTMemoryStream::CTMemoryStream(CTMemoryStream_* p, bool owner)
  : CTStream((CTStream_*)p, owner)
{
}

CTMemoryStream::CTMemoryStream()
  : CTMemoryStream(CTMemoryStream_new(), true)
{
}

CTMemoryStream::CTMemoryStream(void* pvBuffer, SLONG slSize, CTStream::OpenMode om)
  : CTMemoryStream(CTMemoryStream_new_buffer(pvBuffer, slSize, (INDEX)om), true)
{
}

CTMemoryStream::~CTMemoryStream()
{
  if (m_owner)
    CTMemoryStream_delete(C_Handle());
  m_owner = false;
  mp_stream = nullptr;
}

void CTMemoryStream::LockBuffer(void** ppvBuffer, SLONG* pslSize)
{
  CTMemoryStream_LockBuffer(C_Handle(), ppvBuffer, pslSize);
}

void CTMemoryStream::UnlockBuffer()
{
  CTMemoryStream_UnlockBuffer(C_Handle());
}

BOOL FileExists(const CTFileName& fnmFile)
{
  return FileExists_(fnmFile);
}

BOOL FileExistsForWriting(const CTFileName& fnmFile)
{
  return FileExistsForWriting_(fnmFile);
}

SLONG GetFileTimeStamp_t(const CTFileName& fnmFile)
{
  const auto res = GetFileTimeStamp_t_(fnmFile);
  SECppAPI_CheckException();
  return res;
}

ULONG GetFileCRC32_t(const CTFileName& fnmFile)
{
  const auto res = GetFileCRC32_t_(fnmFile);
  SECppAPI_CheckException();
  return res;
}

BOOL IsFileReadOnly(const CTFileName& fnmFile)
{
  return IsFileReadOnly_(fnmFile);
}

BOOL RemoveFile(const CTFileName& fnmFile)
{
  return RemoveFile_(fnmFile);
}

INDEX ExpandFilePath(ULONG ulType, const CTFileName& fnmFile, CTFileName& fnmExpanded)
{
  return ExpandFilePath_(ulType, fnmFile, fnmExpanded);
}

void MakeDirList(
  CDynamicStackArray_CTFileName& adeDir,
  const CTFileName& fnmDir,
  const CTString& strPattern,
  ULONG ulFlags)
{
  return MakeDirList_(adeDir, fnmDir, strPattern, ulFlags);
}

extern CTFileName _fnmApplicationPath(_fnmApplicationPath_(), false);
extern CTFileName _fnmMod(_fnmMod_(), false);
extern CTString _strModName(_strModName_(), false);
extern CTString _strModURL(_strModURL_(), false);
extern CTString _strModExt(_strModExt_(), false);
extern CTFileName _fnmCDPath(_fnmCDPath_(), false);
extern CTFileName _fnmApplicationExe(_fnmApplicationExe_(), false);

void UseApplicationPath()
{
  UseApplicationPath_();
}

void IgnoreApplicationPath()
{
  IgnoreApplicationPath_();
}
