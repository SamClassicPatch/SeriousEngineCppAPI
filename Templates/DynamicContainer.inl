#pragma once

#define IMPL_CDynamicContainer(TYPE)\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner)\
    : CStaticStackArray_##TYPE((CStaticStackArray_##TYPE##_*)p, owner)\
  {\
  }\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE()\
    : CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_new(), true)\
  {\
  }\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o)\
    : CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_clone(o), true)\
  {\
  }\
  inline CDynamicContainer_##TYPE::~CDynamicContainer_##TYPE()\
  {\
    if (m_owner)\
      CDynamicContainer_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  inline CDynamicContainer_##TYPE& CDynamicContainer_##TYPE::operator=(CDynamicContainer_##TYPE& o)\
  {\
    CDynamicContainer_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  inline INDEX CDynamicContainer_##TYPE::GetIndex(TYPE##_* ptMember)\
  {\
    return CDynamicContainer_##TYPE##_GetIndex(C_Handle(), ptMember);\
  }\
  inline void CDynamicContainer_##TYPE::Add(TYPE##_* ptNewObject)\
  {\
    CDynamicContainer_##TYPE##_Add(C_Handle(), ptNewObject);\
  }\
  inline void CDynamicContainer_##TYPE::Remove(TYPE##_* ptOldObject)\
  {\
    CDynamicContainer_##TYPE##_Remove(C_Handle(), ptOldObject);\
  }\
  inline void CDynamicContainer_##TYPE::Clear()\
  {\
    CDynamicContainer_##TYPE##_Clear(C_Handle());\
  }\
  inline BOOL CDynamicContainer_##TYPE::IsMember(TYPE##_* ptOldObject)\
  {\
    return CDynamicContainer_##TYPE##_IsMember(C_Handle(), ptOldObject);\
  }\
  __forceinline TYPE##Ptr CDynamicContainer_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicContainer_##TYPE##_Element(C_Handle(), iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicContainer_##TYPE::Pointer(INDEX iObject) const\
  {\
    return (TYPE##_*)(CDynamicContainer_##TYPE##_Element_const(C_Handle(), iObject));\
  }\
  __forceinline TYPE##Ptr CDynamicContainer_##TYPE::operator[](INDEX iObject)\
  {\
    return CDynamicContainer_##TYPE##_Element(C_Handle(), iObject);\
  }\
  __forceinline const TYPE##Ptr CDynamicContainer_##TYPE::operator[](INDEX iObject) const\
  {\
    return (TYPE##_*)(CDynamicContainer_##TYPE##_Element_const(C_Handle(), iObject));\
  }\
  inline void CDynamicContainer_##TYPE::MoveContainer(CDynamicContainer_##TYPE& coOther)\
  {\
    CDynamicContainer_##TYPE##_MoveContainer(C_Handle(), coOther);\
  }\
  __forceinline TYPE##Ptr CDynamicContainer_##TYPE::GetFirst()\
  {\
    return CDynamicContainer_##TYPE##_GetFirst(C_Handle());\
  }

IMPL_CDynamicContainer(CTextureData)

#define IMPL_CDynamicContainer_simple(TYPE)\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner)\
    : CStaticStackArray_##TYPE((CStaticStackArray_##TYPE##_*)p, owner)\
  {\
  }\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE()\
    : CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_new(), true)\
  {\
  }\
  inline CDynamicContainer_##TYPE::CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o)\
    : CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_clone(o), true)\
  {\
  }\
  inline CDynamicContainer_##TYPE::~CDynamicContainer_##TYPE()\
  {\
    if (m_owner)\
      CDynamicContainer_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  inline CDynamicContainer_##TYPE& CDynamicContainer_##TYPE::operator=(CDynamicContainer_##TYPE& o)\
  {\
    CDynamicContainer_##TYPE##_copy(C_Handle(), o);\
    return *this;\
  }\
  inline INDEX CDynamicContainer_##TYPE::GetIndex(TYPE* ptMember)\
  {\
    return CDynamicContainer_##TYPE##_GetIndex(C_Handle(), ptMember);\
  }\
  inline void CDynamicContainer_##TYPE::Add(TYPE* ptNewObject)\
  {\
    CDynamicContainer_##TYPE##_Add(C_Handle(), ptNewObject);\
  }\
  inline void CDynamicContainer_##TYPE::Remove(TYPE* ptOldObject)\
  {\
    CDynamicContainer_##TYPE##_Remove(C_Handle(), ptOldObject);\
  }\
  inline void CDynamicContainer_##TYPE::Clear()\
  {\
    CDynamicContainer_##TYPE##_Clear(C_Handle());\
  }\
  inline BOOL CDynamicContainer_##TYPE::IsMember(TYPE* ptOldObject)\
  {\
    return CDynamicContainer_##TYPE##_IsMember(C_Handle(), ptOldObject);\
  }\
  inline TYPE* CDynamicContainer_##TYPE::Pointer(INDEX iObject)\
  {\
    return CDynamicContainer_##TYPE##_Element(C_Handle(), iObject);\
  }\
  inline const TYPE* CDynamicContainer_##TYPE::Pointer(INDEX iObject) const\
  {\
    return CDynamicContainer_##TYPE##_Element_const(C_Handle(), iObject);\
  }\
  inline TYPE& CDynamicContainer_##TYPE::operator[](INDEX iObject)\
  {\
    return *CDynamicContainer_##TYPE##_Element(C_Handle(), iObject);\
  }\
  inline const TYPE& CDynamicContainer_##TYPE::operator[](INDEX iObject) const\
  {\
    return *CDynamicContainer_##TYPE##_Element_const(C_Handle(), iObject);\
  }\
  inline void CDynamicContainer_##TYPE::MoveContainer(CDynamicContainer_##TYPE& coOther)\
  {\
    CDynamicContainer_##TYPE##_MoveContainer(C_Handle(), coOther);\
  }\
  inline TYPE& CDynamicContainer_##TYPE::GetFirst()\
  {\
    return *CDynamicContainer_##TYPE##_GetFirst(C_Handle());\
  }
