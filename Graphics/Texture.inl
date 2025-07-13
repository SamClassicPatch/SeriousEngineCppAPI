#pragma once

inline CTextureData::CTextureData(CTextureData_* p, bool owner)
  : CAnimData((CAnimData_*)p, owner)
  , td_ulFlags(*CTextureData_td_ulFlags(C_Handle()))
  , td_mexWidth(*CTextureData_td_mexWidth(C_Handle()))
  , td_mexHeight(*CTextureData_td_mexHeight(C_Handle()))
  , td_ctFrames(*CTextureData_td_ctFrames(C_Handle()))
  , td_pulFrames(*CTextureData_td_pulFrames(C_Handle()))
{
}

inline CTextureData::CTextureData()
  : CTextureData(CTextureData_new(), true)
{
}

inline CTextureData::~CTextureData()
{
  if (m_owner)
    CTextureData_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline BOOL CTextureData::HasEffectTexture() const
{
  return CTextureData_HasEffectTexture(C_Handle());
}

inline INDEX CTextureData::ClampMipLevel(FLOAT fMipFactor) const
{
  return CTextureData_ClampMipLevel(C_Handle(), fMipFactor);
}

inline MEX CTextureData::GetWidth() const
{
  return CTextureData_GetWidth(C_Handle());
}

inline MEX CTextureData::GetHeight() const
{
  return CTextureData_GetHeight(C_Handle());
}

inline PIX CTextureData::GetPixWidth() const
{
  return CTextureData_GetPixWidth(C_Handle());
}

inline PIX CTextureData::GetPixHeight() const
{
  return CTextureData_GetPixHeight(C_Handle());
}

inline ULONG CTextureData::GetFlags() const
{
  return CTextureData_GetFlags(C_Handle());
}

inline ULONG CTextureData::GetNoOfMips() const
{
  return CTextureData_GetNoOfMips(C_Handle());
}

inline ULONG CTextureData::GetNoOfFineMips() const
{
  return CTextureData_GetNoOfFineMips(C_Handle());
}

inline BOOL CTextureData::IsModified()
{
  return CTextureData_IsModified(C_Handle());
}

inline void CTextureData::Export_t(class CImageInfo& iiExportedImage, INDEX iFrame)
{
  CTextureData_Export_t(C_Handle(), iiExportedImage, iFrame);
  SECppAPI_CheckException();
}

inline void CTextureData::Create_t(const CImageInfo* pII, MEX mexWanted, INDEX ctFineMips, BOOL bForce32bit)
{
  CTextureData_Create_t(C_Handle(), *pII, mexWanted, ctFineMips, bForce32bit);
  SECppAPI_CheckException();
}

inline void CTextureData::Clear()
{
  CTextureData_Clear(C_Handle());
}

inline void CTextureData::Force(ULONG ulTexFlags)
{
  CTextureData_Force(C_Handle(), ulTexFlags);
  SECppAPI_CheckException();
}

inline COLOR CTextureData::GetTexel(MEX mexU, MEX mexV)
{
  return CTextureData_GetTexel(C_Handle(), mexU, mexV);
}

inline void CTextureData::FetchRow(PIX pixRow, void* pfDst, INDEX iChannel, BOOL bConvertToFloat)
{
  CTextureData_FetchRow(C_Handle(), pixRow, pfDst, iChannel, bConvertToFloat);
}

inline ULONG* CTextureData::GetRowPointer(PIX pixRow)
{
  return CTextureData_GetRowPointer(C_Handle(), pixRow);
}


inline CTextureObject::CTextureObject(CTextureObject_* p, bool owner)
  : CAnimObject((CAnimObject_*)p, owner)
{
}

inline CTextureObject::CTextureObject()
  : CTextureObject(CTextureObject_new(), true)
{
}

inline CTextureObject::~CTextureObject()
{
  if (m_owner)
    CTextureObject_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline MEX CTextureObject::GetWidth() const
{
  return CTextureObject_GetWidth(C_Handle());
}

inline MEX CTextureObject::GetHeight() const
{
  return CTextureObject_GetHeight(C_Handle());
}

inline ULONG CTextureObject::GetFlags() const
{
  return CTextureObject_GetFlags(C_Handle());
}

inline void CTextureObject::SetData_t(const CTFileName& fnmTexture)
{
  CTextureObject_SetData_t(C_Handle(), fnmTexture);
  SECppAPI_CheckException();
}

__forceinline const CTFileNamePtr CTextureObject::GetName()
{
  return (CTFileName_*)CTextureObject_GetName(C_Handle());
}


inline void CreateTexture_t(const CTFileName& inFileName, MEX inMex, INDEX inMipmaps, BOOL bForce32bit)
{
  CreateTexture_t_(inFileName, inMex, inMipmaps, bForce32bit);
  SECppAPI_CheckException();
}

inline void CreateTexture_t(const CTFileName& inFileName, const CTFileName& outFileName, MEX inMex, INDEX inMipmaps, BOOL bForce32bit)
{
  CreateTexture_t_o(inFileName, outFileName, inMex, inMipmaps, bForce32bit);
  SECppAPI_CheckException();
}

inline void ProcessScript_t(const CTFileName& inFileName)
{
  ProcessScript_t_(inFileName);
  SECppAPI_CheckException();
}
