#include "Types.h"

void SECppAPI_CheckException()
{
  if (HasException())
    throw GrabException();
}
