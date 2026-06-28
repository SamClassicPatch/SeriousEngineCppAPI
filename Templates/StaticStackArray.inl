#pragma once

#define IMPL_CStaticStackArray(TYPE)\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_* p, bool owner)\
    : CStaticArray_##TYPE((CStaticArray_##TYPE##_*)p, owner)\
  {\
  }\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE()\
    : CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_new(), true)\
  {\
  }\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE(CStaticStackArray_##TYPE& o)\
    : CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_clone(o), true)\
  {\
  }\
  inline CStaticStackArray_##TYPE::~CStaticStackArray_##TYPE()\
  {\
    if (m_owner)\
      CStaticStackArray_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  inline CStaticStackArray_##TYPE& CStaticStackArray_##TYPE::operator=(CStaticStackArray_##TYPE& o)\
  {\
    CStaticStackArray_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  inline void CStaticStackArray_##TYPE::SetAllocationStep(INDEX ctStep)\
  {\
    CStaticStackArray_##TYPE##_SetAllocationStep(C_Handle(), ctStep);\
  }\
  inline void CStaticStackArray_##TYPE::New(INDEX iCount)\
  {\
    CStaticStackArray_##TYPE##_New(C_Handle(), iCount);\
  }\
  inline void CStaticStackArray_##TYPE::Delete()\
  {\
    CStaticStackArray_##TYPE##_Delete(C_Handle());\
  }\
  inline void CStaticStackArray_##TYPE::Clear()\
  {\
    CStaticStackArray_##TYPE##_Clear(C_Handle());\
  }\
  __forceinline TYPE##Ptr CStaticStackArray_##TYPE::Push()\
  {\
    return CStaticStackArray_##TYPE##_Push(C_Handle());\
  }\
  inline TYPE##_* CStaticStackArray_##TYPE::Push(INDEX ct)\
  {\
    return CStaticStackArray_##TYPE##_Push_i(C_Handle(), ct);\
  }\
  __forceinline TYPE CStaticStackArray_##TYPE::Pop()\
  {\
    return TYPE(CStaticStackArray_##TYPE##_Pop(C_Handle()), false);\
  }\
  inline void CStaticStackArray_##TYPE::PopUntil(INDEX iNewTop)\
  {\
    CStaticStackArray_##TYPE##_PopUntil(C_Handle(), iNewTop);\
  }\
  inline void CStaticStackArray_##TYPE::PopAll()\
  {\
    CStaticStackArray_##TYPE##_PopAll(C_Handle());\
  }\
  inline INDEX CStaticStackArray_##TYPE::Count() const\
  {\
    return CStaticStackArray_##TYPE##_Count(C_Handle());\
  }\
  inline void CStaticStackArray_##TYPE::MoveArray(CStaticStackArray_##TYPE& arOther)\
  {\
    CStaticStackArray_##TYPE##_MoveArray(C_Handle(), arOther);\
  }

IMPL_CStaticStackArray(PIX2D)
IMPL_CStaticStackArray(FLOAT3D)

#define IMPL_CStaticStackArray_simple(TYPE)\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_* p, bool owner)\
    : CStaticArray_##TYPE((CStaticArray_##TYPE##_*)p, owner)\
  {\
  }\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE()\
    : CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_new(), true)\
  {\
  }\
  inline CStaticStackArray_##TYPE::CStaticStackArray_##TYPE(CStaticStackArray_##TYPE& o)\
    : CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_clone(o), true)\
  {\
  }\
  inline CStaticStackArray_##TYPE::~CStaticStackArray_##TYPE()\
  {\
    if (m_owner)\
      CStaticStackArray_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  inline CStaticStackArray_##TYPE& CStaticStackArray_##TYPE::operator=(CStaticStackArray_##TYPE& o)\
  {\
    CStaticStackArray_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  inline void CStaticStackArray_##TYPE::SetAllocationStep(INDEX ctStep)\
  {\
    CStaticStackArray_##TYPE##_SetAllocationStep(C_Handle(), ctStep);\
  }\
  inline void CStaticStackArray_##TYPE::New(INDEX iCount)\
  {\
    CStaticStackArray_##TYPE##_New(C_Handle(), iCount);\
  }\
  inline void CStaticStackArray_##TYPE::Delete()\
  {\
    CStaticStackArray_##TYPE##_Delete(C_Handle());\
  }\
  inline void CStaticStackArray_##TYPE::Clear()\
  {\
    CStaticStackArray_##TYPE##_Clear(C_Handle());\
  }\
  inline TYPE& CStaticStackArray_##TYPE::Push()\
  {\
    return *CStaticStackArray_##TYPE##_Push(C_Handle());\
  }\
  inline TYPE* CStaticStackArray_##TYPE::Push(INDEX ct)\
  {\
    return CStaticStackArray_##TYPE##_Push_i(C_Handle(), ct);\
  }\
  inline TYPE& CStaticStackArray_##TYPE::Pop()\
  {\
    return *CStaticStackArray_##TYPE##_Pop(C_Handle());\
  }\
  inline void CStaticStackArray_##TYPE::PopUntil(INDEX iNewTop)\
  {\
    CStaticStackArray_##TYPE##_PopUntil(C_Handle(), iNewTop);\
  }\
  inline void CStaticStackArray_##TYPE::PopAll()\
  {\
    CStaticStackArray_##TYPE##_PopAll(C_Handle());\
  }\
  inline INDEX CStaticStackArray_##TYPE::Count() const\
  {\
    return CStaticStackArray_##TYPE##_Count(C_Handle());\
  }\
  inline void CStaticStackArray_##TYPE::MoveArray(CStaticStackArray_##TYPE& arOther)\
  {\
    CStaticStackArray_##TYPE##_MoveArray(C_Handle(), arOther);\
  }

IMPL_CStaticStackArray_simple(INDEX)
IMPL_CStaticStackArray_simple(SLONG)
