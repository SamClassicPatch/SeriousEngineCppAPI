#include "DynamicStackArray.h"
#include <SeriousEngineCAPI/Templates/DynamicStackArray.h>

#define IMPL_CDynamicStackArray(TYPE)\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_* p, bool owner)\
    : CDynamicArray_##TYPE((CDynamicArray_##TYPE##_*)p, owner)\
  {\
  }\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE()\
    : CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_new(), true)\
  {\
  }\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE& o)\
    : CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_clone(o), true)\
  {\
  }\
  CDynamicStackArray_##TYPE::~CDynamicStackArray_##TYPE()\
  {\
    if (m_owner)\
      CDynamicStackArray_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  CDynamicStackArray_##TYPE& CDynamicStackArray_##TYPE::operator=(CDynamicStackArray_##TYPE& o)\
  {\
    CDynamicStackArray_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  void CDynamicStackArray_##TYPE::SetAllocationStep(INDEX ctStep)\
  {\
    CDynamicStackArray_##TYPE##_SetAllocationStep(C_Handle(), ctStep);\
  }\
  void CDynamicStackArray_##TYPE::Clear()\
  {\
    CDynamicStackArray_##TYPE##_Clear(C_Handle());\
  }\
  TYPE##_* CDynamicStackArray_##TYPE::Push()\
  {\
    return CDynamicStackArray_##TYPE##_Push(C_Handle());\
  }\
  TYPE##_* CDynamicStackArray_##TYPE::Push(INDEX ct)\
  {\
    return CDynamicStackArray_##TYPE##_Push_i(C_Handle(), ct);\
  }\
  void CDynamicStackArray_##TYPE::PopAll()\
  {\
    CDynamicStackArray_##TYPE##_PopAll(C_Handle());\
  }\
  INDEX CDynamicStackArray_##TYPE::Count() const\
  {\
    return CDynamicStackArray_##TYPE##_Count(C_Handle());\
  }

IMPL_CDynamicStackArray(CTString)
IMPL_CDynamicStackArray(CTFileName)

#undef IMPL_CDynamicStackArray

#define IMPL_CDynamicStackArray(TYPE)\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_* p, bool owner)\
    : CDynamicArray_##TYPE((CDynamicArray_##TYPE##_*)p, owner)\
  {\
  }\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE()\
    : CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_new(), true)\
  {\
  }\
  CDynamicStackArray_##TYPE::CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE& o)\
    : CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_clone(o), true)\
  {\
  }\
  CDynamicStackArray_##TYPE::~CDynamicStackArray_##TYPE()\
  {\
    if (m_owner)\
      CDynamicStackArray_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  CDynamicStackArray_##TYPE& CDynamicStackArray_##TYPE::operator=(CDynamicStackArray_##TYPE& o)\
  {\
    CDynamicStackArray_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  void CDynamicStackArray_##TYPE::SetAllocationStep(INDEX ctStep)\
  {\
    CDynamicStackArray_##TYPE##_SetAllocationStep(C_Handle(), ctStep);\
  }\
  void CDynamicStackArray_##TYPE::Clear()\
  {\
    CDynamicStackArray_##TYPE##_Clear(C_Handle());\
  }\
  TYPE& CDynamicStackArray_##TYPE::Push()\
  {\
    return *CDynamicStackArray_##TYPE##_Push(C_Handle());\
  }\
  TYPE* CDynamicStackArray_##TYPE::Push(INDEX ct)\
  {\
    return CDynamicStackArray_##TYPE##_Push_i(C_Handle(), ct);\
  }\
  void CDynamicStackArray_##TYPE::PopAll()\
  {\
    CDynamicStackArray_##TYPE##_PopAll(C_Handle());\
  }\
  INDEX CDynamicStackArray_##TYPE::Count() const\
  {\
    return CDynamicStackArray_##TYPE##_Count(C_Handle());\
  }

IMPL_CDynamicStackArray(FLOAT)
