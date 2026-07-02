#pragma once

inline CSetFPUPrecision::CSetFPUPrecision(FPUPrecisionType fptNew)
{
  // remember old precision
  sfp_fptOldPrecision = (FPUPrecisionType)GetFPUPrecision_();
  // set new precision if needed
  sfp_fptNewPrecision = fptNew;
  if (sfp_fptNewPrecision != sfp_fptOldPrecision) {
    SetFPUPrecision_((FPUPrecisionType_)fptNew);
  }
}

inline CSetFPUPrecision::~CSetFPUPrecision()
{
  // restore old precision if needed
  if (sfp_fptNewPrecision != sfp_fptOldPrecision) {
    SetFPUPrecision_((FPUPrecisionType_)sfp_fptOldPrecision);
  }
}
