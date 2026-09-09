/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

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
