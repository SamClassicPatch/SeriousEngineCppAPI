#pragma once

#define IMPL_CStaticArray(TYPE)\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE(CStaticArray_##TYPE##_* p, bool owner)\
    : m_owner(owner)\
    , mp_array(p)\
  {\
  }\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE()\
    : m_owner(true)\
    , mp_array(CStaticArray_##TYPE##_new())\
  {\
  }\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE(CStaticArray_##TYPE& o)\
    : m_owner(true)\
    , mp_array(CStaticArray_##TYPE##_clone(o))\
  {\
  }\
  inline CStaticArray_##TYPE::~CStaticArray_##TYPE()\
  {\
    if (m_owner)\
      CStaticArray_##TYPE##_delete(mp_array);\
  }\
  inline CStaticArray_##TYPE& CStaticArray_##TYPE::operator=(CStaticArray_##TYPE& o)\
  {\
    CStaticArray_##TYPE##_copy(mp_array, o);\
    return *this;\
  }\
  inline void CStaticArray_##TYPE::New(INDEX iCount)\
  {\
    CStaticArray_##TYPE##_New(mp_array, iCount);\
  }\
  inline void CStaticArray_##TYPE::Expand(INDEX iNewCount)\
  {\
    CStaticArray_##TYPE##_Expand(mp_array, iNewCount);\
  }\
  inline void CStaticArray_##TYPE::Delete()\
  {\
    CStaticArray_##TYPE##_Delete(mp_array);\
  }\
  inline void CStaticArray_##TYPE::Clear()\
  {\
    CStaticArray_##TYPE##_Clear(mp_array);\
  }\
  __forceinline TYPE##Ptr CStaticArray_##TYPE::operator[](INDEX iObject)\
  {\
    return CStaticArray_##TYPE##_Element(mp_array, iObject);\
  }\
  __forceinline const TYPE##Ptr CStaticArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return (TYPE##_*)CStaticArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline INDEX CStaticArray_##TYPE::Count() const\
  {\
    return CStaticArray_##TYPE##_Count(mp_array);\
  }\
  inline INDEX CStaticArray_##TYPE::Index(TYPE##_* ptObject)\
  {\
    return CStaticArray_##TYPE##_Index(mp_array, ptObject);\
  }\
  inline void CStaticArray_##TYPE::CopyArray(const CStaticArray_##TYPE& arOriginal)\
  {\
    CStaticArray_##TYPE##_CopyArray(mp_array, arOriginal);\
  }\
  inline void CStaticArray_##TYPE::MoveArray(CStaticArray_##TYPE& arOther)\
  {\
    CStaticArray_##TYPE##_MoveArray(mp_array, arOther);\
  }

IMPL_CStaticArray(PIX2D)
IMPL_CStaticArray(FLOAT2D)
IMPL_CStaticArray(FLOAT3D)

#define IMPL_CStaticArray_simple(TYPE)\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE(CStaticArray_##TYPE##_* p, bool owner)\
    : m_owner(owner)\
    , mp_array(p)\
  {\
  }\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE()\
    : m_owner(true)\
    , mp_array(CStaticArray_##TYPE##_new())\
  {\
  }\
  inline CStaticArray_##TYPE::CStaticArray_##TYPE(CStaticArray_##TYPE& o)\
    : m_owner(true)\
    , mp_array(CStaticArray_##TYPE##_clone(o))\
  {\
  }\
  inline CStaticArray_##TYPE::~CStaticArray_##TYPE()\
  {\
    if (m_owner)\
      CStaticArray_##TYPE##_delete(mp_array);\
  }\
  inline CStaticArray_##TYPE& CStaticArray_##TYPE::operator=(CStaticArray_##TYPE& o)\
  {\
    CStaticArray_##TYPE##_copy(mp_array, o);\
    return *this;\
  }\
  inline void CStaticArray_##TYPE::New(INDEX iCount)\
  {\
    CStaticArray_##TYPE##_New(mp_array, iCount);\
  }\
  inline void CStaticArray_##TYPE::Expand(INDEX iNewCount)\
  {\
    CStaticArray_##TYPE##_Expand(mp_array, iNewCount);\
  }\
  inline void CStaticArray_##TYPE::Delete()\
  {\
    CStaticArray_##TYPE##_Delete(mp_array);\
  }\
  inline void CStaticArray_##TYPE::Clear()\
  {\
    CStaticArray_##TYPE##_Clear(mp_array);\
  }\
  inline TYPE& CStaticArray_##TYPE::operator[](INDEX iObject)\
  {\
    return *CStaticArray_##TYPE##_Element(mp_array, iObject);\
  }\
  inline const TYPE& CStaticArray_##TYPE::operator[](INDEX iObject) const\
  {\
    return *CStaticArray_##TYPE##_Element_const(mp_array, iObject);\
  }\
  inline INDEX CStaticArray_##TYPE::Count() const\
  {\
    return CStaticArray_##TYPE##_Count(mp_array);\
  }\
  inline INDEX CStaticArray_##TYPE::Index(TYPE* ptObject)\
  {\
    return CStaticArray_##TYPE##_Index(mp_array, ptObject);\
  }\
  inline void CStaticArray_##TYPE::CopyArray(const CStaticArray_##TYPE& arOriginal)\
  {\
    CStaticArray_##TYPE##_CopyArray(mp_array, arOriginal);\
  }\
  inline void CStaticArray_##TYPE::MoveArray(CStaticArray_##TYPE& arOther)\
  {\
    CStaticArray_##TYPE##_MoveArray(mp_array, arOther);\
  }

IMPL_CStaticArray_simple(UWORD)
IMPL_CStaticArray_simple(ULONG)
IMPL_CStaticArray_simple(INDEX)
IMPL_CStaticArray_simple(SLONG)
