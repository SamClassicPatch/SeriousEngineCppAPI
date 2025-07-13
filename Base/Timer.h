#pragma once
#include "Types.h"
#include "CTString.h"
#include "Synchronization.h"
#include <SeriousEngineCAPI/Base/Timer.h>

/*
 * Class that holds and manipulates with high-precision timer values.
 */
class CTimerValue
{
public:
  CTimerValue(CTimerValue_* p, bool owner = false);
  CTimerValue();
  CTimerValue(int64_t i64);
  CTimerValue(DOUBLE dSeconds);
  CTimerValue(const CTimerValue& o);
  ~CTimerValue();
  CTimerValue& operator=(const CTimerValue& o);

  /* Clear timer value (set it to zero). */
  void Clear();
  /* Addition. */
  CTimerValue& operator+=(const CTimerValue& tvOther);
  CTimerValue operator+(const CTimerValue& tvOther) const;
  /* Substraction. */
  CTimerValue& operator-=(const CTimerValue& tvOther);
  CTimerValue operator-(const CTimerValue& tvOther) const;
  /* Comparisons. */
  BOOL operator<(const CTimerValue& tvOther) const;
  BOOL operator>(const CTimerValue& tvOther) const;
  BOOL operator<=(const CTimerValue& tvOther) const;
  BOOL operator>=(const CTimerValue& tvOther) const;
  /* Get the timer value in seconds. - use for time spans only! */
  DOUBLE GetSeconds();
  /* Get the timer value in milliseconds as integral value. */
  int64_t GetMilliseconds();

  inline CTimerValue_* C_Handle() { return mp_handle; }
  inline const CTimerValue_* C_Handle() const { return mp_handle; }
  inline operator CTimerValue_* () { return C_Handle(); }
  inline operator const CTimerValue_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTimerValue_* mp_handle = nullptr;

public:
  int64_t& tv_llValue;
};

// a base class for hooking on timer interrupt
class CTimerHandler
{
public:
  explicit CTimerHandler(void(__cdecl* callback)(void));
  virtual ~CTimerHandler();

  /* This is called every TickQuantum seconds. */
  virtual void HandleTimer() = 0;

  inline CTimerHandler_* C_Handle() { return mp_handle; }
  inline const CTimerHandler_* C_Handle() const { return mp_handle; }
  inline operator CTimerHandler_* () { return C_Handle(); }
  inline operator const CTimerHandler_* () const { return C_Handle(); }

private:
  CTimerHandler_* mp_handle = nullptr;
};

CTCriticalSection _pTimer_tm_csHooks();
CTimerValue _pTimer_GetHighPrecisionTimer();

// convert a time value to a printable string (hh:mm:ss)
CTString TimeToString(FLOAT fTime);

#include "Timer.inl"
