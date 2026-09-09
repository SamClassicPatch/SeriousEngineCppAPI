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
#include <SeriousEngineCAPI/Entities/EntityProperties.h>

class CEntityPropertyEnumValue
{
public:
  CEntityPropertyEnumValue(CEntityPropertyEnumValue_* p, bool dummy = false);
  ~CEntityPropertyEnumValue();
  CEntityPropertyEnumValue(const CEntityPropertyEnumValue& ln) = delete;
  CEntityPropertyEnumValue& operator=(const CEntityPropertyEnumValue& ln) = delete;

  inline CEntityPropertyEnumValue_* C_Handle() { return mp_handle; }
  inline const CEntityPropertyEnumValue_* C_Handle() const { return mp_handle; }
  inline operator CEntityPropertyEnumValue_* () { return C_Handle(); }
  inline operator const CEntityPropertyEnumValue_* () const { return C_Handle(); }
private:
  CEntityPropertyEnumValue_* mp_handle = nullptr;

public:
  INDEX& epev_iValue;      // value
  char*& epev_strName;     // descriptive name of the enum value (for editor)
};

class CEntityPropertyEnumType
{
public:
  CEntityPropertyEnumType(CEntityPropertyEnumType_* p, bool dummy = false);
  ~CEntityPropertyEnumType();
  CEntityPropertyEnumType(const CEntityPropertyEnumType& ln) = delete;
  CEntityPropertyEnumType& operator=(const CEntityPropertyEnumType& ln) = delete;

  CEntityPropertyEnumValue epet_aepevValues(INDEX i);

  inline CEntityPropertyEnumType_* C_Handle() { return mp_handle; }
  inline const CEntityPropertyEnumType_* C_Handle() const { return mp_handle; }
  inline operator CEntityPropertyEnumType_* () { return C_Handle(); }
  inline operator const CEntityPropertyEnumType_* () const { return C_Handle(); }
private:
  CEntityPropertyEnumType_* mp_handle = nullptr;

public:
  INDEX& epet_ctValues; // number of values
};

// types that are used only for properties.
// range, edited visually as sphere around entity
using RANGE = FLOAT;
// type of illumination (for lights that illuminate through polygons)
using ILLUMINATIONTYPE = INDEX;
// type of light animation
using ANIMATION = INDEX;
// CTString browsed like a file - doesn't cause dependencies
using CTFileNameNoDep = CTString;
// CTString that gets translated to different languages
using CTStringTrans = CTString;

class CEntityProperty
{
public:
  CEntityProperty(CEntityProperty_* p, bool dummy = false);
  ~CEntityProperty();
  CEntityProperty(const CEntityProperty& ln) = delete;
  CEntityProperty& operator=(const CEntityProperty& ln) = delete;

