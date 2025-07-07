#pragma once
#include "../Base/Types.h"
#include "DynamicArray.h"
#include <SeriousEngineCAPI/Templates/DynamicStackArray.h>

#define DECLARE_CDynamicStackArray(TYPE)\
  class CDynamicStackArray_##TYPE : public CDynamicArray_##TYPE\
  {\
    public:\
      CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_* p, bool owner = false);\
      CDynamicStackArray_##TYPE();\
      CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE& o);\
      ~CDynamicStackArray_##TYPE();\
      \
      CDynamicStackArray_##TYPE& operator=(CDynamicStackArray_##TYPE& o);\
      \
      /* Set how many elements to allocate when stack overflows. */\
      void SetAllocationStep(INDEX ctStep);\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Add new object on top of stack. */\
      TYPE Push();\
      TYPE##_* Push(INDEX ct);\
      /* Remove all objects from stack, but keep stack space. */\
      void PopAll();\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      \
      inline CDynamicStackArray_##TYPE##_* C_Handle() { return (CDynamicStackArray_##TYPE##_*)mp_array; }\
      inline const CDynamicStackArray_##TYPE##_* C_Handle() const { return (const CDynamicStackArray_##TYPE##_*)mp_array; }\
      inline operator CDynamicStackArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicStackArray_##TYPE##_* () const { return C_Handle(); }\
  };

DECLARE_CDynamicStackArray(CTString)
DECLARE_CDynamicStackArray(CTFileName)

#define DECLARE_CDynamicStackArray_simple(TYPE)\
  class CDynamicStackArray_##TYPE : public CDynamicArray_##TYPE\
  {\
    public:\
      CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE##_* p, bool owner = false);\
      CDynamicStackArray_##TYPE();\
      CDynamicStackArray_##TYPE(CDynamicStackArray_##TYPE& o);\
      ~CDynamicStackArray_##TYPE();\
      \
      CDynamicStackArray_##TYPE& operator=(CDynamicStackArray_##TYPE& o);\
      \
      /* Set how many elements to allocate when stack overflows. */\
      void SetAllocationStep(INDEX ctStep);\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Add new object on top of stack. */\
      TYPE& Push();\
      TYPE* Push(INDEX ct);\
      /* Remove all objects from stack, but keep stack space. */\
      void PopAll();\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      \
      inline CDynamicStackArray_##TYPE##_* C_Handle() { return (CDynamicStackArray_##TYPE##_*)mp_array; }\
      inline const CDynamicStackArray_##TYPE##_* C_Handle() const { return (const CDynamicStackArray_##TYPE##_*)mp_array; }\
      inline operator CDynamicStackArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicStackArray_##TYPE##_* () const { return C_Handle(); }\
  };

DECLARE_CDynamicStackArray_simple(FLOAT)

#include "DynamicStackArray.inl"
