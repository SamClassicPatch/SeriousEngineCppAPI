#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Graphics/Vertex.h>

class GFXVertex3
{
public:
  GFXVertex3(GFXVertex3_* p, bool owner = false);
  GFXVertex3();
  GFXVertex3(const GFXVertex3& o);
  ~GFXVertex3();
  GFXVertex3& operator=(const GFXVertex3& o);

  inline GFXVertex3_* C_Handle() { return mp_handle; }
  inline const GFXVertex3_* C_Handle() const { return mp_handle; }
  inline operator GFXVertex3_* () { return C_Handle(); }
  inline operator const GFXVertex3_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXVertex3_* mp_handle = nullptr;

public:
  FLOAT& x;
  FLOAT& y;
  FLOAT& z;
};

class GFXNormal3
{
public:
  GFXNormal3(GFXNormal3_* p, bool owner = false);
  GFXNormal3();
  GFXNormal3(const GFXNormal3& o);
  ~GFXNormal3();
  GFXNormal3& operator=(const GFXNormal3& o);

  inline GFXNormal3_* C_Handle() { return mp_handle; }
  inline const GFXNormal3_* C_Handle() const { return mp_handle; }
  inline operator GFXNormal3_* () { return C_Handle(); }
  inline operator const GFXNormal3_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXNormal3_* mp_handle = nullptr;

public:
  FLOAT& nx;
  FLOAT& ny;
  FLOAT& nz;
};

class GFXTexCoord
{
public:
  GFXTexCoord(GFXTexCoord_* p, bool owner = false);
  GFXTexCoord();
  GFXTexCoord(const GFXTexCoord& o);
  ~GFXTexCoord();
  GFXTexCoord& operator=(const GFXTexCoord& o);

  inline GFXTexCoord_* C_Handle() { return mp_handle; }
  inline const GFXTexCoord_* C_Handle() const { return mp_handle; }
  inline operator GFXTexCoord_* () { return C_Handle(); }
  inline operator const GFXTexCoord_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXTexCoord_* mp_handle = nullptr;

public:
  FLOAT& u;
  FLOAT& v;
  FLOAT& s;
  FLOAT& t;
};

class GFXTexCoord4
{
public:
  GFXTexCoord4(GFXTexCoord4_* p, bool owner = false);
  GFXTexCoord4();
  GFXTexCoord4(const GFXTexCoord4& o);
  ~GFXTexCoord4();
  GFXTexCoord4& operator=(const GFXTexCoord4& o);

  inline GFXTexCoord4_* C_Handle() { return mp_handle; }
  inline const GFXTexCoord4_* C_Handle() const { return mp_handle; }
  inline operator GFXTexCoord4_* () { return C_Handle(); }
  inline operator const GFXTexCoord4_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXTexCoord4_* mp_handle = nullptr;

public:
  FLOAT& s;
  FLOAT& t;
  FLOAT& r;
  FLOAT& q;
};

class GFXColor
{
public:
  GFXColor(GFXColor_* p, bool owner = false);
  GFXColor();
  GFXColor(COLOR col);
  GFXColor(const GFXColor& o);
  ~GFXColor();
  GFXColor& operator=(const GFXColor& o);

  void Set(COLOR col);
  void MultiplyRGBA(const GFXColor& col1, const GFXColor& col2);
  void MultiplyRGB(const GFXColor& col1, const GFXColor& col2);
  void MultiplyRGBCopyA1(const GFXColor& col1, const GFXColor& col2);
  void AttenuateRGB(ULONG ulA);
  void AttenuateA(ULONG ulA);

  inline GFXColor_* C_Handle() { return mp_handle; }
  inline const GFXColor_* C_Handle() const { return mp_handle; }
  inline operator GFXColor_* () { return C_Handle(); }
  inline operator const GFXColor_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXColor_* mp_handle = nullptr;

public:
  UBYTE& r;
  UBYTE& g;
  UBYTE& b;
  UBYTE& a;
  ULONG& abgr;
};

class GFXVertex4
{
public:
  GFXVertex4(GFXVertex4_* p, bool owner = false);
  GFXVertex4();
  GFXVertex4(const GFXVertex4& o);
  ~GFXVertex4();
  GFXVertex4& operator=(const GFXVertex4& o);

  inline GFXVertex4_* C_Handle() { return mp_handle; }
  inline const GFXVertex4_* C_Handle() const { return mp_handle; }
  inline operator GFXVertex4_* () { return C_Handle(); }
  inline operator const GFXVertex4_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXVertex4_* mp_handle = nullptr;

public:
  FLOAT& x;
  FLOAT& y;
  FLOAT& z;
  GFXColor col;
  SLONG& shade;
};

class GFXNormal4
{
public:
  GFXNormal4(GFXNormal4_* p, bool owner = false);
  GFXNormal4();
  GFXNormal4(const GFXNormal4& o);
  ~GFXNormal4();
  GFXNormal4& operator=(const GFXNormal4& o);

  inline GFXNormal4_* C_Handle() { return mp_handle; }
  inline const GFXNormal4_* C_Handle() const { return mp_handle; }
  inline operator GFXNormal4_* () { return C_Handle(); }
  inline operator const GFXNormal4_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  GFXNormal4_* mp_handle = nullptr;

public:
  FLOAT& nx;
  FLOAT& ny;
  FLOAT& nz;
  ULONG& ul;
};

#include "Vertex.inl"
