#pragma once
#include "../Base/Types.h"
#include "../Math/Vector.h"
#include "../Graphics/Texture.h"
#include <SeriousEngineCAPI/Templates/StaticArray.h>

#define DECLARE_CStaticArray(TYPE)\
  class CStaticArray_##TYPE\
  {\
    public:\
      CStaticArray_##TYPE(CStaticArray_##TYPE##_* p, bool owner = false);\
      CStaticArray_##TYPE();\
      CStaticArray_##TYPE(CStaticArray_##TYPE& o);\
      ~CStaticArray_##TYPE();\
      \
      CStaticArray_##TYPE& operator=(CStaticArray_##TYPE& o);\
      \
      /* Create a given number of objects. */\
      void New(INDEX iCount);\
      /* Expand stack size but keep old objects. */\
      void Expand(INDEX iNewCount);\
      /* Destroy all objects. */\
      void Delete();\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      \
      /* Random access operator. */\
      TYPE##Ptr operator[](INDEX iObject);\
      const TYPE##Ptr operator[](INDEX iObject) const;\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      /* Get index of a object from it's pointer. */\
      INDEX Index(TYPE##_* ptObject);\
      \
      /* Copy all elements of another array into this one. */\
      void CopyArray(const CStaticArray_##TYPE& arOriginal);\
      /* Move all elements of another array into this one. */\
      void MoveArray(CStaticArray_##TYPE& arOther);\
      \
      inline CStaticArray_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CStaticArray_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CStaticArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CStaticArray_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CStaticArray_##TYPE##_* mp_array = nullptr;\
  };\
  class CStaticArrayIterator_##TYPE {\
  private:\
    INDEX sai_Index;\
    CStaticArray_##TYPE& sai_Array;\
    TYPE##Ptr p_cur;\
  public:\
    inline CStaticArrayIterator_##TYPE(CStaticArray_##TYPE& sa) : sai_Array(sa) { sai_Index = 0; p_cur = sai_Array[sai_Index]; }\
    inline ~CStaticArrayIterator_##TYPE() { sai_Index = -1; p_cur.Reset(); }\
    inline void MoveToNext() { sai_Index++; p_cur = sai_Array[sai_Index]; }\
    inline BOOL IsPastEnd() { return sai_Index>=sai_Array.Count(); }\
    inline TYPE##Ptr Current() { return p_cur; }\
    inline TYPE##Ptr operator*() { return p_cur; }\
    inline operator TYPE##Ptr () { return p_cur; }\
    inline TYPE##Ptr operator->(void) { return p_cur; }\
  };

DECLARE_CStaticArray(PIX2D)
DECLARE_CStaticArray(FLOAT2D)
DECLARE_CStaticArray(FLOAT3D)
DECLARE_CStaticArray(DOUBLE3D)

#define DECLARE_CStaticArray_simple(TYPE)\
  class CStaticArray_##TYPE\
  {\
    public:\
      CStaticArray_##TYPE(CStaticArray_##TYPE##_* p, bool owner = false);\
      CStaticArray_##TYPE();\
      CStaticArray_##TYPE(CStaticArray_##TYPE& o);\
      ~CStaticArray_##TYPE();\
      \
      CStaticArray_##TYPE& operator=(CStaticArray_##TYPE& o);\
      \
      /* Create a given number of objects. */\
      void New(INDEX iCount);\
      /* Expand stack size but keep old objects. */\
      void Expand(INDEX iNewCount);\
      /* Destroy all objects. */\
      void Delete();\
      /* Destroy all objects, and reset the array to initial (empty) state. */\
      void Clear();\
      \
      /* Random access operator. */\
      TYPE& operator[](INDEX iObject);\
      const TYPE& operator[](INDEX iObject) const;\
      /* Get number of objects in array. */\
      INDEX Count() const;\
      /* Get index of a object from it's pointer. */\
      INDEX Index(TYPE* ptObject);\
      \
      /* Copy all elements of another array into this one. */\
      void CopyArray(const CStaticArray_##TYPE& arOriginal);\
      /* Move all elements of another array into this one. */\
      void MoveArray(CStaticArray_##TYPE& arOther);\
      \
      inline CStaticArray_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CStaticArray_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CStaticArray_##TYPE##_* () { return C_Handle(); }\
      inline operator const CStaticArray_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CStaticArray_##TYPE##_* mp_array = nullptr;\
  };\
  class CStaticArrayIterator_##TYPE {\
  private:\
    INDEX sai_Index;\
    CStaticArray_##TYPE& sai_Array;\
  public:\
    inline CStaticArrayIterator_##TYPE(CStaticArray_##TYPE& sa) : sai_Array(sa) { sai_Index = 0; }\
    inline ~CStaticArrayIterator_##TYPE() { sai_Index = -1; }\
    inline void MoveToNext() { sai_Index++; }\
    inline BOOL IsPastEnd() { return sai_Index>=sai_Array.Count(); }\
    inline TYPE& Current() { return sai_Array[sai_Index]; }\
    inline TYPE& operator*() { return sai_Array[sai_Index]; }\
    inline operator TYPE* () { return &sai_Array[sai_Index]; }\
    inline TYPE* operator->(void) { return &sai_Array[sai_Index]; }\
  };

#define FOREACHINSTATICARRAY(array, type, iter) \
  for(CStaticArrayIterator_##type iter(array); !iter.IsPastEnd(); iter.MoveToNext() )

DECLARE_CStaticArray_simple(UWORD)
DECLARE_CStaticArray_simple(ULONG)
DECLARE_CStaticArray_simple(SLONG)
DECLARE_CStaticArray_simple(INDEX)

#include "StaticArray.inl"
