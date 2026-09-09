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

class CTextureTransformation
{
public:
  CTextureTransformation(CTextureTransformation_* p, bool dummy = false);
  ~CTextureTransformation();
  CTextureTransformation(const CTextureTransformation& ln) = delete;
  CTextureTransformation& operator=(const CTextureTransformation& ln) = delete;

  inline CTextureTransformation_* C_Handle() { return mp_handle; }
  inline const CTextureTransformation_* C_Handle() const { return mp_handle; }
  inline operator CTextureTransformation_* () { return C_Handle(); }
  inline operator const CTextureTransformation_* () const { return C_Handle(); }
private:
  CTextureTransformation_* mp_handle = nullptr;

public:
  CTString tt_strName;
  CMappingDefinition tt_mdTransformation;
};

class CTextureBlending
{
public:
  CTextureBlending(CTextureBlending_* p, bool dummy = false);
  ~CTextureBlending();
  CTextureBlending(const CTextureBlending& ln) = delete;
  CTextureBlending& operator=(const CTextureBlending& ln) = delete;

  inline CTextureBlending_* C_Handle() { return mp_handle; }
  inline const CTextureBlending_* C_Handle() const { return mp_handle; }
  inline operator CTextureBlending_* () { return C_Handle(); }
  inline operator const CTextureBlending_* () const { return C_Handle(); }
private:
  CTextureBlending_* mp_handle = nullptr;

public:
  CTString tb_strName;
  UBYTE& tb_ubBlendingType;    // uses gfx flags for texture blending (STX_BLEND_xxxx)
  COLOR& tb_colMultiply;       // original polygon color is multiplied by this
};

class CSurfaceType
{
public:
  CSurfaceType(CSurfaceType_* p, bool dummy = false);
  ~CSurfaceType();
  CSurfaceType(const CSurfaceType& ln) = delete;
  CSurfaceType& operator=(const CSurfaceType& ln) = delete;

  inline CSurfaceType_* C_Handle() { return mp_handle; }
  inline const CSurfaceType_* C_Handle() const { return mp_handle; }
  inline operator CSurfaceType_* () { return C_Handle(); }
  inline operator const CSurfaceType_* () const { return C_Handle(); }
private:
  CSurfaceType_* mp_handle = nullptr;

public:
  FLOAT& st_fFriction;       // friction coefficient on the surface
  FLOAT& st_fStairsHeight;   // stairs step-up height modifier (=0-no step, >0 use max, <0 use min)
  FLOAT& st_fClimbSlopeCos;  // cosine of max. climbable slope
  FLOAT& st_fJumpSlopeCos;   // cosine of max. jump-from slope
  INDEX& st_iWalkDamageType;         // type of damage inflicted when walking on surface
  FLOAT& st_fWalkDamageAmount;       // how much to damage when inside
  FLOAT& st_tmWalkDamageDelay;       // how much to delay before first damage
  FLOAT& st_tmWalkDamageFrequency;   // how much to delay between two damages
  ULONG& st_ulFlags;
  CTString st_strName;      // name of surface type
};

class CContentType
{
public:
  CContentType(CContentType_* p, bool dummy = false);
  ~CContentType();
  CContentType(const CContentType& ln) = delete;
  CContentType& operator=(const CContentType& ln) = delete;

  inline CContentType_* C_Handle() { return mp_handle; }
  inline const CContentType_* C_Handle() const { return mp_handle; }
  inline operator CContentType_* () { return C_Handle(); }
  inline operator const CContentType_* () const { return C_Handle(); }
private:
  CContentType_* mp_handle = nullptr;

public:
  CTString ct_strName;  // name of surface type
  ULONG& ct_ulFlags;     // various flags
  FLOAT& ct_fDensity;    // density of the fluid inside content kg/m3 - defines buoyancy
  FLOAT& ct_fFluidFriction;      // friction inside the fluid (stopping movements)
  FLOAT& ct_fControlMultiplier;  // defines voluntary acceleration/decceleration
  FLOAT& ct_fSpeedMultiplier;    // max. speed modifier inside the fluid
  INDEX& ct_iSwimDamageType;         // type of damage inflicted when swimming
  FLOAT& ct_fSwimDamageAmount;       // how much to damage when inside
  FLOAT& ct_tmSwimDamageDelay;       // how much to delay before first damage
  FLOAT& ct_tmSwimDamageFrequency;   // how much to delay between two damages
  FLOAT& ct_fDrowningDamageAmount;   // how much to damage when drowning
  FLOAT& ct_tmDrowningDamageDelay;   // how much to delay between two damages
  FLOAT& ct_fKillImmersion;          // contents kills anything alive that gets in deeper than this
  INDEX& ct_iKillDamageType;         // type of killing damage
};

class CEnvironmentType
{
public:
  CEnvironmentType(CEnvironmentType_* p, bool dummy = false);
  ~CEnvironmentType();
  CEnvironmentType(const CEnvironmentType& ln) = delete;
  CEnvironmentType& operator=(const CEnvironmentType& ln) = delete;

  inline CEnvironmentType_* C_Handle() { return mp_handle; }
  inline const CEnvironmentType_* C_Handle() const { return mp_handle; }
  inline operator CEnvironmentType_* () { return C_Handle(); }
  inline operator const CEnvironmentType_* () const { return C_Handle(); }
private:
  CEnvironmentType_* mp_handle = nullptr;

public:
  CTString et_strName;  // name of environment type
  INDEX& et_iType;
  FLOAT& et_fSize;
};

class CIlluminationType
{
public:
  CIlluminationType(CIlluminationType_* p, bool dummy = false);
  ~CIlluminationType();
  CIlluminationType(const CIlluminationType& ln) = delete;
  CIlluminationType& operator=(const CIlluminationType& ln) = delete;

  inline CIlluminationType_* C_Handle() { return mp_handle; }
  inline const CIlluminationType_* C_Handle() const { return mp_handle; }
  inline operator CIlluminationType_* () { return C_Handle(); }
  inline operator const CIlluminationType_* () const { return C_Handle(); }
private:
  CIlluminationType_* mp_handle = nullptr;

public:
  CTString it_strName;  // name of illumination type
};

#include "WorldSettings.inl"
