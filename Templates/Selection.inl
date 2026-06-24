#pragma once

#define IMPL_CSelection(TYPE)\
  inline CSelection_##TYPE::CSelection_##TYPE(CSelection_##TYPE##_* p, bool owner)\
    : CDynamicContainer_##TYPE((CDynamicContainer_##TYPE##_*)p, owner)\
  {\
  }\
  inline CSelection_##TYPE::CSelection_##TYPE()\
    : CSelection_##TYPE(CSelection_##TYPE##_new(), true)\
  {\
  }\
  inline CSelection_##TYPE::~CSelection_##TYPE()\
  {\
    if (m_owner)\
      CSelection_##TYPE##_delete(C_Handle());\
    m_owner = false;\
    mp_array = nullptr;\
  }\
  inline void CSelection_##TYPE::Clear()\
  {\
    CSelection_##TYPE##_Clear(C_Handle());\
  }\
  inline void CSelection_##TYPE::Select(TYPE##_* tToSelect)\
  {\
    CSelection_##TYPE##_Select(C_Handle(), tToSelect);\
  }\
  inline void CSelection_##TYPE::Deselect(TYPE##_* tToDeselect)\
  {\
    CSelection_##TYPE##_Deselect(C_Handle(), tToDeselect);\
  }\
  inline BOOL CSelection_##TYPE::IsSelected(TYPE##_* tToSelect)\
  {\
    return CSelection_##TYPE##_IsSelected(C_Handle(), tToSelect);\
  }\
  __forceinline TYPE##Ptr CSelection_##TYPE::GetFirstInSelection()\
  {\
    return CSelection_##TYPE##_GetFirstInSelection(C_Handle());\
  }
