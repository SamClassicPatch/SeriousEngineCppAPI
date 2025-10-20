#pragma once
#include "../Base/CTString.h"
#include "../Templates/StaticArray.h"
#include "../Templates/DynamicArray.h"
#include "Vector.h"
#include "Plane.h"
#include "TextureMapping.h"
#include "Projection.h"
#include "Projection_DOUBLE.h"

// a vertex in 3d object
class CObjectVertex {
public:
  CObjectVertex(CObjectVertex_* p, bool owner = false);
  CObjectVertex();
  CObjectVertex(const DOUBLE3D& o);
  CObjectVertex(const CObjectVertex& o);
  ~CObjectVertex();
  CObjectVertex& operator=(const CObjectVertex& o);

  inline CObjectVertex_* C_Handle() { return mp_handle; }
  inline const CObjectVertex_* C_Handle() const { return mp_handle; }
  inline operator CObjectVertex_* () { return C_Handle(); }
  inline operator const CObjectVertex_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectVertex_* mp_handle = nullptr;

public:
  CObjectVertex_*& ovx_Remap;         // pointer for index remapping
  ULONG& ovx_Tag;                    // tag for format-specific data
  INDEX& ovx_Index;                  // index for easier conversions
  // flags 0-7 are used by CObjectVertex, flags 8-31 are reserved for custom formats
  ULONG& ovx_ulFlags;                // flags
  DOUBLE3D value;
};

// a plane in 3d object
class CObjectPlane {
public:
  CObjectPlane(CObjectPlane_* p, bool owner = false);
  CObjectPlane();
  CObjectPlane(const DOUBLEplane3D& o);
  CObjectPlane(const CObjectPlane& o);
  ~CObjectPlane();
  CObjectPlane& operator=(const CObjectPlane& o);

  inline CObjectPlane_* C_Handle() { return mp_handle; }
  inline const CObjectPlane_* C_Handle() const { return mp_handle; }
  inline operator CObjectPlane_* () { return C_Handle(); }
  inline operator const CObjectPlane_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectPlane_* mp_handle = nullptr;

public:
  CObjectPlane_*& opl_Remap;          // pointer for index remapping
  ULONG& opl_Tag;                    // tag for format-specific data
  INDEX& opl_Index;                  // index for easier conversions
  DOUBLEplane3D value;
};

// an edge in 3d object
class CObjectEdge {
public:
  CObjectEdge(CObjectEdge_* p, bool owner = false);
  CObjectEdge();
  CObjectEdge(CObjectVertex& ovxVertex0, CObjectVertex& ovxVertex1);
  CObjectEdge(const CObjectEdge& o);
  ~CObjectEdge();
  CObjectEdge& operator=(const CObjectEdge& o);

  inline CObjectEdge_* C_Handle() { return mp_handle; }
  inline const CObjectEdge_* C_Handle() const { return mp_handle; }
  inline operator CObjectEdge_* () { return C_Handle(); }
  inline operator const CObjectEdge_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectEdge_* mp_handle = nullptr;

public:
  ULONG& oed_Tag;                  // tag for format-specific data
  INDEX& oed_Index;                // index for easier conversions
  CObjectEdge_*& optimize_oed_Remap;         // pointer for index remapping
  CObjectEdge_*& optimize_oed_InverseEdge;   // pointer to inverse edge, if exists
  CObjectEdge_*& colinear1_oed_FirstChild;    // pointer to first part of split edge
  CObjectEdge_*& colinear1_oed_NextSibling;   // pointer to next part of split edge
  CEdgeEx_*& colinear2_oed_pedxLine;          // pointer to line information
  CObjectVertex_*& oed_Vertex0;     // start vertex
  CObjectVertex_*& oed_Vertex1;     // end vertex
};

// a material in 3d object
class CObjectMaterial {
public:
  CObjectMaterial(CObjectMaterial_* p, bool owner = false);
  CObjectMaterial();
  CObjectMaterial(const CTString& o);
  CObjectMaterial(const CObjectMaterial& o);
  ~CObjectMaterial();
  CObjectMaterial& operator=(const CObjectMaterial& o);

  /* Color assignment. */
  inline void SetColor(const COLOR& clrColor) { omt_Color = clrColor; };

  inline CObjectMaterial_* C_Handle() { return mp_handle; }
  inline const CObjectMaterial_* C_Handle() const { return mp_handle; }
  inline operator CObjectMaterial_* () { return C_Handle(); }
  inline operator const CObjectMaterial_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectMaterial_* mp_handle = nullptr;

public:
  ULONG& omt_Tag;                  // tag for format-specific data
  INDEX& omt_Index;                // index for easier conversions
  CTString omt_Name;               // name of this material
  CTString omt_strName2;
  CTString omt_strName3;
  COLOR& omt_Color;                // color of this material (surface)
};

