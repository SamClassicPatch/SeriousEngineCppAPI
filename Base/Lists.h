#pragma once
#include "Types.h"

/* structures for doubly linked lists */
/* list node */
class CListNode
{
public:
  CListNode(CListNode_* p, bool dummy = false);
  ~CListNode();
  CListNode& operator=(const CListNode& lnOriginal);

  /* Check if list node is valid. */
  BOOL IsValid() const;
  /* Check that this list node is linked in some list. */
  BOOL IsLinked() const;
  /* Add a node after this node. */
  void AddAfter(CListNode& node);
  void AddAfter(CListNode_* node);
  /* Add a node before this node. */
  void AddBefore(CListNode& node);
  void AddBefore(CListNode_* node);
  /* Remove this node from list. */
  void Remove();
  /* Check if this list node is head marker of list. */
  BOOL IsHeadMarker() const;
  /* Check if this list node is tail marker of list. */
  BOOL IsTailMarker() const;
  /* Check if this list node is at the head of list. */
  BOOL IsHead() const;
  /* Check if this list node is at the tail of list. */
  BOOL IsTail() const;
  /* Get successor of this node. */
  CListNodePtr Succ() const;
  /* Get predeccessor of this node. */
  CListNodePtr Pred() const;

  /* Insert a node before current one during iteration. */
  void IterationInsertBefore(CListNode& lnNew);
  /* Insert a node after current one during iteration. */
  void IterationInsertAfter(CListNode& lnNew);

  /* Find the head of the list that this node is in. */
  CListHeadPtr GetHead();

  inline CListNode_* C_Handle() { return mp_handle; }
  inline const CListNode_* C_Handle() const { return mp_handle; }
  inline operator CListNode_* () { return C_Handle(); }
  inline operator const CListNode_* () const { return C_Handle(); }
private:
  CListNode_* mp_handle = nullptr;
};
/* list head */
class CListHead
{
public:
  CListHead(CListHead_* p, bool dummy = false);
  ~CListHead();
  CListHead(const CListHead& lh) = delete;
  void operator=(const CListHead& lh) = delete;

  /* Check if this list head is valid. */
  BOOL IsValid() const;
  /* Clear the list head. */
  void Clear();
  /* Get list head. */
  CListNodePtr Head() const;
  /* Get list tail. */
  CListNodePtr Tail() const;
  /* Add a new element to head of list. */
  void AddHead(CListNode& node);
  void AddHead(CListNode_* node);
  /* Add a new element to tail of list. */
  void AddTail(CListNode& node);
  void AddTail(CListNode_* node);
  /* Remove first element from list. */
  void RemHead();
  /* Remove last element from list. */
  void RemTail();
  /* Remove all elements from list. */
  void RemAll();
  /* Test if list is empty. */
  BOOL IsEmpty() const;
  /* Move all elements of another list into this one. */
  void MoveList(CListHead& lhOther);
  void MoveList(CListHead_* lhOther);
  /* Return the number of elements in list. */
  INDEX Count() const;
  /* Sort the list. */
  void Sort(INDEX (*pCompare)(const void* p0, const void* p1), int iNodeOffset);

  inline CListHead_* C_Handle() { return mp_handle; }
  inline const CListHead_* C_Handle() const { return mp_handle; }
  inline operator CListHead_* () { return C_Handle(); }
  inline operator const CListHead_* () const { return C_Handle(); }

private:
  CListHead_* mp_handle = nullptr;
};

#include "Lists.inl"
