#pragma once

inline CTimerValue::CTimerValue(CTimerValue_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tv_llValue(*CTimerValue_tv_llValue(mp_handle))
{
}

inline CTimerValue::CTimerValue()
  : CTimerValue(CTimerValue_new(), true)
{
}

inline CTimerValue::CTimerValue(int64_t i64)
  : CTimerValue(CTimerValue_new_i64(i64), true)
{
}

inline CTimerValue::CTimerValue(DOUBLE dSeconds)
  : CTimerValue(CTimerValue_new_s(dSeconds), true)
{
}

inline CTimerValue::CTimerValue(const CTimerValue& o)
  : CTimerValue(CTimerValue_clone(o))
{
}

inline CTimerValue::~CTimerValue()
{
  if (m_owner)
    CTimerValue_delete(mp_handle);
}

inline CTimerValue& CTimerValue::operator=(const CTimerValue& o)
{
  CTimerValue_copy(mp_handle, o);
  return *this;
}

inline void CTimerValue::Clear()
{
  CTimerValue_Clear(mp_handle);
}

inline CTimerValue& CTimerValue::operator+=(const CTimerValue& tvOther)
{
  tv_llValue += tvOther.tv_llValue;
  return *this;
}

__forceinline CTimerValue CTimerValue::operator+(const CTimerValue& tvOther) const
{
  return CTimerValue(tv_llValue + tvOther.tv_llValue);
}

inline CTimerValue& CTimerValue::operator-=(const CTimerValue& tvOther)
{
  tv_llValue -= tvOther.tv_llValue;
  return *this;
}

__forceinline CTimerValue CTimerValue::operator-(const CTimerValue& tvOther) const
{
  return CTimerValue(tv_llValue - tvOther.tv_llValue);
}

inline BOOL CTimerValue::operator<(const CTimerValue& tvOther) const
{
  return tv_llValue < tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator>(const CTimerValue& tvOther) const
{
  return tv_llValue > tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator<=(const CTimerValue& tvOther) const
{
  return tv_llValue <= tvOther.tv_llValue;
}

inline BOOL CTimerValue::operator>=(const CTimerValue& tvOther) const
{
  return tv_llValue >= tvOther.tv_llValue;
}

inline DOUBLE CTimerValue::GetSeconds()
{
  return CTimerValue_GetSeconds(mp_handle);
}

inline int64_t CTimerValue::GetMilliseconds()
{
  return CTimerValue_GetMilliseconds(mp_handle);
}


inline CTimerHandler::CTimerHandler(void(*callback)(void))
  : mp_handle(CTimerHandler_new(callback))
{
}

inline CTimerHandler::~CTimerHandler()
{
  CTimerHandler_delete(mp_handle);
}

__forceinline CTCriticalSectionPtr _pTimer_tm_csHooks()
{
  return _pTimer_tm_csHooks();
}

__forceinline CTimerValue _pTimer_GetHighPrecisionTimer()
{
  return CTimerValue(_pTimer_GetHighPrecisionTimer_(), true);
}

__forceinline CTString TimeToString(FLOAT fTime)
{
  return CTString(TimeToString_(fTime), true);
}
