#pragma once

inline CChangeable::CChangeable(CChangeable_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CChangeable::CChangeable()
  : m_owner(true)
  , mp_handle(CChangeable_new())
{
}

inline CChangeable::CChangeable(const CChangeable& o)
  : m_owner(true)
  , mp_handle(CChangeable_clone(o))
{
}

inline CChangeable::~CChangeable()
{
  if (m_owner)
    CChangeable_delete(mp_handle);
}

inline CChangeable& CChangeable::operator=(const CChangeable& o)
{
  CChangeable_copy(mp_handle, o);
  return *this;
}

inline void CChangeable::MarkChanged()
{
  CChangeable_MarkChanged(mp_handle);
}

inline BOOL CChangeable::IsUpToDate(const CUpdateable& ud) const
{
  return CChangeable_IsUpToDate(mp_handle, ud);
}
