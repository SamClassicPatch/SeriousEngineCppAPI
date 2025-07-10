#pragma once

inline CFontCharData::CFontCharData(CFontCharData_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , fcd_pixXOffset(*CFontCharData_fcd_pixXOffset(mp_handle))
  , fcd_pixYOffset(*CFontCharData_fcd_pixYOffset(mp_handle))
  , fcd_pixStart(*CFontCharData_fcd_pixStart(mp_handle))
  , fcd_pixEnd(*CFontCharData_fcd_pixEnd(mp_handle))
{
}

inline CFontCharData::CFontCharData()
  : CFontCharData(CFontCharData_new(), true)
{
}

inline CFontCharData::CFontCharData(const CFontCharData& o)
  : CFontCharData(CFontCharData_clone(o), true)
{
}

inline CFontCharData::~CFontCharData()
{
  if (m_owner)
    CFontCharData_delete(C_Handle());
}

inline CFontCharData& CFontCharData::operator=(const CFontCharData& o)
{
  CFontCharData_copy(C_Handle(), o);
  return *this;
}

inline void CFontCharData::Read_t(CTStream* inFile)
{
  CFontCharData_Read_t(mp_handle, *inFile);
  SECppAPI_CheckException();
}

inline void CFontCharData::Write_t(CTStream* outFile)
{
  CFontCharData_Write_t(mp_handle, *outFile);
  SECppAPI_CheckException();
}

inline CFontData::CFontData(CFontData_* p, bool owner)
  : CSerial((CSerial_*)p, owner)
  , fd_pixCharSpacing(*CFontData_fd_pixCharSpacing(C_Handle()))
  , fd_pixLineSpacing(*CFontData_fd_pixLineSpacing(C_Handle()))
  , fd_pixCharWidth(*CFontData_fd_pixCharWidth(C_Handle()))
  , fd_pixCharHeight(*CFontData_fd_pixCharHeight(C_Handle()))
  , fd_bFixedWidth(*CFontData_fd_bFixedWidth(C_Handle()))
  , fd_fnTexture(CFontData_fd_fnTexture(C_Handle()), false)
  , fd_ptdTextureData(*CFontData_fd_ptdTextureData(C_Handle()))
{
}

inline CFontData::CFontData()
  : CFontData(CFontData_new(), true)
{
}

inline CFontData::CFontData(const CFontData& o)
  : CFontData(CFontData_clone(o), true)
{
}

inline CFontData::~CFontData()
{
  if (m_owner)
    CFontData_delete(C_Handle());
  m_owner = false;
  mp_handle = nullptr;
}

inline CFontData& CFontData::operator=(const CFontData& o)
{
  CFontData_copy(C_Handle(), o);
  return *this;
}

inline PIX CFontData::GetWidth() const
{
  return fd_pixCharWidth;
}

inline PIX CFontData::GetHeight() const
{
  return fd_pixCharHeight;
}

inline PIX CFontData::GetCharSpacing() const
{
  return fd_pixCharSpacing;
}

inline PIX CFontData::GetLineSpacing() const
{
  return fd_pixLineSpacing;
}

inline BOOL CFontData::IsFixedWidth() const
{
  return fd_bFixedWidth;
}

inline void CFontData::SetCharSpacing(PIX pixSpacing)
{
  fd_pixCharSpacing = pixSpacing;
}

inline void CFontData::SetLineSpacing(PIX pixSpacing)
{
  fd_pixLineSpacing = pixSpacing;
}

inline void CFontData::SetFixedWidth()
{
  fd_bFixedWidth = TRUE;
}

inline void CFontData::SetVariableWidth()
{
  fd_bFixedWidth = FALSE;
}

inline void CFontData::SetSpaceWidth(FLOAT fWidthRatio)
{
  CFontData_SetSpaceWidth(C_Handle(), fWidthRatio);
}

__forceinline CFontCharData CFontData::fd_fcdFontCharData(unsigned char c)
{
  return CFontCharData(CFontData_fd_fcdFontCharData(C_Handle(), c), false);
}

__forceinline const CFontCharData CFontData::fd_fcdFontCharData(unsigned char c) const
{
  return CFontCharData(CFontData_fd_fcdFontCharData((CFontData_*)C_Handle(), c), false);
}

inline void CFontData::Read_t(CTStream* inFile)
{
  CFontData_Read_t(C_Handle(), *inFile);
  SECppAPI_CheckException();
}

inline void CFontData::Write_t(CTStream* outFile)
{
  CFontData_Write_t(C_Handle(), *outFile);
  SECppAPI_CheckException();
}

inline void CFontData::Make_t(const CTFileName& fnTexture, PIX pixCharWidth, PIX pixCharHeight, CTFileName& fnOrderFile, BOOL bUseAlpha)
{
  CFontData_Make_t(C_Handle(), fnTexture, pixCharWidth, pixCharHeight, fnOrderFile, bUseAlpha);
  SECppAPI_CheckException();
}

inline void CFontData::Clear()
{
  CFontData_Clear(C_Handle());
}
