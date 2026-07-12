#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Light/LightSource.h>

class CLightSource
{
public:
  CLightSource(CLightSource_* p, bool dummy = false);
  ~CLightSource();
  CLightSource(const CLightSource& ln) = delete;
  CLightSource& operator=(const CLightSource& ln) = delete;

  inline CLightSource_* C_Handle() { return mp_handle; }
  inline const CLightSource_* C_Handle() const { return mp_handle; }
  inline operator CLightSource_* () { return C_Handle(); }
  inline operator const CLightSource_* () const { return C_Handle(); }
private:
  CLightSource_* mp_handle = nullptr;

public:
  ULONG& ls_ulFlags; // various flags
  CEntity_*& ls_penEntity; // the entity of this light source
};

#include "LightSource.inl"
