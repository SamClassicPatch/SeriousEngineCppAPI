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
#include "CTString.h"
#include <SeriousEngineCAPI/Base/TranslationPair.h>

inline CTranslationPair::CTranslationPair(CTranslationPair_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CTranslationPair::CTranslationPair()
  : m_owner(true)
  , mp_handle(CTranslationPair_new())
{
}

inline CTranslationPair::CTranslationPair(const CTranslationPair& strOriginal)
  : m_owner(true)
  , mp_handle(CTranslationPair_clone(strOriginal))
{
}

inline CTranslationPair::~CTranslationPair()
{
  if (m_owner)
    CTranslationPair_delete(mp_handle);
}

inline CTranslationPair& CTranslationPair::operator=(const CTranslationPair& o)
{
  CTranslationPair_copy(mp_handle, o);
  return *this;
}

inline void CTranslationPair::Clear()
{
  CTranslationPair_Clear(mp_handle);
}

inline const CTString CTranslationPair::GetName() const
{
  return CTString((CTString_*)CTranslationPair_GetName(mp_handle));
}

inline BOOL& CTranslationPair::m_bUsed()
{
  return *CTranslationPair_m_bUsed(mp_handle);
}

inline BOOL CTranslationPair::m_bUsed() const
{
  return *CTranslationPair_m_bUsed_const(mp_handle);
}

inline CTString_* CTranslationPair::tp_strSrc()
{
  return CTranslationPair_tp_strSrc(mp_handle);
}

inline const CTString_* CTranslationPair::tp_strSrc() const
{
  return CTranslationPair_tp_strSrc_const(mp_handle);
}

inline CTString_* CTranslationPair::tp_strDst()
{
  return CTranslationPair_tp_strDst(mp_handle);
}

inline const CTString_* CTranslationPair::tp_strDst() const
{
  return CTranslationPair_tp_strDst_const(mp_handle);
}
