#pragma once
#include "../Base/Types.h"
#include "../Base/Stream.h"
#include "../Base/Serial.h"
#include <SeriousEngineCAPI/Graphics/Font.h>

// some default fonts
#define _pfdDisplayFont\
  _pfdDisplayFont_()
#define _pfdConsoleFont\
  _pfdConsoleFont_()

/*
 * font letter description
 */
class CFontCharData
{
public:
  CFontCharData(CFontCharData_* p, bool owner = false);
  CFontCharData();
  CFontCharData(const CFontCharData& o);
  ~CFontCharData();
  CFontCharData& operator=(const CFontCharData& o);

  // simple stream functions
  void Read_t(CTStream* inFile);
  void Write_t(CTStream* outFile);

  inline CFontCharData_* C_Handle() { return mp_handle; }
  inline const CFontCharData_* C_Handle() const { return mp_handle; }
  inline operator CFontCharData_* () { return C_Handle(); }
  inline operator const CFontCharData_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CFontCharData_* mp_handle = nullptr;

public:
  PIX& fcd_pixXOffset; // offset of letter inside tex file (in pixels)
  PIX& fcd_pixYOffset;
  PIX& fcd_pixStart;       // position and size adjustment for current letter
  PIX& fcd_pixEnd;
};

/*
 * font description
 */
class CFontData : public CSerial
{
public:
  CFontData(CFontData_* p, bool owner = false);
  CFontData();
  CFontData(const CFontData& o);
  ~CFontData();
  CFontData& operator=(const CFontData& o);

  PIX  GetWidth() const;
  PIX  GetHeight() const;
  PIX  GetCharSpacing() const;
  PIX  GetLineSpacing() const;
  BOOL IsFixedWidth() const;
  void SetCharSpacing(PIX pixSpacing);
  void SetLineSpacing(PIX pixSpacing);
  void SetFixedWidth();
  void SetVariableWidth();
  void SetSpaceWidth(FLOAT fWidthRatio);
  CFontCharData fd_fcdFontCharData(unsigned char c);
  const CFontCharData fd_fcdFontCharData(unsigned char c) const;

  void Read_t(CTStream* inFile); // throw char *
  void Write_t(CTStream* outFile); // throw char *
  void Make_t(const CTFileName& fnTexture, PIX pixCharWidth, PIX pixCharHeight,
    CTFileName& fnOrderFile, BOOL bUseAlpha);
  void Clear();

  inline CFontData_* C_Handle() { return (CFontData_*)CSerial::C_Handle(); }
  inline const CFontData_* C_Handle() const { return (const CFontData_*)CSerial::C_Handle(); }
  inline operator CFontData_* () { return C_Handle(); }
  inline operator const CFontData_* () const { return C_Handle(); }

public:
  PIX& fd_pixCharSpacing;  // intra character and intra line spacing
  PIX& fd_pixLineSpacing;
  PIX&  fd_pixCharWidth;     // maximum character width and height
  PIX& fd_pixCharHeight;
  BOOL& fd_bFixedWidth;   // treated as of fixed width

  CTFileName fd_fnTexture;
  CTextureData_*& fd_ptdTextureData;
};

#include "Font.inl"
