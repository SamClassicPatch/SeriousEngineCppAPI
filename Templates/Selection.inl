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
