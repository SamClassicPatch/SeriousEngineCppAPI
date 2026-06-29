#pragma once

inline CLightSource::CLightSource(CLightSource_* p, bool)
  : mp_handle(p)
  , ls_ulFlags(*CLightSource_ls_ulFlags(p))
{
}

inline CLightSource::~CLightSource()
{
}