// a reference to edge in polygon
class CObjectPolygonEdge {
public:
  CObjectPolygonEdge(CObjectPolygonEdge_* p, bool owner = false);
  CObjectPolygonEdge();
  CObjectPolygonEdge(CObjectEdge_* poed);
  CObjectPolygonEdge(CObjectEdge_* poed, BOOL bReverse);
  CObjectPolygonEdge(const CObjectPolygonEdge& o);
  ~CObjectPolygonEdge();
  CObjectPolygonEdge& operator=(const CObjectPolygonEdge& o);

  /* Get start and end vertices. */
  void GetVertices(CObjectVertex_*& povxStart, CObjectVertex_*& povxEnd);

  inline CObjectPolygonEdge_* C_Handle() { return mp_handle; }
  inline const CObjectPolygonEdge_* C_Handle() const { return mp_handle; }
  inline operator CObjectPolygonEdge_* () { return C_Handle(); }
  inline operator const CObjectPolygonEdge_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectPolygonEdge_* mp_handle = nullptr;

public:
  CObjectEdge_*& ope_Edge;         // pointer to the edge
  BOOL& ope_Backward;              // true if vertex0 and vertex1 must be swapped
};

DECLARE_CDynamicArray(CObjectEdge)
DECLARE_CDynamicArray(CObjectPolygonEdge)

class CObjectPolygon {
public:
  CObjectPolygon(CObjectPolygon_* p, bool owner = false);
  CObjectPolygon();
  CObjectPolygon(const CObjectPolygon&) = delete;
  ~CObjectPolygon();
  CObjectPolygon& operator=(const CObjectPolygon&) = delete;

  /* Join polygon edges that are collinear and continuing. */
  void JoinContinuingEdges(CDynamicArray_CObjectEdge& oedEdges);
  /* Remove polygon edges that are used twice from a polygon. */
  void RemoveRedundantEdges();
  /* Remove polygon edges that are marked as unused (oed_Edge==NULL) from polygon. */
  void RemoveMarkedEdges(INDEX ctNonMarkedEdges);
  /* Remove polygon edges that have zero length from a polygon. */
  void RemoveDummyEdgeReferences();

  inline CObjectPolygon_* C_Handle() { return mp_handle; }
  inline const CObjectPolygon_* C_Handle() const { return mp_handle; }
  inline operator CObjectPolygon_* () { return C_Handle(); }
  inline operator const CObjectPolygon_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectPolygon_* mp_handle = nullptr;

public:
  ULONG& opo_Tag;                                     // tag for format-specific data
  INDEX& opo_Index;                                   // index for easier conversions
  UBYTE* opo_ubUserData;                              // reserved space for other data
  CObjectPlane_*& opo_Plane;                          // plane of this polygon
  CDynamicArray_CObjectPolygonEdge opo_PolygonEdges;  // edges in this polygon
  CObjectMaterial_*& opo_Material;                    // material of this polygon
  CMappingDefinition opo_amdMappings[4];              // mapping of textures on this polygon
  ULONG& opo_ulFlags;                                 // various flags
  COLOR& opo_colorColor;                              // color of this polygon
};

DECLARE_CDynamicArray(CObjectVertex)
DECLARE_CDynamicArray(CObjectPlane)
DECLARE_CDynamicArray(CObjectMaterial)
DECLARE_CDynamicArray(CObjectPolygon)

// a sector in 3d object
class CObjectSector {
public:
  CObjectSector(CObjectSector_* p, bool owner = false);
  CObjectSector();
  CObjectSector(CObjectSector& o);
  ~CObjectSector();
  CObjectSector& operator=(CObjectSector& o);

  ULONG osc_ulFlags(INDEX i) const;
  ULONG& osc_ulFlags(INDEX i);

  /* Create a new polygon in given sector. */
  CObjectPolygonPtr CreatePolygon(INDEX ctVertices, INDEX aivVertices[],
    CObjectMaterial& omaMaterial, ULONG ulFlags, BOOL bReverse);
  /* Create a new polygon in given sector. */
  CObjectPolygonPtr CreatePolygon(INDEX ctVertices, CStaticArray_DOUBLE3D& avVertices,
    CObjectMaterial& omaMaterial, ULONG ulFlags, BOOL bReverse);

