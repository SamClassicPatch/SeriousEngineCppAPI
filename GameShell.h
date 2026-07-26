#pragma once
#include "Base/Types.h"
#include "Base/FileName.h"
#include <SeriousEngineCAPI/GameShell.h>

class GameGUI_interface
{
public:
  GameGUI_interface();
  ~GameGUI_interface();
  GameGUI_interface(const GameGUI_interface&) = delete;
  GameGUI_interface& operator=(const GameGUI_interface&) = delete;

  // initialize game and load settings
  void Initialize(const CTFileName& fnGameSettings);
  // save settings and cleanup
  void End();
  // run a quicktest game from within editor
  void QuickTest(const CTFileName& fnMapName, CDrawPort_* pdpDrawport, CViewPort_* pvpViewport);

  inline GameGUI_interface_* C_Handle() { return mp_handle; }
  inline const GameGUI_interface_* C_Handle() const { return mp_handle; }
  inline operator GameGUI_interface_* () { return C_Handle(); }
  inline operator const GameGUI_interface_* () const { return C_Handle(); }

private:
  GameGUI_interface_* mp_handle = nullptr;
};

#include "GameShell.inl"
