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

// class for an object that maintains global timer(s)
class CTimer
{
public:
  // interval defining frequency of the game ticker
  static inline TIME TickQuantum = CTimer_TickQuantum;     // 20 ticks per second

  CTimer(CTimer_* p, bool owner = false);
  CTimer(BOOL bInterrupt = TRUE);
  ~CTimer();

  /* Add a timer handler. */
  void AddHandler(CTimerHandler* pthNew);
  /* Remove a timer handler. */
  void RemHandler(CTimerHandler* pthOld);
  /* Handle timer handlers manually. */
  void HandleTimerHandlers();

  /* Set the real time tick value. */
  void SetRealTimeTick(TIME tNewRealTimeTick);
  /* Get the real time tick value. */
  TIME GetRealTimeTick() const;

  /* NOTE: CurrentTick is local to each thread, and every thread must take
     care to increment the current tick or copy it from real time tick if
     it wants to make animations and similar to work. */

     /* Set the current game tick used for time dependent tasks (animations etc.). */
  void SetCurrentTick(TIME tNewCurrentTick);
  /* Get current game time, always valid for the currently active task. */
  TIME CurrentTick() const;
  /* Get lerped game time. */
  TIME GetLerpedCurrentTick() const;

  // Set factor for lerping between ticks.
  void SetLerp(FLOAT fLerp);    // sets both primary and secondary
  void SetLerp2(FLOAT fLerp);   // sets only secondary
  // Disable lerping factor (set both factors to 1)
  void DisableLerp();
  // Get current factor used for lerping between game ticks.
  FLOAT GetLerpFactor() const;
  // Get current factor used for lerping between game ticks.
  FLOAT GetLerpFactor2() const;

  /* Get current timer value of high precision timer. */
  CTimerValue GetHighPrecisionTimer();

  inline CTimer_* C_Handle() { return mp_handle; }
  inline const CTimer_* C_Handle() const { return mp_handle; }
  inline operator CTimer_* () { return C_Handle(); }
  inline operator const CTimer_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CTimer_* mp_handle = nullptr;

public:
  CTCriticalSection tm_csHooks;   // access to timer hooks
};

// global timer object
#define _Timer\
  CTimer(_pTimer_(), false)

// convert a time value to a printable string (hh:mm:ss)
CTString TimeToString(FLOAT fTime);

#include "Timer.inl"
