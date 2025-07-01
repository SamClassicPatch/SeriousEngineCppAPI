#pragma once

inline CUpdateable::CUpdateable(CUpdateable_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CUpdateable::CUpdateable()
  : m_owner(true)
  , mp_handle(CUpdateable_new())
{
}

inline CUpdateable::CUpdateable(const CUpdateable& o)
  : m_owner(true)
  , mp_handle(CUpdateable_clone(o))
{
}

inline CUpdateable::~CUpdateable()
{
  if (m_owner)
    CUpdateable_delete(mp_handle);
}

inline CUpdateable& CUpdateable::operator=(const CUpdateable& o)
{
  CUpdateable_copy(mp_handle, o);
  return *this;
}

inline TIME CUpdateable::LastUpdateTime() const
{
  return CUpdateable_LastUpdateTime(mp_handle);
}

inline void CUpdateable::MarkUpdated()
{
  CUpdateable_MarkUpdated(mp_handle);
}

inline void CUpdateable::Invalidate()
{
  CUpdateable_Invalidate(mp_handle);
}
