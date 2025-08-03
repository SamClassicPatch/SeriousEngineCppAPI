#pragma once

inline CUpdateableRT::CUpdateableRT(CUpdateableRT_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CUpdateableRT::CUpdateableRT()
  : m_owner(true)
  , mp_handle(CUpdateableRT_new())
{
}

inline CUpdateableRT::CUpdateableRT(const CUpdateableRT& o)
  : m_owner(true)
  , mp_handle(CUpdateableRT_clone(o))
{
}

inline CUpdateableRT::~CUpdateableRT()
{
  if (m_owner)
    CUpdateableRT_delete(mp_handle);
}

inline CUpdateableRT& CUpdateableRT::operator=(const CUpdateableRT& o)
{
  CUpdateableRT_copy(mp_handle, o);
  return *this;
}

inline TIME CUpdateableRT::LastUpdateTime() const
{
  return CUpdateableRT_LastUpdateTime(mp_handle);
}

inline void CUpdateableRT::MarkUpdated()
{
  CUpdateableRT_MarkUpdated(mp_handle);
}

inline void CUpdateableRT::Invalidate()
{
  CUpdateableRT_Invalidate(mp_handle);
}
