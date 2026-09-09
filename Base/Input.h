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
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Input.h>

// Enable input inside one viewport, or window
void _pInput_EnableInput(CViewPort_* pvp);
void _pInput_EnableInput(HWND hWnd);
// Disable input
void _pInput_DisableInput();
// enable/disable joystick polling (it can be slow to poll if user doesn't realy use the joystick)
void _pInput_SetJoyPolling(BOOL bPoll);
// Test input activity
BOOL _pInput_IsInputEnabled();
// Scan states of all available input sources
void _pInput_GetInput(BOOL bPreScan);
// Clear all input states (keys become not pressed, axes are reset to zero)
void _pInput_ClearInput();
// Get count of available axis
INDEX _pInput_GetAvailableAxisCount();
// Get count of available buttons
INDEX _pInput_GetAvailableButtonsCount();
// Get name of given axis
const CTString _pInput_GetAxisName(INDEX iAxisNo);
const CTString _pInput_GetAxisTransName(INDEX iAxisNo);
// Get current position of given axis
FLOAT _pInput_GetAxisValue(INDEX iAxisNo);
// Get given button's name
const CTString _pInput_GetButtonName(INDEX iButtonNo);
// Get given button's name translated
const CTString _pInput_GetButtonTransName(INDEX iButtonNo);
// Get given button's current state
BOOL _pInput_GetButtonState(INDEX iButtonNo);

#include "Input.inl"
