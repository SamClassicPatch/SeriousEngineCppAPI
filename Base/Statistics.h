#pragma once
#include "Types.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/Statistics.h>

// reset all values
inline void STAT_Reset() { STAT_Reset_(); }
// make a new report
inline void STAT_Report(CTString& strReport) { STAT_Report_(strReport); }
