#pragma once

inline UWORD* GetBufferForEditing(CTerrain* ptrTerrain, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData)
{
  return GetBufferForEditing_(ptrTerrain ? ptrTerrain->C_Handle() : nullptr, rcExtract, (BufferType_)btBufferType, iBufferData);
}

inline void SetBufferForEditing(CTerrain* ptrTerrain, UWORD* puwEditedBuffer, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData)
{
  SetBufferForEditing_(ptrTerrain ? ptrTerrain->C_Handle() : nullptr, puwEditedBuffer, rcExtract, btBufferType, iBufferData);
}

inline void ShowSelection(CTerrain* ptrTerrain, Rect& rcExtract, CTextureData* ptdBrush, COLOR colSelection, FLOAT fStrenght, SelectionFill sfFill)
{
  ShowSelection_(ptrTerrain ? ptrTerrain->C_Handle() : nullptr, rcExtract, ptdBrush ? ptdBrush->C_Handle() : nullptr, colSelection, fStrenght, (SelectionFill_)sfFill);
}
