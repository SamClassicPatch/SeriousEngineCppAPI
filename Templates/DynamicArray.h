#pragma once
#include "../Base/Types.h"
#include "../Base/FileName.h"
#include "../Base/TranslationPair.h"
#include <SeriousEngineCAPI/Templates/DynamicArray.h>

#define FOREACHINDYNAMICARRAY(array, type, iter) \
  for(CDynamicArray_##type::TIterType iter(array); !iter.IsPastEnd(); iter.MoveToNext() )

template<typename PtrType, typename ArrType>
class CDynamicArrayIterator {
private:
  INDEX dai_Index = 0;    // index of current element
  ArrType& dai_Array; // reference to array
public:
  /* Constructor for given array. */
  inline CDynamicArrayIterator(ArrType& da) : dai_Array(da) {}
  /* Destructor. */
  inline ~CDynamicArrayIterator() {}

  /* Move to next object. */
  inline void MoveToNext() { ++dai_Index; }
  /* Check if finished. */
  inline BOOL IsPastEnd() { return dai_Index >= dai_Array.Count(); }
  /* Get current element. */
  __forceinline PtrType Current() { return PtrType(dai_Array.Pointer(dai_Index)); }
  __forceinline PtrType operator*() { return PtrType(dai_Array.Pointer(dai_Index)); }
  __forceinline operator PtrType () { return PtrType(dai_Array.Pointer(dai_Index)); }
  __forceinline PtrType operator->() { return PtrType(dai_Array.Pointer(dai_Index)); }
};

#define DECLARE_CDynamicArray(TYPE)\
  class CDynamicArray_##TYPE\
  {\
    public:\
      using TIterType = CDynamicArrayIterator<TPointer<TYPE, TYPE##_>, CDynamicArray_##TYPE>;\
      CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner = false);\
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
      TYPE##Ptr AllocBlock(INDEX count);\
      /* Get index of a object from it's pointer. */\
      INDEX GetIndex(TYPE##_* element);\
      /* Create a given number of new objects. */\
      TYPE##Ptr New(INDEX iCount = 1);\
      /* Destroy a given member. */\
      void Delete(TYPE##_* ptObject);\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Get pointer to a object from it's index. */\
      TYPE##Ptr Pointer(INDEX iObject);\
      const TYPE##Ptr Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE##Ptr operator[](INDEX iObject);\
      const TYPE##Ptr operator[](INDEX iObject) const;\
      /* Move all elements of another array into this one. */\
      void MoveArray(CDynamicArray_##TYPE& arOther);\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      \
      inline CDynamicArray_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicArray_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicArray_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicArray_##TYPE##_* mp_array = nullptr;\
  };

DECLARE_CDynamicArray(CTString)
DECLARE_CDynamicArray(CTFileName)
DECLARE_CDynamicArray(CTranslationPair)

template<typename Type, typename ArrType>
class CDynamicArrayIteratorSimple {
private:
  INDEX dai_Index = 0;    // index of current element
  ArrType& dai_Array; // reference to array
public:
  /* Constructor for given array. */
  inline CDynamicArrayIteratorSimple(ArrType& da) : dai_Array(da) {}
  /* Destructor. */
  inline ~CDynamicArrayIteratorSimple() {}

  /* Move to next object. */
  inline void MoveToNext() { ++dai_Index; }
  /* Check if finished. */
  inline BOOL IsPastEnd() { return dai_Index >= dai_Array.Count(); }
  /* Get current element. */
  inline Type& Current() { return *dai_Array.Pointer(dai_Index); }
  inline Type& operator*() { return *dai_Array.Pointer(dai_Index); }
  inline operator Type* () { return dai_Array.Pointer(dai_Index); }
  inline Type* operator->() { return dai_Array.Pointer(dai_Index); }
};

#define DECLARE_CDynamicArray_simple(TYPE)\
  class CDynamicArray_##TYPE\
  {\
    public:\
      using TIterType = CDynamicArrayIteratorSimple<TYPE, CDynamicArray_##TYPE>;\
      CDynamicArray_##TYPE(CDynamicArray_##TYPE##_* p, bool owner = false);\
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
      TYPE* AllocBlock(INDEX count);\
      /* Get index of a object from it's pointer. */\
      INDEX GetIndex(TYPE* element);\
      /* Create a given number of new objects. */\
      TYPE* New(INDEX iCount = 1);\
      /* Destroy a given member. */\
      void Delete(TYPE* ptObject);\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      /* Get pointer to a object from it's index. */\
      TYPE* Pointer(INDEX iObject);\
      const TYPE* Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE& operator[](INDEX iObject);\
      const TYPE& operator[](INDEX iObject) const;\
      /* Move all elements of another array into this one. */\
      void MoveArray(CDynamicArray_##TYPE& arOther);\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      \
      inline CDynamicArray_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicArray_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicArray_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicArray_##TYPE##_* mp_array = nullptr;\
  };

DECLARE_CDynamicArray_simple(FLOAT)

#include "DynamicArray.inl"
