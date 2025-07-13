#pragma once

inline CImageInfo::CImageInfo(CImageInfo_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ii_Width(*CImageInfo_ii_Width(mp_handle))
  , ii_Height(*CImageInfo_ii_Height(mp_handle))
  , ii_BitsPerPixel(*CImageInfo_ii_BitsPerPixel(mp_handle))
  , ii_Picture(*CImageInfo_ii_Picture(mp_handle))
{
}

inline CImageInfo::CImageInfo()
  : CImageInfo(CImageInfo_new(), true)
{
}

inline CImageInfo::~CImageInfo()
{
  if (m_owner)
    CImageInfo_delete(mp_handle);
}

inline void CImageInfo::Read_t(CTStream* inFile)
{
  CImageInfo_Read_t(mp_handle, *inFile);
  SECppAPI_CheckException();
}

inline void CImageInfo::Write_t(CTStream* outFile) const
{
  CImageInfo_Write_t(mp_handle, *outFile);
  SECppAPI_CheckException();
}

inline void CImageInfo::Attach(UBYTE* pPicture, PIX pixWidth, PIX pixHeight, SLONG slBitsPerPixel)
{
  CImageInfo_Attach(mp_handle, pPicture, pixWidth, pixHeight, slBitsPerPixel);
}

inline void CImageInfo::Detach()
{
  CImageInfo_Detach(mp_handle);
}

inline void CImageInfo::Clear()
{
  CImageInfo_Clear(mp_handle);
}

inline void CImageInfo::ExpandEdges(INDEX ctPasses)
{
  CImageInfo_ExpandEdges(mp_handle, ctPasses);
}

inline INDEX CImageInfo::GetGfxFileInfo_t(const CTFileName& strFileName)
{
  INDEX res = CImageInfo_GetGfxFileInfo_t(mp_handle, strFileName);
  SECppAPI_CheckException();
  return res;
}

inline void CImageInfo::LoadAnyGfxFormat_t(const CTFileName& strFileName)
{
  CImageInfo_LoadAnyGfxFormat_t(mp_handle, strFileName);
  SECppAPI_CheckException();
}

inline void CImageInfo::SaveTGA_t(const CTFileName& strFileName) const
{
  CImageInfo_SaveTGA_t(mp_handle, strFileName);
  SECppAPI_CheckException();
}
