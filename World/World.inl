#pragma once

inline CWorld::CWorld(CWorld_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
{
}

inline CWorld::CWorld()
  : CWorld(CWorld_new(), true)
{
}

inline CWorld::~CWorld()
{
  if (m_owner)
    CWorld_delete(C_Handle());
}
