#pragma once
#include "../Base/Types.h"
#include "../Entities/EntityEvent.h"
#include <SeriousEngineCAPI/Classes/BaseEvents.h>

class EFirstWorldBase : public CEntityEvent
{
public:
  EFirstWorldBase(EFirstWorldBase_* p, bool owner = false);
  EFirstWorldBase();
  EFirstWorldBase(const EFirstWorldBase& o);
  ~EFirstWorldBase();
  EFirstWorldBase& operator=(const EFirstWorldBase& o);

  inline EFirstWorldBase_* C_Handle() { return CEntityEvent_to_EFirstWorldBase(mp_handle); }
  inline const EFirstWorldBase_* C_Handle() const { return CEntityEvent_to_EFirstWorldBase_const(mp_handle); }
  inline operator EFirstWorldBase_* () { return C_Handle(); }
  inline operator const EFirstWorldBase_* () const { return C_Handle(); }

private:
  bool m_owner = true;
};

#include "BaseEvents.inl"
