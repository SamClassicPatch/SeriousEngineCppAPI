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

inline UWORD* GetBufferForEditing(CTerrain_* ptrTerrain, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData)
{
  return GetBufferForEditing_(ptrTerrain, rcExtract, (BufferType_)btBufferType, iBufferData);
}

inline void SetBufferForEditing(CTerrain_* ptrTerrain, UWORD* puwEditedBuffer, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData)
{
  SetBufferForEditing_(ptrTerrain, puwEditedBuffer, rcExtract, btBufferType, iBufferData);
}

inline void ShowSelection(CTerrain_* ptrTerrain, Rect& rcExtract, CTextureData_* ptdBrush, COLOR colSelection, FLOAT fStrenght, SelectionFill sfFill)
{
  ShowSelection_(ptrTerrain, rcExtract, ptdBrush, colSelection, fStrenght, (SelectionFill_)sfFill);
}
