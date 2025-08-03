#pragma once
#include "UpdateableRT.h"
#include <SeriousEngineCAPI/Base/ChangeableRT.h>

/*
 * Object that can change in time.
 */
class CChangeableRT
{
public:
  CChangeableRT(CChangeableRT_* p, bool owner = false);
  CChangeableRT();
  CChangeableRT(const CChangeableRT& o);
  virtual ~CChangeableRT();

  CChangeableRT& operator=(const CChangeableRT& o);

  /* Mark that something has changed in this object. */
  void MarkChanged();
  /* Test if some updateable object is up to date with this changeable. */
  BOOL IsUpToDate(const CUpdateableRT& ud) const;

  inline CChangeableRT_* C_Handle() { return mp_handle; }
  inline const CChangeableRT_* C_Handle() const { return mp_handle; }
  inline operator CChangeableRT_* () { return C_Handle(); }
  inline operator const CChangeableRT_* () const { return C_Handle(); }

protected:
  bool m_owner = true;
  CChangeableRT_* mp_handle = nullptr;
};

#include "ChangeableRT.inl"
