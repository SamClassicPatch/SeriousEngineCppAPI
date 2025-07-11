#pragma once
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Graphics/Raster.h>

class CRaster
{
public:
  CRaster(CRaster_* p);

  inline CRaster_* C_Handle() { return mp_handle; }
  inline const CRaster_* C_Handle() const { return mp_handle; }
  inline operator CRaster_* () { return C_Handle(); }
  inline operator const CRaster_* () const { return C_Handle(); }

private:
  CRaster_* mp_handle;

public:
  CViewPort_*& ra_pvpViewPort;
};

#include "Raster.inl"
