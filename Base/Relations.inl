#pragma once

inline CRelationLnk::CRelationLnk(CRelationLnk_* p, bool)
  : mp_handle(p)
{
}

inline CRelationLnk::~CRelationLnk()
{
}

inline CListHead_* CRelationLnk::GetSrc()
{
  return CRelationLnk_GetSrc(C_Handle());
}

inline CListHead_* CRelationLnk::GetDst()
{
  return CRelationLnk_GetDst(C_Handle());
}
