#pragma once
#include "Updateable.h"
#include <SeriousEngineCAPI/Base/Changeable.h>

/*
 * Object that can change in time.
 */
class CChangeable
{
public:
  CChangeable(CChangeable_* p, bool owner = false);
  CChangeable();
  CChangeable(const CChangeable& o);
  virtual ~CChangeable();

  CChangeable& operator=(const CChangeable& o);

  /* Mark that something has changed in this object. */
  void MarkChanged();
  /* Test if some updateable object is up to date with this changeable. */
  BOOL IsUpToDate(const CUpdateable& ud) const;

  inline CChangeable_* C_Handle() { return mp_handle; }
  inline const CChangeable_* C_Handle() const { return mp_handle; }
  inline operator CChangeable_* () { return C_Handle(); }
  inline operator const CChangeable_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  CChangeable_* mp_handle = nullptr;
};

#include "Changeable.inl"
