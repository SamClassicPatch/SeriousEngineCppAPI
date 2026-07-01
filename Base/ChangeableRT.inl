#pragma once

inline CChangeableRT::CChangeableRT(CChangeableRT_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CChangeableRT::CChangeableRT()
  : m_owner(true)
  , mp_handle(CChangeableRT_new())
{
}

inline CChangeableRT::CChangeableRT(const CChangeableRT& o)
  : m_owner(true)
  , mp_handle(CChangeableRT_clone(o))
{
}

inline CChangeableRT::~CChangeableRT()
{
  if (m_owner)
    CChangeableRT_delete(mp_handle);
}

inline CChangeableRT& CChangeableRT::operator=(const CChangeableRT& o)
{
  CChangeableRT_copy(mp_handle, o);
  return *this;
}

inline void CChangeableRT::MarkChanged()
{
  CChangeableRT_MarkChanged(mp_handle);
}

inline BOOL CChangeableRT::IsUpToDate(const CUpdateableRT& ud) const
{
  return CChangeableRT_IsUpToDate(mp_handle, ud);
}
