#pragma once

inline CLightSource::CLightSource(CLightSource_* p, bool)
  : mp_handle(p)
  , ls_ulFlags(*CLightSource_ls_ulFlags(p))
  , ls_penEntity(*CLightSource_ls_penEntity(p))
{
}

inline CLightSource::~CLightSource()
{
}
