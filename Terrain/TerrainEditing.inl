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
