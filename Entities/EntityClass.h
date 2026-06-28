#pragma once
#include "../Base/Types.h"
#include "../Base/Serial.h"
#include "Entity.h"
#include "EntityProperties.h"
#include <SeriousEngineCAPI/Entities/EntityClass.h>

class CEntityClass : public CSerial
{
public:
  CEntityClass(CEntityClass_* p, bool dummy = false);
  ~CEntityClass();
  CEntityClass(const CEntityClass& ln) = delete;
  CEntityClass& operator=(const CEntityClass& ln) = delete;

  /* Construct a new member of the class. */
  CEntityPtr New();

  /* Get pointer to entity property from its name. */
  CEntityPropertyPtr PropertyForName(const CTString& strPropertyName);

  inline CEntityClass_* C_Handle() { return mp_handle; }
  inline const CEntityClass_* C_Handle() const { return mp_handle; }
  inline operator CEntityClass_* () { return C_Handle(); }
  inline operator const CEntityClass_* () const { return C_Handle(); }
private:
  CEntityClass_* mp_handle = nullptr;

public:
  CDLLEntityClassPtr ec_pdecDLLClass; // pointer to DLL class in the DLL
};

#include "EntityClass.inl"
