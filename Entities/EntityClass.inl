#pragma once

inline CEntityClass::CEntityClass(CEntityClass_* p, bool)
  : CSerial((CSerial_*)p, false)
  , ec_pdecDLLClass(*CEntityClass_ec_pdecDLLClass(p))
{
}

inline CEntityClass::~CEntityClass()
{
}

__forceinline CEntityPtr CEntityClass::New()
{
  return CEntityClass_New(C_Handle());
}

__forceinline CEntityPropertyPtr CEntityClass::PropertyForName(const CTString& strPropertyName)
{
  return CEntityClass_PropertyForName(C_Handle(), strPropertyName);
}
