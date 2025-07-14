#pragma once
#include "Types.h"
#include "CTString.h"
#include <SeriousEngineCAPI/Base/ErrorReporting.h>

/* Throw an exception of formatted string. */
void ThrowF_t [[noreturn]] (const char* strFormat, ...); // throws char *
/* Report error and terminate program. */
void FatalError [[noreturn]] (const char* strFormat, ...);
/* Report warning without terminating program (stops program until user responds). */
void WarningMessage(const char* strFormat, ...);
/* Report information message to user (stops program until user responds). */
void InfoMessage(const char* strFormat, ...);
/* Get the description string for windows error code. */
const CTString GetWindowsError(DWORD dwWindowsErrorCode);

#include "ErrorReporting.inl"
