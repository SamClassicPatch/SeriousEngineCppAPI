#pragma once
#include "../Base/Types.h"
#include "../Base/Serial.h"
#include <SeriousEngineCAPI/Sound/SoundData.h>

#define SDF_ENCODED       SDF_ENCODED_ // this is ogg or mpx compressed file
#define SDF_STREAMING     SDF_STREAMING_ // streaming from disk

class CSoundData : public CSerial
{
public:
  CSoundData(CSoundData_* p, bool owner = false);
  CSoundData();
  ~CSoundData();

  // get sound length in seconds
  DOUBLE GetSecondsLength();

  inline CSoundData_* C_Handle() { return (CSoundData_*)CSerial::C_Handle(); }
  inline const CSoundData_* C_Handle() const { return (const CSoundData_*)CSerial::C_Handle(); }
  inline operator CSoundData_* () { return C_Handle(); }
  inline operator const CSoundData_* () const { return C_Handle(); }
};

#include "SoundData.inl"
