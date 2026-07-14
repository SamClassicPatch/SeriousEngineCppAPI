#pragma once

inline CTCriticalSection::CTCriticalSection(CTCriticalSection_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CTCriticalSection::CTCriticalSection()
  : m_owner(true)
  , mp_handle(CTCriticalSection_new())
{
}

inline CTCriticalSection::~CTCriticalSection()
{
  if (m_owner)
    CTCriticalSection_delete(mp_handle);
}

inline CTSingleLock::CTSingleLock(CTSingleLock_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CTSingleLock::CTSingleLock(CTCriticalSection_* pcs, BOOL bLock)
  : m_owner(true)
  , mp_handle(CTSingleLock_new(pcs, bLock))
{
}

inline CTSingleLock::~CTSingleLock()
{
  if (m_owner)
    CTSingleLock_delete(mp_handle);
}

inline void CTSingleLock::Lock()
{
  CTSingleLock_Lock(mp_handle);
}

inline BOOL CTSingleLock::TryToLock()
{
  return CTSingleLock_TryToLock(mp_handle);
}

inline BOOL CTSingleLock::IsLocked()
{
  return CTSingleLock_IsLocked(mp_handle);
}

inline void CTSingleLock::Unlock()
{
  CTSingleLock_Unlock(mp_handle);
}

