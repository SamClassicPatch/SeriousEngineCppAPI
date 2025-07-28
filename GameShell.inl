#pragma once

inline GameGUI_interface::GameGUI_interface()
  : mp_handle(GameGUI_interface_new())
{
}

inline GameGUI_interface::~GameGUI_interface()
{
  GameGUI_interface_delete(mp_handle);
}

inline void GameGUI_interface::Initialize(const CTFileName& fnGameSettings)
{
  GameGUI_interface_Initialize(mp_handle, fnGameSettings);
}

inline void GameGUI_interface::End()
{
  GameGUI_interface_End(mp_handle);
}

inline void GameGUI_interface::QuickTest(const CTFileName& fnMapName, CDrawPort_* pdpDrawport, CViewPort_* pvpViewport)
{
  GameGUI_interface_QuickTest(mp_handle, fnMapName, pdpDrawport, pvpViewport);
}

inline void GameGUI_interface::OnInvokeConsole()
{
  GameGUI_interface_OnInvokeConsole(mp_handle);
}

inline void GameGUI_interface::OnPlayerSettings()
{
  GameGUI_interface_OnPlayerSettings(mp_handle);
}

inline void GameGUI_interface::OnAudioQuality()
{
  GameGUI_interface_OnAudioQuality(mp_handle);
}

inline void GameGUI_interface::OnVideoQuality()
{
  GameGUI_interface_OnVideoQuality(mp_handle);
}

inline void GameGUI_interface::OnSelectPlayerAndControls()
{
  GameGUI_interface_OnSelectPlayerAndControls(mp_handle);
}
