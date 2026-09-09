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
#include "DynamicContainer.h"
#include <SeriousEngineCAPI/Templates/Selection.h>

#define DECLARE_CSelection(TYPE)\
  class CSelection_##TYPE : public CDynamicContainer_##TYPE\
  {\
    public:\
      CSelection_##TYPE(CSelection_##TYPE##_* p, bool owner = false);\
      CSelection_##TYPE();\
      CSelection_##TYPE(CSelection_##TYPE& o) = delete;\
      ~CSelection_##TYPE();\
      \
      CSelection_##TYPE& operator=(CSelection_##TYPE& o) = delete;\
      \
      /* Deselect all objects. */\
      void Clear();\
      /* Select one object. */\
      void Select(TYPE##_* tToSelect);\
      /* Deselect one object. */\
      void Deselect(TYPE##_* tToDeselect);\
      /* Test if one object is selected. */\
      BOOL IsSelected(TYPE##_* tToSelect);\
      /* Get first in selection. NULL if empty selection */\
      TYPE##Ptr GetFirstInSelection();\
      \
      inline CSelection_##TYPE##_* C_Handle() { return (CSelection_##TYPE##_*)mp_array; }\
      inline const CSelection_##TYPE##_* C_Handle() const { return (const CSelection_##TYPE##_*)mp_array; }\
      inline operator CSelection_##TYPE##_* () { return C_Handle(); }\
      inline operator const CSelection_##TYPE##_* () const { return C_Handle(); }\
  };

#include "Selection.inl"
