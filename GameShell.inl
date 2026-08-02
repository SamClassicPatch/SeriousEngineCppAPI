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
