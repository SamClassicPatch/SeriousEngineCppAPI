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
#include "StaticArray.h"
#include <SeriousEngineCAPI/Templates/StaticStackArray.h>

#define DECLARE_CStaticStackArray(TYPE)\
  class CStaticStackArray_##TYPE : public CStaticArray_##TYPE\
  {\
    public:\
      CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_* p, bool owner = false);\
      CStaticStackArray_##TYPE();\
      CStaticStackArray_##TYPE(CStaticStackArray_##TYPE& o);\
      ~CStaticStackArray_##TYPE();\
      \
      CStaticStackArray_##TYPE& operator=(CStaticStackArray_##TYPE& o);\
      \
      /* Set how many elements to allocate when stack overflows. */\
      void SetAllocationStep(INDEX ctStep);\
      /* Create a given number of objects. */\
      void New(INDEX iCount);\
      /* Destroy all objects. */\
      void Delete();\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Add new object on top of stack. */\
      TYPE##Ptr Push();\
      TYPE##_* Push(INDEX ct);\
      /* Remove one object from top of stack and return it. */\
      TYPE Pop();\
      /* Remove objects with higher than the given index from stack, but keep stack space. */\
      void PopUntil(INDEX iNewTop);\
      /* Remove all objects from stack, but keep stack space. */\
      void PopAll();\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      /* Move all elements of another array into this one. */\
      void MoveArray(CStaticStackArray_##TYPE& arOther);\
      \
      inline CStaticStackArray_##TYPE##_* C_Handle() { return (CStaticStackArray_##TYPE##_*)mp_array; }\
      inline const CStaticStackArray_##TYPE##_* C_Handle() const { return (const CStaticStackArray_##TYPE##_*)mp_array; }\
      inline operator CStaticStackArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CStaticStackArray_##TYPE##_* () const { return C_Handle(); }\
  };

DECLARE_CStaticStackArray(PIX2D)
DECLARE_CStaticStackArray(FLOAT3D)

#define DECLARE_CStaticStackArray_simple(TYPE)\
  class CStaticStackArray_##TYPE : public CStaticArray_##TYPE\
  {\
    public:\
      CStaticStackArray_##TYPE(CStaticStackArray_##TYPE##_* p, bool owner = false);\
      CStaticStackArray_##TYPE();\
      CStaticStackArray_##TYPE(CStaticStackArray_##TYPE& o);\
      ~CStaticStackArray_##TYPE();\
      \
      CStaticStackArray_##TYPE& operator=(CStaticStackArray_##TYPE& o);\
      \
      /* Set how many elements to allocate when stack overflows. */\
      void SetAllocationStep(INDEX ctStep);\
      /* Create a given number of objects. */\
      void New(INDEX iCount);\
      /* Destroy all objects. */\
      void Delete();\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Add new object on top of stack. */\
      TYPE& Push();\
      TYPE* Push(INDEX ct);\
      /* Remove one object from top of stack and return it. */\
      TYPE& Pop();\
      /* Remove objects with higher than the given index from stack, but keep stack space. */\
      void PopUntil(INDEX iNewTop);\
      /* Remove all objects from stack, but keep stack space. */\
      void PopAll();\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      /* Move all elements of another array into this one. */\
      void MoveArray(CStaticStackArray_##TYPE& arOther);\
      \
      inline CStaticStackArray_##TYPE##_* C_Handle() { return (CStaticStackArray_##TYPE##_*)mp_array; }\
      inline const CStaticStackArray_##TYPE##_* C_Handle() const { return (const CStaticStackArray_##TYPE##_*)mp_array; }\
      inline operator CStaticStackArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CStaticStackArray_##TYPE##_* () const { return C_Handle(); }\
  };

DECLARE_CStaticStackArray_simple(INDEX)
DECLARE_CStaticStackArray_simple(SLONG)

#include "StaticStackArray.inl"
