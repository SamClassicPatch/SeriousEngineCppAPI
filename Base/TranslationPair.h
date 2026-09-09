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
#include "Types.h"

class CTranslationPair
{
public:
  CTranslationPair(CTranslationPair_* p, bool owner = false);
  CTranslationPair();
  CTranslationPair(const CTranslationPair& strOriginal);
  ~CTranslationPair();

  CTranslationPair& operator=(const CTranslationPair& o);

  void Clear();
  const CTString GetName() const;

  BOOL& m_bUsed();
  BOOL m_bUsed() const;

  CTString_* tp_strSrc();
  const CTString_* tp_strSrc() const;

  CTString_* tp_strDst();
  const CTString_* tp_strDst() const;

  inline CTranslationPair_* C_Handle() { return mp_handle; }
  inline const CTranslationPair_* C_Handle() const { return mp_handle; }
  inline operator CTranslationPair_* () { return C_Handle(); }
  inline operator const CTranslationPair_* () const { return C_Handle(); }
protected:
  bool m_owner = true;
  CTranslationPair_* mp_handle = nullptr;
};

#include "TranslationPair.inl"
