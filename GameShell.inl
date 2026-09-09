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

inline GameGUI_interface::GameGUI_interface()
  : mp_handle(nullptr)
{
  auto* handle = GameGUI_interface_new();
  SECppAPI_CheckException();
  mp_handle = handle;
}

inline GameGUI_interface::~GameGUI_interface()
{
  if (mp_handle)
  {
    GameGUI_interface_delete(mp_handle);
    SECppAPI_CheckException();
  }
}

inline void GameGUI_interface::Initialize(const CTFileName& fnGameSettings)
{
  GameGUI_interface_Initialize(mp_handle, fnGameSettings);
  SECppAPI_CheckException();
}

inline void GameGUI_interface::End()
{
  GameGUI_interface_End(mp_handle);
  SECppAPI_CheckException();
}

inline void GameGUI_interface::QuickTest(const CTFileName& fnMapName, CDrawPort_* pdpDrawport, CViewPort_* pvpViewport)
{
  GameGUI_interface_QuickTest(mp_handle, fnMapName, pdpDrawport, pvpViewport);
  SECppAPI_CheckException();
}
