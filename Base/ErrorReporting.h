/* Copyright (c) 2026 SeriousAlexej.
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

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
