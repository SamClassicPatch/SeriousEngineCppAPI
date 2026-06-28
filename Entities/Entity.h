#pragma once
#include "../Base/Types.h"

class CEntity
{
public:
  CEntity(CEntity_* p, bool dummy = false);
  ~CEntity();
  CEntity(const CEntity& ln) = delete;
  CEntity& operator=(const CEntity& ln) = delete;

  inline CEntity_* C_Handle() { return mp_handle; }
  inline const CEntity_* C_Handle() const { return mp_handle; }
  inline operator CEntity_* () { return C_Handle(); }
  inline operator const CEntity_* () const { return C_Handle(); }
private:
  CEntity_* mp_handle = nullptr;

public:
};

#include "Entity.inl"
