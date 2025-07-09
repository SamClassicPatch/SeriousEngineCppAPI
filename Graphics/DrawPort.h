#pragma once
#include "../Base/Types.h"

class CDrawPort
{
public:
  CDrawPort(CDrawPort_* p, bool owner = false);
  CDrawPort();
  CDrawPort(const CDrawPort& o);
  ~CDrawPort();
  CDrawPort& operator=(const CDrawPort& o);

  inline CDrawPort_* C_Handle() { return mp_handle; }
  inline const CDrawPort_* C_Handle() const { return mp_handle; }
  inline operator CDrawPort_* () { return C_Handle(); }
  inline operator const CDrawPort_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CDrawPort_* mp_handle = nullptr;
};