  inline CObjectSector_* C_Handle() { return mp_handle; }
  inline const CObjectSector_* C_Handle() const { return mp_handle; }
  inline operator CObjectSector_* () { return C_Handle(); }
  inline operator const CObjectSector_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObjectSector_* mp_handle = nullptr;

public:
  CDynamicArray_CObjectVertex osc_aovxVertices;      // vertices
  CDynamicArray_CObjectPlane osc_aoplPlanes;         // planes
  CDynamicArray_CObjectMaterial osc_aomtMaterials;   // material info
  CDynamicArray_CObjectEdge osc_aoedEdges;           // edges
  CDynamicArray_CObjectPolygon osc_aopoPolygons;     // polygons
  ULONG& osc_Tag;                                    // tag for format-specific data
  INDEX& osc_Index;                                  // index for easier conversions
  COLOR& osc_colColor;                               // color of this sector
  COLOR& osc_colAmbient;                             // ambient lightning of this sector
  CTString osc_strName;                              // name of the sector
};

// a local class that holds extended edge information for finding collinear edges.
class CEdgeEx {
public:
  CEdgeEx(CEdgeEx_* p, bool owner = false);
  CEdgeEx();
  CEdgeEx(const CEdgeEx& o);
  ~CEdgeEx();
  CEdgeEx& operator=(const CEdgeEx& o);

  inline CEdgeEx_* C_Handle() { return mp_handle; }
  inline const CEdgeEx_* C_Handle() const { return mp_handle; }
  inline operator CEdgeEx_* () { return C_Handle(); }
  inline operator const CEdgeEx_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CEdgeEx_* mp_handle = nullptr;

public:
  CObjectEdge_*& edx_poedEdge;    // the original edge in object
  // constants of the line that the edge is on
  DOUBLE3D edx_vDirection;       // normalized direction vector of the line
  DOUBLE3D edx_vReferencePoint;  // reference point on the line
  BOOL& edx_bReverse;            // set if the edge direction is opposite to the line direction
};

DECLARE_CDynamicArrayNoClear(CObjectSector)

/*
 * A mathematical format of 3d object used for importing/exporting, CSG etc.
 */
class CObject3D {
public:
  CObject3D(CObject3D_* p, bool owner = false);
  CObject3D();
  CObject3D(CObject3D& o);
  ~CObject3D();
  CObject3D& operator=(CObject3D& o);

  /* Remove sectors with no polygons. */
  void RemoveEmptySectors();
  /* Create indices of all sectors (doesn't create vertex indices etc.). */
  void CreateSectorIndices();
  /* Clear all arrays. */
  void Clear();
  /* Remove unused and replicated elements. */
  void Optimize();
  /* See if all polygons in object 3D are valid (planar). */
  BOOL ArePolygonsPlanar();
  /* Create BSP trees for all sectors. */
  void CreateSectorBSPs();
  /* Project the whole object into some other space. */
  void Project(CSimpleProjection3D_DOUBLE& pr);
  /* Turn all sectors in object inside-out. (not recommended for multi sector objects) */
  void Inverse();
  /* Recalculate all planes from vertices. (used when stretching vertices) */
  void RecalculatePlanes();

  /**** CSG operations -- they all destroy both operands! ****/
  /* Add rooms. */
  void CSGAddRooms(CObject3D& obA, CObject3D& obB);
  /* Add material from object B to object A. (B should have only one
    open sector and no closed sectors) */
  void CSGAddMaterial(CObject3D& obA, CObject3D& obB);
  void CSGAddMaterialReverse(CObject3D& obA, CObject3D& obB);
  /* Remove material of object B from object A. (B should have only one
    open sector and no closed sectors) */
  void CSGRemoveMaterial(CObject3D& obA, CObject3D& obB);
  /* Split sectors of object A using object B. (B should have only one
    closed sector and no open sectors) */
  void CSGSplitSectors(CObject3D& obA, CObject3D& obB);
  /* Join sectors of object A with sectors of object B. (both A and B should
    have only one sector) */
  void CSGJoinSectors(CObject3D& obA, CObject3D& obB);
  /* Split polygons of object A with sectors of object B. (both A and B should
    have only one sector) */
  void CSGSplitPolygons(CObject3D& obA, CObject3D& obB);
  /* Turn all portals to walls. */
  void TurnPortalsToWalls();

  /* Find bounding box of the object. */
  void GetBoundingBox(DOUBLEaabbox3D& boxObject);

  /* Dump the object 3D to debug window. */
  void DebugDump();

  inline CObject3D_* C_Handle() { return mp_handle; }
  inline const CObject3D_* C_Handle() const { return mp_handle; }
  inline operator CObject3D_* () { return C_Handle(); }
  inline operator const CObject3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  CObject3D_* mp_handle = nullptr;

public:
  CDynamicArray_CObjectSector ob_aoscSectors;         // sectors
};

#include "Object3D.inl"
