#pragma once
#include "StaticStackArray.h"
#include <SeriousEngineCAPI/Templates/DynamicContainer.h>

#define DECLARE_CDynamicContainer(TYPE)\
  class CDynamicContainer_##TYPE\
  {\
    public:\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner = false);\
      CDynamicContainer_##TYPE();\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o);\
      ~CDynamicContainer_##TYPE();\
      \
      CDynamicContainer_##TYPE& operator=(CDynamicContainer_##TYPE& o);\
      \
      /* Get index of an object from it's pointer. */\
      INDEX GetIndex(TYPE##_* ptMember);\
      /* Add a given object to container. */\
      void Add(TYPE##_* ptNewObject);\
      /* Remove a given object from container. */\
      void Remove(TYPE##_* ptOldObject);\
      /* Remove all objects, and reset the container to initial (empty) state. */\
      void Clear();\
      /* Test if a given object is in the container. */\
      BOOL IsMember(TYPE##_* ptOldObject);\
      \
      /* Get pointer to a object from it's index. */\
      TYPE##Ptr Pointer(INDEX iObject);\
      const TYPE##Ptr Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE##Ptr operator[](INDEX iObject);\
      const TYPE##Ptr operator[](INDEX iObject) const;\
      /* Move all elements of another container into this one. */\
      void MoveContainer(CDynamicContainer_##TYPE& coOther);\
      \
      /* Get first object in container (there must be at least one when calling this). */\
      TYPE##Ptr GetFirst();\
      \
      inline CDynamicContainer_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicContainer_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicContainer_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicContainer_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicContainer_##TYPE##_* mp_array = nullptr;\
  };

DECLARE_CDynamicContainer(CTextureData)

#define DECLARE_CDynamicContainer_simple(TYPE)\
  class CDynamicContainer_##TYPE\
  {\
    public:\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE##_* p, bool owner = false);\
      CDynamicContainer_##TYPE();\
      CDynamicContainer_##TYPE(CDynamicContainer_##TYPE& o);\
      ~CDynamicContainer_##TYPE();\
      \
      CDynamicContainer_##TYPE& operator=(CDynamicContainer_##TYPE& o);\
      \
      /* Get index of an object from it's pointer. */\
      INDEX GetIndex(TYPE* ptMember);\
      /* Add a given object to container. */\
      void Add(TYPE* ptNewObject);\
      /* Remove a given object from container. */\
      void Remove(TYPE* ptOldObject);\
      /* Remove all objects, and reset the container to initial (empty) state. */\
      void Clear();\
      /* Test if a given object is in the container. */\
      BOOL IsMember(TYPE* ptOldObject);\
      \
      /* Get pointer to a object from it's index. */\
      TYPE* Pointer(INDEX iObject);\
      const TYPE* Pointer(INDEX iObject) const;\
      /* Random access operator. */\
      TYPE& operator[](INDEX iObject);\
      const TYPE& operator[](INDEX iObject) const;\
      /* Move all elements of another container into this one. */\
      void MoveContainer(CDynamicContainer_##TYPE& coOther);\
      \
      /* Get first object in container (there must be at least one when calling this). */\
      TYPE& GetFirst();\
      \
      inline CDynamicContainer_##TYPE##_* C_Handle() { return mp_array; }\
      inline const CDynamicContainer_##TYPE##_* C_Handle() const { return mp_array; }\
      inline operator CDynamicContainer_##TYPE##_* () { return C_Handle(); }\
      inline operator const CDynamicContainer_##TYPE##_* () const { return C_Handle(); }\
    protected:\
      bool m_owner = true;\
      CDynamicContainer_##TYPE##_* mp_array = nullptr;\
  };

#include "DynamicContainer.inl"
