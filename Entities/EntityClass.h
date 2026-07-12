#pragma once
#include "../Base/Types.h"
#include "../Base/Serial.h"
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
  CEntity_* New();

  /* Get pointer to entity property from its name. */
  CEntityPropertyPtr PropertyForName(const CTString& strPropertyName);

  inline CEntityClass_* C_Handle() { return (CEntityClass_*)CSerial::C_Handle(); }
  inline const CEntityClass_* C_Handle() const { return (const CEntityClass_*)CSerial::C_Handle(); }
  inline operator CEntityClass_* () { return C_Handle(); }
  inline operator const CEntityClass_* () const { return C_Handle(); }

public:
  CDLLEntityClassPtr ec_pdecDLLClass; // pointer to DLL class in the DLL
};

#include "EntityClass.inl"
