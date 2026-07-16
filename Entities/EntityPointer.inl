#pragma once

inline CEntityPointer::CEntityPointer(CEntityPointer_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CEntityPointer::CEntityPointer()
  : CEntityPointer(CEntityPointer_new(), true)
{
}

inline CEntityPointer::CEntityPointer(const CEntityPointer& o)
  : CEntityPointer(CEntityPointer_clone(o), true)
{
}

inline CEntityPointer::CEntityPointer(CEntity_* o)
  : CEntityPointer(CEntityPointer_new_e(o), true)
{
}

inline CEntityPointer::~CEntityPointer()
{
  if (m_owner)
    CEntityPointer_delete(C_Handle());
}

inline CEntityPointer& CEntityPointer::operator=(const CEntityPointer& o)
{
  CEntityPointer_copy(C_Handle(), o);
  return *this;
}

inline CEntityPointer& CEntityPointer::operator=(CEntity_* o)
{
  CEntityPointer_copy_e(C_Handle(), o);
  return *this;
}

inline bool CEntityPointer::operator==(const CEntityPointer& o) const
{
  return CEntityPointer_equal(C_Handle(), o) == TRUE;
}

inline bool CEntityPointer::operator==(const CEntity_* o) const
{
  return *CEntityPointer_ep_pen(C_Handle()) == o;
}

inline bool CEntityPointer::operator!=(const CEntityPointer& o) const
{
  return !((*this) == o);
}

inline bool CEntityPointer::operator!=(const CEntity_* o) const
{
  return !((*this) == o);
}

inline CEntityPointer::operator bool()
{
  return *CEntityPointer_ep_pen(C_Handle()) != nullptr;
}

inline CEntityPointer::operator bool() const
{
  return *CEntityPointer_ep_pen(C_Handle()) != nullptr;
}

__forceinline CEntityPtr CEntityPointer::ep_pen() const
{
  return *CEntityPointer_ep_pen(C_Handle());
}

__forceinline CEntityPtr CEntityPointer::operator->() const
{
  return ep_pen();
}

__forceinline CEntityPointer::operator CEntityPtr() const
{
  return ep_pen();
}

__forceinline CEntity& CEntityPointer::operator*() const
{
  mp_cache = ep_pen();
  return *mp_cache;
}
