#pragma once

inline CRaster::CRaster(CRaster_* p)
  : mp_handle(p)
  , ra_pvpViewPort(*CRaster_ra_pvpViewPort(mp_handle))
{
}
