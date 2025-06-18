#pragma once
#include <SeriousEngineCAPI/Base/Stream.h>
#include "../Base/API.h"

class SECPPAPI CTStream
{
public:

  inline CTStream_* C_Handle() { return mp_stream; }
  inline const CTStream_* C_Handle() const { return mp_stream; }
private:
  const bool m_owner = true;
  CTStream_* mp_stream = nullptr;
};
