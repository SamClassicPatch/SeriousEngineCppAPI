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
#include "Terrain.h"
#include <SeriousEngineCAPI/Terrain/TerrainEditing.h>

enum EEditingTool : EEditingTool_ {
  ET_NONE = ET_NONE_,
  ET_HEIGHT_TOOL = ET_HEIGHT_TOOL_,
  ET_SMOTH_TOOL = ET_SMOTH_TOOL_,
  ET_EQUALIZE = ET_EQUALIZE_,
  ET_ERASE = ET_ERASE_,
  ET_FLATERN = ET_FLATERN_,
  ET_NOISE = ET_NOISE_,
};

enum BufferType : BufferType_ {
  BT_INVALID = BT_INVALID_,
  BT_HEIGHT_MAP = BT_HEIGHT_MAP_,
  BT_LAYER_MASK = BT_LAYER_MASK_,
  BT_EDGE_MAP = BT_EDGE_MAP_,
};

enum SelectionFill : SelectionFill_ {
  SF_POLYGON = SF_POLYGON_,
  SF_WIREFRAME = SF_WIREFRAME_,
  SF_POINTS = SF_POINTS_
};

UWORD* GetBufferForEditing(CTerrain_* ptrTerrain, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData = -1);
void SetBufferForEditing(CTerrain_* ptrTerrain, UWORD* puwEditedBuffer, Rect& rcExtract, BufferType btBufferType, INDEX iBufferData = -1);
void ShowSelection(CTerrain_* ptrTerrain, Rect& rcExtract, CTextureData_* ptdBrush, COLOR colSelection, FLOAT fStrenght, SelectionFill sfFill = SF_POLYGON);

#include "TerrainEditing.inl"
