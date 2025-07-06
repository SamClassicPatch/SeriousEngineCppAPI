#pragma once
#include "../Base/Anim.h"
#include "ImageInfo.h"
#include <SeriousEngineCAPI/Graphics/Texture.h>

/*
 * Bitmap data for a class of texture objects
 */
class CTextureData : public CAnimData
{
public:
  CTextureData(CTextureData_* p, bool owner = false);
  CTextureData();
  ~CTextureData();

  BOOL HasEffectTexture() const;

  // converts global mip level to the corresponding one of texture
  INDEX ClampMipLevel(FLOAT fMipFactor) const;

  // gets values from some of texture data members
  MEX GetWidth() const;
  MEX GetHeight() const;
  PIX GetPixWidth() const;
  PIX GetPixHeight() const;
  ULONG GetFlags() const;
  ULONG GetNoOfMips() const;
  ULONG GetNoOfFineMips() const;

  // check if texture frame(s) has been somehow altered (dithering, filtering, saturation, colorizing...)
  BOOL IsModified();
  // export finest mipmap of one texture's frame to imageinfo
  void Export_t(class CImageInfo& iiExportedImage, INDEX iFrame);
  // creates new texture with one frame
  void Create_t(const CImageInfo* pII, MEX mexWanted, INDEX ctFineMips, BOOL bForce32bit);

  // free memory allocated for texture
  void Clear();

  // force texture to be re-loaded (if needed) in corresponding manner
  void Force(ULONG ulTexFlags);

  // get texel from texture's largest mip-map
  COLOR GetTexel(MEX mexU, MEX mexV);
  // copy (and eventually convert to floats) one row from texture to an array (iChannel is 1=R,2=G,3=B,4=A)
  void  FetchRow(PIX pixRow, void* pfDst, INDEX iChannel = 4, BOOL bConvertToFloat = TRUE);
  // get pointer to one row of texture
  ULONG* GetRowPointer(PIX pixRow);

  inline CTextureData_* C_Handle() { return (CTextureData_*)CAnimData::C_Handle(); }
  inline const CTextureData_* C_Handle() const { return (const CTextureData_*)CAnimData::C_Handle(); }
  inline operator CTextureData_* () { return C_Handle(); }
  inline operator const CTextureData_* () const { return C_Handle(); }

public:
  ULONG&  td_ulFlags; // see defines
  MEX&    td_mexWidth; // texture dimensions
  MEX&    td_mexHeight;
  INDEX&  td_ctFrames; // number of different frames
  ULONG*& td_pulFrames; // all frames with their mip-maps and private palettes
};


/*
 * An instance of a texture object
 */
class CTextureObject : public CAnimObject
{
public:
  CTextureObject(CTextureObject_* p, bool owner = false);
  CTextureObject();
  ~CTextureObject();

  MEX GetWidth() const;
  MEX GetHeight() const;
  ULONG GetFlags() const;

  // obtain texture and set it for this object
  void SetData_t(const CTFileName& fnmTexture); // throw char *
  // get filename of texture or empty string if no texture
  const CTFileName GetName();

  inline CTextureObject_* C_Handle() { return (CTextureObject_*)CAnimObject::C_Handle(); }
  inline const CTextureObject_* C_Handle() const { return (const CTextureObject_*)CAnimObject::C_Handle(); }
  inline operator CTextureObject_* () { return C_Handle(); }
  inline operator const CTextureObject_* () const { return C_Handle(); }
};

void CreateTexture_t(const CTFileName& inFileName,
  MEX inMex, INDEX inMipmaps, BOOL bForce32bit);
void CreateTexture_t(const CTFileName& inFileName, const CTFileName& outFileName,
  MEX inMex, INDEX inMipmaps, BOOL bForce32bit);
void ProcessScript_t(const CTFileName& inFileName);

#include "Texture.inl"
