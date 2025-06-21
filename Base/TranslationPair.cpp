#include "TranslationPair.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/TranslationPair.h>

CTranslationPair::CTranslationPair(CTranslationPair_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

CTranslationPair::CTranslationPair()
  : m_owner(true)
  , mp_handle(CTranslationPair_new())
{
}

CTranslationPair::CTranslationPair(const CTranslationPair& strOriginal)
  : m_owner(true)
  , mp_handle(CTranslationPair_clone(strOriginal))
{
}

CTranslationPair::~CTranslationPair()
{
  if (m_owner)
    CTranslationPair_delete(mp_handle);
}

CTranslationPair& CTranslationPair::operator=(const CTranslationPair& o)
{
  CTranslationPair_copy(mp_handle, o);
  return *this;
}

void CTranslationPair::Clear()
{
  CTranslationPair_Clear(mp_handle);
}

const CTString CTranslationPair::GetName() const
{
  return CTString((CTString_*)CTranslationPair_GetName(mp_handle));
}

BOOL& CTranslationPair::m_bUsed()
{
  return *CTranslationPair_m_bUsed(mp_handle);
}

BOOL CTranslationPair::m_bUsed() const
{
  return *CTranslationPair_m_bUsed_const(mp_handle);
}

CTString CTranslationPair::tp_strSrc()
{
  return CTString(CTranslationPair_tp_strSrc(mp_handle));
}

const CTString CTranslationPair::tp_strSrc() const
{
  return CTString((CTString_*)CTranslationPair_tp_strSrc_const(mp_handle));
}

CTString CTranslationPair::tp_strDst()
{
  return CTString(CTranslationPair_tp_strDst(mp_handle));
}

const CTString CTranslationPair::tp_strDst() const
{
  return CTString((CTString_*)CTranslationPair_tp_strDst_const(mp_handle));
}
