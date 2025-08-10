#pragma once

inline GFXVertex3::GFXVertex3(GFXVertex3_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , x(*GFXVertex3_x(mp_handle))
  , y(*GFXVertex3_y(mp_handle))
  , z(*GFXVertex3_z(mp_handle))
{
}

inline GFXVertex3::GFXVertex3()
  : GFXVertex3(GFXVertex3_new(), true)
{
}

inline GFXVertex3::GFXVertex3(const GFXVertex3& o)
  : GFXVertex3(GFXVertex3_clone(o), true)
{
}

inline GFXVertex3::~GFXVertex3()
{
  if (m_owner)
    GFXVertex3_delete(mp_handle);
}

inline GFXVertex3& GFXVertex3::operator=(const GFXVertex3& o)
{
  GFXVertex3_copy(mp_handle, o);
  return *this;
}

inline GFXNormal3::GFXNormal3(GFXNormal3_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , nx(*GFXNormal3_nx(mp_handle))
  , ny(*GFXNormal3_ny(mp_handle))
  , nz(*GFXNormal3_nz(mp_handle))
{
}

inline GFXNormal3::GFXNormal3()
  : GFXNormal3(GFXNormal3_new(), true)
{
}

inline GFXNormal3::GFXNormal3(const GFXNormal3& o)
  : GFXNormal3(GFXNormal3_clone(o), true)
{
}

inline GFXNormal3::~GFXNormal3()
{
  if (m_owner)
    GFXNormal3_delete(mp_handle);
}

inline GFXNormal3& GFXNormal3::operator=(const GFXNormal3& o)
{
  GFXNormal3_copy(mp_handle, o);
  return *this;
}

inline GFXTexCoord::GFXTexCoord(GFXTexCoord_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , u(*GFXTexCoord_u(mp_handle))
  , v(*GFXTexCoord_v(mp_handle))
  , s(*GFXTexCoord_s(mp_handle))
  , t(*GFXTexCoord_t(mp_handle))
{
}

inline GFXTexCoord::GFXTexCoord()
  : GFXTexCoord(GFXTexCoord_new(), true)
{
}

inline GFXTexCoord::GFXTexCoord(const GFXTexCoord& o)
  : GFXTexCoord(GFXTexCoord_clone(o), true)
{
}

inline GFXTexCoord::~GFXTexCoord()
{
  if (m_owner)
    GFXTexCoord_delete(mp_handle);
}

inline GFXTexCoord& GFXTexCoord::operator=(const GFXTexCoord& o)
{
  GFXTexCoord_copy(mp_handle, o);
  return *this;
}

inline GFXTexCoord4::GFXTexCoord4(GFXTexCoord4_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , s(*GFXTexCoord4_s(mp_handle))
  , t(*GFXTexCoord4_t(mp_handle))
  , r(*GFXTexCoord4_r(mp_handle))
  , q(*GFXTexCoord4_q(mp_handle))
{
}

inline GFXTexCoord4::GFXTexCoord4()
  : GFXTexCoord4(GFXTexCoord4_new(), true)
{
}

inline GFXTexCoord4::GFXTexCoord4(const GFXTexCoord4& o)
  : GFXTexCoord4(GFXTexCoord4_clone(o), true)
{
}

inline GFXTexCoord4::~GFXTexCoord4()
{
  if (m_owner)
    GFXTexCoord4_delete(mp_handle);
}

inline GFXTexCoord4& GFXTexCoord4::operator=(const GFXTexCoord4& o)
{
  GFXTexCoord4_copy(mp_handle, o);
  return *this;
}

inline GFXColor::GFXColor(GFXColor_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , r(*GFXColor_r(mp_handle))
  , g(*GFXColor_g(mp_handle))
  , b(*GFXColor_b(mp_handle))
  , a(*GFXColor_a(mp_handle))
  , abgr(*GFXColor_abgr(mp_handle))
{
}

inline GFXColor::GFXColor()
  : GFXColor(GFXColor_new(), true)
{
}

inline GFXColor::GFXColor(COLOR col)
  : GFXColor(GFXColor_new_col(col), true)
{
}

inline GFXColor::GFXColor(const GFXColor& o)
  : GFXColor(GFXColor_clone(o), true)
{
}

inline GFXColor::~GFXColor()
{
  if (m_owner)
    GFXColor_delete(mp_handle);
}

inline GFXColor& GFXColor::operator=(const GFXColor& o)
{
  GFXColor_copy(mp_handle, o);
  return *this;
}

inline void GFXColor::Set(COLOR col)
{
  GFXColor_Set(mp_handle, col);
}

inline void GFXColor::MultiplyRGBA(const GFXColor& col1, const GFXColor& col2)
{
  GFXColor_MultiplyRGBA(mp_handle, col1, col2);
}

inline void GFXColor::MultiplyRGB(const GFXColor& col1, const GFXColor& col2)
{
  GFXColor_MultiplyRGB(mp_handle, col1, col2);
}

inline void GFXColor::MultiplyRGBCopyA1(const GFXColor& col1, const GFXColor& col2)
{
  GFXColor_MultiplyRGBCopyA1(mp_handle, col1, col2);
}

inline void GFXColor::AttenuateRGB(ULONG ulA)
{
  GFXColor_AttenuateRGB(mp_handle, ulA);
}

inline void GFXColor::AttenuateA(ULONG ulA)
{
  GFXColor_AttenuateA(mp_handle, ulA);
}

inline GFXVertex4::GFXVertex4(GFXVertex4_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , x(*GFXVertex4_x(mp_handle))
  , y(*GFXVertex4_y(mp_handle))
  , z(*GFXVertex4_z(mp_handle))
  , col(GFXVertex4_col(mp_handle), false)
  , shade(*GFXVertex4_shade(mp_handle))
{
}

inline GFXVertex4::GFXVertex4()
  : GFXVertex4(GFXVertex4_new(), true)
{
}

inline GFXVertex4::GFXVertex4(const GFXVertex4& o)
  : GFXVertex4(GFXVertex4_clone(o), true)
{
}

inline GFXVertex4::~GFXVertex4()
{
  if (m_owner)
    GFXVertex4_delete(mp_handle);
}

inline GFXVertex4& GFXVertex4::operator=(const GFXVertex4& o)
{
  GFXVertex4_copy(mp_handle, o);
  return *this;
}

inline GFXNormal4::GFXNormal4(GFXNormal4_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , nx(*GFXNormal4_nx(mp_handle))
  , ny(*GFXNormal4_ny(mp_handle))
  , nz(*GFXNormal4_nz(mp_handle))
  , ul(*GFXNormal4_ul(mp_handle))
{
}

inline GFXNormal4::GFXNormal4()
  : GFXNormal4(GFXNormal4_new(), true)
{
}

inline GFXNormal4::GFXNormal4(const GFXNormal4& o)
  : GFXNormal4(GFXNormal4_clone(o), true)
{
}

inline GFXNormal4::~GFXNormal4()
{
  if (m_owner)
    GFXNormal4_delete(mp_handle);
}

inline GFXNormal4& GFXNormal4::operator=(const GFXNormal4& o)
{
  GFXNormal4_copy(mp_handle, o);
  return *this;
}
