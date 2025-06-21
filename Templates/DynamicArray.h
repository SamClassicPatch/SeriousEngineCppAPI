#pragma once
#include "../Base/Types.h"

#define DECLARE_CDynamicArray(TYPE)\
  class SECPPAPI CDynamicArray_##TYPE\
  {\
    public:\
      explicit CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner = false);\
      CDynamicArray_##TYPE();\
      CDynamicArray_##TYPE(CDynamicArray_##TYPE& o);\
      ~CDynamicArray_##TYPE();\
      \
      CDynamicArray_##TYPE& operator=(CDynamicArray_##TYPE& o);\
      \
      /* Grow pointer array by a given number of indices. */\
      void GrowPointers(INDEX count);\
      /* Shrink pointer array by a given number of indices. */\
      void ShrinkPointers(INDEX count);\
      /* Allocate a new memory block. */\
      TYPE AllocBlock(INDEX count);\
      /* Get index of a object from it's pointer. */\
      INDEX GetIndex(TYPE##_* element);\
      /* Create a given number of new objects. */\
      TYPE New(INDEX iCount = 1);\
      /* Destroy a given member. */\
      void Delete(TYPE##_* ptObject);\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Get pointer to a object from it's index. */\
      TYPE Pointer(INDEX iObject);\
      const TYPE Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE operator[](INDEX iObject);\
      const TYPE operator[](INDEX iObject) const;\
      /* Move all elements of another array into this one. */\
      void MoveArray(CDynamicArray_##TYPE& arOther);\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      \
      inline CDynamicArray_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicArray_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicArray_##TYPE##_* () const { return C_Handle(); }\
    private:\
      bool m_owner = true;\
      CDynamicArray_##TYPE##_* mp_array = nullptr;\
  };

DECLARE_CDynamicArray(CTFileName)
DECLARE_CDynamicArray(CTranslationPair)

#undef DECLARE_CDynamicArray
