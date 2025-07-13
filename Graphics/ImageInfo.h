#pragma once
#include "../Base/Types.h"
#include "../Base/Stream.h"
#include <SeriousEngineCAPI/Graphics/ImageInfo.h>

class CImageInfo
{
public:
  CImageInfo(CImageInfo_* p, bool owner = false);
  CImageInfo();
  ~CImageInfo();

  // reads image info raw format from file
  void Read_t(CTStream* inFile); // throw char *
  // writes image info raw format to file
  void Write_t(CTStream* outFile) const; // throw char *

  // initializes structure members and attaches pointer to image
  void Attach(UBYTE* pPicture, PIX pixWidth, PIX pixHeight, SLONG slBitsPerPixel);
  // clears the content of an image info structure but does not free allocated memory
  void Detach();
  // clears the content of an image info structure and frees allocated memory
  void Clear();
  // expand image edges
  void ExpandEdges(INDEX ctPasses = 8192);

  // sets image info structure members with info form file of any supported graphic format,
  //  but does not load picture content nor palette; returns format type (see #defines)
  //  (supported formats: CroTeam's RAW, PCX24, TGA32 uncompressed)
  INDEX GetGfxFileInfo_t(const CTFileName& strFileName); // throw char *

  // sets image info structure members with info form file of any supported graphic format
  //  and loads picture content and, eventually, palette
  void LoadAnyGfxFormat_t(const CTFileName& strFileName); // throw char *

  // converts image info structure and content to PCX or TGA format and saves it to file
  void SaveTGA_t(const CTFileName& strFileName) const; // throw char *

  inline CImageInfo_* C_Handle() { return mp_handle; }
  inline const CImageInfo_* C_Handle() const { return mp_handle; }
  inline operator CImageInfo_* () { return C_Handle(); }
  inline operator const CImageInfo_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CImageInfo_* mp_handle = nullptr;

public:
  PIX&    ii_Width;	           // width of image in pixels
  PIX&    ii_Height;	           // height of image in pixels
  SLONG&  ii_BitsPerPixel;      // depth of image (color bits; 24 or 32=24+8 alpha)
  UBYTE*& ii_Picture; 	         // pointer to picture contents (raw bytes)
};

#include "ImageInfo.inl"
