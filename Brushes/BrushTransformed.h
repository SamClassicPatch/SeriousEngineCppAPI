#pragma once
#include "../Base/Types.h"
#include "../Math/VectorDecl.h"
#include "../Math/Plane.h"
#include "../Math/TextureMapping.h"

/*
 * Cached transformed vertex.
 */
class CWorkingVertex
{
public:
  CWorkingVertex(CWorkingVertex_* p, bool dummy = false);
  ~CWorkingVertex();
  CWorkingVertex(const CWorkingVertex& o) = delete;
  CWorkingVertex& operator=(const CWorkingVertex& o) = delete;

  inline CWorkingVertex_* C_Handle() { return mp_handle; }
  inline const CWorkingVertex_* C_Handle() const { return mp_handle; }
  inline operator CWorkingVertex_* () { return C_Handle(); }
  inline operator const CWorkingVertex_* () const { return C_Handle(); }
private:
  CWorkingVertex_* mp_handle = nullptr;

public:
  FLOAT3D wvx_vRelative;  // coordinates in brush space
};

/*
 * Cached transformed plane.
 */
class CWorkingPlane
{
public:
  CWorkingPlane(CWorkingPlane_* p, bool dummy = false);
  ~CWorkingPlane();
  CWorkingPlane(const CWorkingPlane& o) = delete;
  CWorkingPlane& operator=(const CWorkingPlane& o) = delete;

  inline CWorkingPlane_* C_Handle() { return mp_handle; }
  inline const CWorkingPlane_* C_Handle() const { return mp_handle; }
  inline operator CWorkingPlane_* () { return C_Handle(); }
  inline operator const CWorkingPlane_* () const { return C_Handle(); }
private:
  CWorkingPlane_* mp_handle = nullptr;

public:
  FLOATplane3D wpl_plRelative;     // coordinates in brush space
  CMappingVectors wpl_mvRelative;  // mapping vectors in brush space
  FLOATplane3D wpl_plView;         // coordinates in view space
  CMappingVectors wpl_mvView;      // mapping vectors in view space
  CPlanarGradients wpl_pgOoK;      // plane gradients in default mapping
  BOOL& wpl_bVisible;              // set if the plane is visible
};

/*
 * Cached transformed edge.
 */
class CWorkingEdge
{
public:
  CWorkingEdge(CWorkingEdge_* p, bool dummy = false);
  ~CWorkingEdge();
  CWorkingEdge(const CWorkingEdge& o) = delete;
  CWorkingEdge& operator=(const CWorkingEdge& o) = delete;

  inline CWorkingEdge_* C_Handle() { return mp_handle; }
  inline const CWorkingEdge_* C_Handle() const { return mp_handle; }
  inline operator CWorkingEdge_* () { return C_Handle(); }
  inline operator const CWorkingEdge_* () const { return C_Handle(); }
private:
  CWorkingEdge_* mp_handle = nullptr;

public:
  INDEX& wed_iwvx0;    // working vertices in sector
  INDEX& wed_iwvx1;
};

#include "BrushTransformed.inl"