  enum PropertyType : PropertyType_ {
    EPT_PARENT = EPT_PARENT_,                     // used internaly in WED for setting entity's parents
    EPT_SPAWNFLAGS = EPT_SPAWNFLAGS_,             // used internaly in WED for spawn flags property
    EPT_ENUM = EPT_ENUM_,                         // enum xxx, INDEX with descriptions
    EPT_BOOL = EPT_BOOL_,                         // BOOL
    EPT_FLOAT = EPT_FLOAT_,                       // FLOAT
    EPT_COLOR = EPT_COLOR_,                       // COLOR
    EPT_STRING = EPT_STRING_,                     // CTString
    EPT_RANGE = EPT_RANGE_,                       // RANGE FLOAT edited as a sphere around the entity
    EPT_ENTITYPTR = EPT_ENTITYPTR_,               // CEntityPointer
    EPT_FILENAME = EPT_FILENAME_,                 // CTFileName
    EPT_INDEX = EPT_INDEX_,                       // INDEX
    EPT_ANIMATION = EPT_ANIMATION_,               // ANIMATION, INDEX edited by animation names
    EPT_ILLUMINATIONTYPE = EPT_ILLUMINATIONTYPE_, // ILLUMINATIONTYPE, INDEX edited by illumination names
    EPT_FLOATAABBOX3D = EPT_FLOATAABBOX3D_,       // FLOATaabbox3D
    EPT_ANGLE = EPT_ANGLE_,                       // ANGLE, INDEX edited in degrees
    EPT_FLOAT3D = EPT_FLOAT3D_,                   // FLOAT3D
    EPT_ANGLE3D = EPT_ANGLE3D_,                   // ANGLE3D
    EPT_FLOATplane3D = EPT_FLOATplane3D_,         // FLOATplane3D
    EPT_MODELOBJECT = EPT_MODELOBJECT_,           // CModelObject
    EPT_PLACEMENT3D = EPT_PLACEMENT3D_,           // PLACEMENT3D
    EPT_ANIMOBJECT = EPT_ANIMOBJECT_,             // CAnimObject
    EPT_FILENAMENODEP = EPT_FILENAMENODEP_,       // CTString browsed like a file - doesn't cause dependencies
    EPT_SOUNDOBJECT = EPT_SOUNDOBJECT_,           // CSoundObject
    EPT_STRINGTRANS = EPT_STRINGTRANS_,           // CTString that gets translated to different languages
    EPT_FLOATQUAT3D = EPT_FLOATQUAT3D_,           // FLOATquat3D
    EPT_FLOATMATRIX3D = EPT_FLOATMATRIX3D_,       // FLOATmatrix3D
    EPT_FLAGS = EPT_FLAGS_,                       // flags - ULONG bitfield with names for each field
    EPT_MODELINSTANCE = EPT_MODELINSTANCE_,
  };

  inline CEntityProperty_* C_Handle() { return mp_handle; }
  inline const CEntityProperty_* C_Handle() const { return mp_handle; }
  inline operator CEntityProperty_* () { return C_Handle(); }
  inline operator const CEntityProperty_* () const { return C_Handle(); }
private:
  CEntityProperty_* mp_handle = nullptr;

public:
  PropertyType& ep_eptType;                    // type of property
  CEntityPropertyEnumTypePtr ep_pepetEnumType; // if the type is EPT_ENUM or EPT_FLAGS
  SLONG& ep_slOffset;                          // offset of the property in the class
  char*& ep_strName;                           // descriptive name of the property (for editor)
  ULONG& ep_ulFlags;                           // additional flags for the property
  char&  ep_chShortcut;                        // shortcut key for selecting the property in editor (0 for none)
};

// macro for accessing property inside an entity
#define ENTITY_PROPERTY(entity, offset, type) ((type *)(((UBYTE *)(entity.get_handle()))+offset))

/////////////////////////////////////////////////////////////////////
// The class defining an entity class DLL itself

class CDLLEntityClass
{
public:
  CDLLEntityClass(CDLLEntityClass_* p, bool dummy = false);
  ~CDLLEntityClass();
  CDLLEntityClass(const CDLLEntityClass& ln) = delete;
  CDLLEntityClass& operator=(const CDLLEntityClass& ln) = delete;

  /* Get pointer to entity property from its name. */
  CEntityPropertyPtr PropertyForName(const CTString& strPropertyName);

  CEntityPropertyPtr dec_aepProperties(INDEX i);

  // pointer to the base class
  CDLLEntityClassPtr dec_pdecBase();

  inline CDLLEntityClass_* C_Handle() { return mp_handle; }
  inline const CDLLEntityClass_* C_Handle() const { return mp_handle; }
  inline operator CDLLEntityClass_* () { return C_Handle(); }
  inline operator const CDLLEntityClass_* () const { return C_Handle(); }
private:
  CDLLEntityClass_* mp_handle = nullptr;

public:
  INDEX& dec_ctProperties;             // number of properties
  char*& dec_strName;                  // descriptive name of the class
  char*& dec_strIconFileName;          // filename of texture or thumbnail
};

#include "EntityProperties.inl"
