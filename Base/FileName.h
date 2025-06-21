#pragma once
#include "CTString.h"

class SECPPAPI CTFileName
{
public:

  inline CTFileName_* C_Handle() { return mp_file; }
  inline const CTFileName_* C_Handle() const { return mp_file; }
private:
  const bool m_owner = true;
  CTFileName_* mp_file = nullptr;
};
