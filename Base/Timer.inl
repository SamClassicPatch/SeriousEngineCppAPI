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


inline CTimerHandler::CTimerHandler(void(__cdecl* callback)(void))
  : mp_handle(CTimerHandler_new(callback))
{
}

inline CTimerHandler::~CTimerHandler()
{
  CTimerHandler_delete(mp_handle);
}


inline CTimer::CTimer(CTimer_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tm_csHooks(CTimer_tm_csHooks(mp_handle), false)
{
}

inline CTimer::CTimer(BOOL bInterrupt)
  : CTimer(CTimer_new(bInterrupt), true)
{
}

inline CTimer::~CTimer()
{
  if (m_owner)
    CTimer_delete(mp_handle);
}

inline void CTimer::AddHandler(CTimerHandler* pthNew)
{
  CTimer_AddHandler(mp_handle, *pthNew);
}

inline void CTimer::RemHandler(CTimerHandler* pthOld)
{
  CTimer_RemHandler(mp_handle, *pthOld);
}

inline void CTimer::HandleTimerHandlers()
{
  CTimer_HandleTimerHandlers(mp_handle);
}

inline void CTimer::SetRealTimeTick(TIME tNewRealTimeTick)
{
  CTimer_SetRealTimeTick(mp_handle, tNewRealTimeTick);
}

inline TIME CTimer::GetRealTimeTick() const
{
  return CTimer_GetRealTimeTick(mp_handle);
}

inline void CTimer::SetCurrentTick(TIME tNewCurrentTick)
{
  CTimer_SetCurrentTick(mp_handle, tNewCurrentTick);
}

inline TIME CTimer::CurrentTick() const
{
  return CTimer_CurrentTick(mp_handle);
}

inline TIME CTimer::GetLerpedCurrentTick() const
{
  return CTimer_GetLerpedCurrentTick(mp_handle);
}

inline void CTimer::SetLerp(FLOAT fLerp)
{
  CTimer_SetLerp(mp_handle, fLerp);
}

inline void CTimer::SetLerp2(FLOAT fLerp)
{
  CTimer_SetLerp2(mp_handle, fLerp);
}

inline void CTimer::DisableLerp()
{
  CTimer_DisableLerp(mp_handle);
}

inline FLOAT CTimer::GetLerpFactor() const
{
  return CTimer_GetLerpFactor(mp_handle);
}

inline FLOAT CTimer::GetLerpFactor2() const
{
  return CTimer_GetLerpFactor2(mp_handle);
}

__forceinline CTimerValue CTimer::GetHighPrecisionTimer()
{
  return CTimerValue(CTimer_GetHighPrecisionTimer(mp_handle), true);
}


__forceinline CTString TimeToString(FLOAT fTime)
{
  return CTString(TimeToString_(fTime), true);
}
