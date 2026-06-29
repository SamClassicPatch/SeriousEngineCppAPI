#pragma once

inline EFirstWorldBase::EFirstWorldBase(EFirstWorldBase_* p, bool owner)
  : CEntityEvent(EFirstWorldBase_to_CEntityEvent(p))
  , m_owner(owner)
{
}

inline EFirstWorldBase::EFirstWorldBase()
  : EFirstWorldBase(EFirstWorldBase_new())
  , m_owner(true)
{
}

inline EFirstWorldBase::EFirstWorldBase(const EFirstWorldBase& o)
  : EFirstWorldBase(EFirstWorldBase_clone(o))
  , m_owner(true)
{
}

inline EFirstWorldBase::~EFirstWorldBase()
{
  if (m_owner)
    EFirstWorldBase_delete(C_Handle());
}

inline EFirstWorldBase& EFirstWorldBase::operator=(const EFirstWorldBase& o)
{
  EFirstWorldBase_copy(C_Handle(), o);
  return *this;
}
