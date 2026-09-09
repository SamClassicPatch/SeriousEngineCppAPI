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
#include <SeriousEngineCAPI/Base/Lists.h>

inline CListNode::CListNode(CListNode_* p, bool)
  : mp_handle(p)
{
}

inline CListNode::~CListNode()
{
}

inline BOOL CListNode::IsValid() const
{
  return CListNode_IsValid(mp_handle);
}

inline BOOL CListNode::IsLinked() const
{
  return CListNode_IsLinked(mp_handle);
}

inline void CListNode::AddAfter(CListNode& node)
{
  CListNode_AddAfter(mp_handle, node);
}

inline void CListNode::AddAfter(CListNode_* node)
{
  CListNode_AddAfter(mp_handle, node);
}

inline void CListNode::AddBefore(CListNode& node)
{
  CListNode_AddBefore(mp_handle, node);
}

inline void CListNode::AddBefore(CListNode_* node)
{
  CListNode_AddBefore(mp_handle, node);
}

inline void CListNode::Remove()
{
  CListNode_Remove(mp_handle);
}

inline BOOL CListNode::IsHeadMarker() const
{
  return CListNode_IsHeadMarker(mp_handle);
}

inline BOOL CListNode::IsTailMarker() const
{
  return CListNode_IsTailMarker(mp_handle);
}

inline BOOL CListNode::IsHead() const
{
  return CListNode_IsHead(mp_handle);
}

inline BOOL CListNode::IsTail() const
{
  return CListNode_IsTail(mp_handle);
}

inline CListNodePtr CListNode::Succ() const
{
  return CListNode_Succ(mp_handle);
}

inline CListNodePtr CListNode::Pred() const
{
  return CListNode_Pred(mp_handle);
}

inline void CListNode::IterationInsertBefore(CListNode& lnNew)
{
  CListNode_IterationInsertBefore(mp_handle, lnNew);
}

inline void CListNode::IterationInsertAfter(CListNode& lnNew)
{
  CListNode_IterationInsertAfter(mp_handle, lnNew);
}

inline CListHeadPtr CListNode::GetHead()
{
  return CListNode_GetHead(mp_handle);
}

inline CListHead::CListHead(CListHead_* p, bool)
  : mp_handle(p)
{
}

inline CListHead::~CListHead()
{
}

inline BOOL CListHead::IsValid() const
{
  return CListHead_IsValid(mp_handle);
}

inline void CListHead::Clear()
{
  CListHead_Clear(mp_handle);
}

inline CListNodePtr CListHead::Head() const
{
  return CListHead_Head(mp_handle);
}

inline CListNodePtr CListHead::Tail() const
{
  return CListHead_Tail(mp_handle);
}

inline void CListHead::AddHead(CListNode& node)
{
  CListHead_AddHead(mp_handle, node);
}

inline void CListHead::AddHead(CListNode_* node)
{
  CListHead_AddHead(mp_handle, node);
}

inline void CListHead::AddTail(CListNode& node)
{
  CListHead_AddTail(mp_handle, node);
}

inline void CListHead::AddTail(CListNode_* node)
{
  CListHead_AddTail(mp_handle, node);
}

inline void CListHead::RemHead()
{
  CListHead_RemHead(mp_handle);
}

inline void CListHead::RemTail()
{
  CListHead_RemTail(mp_handle);
}

inline void CListHead::RemAll()
{
  CListHead_RemAll(mp_handle);
}

inline BOOL CListHead::IsEmpty() const
{
  return CListHead_IsEmpty(mp_handle);
}

inline void CListHead::MoveList(CListHead& lhOther)
{
  CListHead_MoveList(mp_handle, lhOther);
}

inline void CListHead::MoveList(CListHead_* lhOther)
{
  CListHead_MoveList(mp_handle, lhOther);
}

inline INDEX CListHead::Count() const
{
  return CListHead_Count(mp_handle);
}

inline void CListHead::Sort(INDEX(*pCompare)(const void* p0, const void* p1), int iNodeOffset)
{
  CListHead_Sort(mp_handle, pCompare, iNodeOffset);
}
