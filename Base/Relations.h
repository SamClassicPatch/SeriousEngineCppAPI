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
#include "../Base/Types.h"
#include "Lists.h"
#include "ListIterator.h"
#include <SeriousEngineCAPI/Base/Relations.h>

// Object representing a link between a domain member and a codomain member.
class CRelationLnk
{
public:
  CRelationLnk(CRelationLnk_* p, bool dummy = false);
  ~CRelationLnk();
  CRelationLnk(const CRelationLnk& o) = delete;
  CRelationLnk& operator=(const CRelationLnk& o) = delete;

  // Get the domain member of this pair.
  CListHead_* GetSrc();
  // Get the codomain member of this pair.
  CListHead_* GetDst();

  inline CRelationLnk_* C_Handle() { return mp_handle; }
  inline const CRelationLnk_* C_Handle() const { return mp_handle; }
  inline operator CRelationLnk_* () { return C_Handle(); }
  inline operator const CRelationLnk_* () const { return C_Handle(); }
private:
  CRelationLnk_* mp_handle = nullptr;
};

// make 'for' construct for walking a list in domain member
#define FOREACHSRCLINK(head, iter) \
  for ( LISTITER(CRelationLnk, rl_lnSrc) iter(head); !iter.IsPastEnd(); iter.MoveToNext() )
// make 'for' construct for walking a list in codomain member
#define FOREACHDSTLINK(head, iter) \
  for ( LISTITER(CRelationLnk, rl_lnDst) iter(head); !iter.IsPastEnd(); iter.MoveToNext() )

// make 'for' construct for walking all codomain members related to a domain member
#define FOREACHDSTOFSRC(srchead, dstclass, dstmember, pdst) \
  FOREACHSRCLINK(srchead, pdst##_iter) { \
    TPointer<dstclass, dstclass##_> pdst(dstclass##_from_##dstmember(pdst##_iter->GetDst()));
// make 'for' construct for walking all domain members related to a codomain member
#define FOREACHSRCOFDST(dsthead, srcclass, srcmember, psrc) \
  FOREACHDSTLINK(dsthead, psrc##_iter) { \
    TPointer<srcclass, srcclass##_> psrc(srcclass##_from_##srcmember(psrc##_iter->GetSrc()));
#define ENDFOR }

#include "Relations.inl"
