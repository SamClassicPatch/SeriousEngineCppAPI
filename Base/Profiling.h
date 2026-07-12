#pragma once
#include "Types.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Profiling.h>

class CProfileForm
{
public:
  CProfileForm(CProfileForm_* p);
  ~CProfileForm();

  /* Reset all profiling values. */
  void Reset();

  /* Report profiling results. */
  void Report(CTString& strReport);

private:
  CProfileForm_* mp_handle;
};

#define _pfGfxProfile\
  CProfileForm(_pfGfxProfile_())

#define _pfModelProfile\
  CProfileForm(_pfModelProfile_())

#define _pfSoundProfile\
  CProfileForm(_pfSoundProfile_())

#define _pfNetworkProfile\
  CProfileForm(_pfNetworkProfile_())

#define _pfRenderProfile\
  CProfileForm(_pfRenderProfile_())

#define _pfWorldEditingProfile\
  CProfileForm(_pfWorldEditingProfile_())

#define _pfPhysicsProfile\
  CProfileForm(_pfPhysicsProfile_())

#include "Profiling.inl"
