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
#include <SeriousEngineCAPI/World/WorldSettings.h>

inline CTextureTransformation::CTextureTransformation(CTextureTransformation_* p, bool)
  : mp_handle(p)
  , tt_strName(CTextureTransformation_tt_strName(p), false)
  , tt_mdTransformation(CTextureTransformation_tt_mdTransformation(p), false)
{
}

inline CTextureTransformation::~CTextureTransformation()
{
}

inline CTextureBlending::CTextureBlending(CTextureBlending_* p, bool)
  : mp_handle(p)
  , tb_strName(CTextureBlending_tb_strName(p), false)
  , tb_ubBlendingType(*CTextureBlending_tb_ubBlendingType(p))
  , tb_colMultiply(*CTextureBlending_tb_colMultiply(p))
{
}

inline CTextureBlending::~CTextureBlending()
{
}

inline CSurfaceType::CSurfaceType(CSurfaceType_* p, bool)
  : mp_handle(p)
  , st_fFriction(*CSurfaceType_st_fFriction(p))
  , st_fStairsHeight(*CSurfaceType_st_fStairsHeight(p))
  , st_fClimbSlopeCos(*CSurfaceType_st_fClimbSlopeCos(p))
  , st_fJumpSlopeCos(*CSurfaceType_st_fJumpSlopeCos(p))
  , st_iWalkDamageType(*CSurfaceType_st_iWalkDamageType(p))
  , st_fWalkDamageAmount(*CSurfaceType_st_fWalkDamageAmount(p))
  , st_tmWalkDamageDelay(*CSurfaceType_st_tmWalkDamageDelay(p))
  , st_tmWalkDamageFrequency(*CSurfaceType_st_tmWalkDamageFrequency(p))
  , st_ulFlags(*CSurfaceType_st_ulFlags(p))
  , st_strName(CSurfaceType_st_strName(p), false)
{
}

inline CSurfaceType::~CSurfaceType()
{
}

inline CContentType::CContentType(CContentType_* p, bool)
  : mp_handle(p)
  , ct_strName(CContentType_ct_strName(p), false)
  , ct_ulFlags(*CContentType_ct_ulFlags(p))
  , ct_fDensity(*CContentType_ct_fDensity(p))
  , ct_fFluidFriction(*CContentType_ct_fFluidFriction(p))
  , ct_fControlMultiplier(*CContentType_ct_fControlMultiplier(p))
  , ct_fSpeedMultiplier(*CContentType_ct_fSpeedMultiplier(p))
  , ct_iSwimDamageType(*CContentType_ct_iSwimDamageType(p))
  , ct_fSwimDamageAmount(*CContentType_ct_fSwimDamageAmount(p))
  , ct_tmSwimDamageDelay(*CContentType_ct_tmSwimDamageDelay(p))
  , ct_tmSwimDamageFrequency(*CContentType_ct_tmSwimDamageFrequency(p))
  , ct_fDrowningDamageAmount(*CContentType_ct_fDrowningDamageAmount(p))
  , ct_tmDrowningDamageDelay(*CContentType_ct_tmDrowningDamageDelay(p))
  , ct_fKillImmersion(*CContentType_ct_fKillImmersion(p))
  , ct_iKillDamageType(*CContentType_ct_iKillDamageType(p))
{
}

inline CContentType::~CContentType()
{
}

inline CEnvironmentType::CEnvironmentType(CEnvironmentType_* p, bool)
  : mp_handle(p)
  , et_strName(CEnvironmentType_et_strName(p), false)
  , et_iType(*CEnvironmentType_et_iType(p))
  , et_fSize(*CEnvironmentType_et_fSize(p))
{
}

inline CEnvironmentType::~CEnvironmentType()
{
}

inline CIlluminationType::CIlluminationType(CIlluminationType_* p, bool)
  : mp_handle(p)
  , it_strName(CIlluminationType_it_strName(p), false)
{
}

inline CIlluminationType::~CIlluminationType()
{
}
