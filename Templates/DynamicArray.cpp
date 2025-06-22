#include "DynamicArray.h"
#include "../Base/FileName.h"
#include "../Base/TranslationPair.h"
#include <SeriousEngineCAPI/Templates/DynamicArray.h>

#define IMPL_CDynamicArray(TYPE)\
  CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner)\
    : m_owner(owner)\
    , mp_array(p)\
  {\
  }\
  CDynamicArray_##TYPE::CDynamicArray_##TYPE()\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_new())\
  {\
  }\
  CDynamicArray_##TYPE::CDynamicArray_##TYPE(CDynamicArray_##TYPE& o)\
    : m_owner(true)\
    , mp_array(CDynamicArray_##TYPE##_clone(o))\
  {\
  }\
  CDynamicArray_##TYPE::~CDynamicArray_##TYPE()\
  {\
    if (m_owner)\
      CDynamicArray_##TYPE##_delete(mp_array);\
  }\
  CDynamicArray_##TYPE& CDynamicArray_##TYPE::operator=(CDynamicArray_##TYPE& o)\
  {\
    CDynamicArray_##TYPE##_copy(mp_array, o);\
    return *this;\
  }\
  void CDynamicArray_##TYPE::GrowPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_GrowPointers(mp_array, count);\
  }\
  void CDynamicArray_##TYPE::ShrinkPointers(INDEX count)\
  {\
    CDynamicArray_##TYPE##_ShrinkPointers(mp_array, count);\
  }\
  TYPE##_* CDynamicArray_##TYPE::AllocBlock(INDEX count)\
  {\
    return CDynamicArray_##TYPE##_AllocBlock(mp_array, count);\
  }\
  INDEX CDynamicArray_##TYPE::GetIndex(TYPE##_* element)\
  {\
    return CDynamicArray_##TYPE##_GetIndex(mp_array, element);\
  }\
  TYPE##_* CDynamicArray_##TYPE::New(INDEX iCount)\
  {\
    return CDynamicArray_##TYPE##_New(mp_array, iCount);\
  }\
  void CDynamicArray_##TYPE::Delete(TYPE##_* ptObject)\
  {\
    CDynamicArray_##TYPE##_Delete(mp_array, ptObject);\
  }\
  void CDynamicArray_##TYPE::Clear()\
  {\
    CDynamicArray_##TYPE##_Clear(mp_array);\
  }\
  TYPE##_* CDynamicArray_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  const TYPE##_* CDynamicArray_##TYPE::Pointer(INDEX iObject) const\
  {\
    return CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  TYPE##_* CDynamicArray_##TYPE::operator[](INDEX iObject)\
  {\
    return CDynamicArray_##TYPE##_Element(mp_array, iObject);\
  }\
  const TYPE##_* CDynamicArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return CDynamicArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  void CDynamicArray_##TYPE::MoveArray(CDynamicArray_##TYPE& arOther)\
  {\
    CDynamicArray_##TYPE##_MoveArray(mp_array, arOther);\
  }\
  INDEX CDynamicArray_##TYPE::Count() const\
  {\
    return CDynamicArray_##TYPE##_Count(mp_array);\
  }

IMPL_CDynamicArray(CTFileName)
IMPL_CDynamicArray(CTranslationPair)
