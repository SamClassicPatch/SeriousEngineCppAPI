#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Math/Float.h>

// FPU precision setting values
enum FPUPrecisionType : FPUPrecisionType_ {
  FPT_24BIT = FPT_24BIT_,
  FPT_53BIT = FPT_53BIT_,
  FPT_64BIT = FPT_64BIT_,
};

/*
 * Class that provides automatic saving/setting/restoring of FPU precision setting.
 */
class CSetFPUPrecision {
private:
  FPUPrecisionType sfp_fptOldPrecision;
  FPUPrecisionType sfp_fptNewPrecision;
public:
  /* Constructor with automatic setting of FPU precision. */
  CSetFPUPrecision(FPUPrecisionType fptNew);
  /* Destructor with automatic restoring of FPU precision. */
  ~CSetFPUPrecision();
};

#include "Float.inl"
