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
#include "../Base/Types.h"
#include <SeriousEngineCAPI/Graphics/Color.h>

// COLOR FORMAT CONVERSION ROUTINES

// convert separate R,G and B color components to CroTeam COLOR format (ULONG type)
COLOR RGBToColor(UBYTE ubR, UBYTE ubG, UBYTE ubB);
// convert CroTeam COLOR format to separate R,G and B color components
void ColorToRGB(COLOR col, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB);
// combine CroTeam COLOR format from separate R,G and B color components
COLOR RGBAToColor(UBYTE ubR, UBYTE ubG, UBYTE ubB, UBYTE ubA);
// separate CroTeam COLOR format to R,G and B color components
void ColorToRGBA(COLOR col, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB, UBYTE& ubA);

// convert HSV components to CroTeam COLOR format
COLOR HSVToColor(UBYTE ubH, UBYTE ubS, UBYTE ubV);
// convert CroTeam COLOR format to HSV components
void ColorToHSV(COLOR colSrc, UBYTE& ubH, UBYTE& ubS, UBYTE& ubV);

// convert HSVA components to CroTeam COLOR format
COLOR HSVAToColor(UBYTE ubH, UBYTE ubS, UBYTE ubV, UBYTE ubA);
// convert CroTeam COLOR format to HSVA components
void ColorToHSVA(COLOR colSrc, UBYTE& ubH, UBYTE& ubS, UBYTE& ubV, UBYTE& ubA);

// is color gray, black or white?
BOOL IsGray(COLOR col);
BOOL IsBlack(COLOR col);
BOOL IsWhite(COLOR col);

// find corresponding desaturated color (it's not same as gray!)
COLOR DesaturateColor(COLOR col);

// is color1 bigger than color2 (gray comparison)
BOOL IsBigger(COLOR col1, COLOR col2);
// has color same hue and saturation (with little tolerance) ?
BOOL CompareChroma(COLOR col1, COLOR col2);

// adjust color saturation and/or hue (hue shift in 0-255 range!)
COLOR AdjustColor(COLOR col, SLONG slHueShift, SLONG slSaturation);
COLOR AdjustGamma(COLOR col, FLOAT fGamma);
// color lerping functions
COLOR LerpColor(COLOR col0, COLOR col1, FLOAT fRatio);
void LerpColor(COLOR col0, COLOR col1, FLOAT fRatio, UBYTE& ubR, UBYTE& ubG, UBYTE& ubB);

// some fast color manipulation functions
COLOR MulColors(COLOR col1, COLOR col2); // fast color multiply function - RES = 1ST * 2ND /255
COLOR AddColors(COLOR col1, COLOR col2); // fast color additon function - RES = clamp (1ST + 2ND)

// converts colors between Croteam, OpenGL and DirectX
ULONG ByteSwap(ULONG ul);

#include "Color.inl"
