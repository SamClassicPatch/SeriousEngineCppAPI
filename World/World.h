#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/World/World.h>

class CWorld
{
public:
  CWorld(CWorld_* p, bool owner = false);
  CWorld();
  ~CWorld();
  CWorld(const CWorld& ln) = delete;
  CWorld& operator=(const CWorld& ln) = delete;

  inline CWorld_* C_Handle() { return mp_handle; }
  inline const CWorld_* C_Handle() const { return mp_handle; }
  inline operator CWorld_* () { return C_Handle(); }
  inline operator const CWorld_* () const { return C_Handle(); }
private:
  bool m_owner = true;
  CWorld_* mp_handle = nullptr;
};

#include "World.inl"
