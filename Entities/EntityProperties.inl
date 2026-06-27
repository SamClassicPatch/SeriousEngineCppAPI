#pragma once

inline CEntityPropertyEnumValue::CEntityPropertyEnumValue(CEntityPropertyEnumValue_* p, bool)
  : mp_handle(p)
  , epev_iValue(*CEntityPropertyEnumValue_epev_iValue(p))
  , epev_strName(*CEntityPropertyEnumValue_epev_strName(p))
{
}

inline CEntityPropertyEnumValue::~CEntityPropertyEnumValue()
{
}

inline CEntityPropertyEnumType::CEntityPropertyEnumType(CEntityPropertyEnumType_* p, bool)
  : mp_handle(p)
  , epet_ctValues(*CEntityPropertyEnumType_epet_ctValues(p))
{
}

inline CEntityPropertyEnumType::~CEntityPropertyEnumType()
{
}

__forceinline CEntityPropertyEnumValue CEntityPropertyEnumType::epet_aepevValues(INDEX i)
{
  return CEntityPropertyEnumType_epet_aepevValues(C_Handle(), i);
}

inline CEntityProperty::CEntityProperty(CEntityProperty_* p, bool)
  : mp_handle(p)
  , ep_eptType(*((PropertyType*)CEntityProperty_ep_eptType(p)))
  , ep_pepetEnumType(*CEntityProperty_ep_pepetEnumType(p))
  , ep_slOffset(*CEntityProperty_ep_slOffset(p))
  , ep_strName(*CEntityProperty_ep_strName(p))
  , ep_ulFlags(*CEntityProperty_ep_ulFlags(p))
  , ep_chShortcut(*CEntityProperty_ep_chShortcut(p))
{
}

inline CEntityProperty::~CEntityProperty()
{
}

inline CDLLEntityClass::CDLLEntityClass(CDLLEntityClass_* p, bool)
  : mp_handle(p)
  , dec_ctProperties(*CDLLEntityClass_dec_ctProperties(p))
  , dec_strName(*CDLLEntityClass_dec_strName(p))
  , dec_strIconFileName(*CDLLEntityClass_dec_strIconFileName(p))
{
}

inline CDLLEntityClass::~CDLLEntityClass()
{
}

__forceinline CEntityPropertyPtr CDLLEntityClass::PropertyForName(const CTString& strPropertyName)
{
  return CDLLEntityClass_PropertyForName(C_Handle(), strPropertyName);
}

__forceinline CEntityProperty CDLLEntityClass::dec_aepProperties(INDEX i)
{
  return CDLLEntityClass_dec_aepProperties(C_Handle(), i);
}

__forceinline CDLLEntityClassPtr CDLLEntityClass::dec_pdecBase()
{
  return *CDLLEntityClass_dec_pdecBase(C_Handle());
}
