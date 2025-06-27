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
