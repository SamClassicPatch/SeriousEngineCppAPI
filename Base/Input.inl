#pragma once

inline void _pInput_EnableInput(CViewPort_* pvp)
{
  _pInput_EnableInput_(pvp);
}

inline void _pInput_EnableInput(HWND hWnd)
{
  _pInput_EnableInput_hwnd_(hWnd);
}

inline void _pInput_DisableInput()
{
  _pInput_DisableInput_();
}

inline void _pInput_SetJoyPolling(BOOL bPoll)
{
  _pInput_SetJoyPolling_(bPoll);
}

inline BOOL _pInput_IsInputEnabled()
{
  return _pInput_IsInputEnabled_();
}

inline void _pInput_GetInput(BOOL bPreScan)
{
  _pInput_GetInput_(bPreScan);
}

inline void _pInput_ClearInput()
{
  _pInput_ClearInput_();
}

inline INDEX _pInput_GetAvailableAxisCount()
{
  return _pInput_GetAvailableAxisCount_();
}

inline INDEX _pInput_GetAvailableButtonsCount()
{
  return _pInput_GetAvailableButtonsCount_();
}

__forceinline const CTString _pInput_GetAxisName(INDEX iAxisNo)
{
  return CTString(_pInput_GetAxisName_(iAxisNo), false);
}

__forceinline const CTString _pInput_GetAxisTransName(INDEX iAxisNo)
{
  return CTString(_pInput_GetAxisTransName_(iAxisNo), false);
}

inline FLOAT _pInput_GetAxisValue(INDEX iAxisNo)
{
  return _pInput_GetAxisValue_(iAxisNo);
}

__forceinline const CTString _pInput_GetButtonName(INDEX iButtonNo)
{
  return CTString(_pInput_GetButtonName_(iButtonNo), false);
}

__forceinline const CTString _pInput_GetButtonTransName(INDEX iButtonNo)
{
  return CTString(_pInput_GetButtonTransName_(iButtonNo), false);
}

inline BOOL _pInput_GetButtonState(INDEX iButtonNo)
{
  return _pInput_GetButtonState_(iButtonNo);
}
