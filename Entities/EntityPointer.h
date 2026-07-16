#pragma once
#include "../Base/Types.h"
#include "Entity.h"
#include <SeriousEngineCAPI/Entities/EntityPointer.h>

/*
 * Smart pointer to entity objects, does the book-keeping for reference counting.
 */
class CEntityPointer
{
public:
  CEntityPointer(CEntityPointer_* p, bool owner = false);
  CEntityPointer();
  CEntityPointer(const CEntityPointer& o);
  CEntityPointer(CEntity_* o);
  ~CEntityPointer();
  CEntityPointer& operator=(const CEntityPointer& o);
  CEntityPointer& operator=(CEntity_* o);
  bool operator==(const CEntityPointer& o) const;
  bool operator==(const CEntity_* o) const;
  bool operator!=(const CEntityPointer& o) const;
  bool operator!=(const CEntity_* o) const;
  operator bool();
  operator bool() const;

  CEntityPtr ep_pen() const;

  CEntityPtr operator->() const;
  operator CEntityPtr () const;
  CEntity& operator*() const;

  inline CEntityPointer_* C_Handle() { return mp_handle; }
  inline const CEntityPointer_* C_Handle() const { return mp_handle; }
  inline operator CEntityPointer_* () { return C_Handle(); }
  inline operator const CEntityPointer_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CEntityPointer_* mp_handle = nullptr;
  mutable CEntityPtr mp_cache;
};

#include "EntityPointer.inl"
