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

#define IMPL_CDynamicArray(TYPE)\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner)\
    : m_owner(owner)\
    , mp_array(p)\
  {\
  }\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE()\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_new())\
  {\
  }\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE& o)\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_clone(o))\
  {\
  }\
  inline CDynamicArray_##TYPE::~CDynamicArray_##TYPE()\
  {\
    if (m_owner)\
      CDynamicArray_##TYPE##_delete(mp_array);\
  }\
  inline CDynamicArray_##TYPE& CDynamicArray_##TYPE::operator=(CDynamicArray_##TYPE& o)\
  {\
    CDynamicArray_##TYPE##_copy(mp_array, o);\
    return *this;\
  }\
  inline void CDynamicArray_##TYPE::GrowPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_GrowPointers(mp_array, count);\
  }\
  inline void CDynamicArray_##TYPE::ShrinkPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_ShrinkPointers(mp_array, count);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::AllocBlock(INDEX count)\
  {\
    return CDynamicArray_##TYPE##_AllocBlock(mp_array, count);\
  }\
  inline INDEX CDynamicArray_##TYPE::GetIndex(TYPE##_* element)\
  {\
    return CDynamicArray_##TYPE##_GetIndex(mp_array, element);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::New(INDEX iCount)\
  {\
    return CDynamicArray_##TYPE##_New(mp_array, iCount);\
  }\
  inline void CDynamicArray_##TYPE::Delete(TYPE##_* ptObject)\
  {\
    CDynamicArray_##TYPE##_Delete(mp_array, ptObject);\
  }\
  inline void CDynamicArray_##TYPE::Clear()\
  {\
    CDynamicArray_##TYPE##_Clear(mp_array);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicArray_##TYPE::Pointer(INDEX iObject) const\
  {\
    return (TYPE##_*)CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::operator[](INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return (TYPE##_*)CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline void CDynamicArray_##TYPE::MoveArray(CDynamicArray_##TYPE& arOther)\
  {\
    CDynamicArray_##TYPE##_MoveArray(mp_array, arOther);\
  }\
  inline INDEX CDynamicArray_##TYPE::Count() const\
  {\
    return CDynamicArray_##TYPE##_Count(mp_array);\
  }

#define IMPL_CDynamicArrayNoClear(TYPE)\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool)\
    : mp_array(p)\
  {\
  }\
  inline CDynamicArray_##TYPE::~CDynamicArray_##TYPE()\
  {\
  }\
  inline void CDynamicArray_##TYPE::GrowPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_GrowPointers(mp_array, count);\
  }\
  inline void CDynamicArray_##TYPE::ShrinkPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_ShrinkPointers(mp_array, count);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::AllocBlock(INDEX count)\
  {\
    return CDynamicArray_##TYPE##_AllocBlock(mp_array, count);\
  }\
  inline INDEX CDynamicArray_##TYPE::GetIndex(TYPE##_* element)\
  {\
    return CDynamicArray_##TYPE##_GetIndex(mp_array, element);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::New(INDEX iCount)\
  {\
    return CDynamicArray_##TYPE##_New(mp_array, iCount);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicArray_##TYPE::Pointer(INDEX iObject) const\
  {\
    return (TYPE##_*)CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  __forceinline TYPE##Ptr CDynamicArray_##TYPE::operator[](INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return (TYPE##_*)CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline void CDynamicArray_##TYPE::MoveArray(CDynamicArray_##TYPE& arOther)\
  {\
    CDynamicArray_##TYPE##_MoveArray(mp_array, arOther);\
  }\
  inline INDEX CDynamicArray_##TYPE::Count() const\
  {\
    return CDynamicArray_##TYPE##_Count(mp_array);\
  }

IMPL_CDynamicArray(CTString)
IMPL_CDynamicArray(CTFileName)
IMPL_CDynamicArray(CTranslationPair)

#define IMPL_CDynamicArray_simple(TYPE)\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner)\
    : m_owner(owner)\
    , mp_array(p)\
  {\
  }\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE()\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_new())\
  {\
  }\
  inline CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE& o)\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_clone(o))\
  {\
  }\
  inline CDynamicArray_##TYPE::~CDynamicArray_##TYPE()\
  {\
    if (m_owner)\
      CDynamicArray_##TYPE##_delete(mp_array);\
  }\
  inline CDynamicArray_##TYPE& CDynamicArray_##TYPE::operator=(CDynamicArray_##TYPE& o)\
  {\
    CDynamicArray_##TYPE##_copy(mp_array, o);\
    return *this;\
  }\
  inline void CDynamicArray_##TYPE::GrowPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_GrowPointers(mp_array, count);\
  }\
  inline void CDynamicArray_##TYPE::ShrinkPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_ShrinkPointers(mp_array, count);\
  }\
  inline TYPE* CDynamicArray_##TYPE::AllocBlock(INDEX count)\
  {\
    return CDynamicArray_##TYPE##_AllocBlock(mp_array, count);\
  }\
  inline INDEX CDynamicArray_##TYPE::GetIndex(TYPE* element)\
  {\
    return CDynamicArray_##TYPE##_GetIndex(mp_array, element);\
  }\
  inline TYPE* CDynamicArray_##TYPE::New(INDEX iCount)\
  {\
    return CDynamicArray_##TYPE##_New(mp_array, iCount);\
  }\
  inline void CDynamicArray_##TYPE::Delete(TYPE* ptObject)\
  {\
    CDynamicArray_##TYPE##_Delete(mp_array, ptObject);\
  }\
  inline void CDynamicArray_##TYPE::Clear()\
  {\
    CDynamicArray_##TYPE##_Clear(mp_array);\
  }\
  inline TYPE* CDynamicArray_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  inline const TYPE* CDynamicArray_##TYPE::Pointer(INDEX iObject) const\
  {\
    return CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline TYPE& CDynamicArray_##TYPE::operator[](INDEX iObject)\
  {\
    return *CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  inline const TYPE& CDynamicArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return *CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline void CDynamicArray_##TYPE::MoveArray(CDynamicArray_##TYPE& arOther)\
  {\
    CDynamicArray_##TYPE##_MoveArray(mp_array, arOther);\
  }\
  inline INDEX CDynamicArray_##TYPE::Count() const\
  {\
    return CDynamicArray_##TYPE##_Count(mp_array);\
  }

IMPL_CDynamicArray_simple(FLOAT)
