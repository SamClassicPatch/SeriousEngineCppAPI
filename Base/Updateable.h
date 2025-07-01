#pragma once
#include "Types.h"
#include <SeriousEngineCAPI/Base/Updateable.h>

/*
 * Object that can be updated to reflect changes in some changeable object(s).
 */
class CUpdateable
{
public:
  CUpdateable(CUpdateable_* p, bool owner = false);
  CUpdateable();
  CUpdateable(const CUpdateable& o);
  ~CUpdateable();

  CUpdateable& operator=(const CUpdateable& o);

  /* Get time when last updated. */
  TIME LastUpdateTime() const;
  /* Mark that the object has been updated. */
  void MarkUpdated();
  /* Mark that the object has become invalid in spite of its time stamp. */
  void Invalidate();

  inline CUpdateable_* C_Handle() { return mp_handle; }
  inline const CUpdateable_* C_Handle() const { return mp_handle; }
  inline operator CUpdateable_* () { return C_Handle(); }
  inline operator const CUpdateable_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CUpdateable_* mp_handle = nullptr;
};

#include "Updateable.inl"
