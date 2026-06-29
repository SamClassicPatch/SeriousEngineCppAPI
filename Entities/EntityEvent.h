#pragma once
#include "../Base/Types.h"

class CEntityEvent
{
public:
  virtual ~CEntityEvent() = 0;

  inline CEntityEvent_* C_Handle() { return mp_handle; }
  inline const CEntityEvent_* C_Handle() const { return mp_handle; }
  inline operator CEntityEvent_* () { return C_Handle(); }
  inline operator const CEntityEvent_* () const { return C_Handle(); }

protected:
  CEntityEvent_* mp_handle = nullptr;
};
