#pragma once
#include "../Base/Types.h"
#include "Vector.h"
#include <SeriousEngineCAPI/Math/AABBox.h>

class INDEXaabbox2D
{
public:
  INDEXaabbox2D(INDEXaabbox2D_* p, bool owner = false);
  INDEXaabbox2D();
  INDEXaabbox2D(const INDEX2D& vPoint);
  INDEXaabbox2D(const INDEX2D& vPoint, const INDEX radius);
  INDEXaabbox2D(const INDEX2D& vPoint1, const INDEX2D& vPoint2);
  INDEXaabbox2D(const INDEXaabbox2D& o);
  ~INDEXaabbox2D();

  INDEXaabbox2D& operator=(const INDEXaabbox2D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  /* Bounding box for union. */
  INDEXaabbox2D& operator|=(const INDEXaabbox2D& b);
  /* Bounding box for intersection. */
  INDEXaabbox2D& operator&=(const INDEXaabbox2D& b);
  /* Bounding box for intersection. */
  INDEXaabbox2D operator&(const INDEXaabbox2D& b) const;
  /* Function for moving bounding box. */
  INDEXaabbox2D& operator+=(const INDEX2D& vct);
  INDEXaabbox2D& operator-=(const INDEX2D& vct);
  /* Function for testing equality of bounding boxes. */
  BOOL operator==(const INDEXaabbox2D& box2) const;
  /* Function for testing difference between bounding boxes. */
  BOOL operator!=(const INDEXaabbox2D& box2) const;
  /* Test if the bounding box contains another bounding box. */
  BOOL operator>=(const INDEXaabbox2D& b) const;
  /* Test if the bounding box is contained in another bounding box. */
  BOOL operator<=(const INDEXaabbox2D& b) const;

  /* Get diagonal vector (size of box). */
  const INDEX2D Size() const;
  /* Get center vector (middle of box). */
  const INDEX2D Center() const;
  /* Get minimal vector (lower left of box). */
  const INDEX2D& Min() const;
  /* Get maximal vector (upper right of box). */
  const INDEX2D& Max() const;
  /* Check if empty. */
  BOOL IsEmpty() const;

  /* Check if intersects or touches another bounding box. */
  BOOL HasContactWith(const INDEXaabbox2D& b) const;
  BOOL HasContactWith(const INDEXaabbox2D& b, INDEX tEpsilon) const;
  /* Check if intersects or touches a sphere. */
  BOOL TouchesSphere(
    const INDEX2D& vSphereCenter, INDEX fSphereRadius) const;

  // expand the bounding box by given size
  void Expand(INDEX tEpsilon);
  // expand the bounding box by given factor of its size along each axis
  void ExpandByFactor(INDEX tFactor);
  // stretch the bounding box by a given sizing factor
  void StretchByFactor(INDEX tSizing);
  // stretch the bounding box by a given sizing vector
  void StretchByVector(INDEX2D vSizing);

  inline INDEXaabbox2D_* C_Handle() { return mp_handle; }
  inline const INDEXaabbox2D_* C_Handle() const { return mp_handle; }
  inline operator INDEXaabbox2D_* () { return C_Handle(); }
  inline operator const INDEXaabbox2D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  INDEXaabbox2D_* mp_handle = nullptr;

public:
  INDEX2D minvect;
  INDEX2D maxvect;
};

class FLOATaabbox2D
{
public:
  FLOATaabbox2D(FLOATaabbox2D_* p, bool owner = false);
  FLOATaabbox2D();
  FLOATaabbox2D(const FLOAT2D& vPoint);
  FLOATaabbox2D(const FLOAT2D& vPoint, const FLOAT radius);
  FLOATaabbox2D(const FLOAT2D& vPoint1, const FLOAT2D& vPoint2);
  FLOATaabbox2D(const FLOATaabbox2D& o);
  ~FLOATaabbox2D();

  FLOATaabbox2D& operator=(const FLOATaabbox2D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  /* Bounding box for union. */
  FLOATaabbox2D& operator|=(const FLOATaabbox2D& b);
  /* Bounding box for intersection. */
  FLOATaabbox2D& operator&=(const FLOATaabbox2D& b);
  /* Bounding box for intersection. */
  FLOATaabbox2D operator&(const FLOATaabbox2D& b) const;
  /* Function for moving bounding box. */
  FLOATaabbox2D& operator+=(const FLOAT2D& vct);
  FLOATaabbox2D& operator-=(const FLOAT2D& vct);
  /* Function for testing equality of bounding boxes. */
  BOOL operator==(const FLOATaabbox2D& box2) const;
  /* Function for testing difference between bounding boxes. */
  BOOL operator!=(const FLOATaabbox2D& box2) const;
  /* Test if the bounding box contains another bounding box. */
  BOOL operator>=(const FLOATaabbox2D& b) const;
  /* Test if the bounding box is contained in another bounding box. */
  BOOL operator<=(const FLOATaabbox2D& b) const;

  /* Get diagonal vector (size of box). */
  const FLOAT2D Size() const;
  /* Get center vector (middle of box). */
  const FLOAT2D Center() const;
  /* Get minimal vector (lower left of box). */
  const FLOAT2D& Min() const;
  /* Get maximal vector (upper right of box). */
  const FLOAT2D& Max() const;
  /* Check if empty. */
  BOOL IsEmpty() const;

  /* Check if intersects or touches another bounding box. */
  BOOL HasContactWith(const FLOATaabbox2D& b) const;
  BOOL HasContactWith(const FLOATaabbox2D& b, FLOAT tEpsilon) const;
  /* Check if intersects or touches a sphere. */
  BOOL TouchesSphere(
    const FLOAT2D& vSphereCenter, FLOAT fSphereRadius) const;

  // expand the bounding box by given size
  void Expand(FLOAT tEpsilon);
  // expand the bounding box by given factor of its size along each axis
  void ExpandByFactor(FLOAT tFactor);
  // stretch the bounding box by a given sizing factor
  void StretchByFactor(FLOAT tSizing);
  // stretch the bounding box by a given sizing vector
  void StretchByVector(FLOAT2D vSizing);

  inline FLOATaabbox2D_* C_Handle() { return mp_handle; }
  inline const FLOATaabbox2D_* C_Handle() const { return mp_handle; }
  inline operator FLOATaabbox2D_* () { return C_Handle(); }
  inline operator const FLOATaabbox2D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  FLOATaabbox2D_* mp_handle = nullptr;

public:
  FLOAT2D minvect;
  FLOAT2D maxvect;
};

class FLOATaabbox3D
{
public:
  FLOATaabbox3D(FLOATaabbox3D_* p, bool owner = false);
  FLOATaabbox3D();
  FLOATaabbox3D(const FLOAT3D& vPoint);
  FLOATaabbox3D(const FLOAT3D& vPoint, const FLOAT radius);
  FLOATaabbox3D(const FLOAT3D& vPoint1, const FLOAT3D& vPoint2);
  FLOATaabbox3D(const FLOATaabbox3D& o);
  ~FLOATaabbox3D();

  FLOATaabbox3D& operator=(const FLOATaabbox3D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  /* Bounding box for union. */
  FLOATaabbox3D& operator|=(const FLOATaabbox3D& b);
  /* Bounding box for intersection. */
  FLOATaabbox3D& operator&=(const FLOATaabbox3D& b);
  /* Bounding box for intersection. */
  FLOATaabbox3D operator&(const FLOATaabbox3D& b) const;
  /* Function for moving bounding box. */
  FLOATaabbox3D& operator+=(const FLOAT3D& vct);
  FLOATaabbox3D& operator-=(const FLOAT3D& vct);
  /* Function for testing equality of bounding boxes. */
  BOOL operator==(const FLOATaabbox3D& box2) const;
  /* Function for testing difference between bounding boxes. */
  BOOL operator!=(const FLOATaabbox3D& box2) const;
  /* Test if the bounding box contains another bounding box. */
  BOOL operator>=(const FLOATaabbox3D& b) const;
  /* Test if the bounding box is contained in another bounding box. */
  BOOL operator<=(const FLOATaabbox3D& b) const;

  /* Get diagonal vector (size of box). */
  const FLOAT3D Size() const;
  /* Get center vector (middle of box). */
  const FLOAT3D Center() const;
  /* Get minimal vector (lower left of box). */
  const FLOAT3D& Min() const;
  /* Get maximal vector (upper right of box). */
  const FLOAT3D& Max() const;
  /* Check if empty. */
  BOOL IsEmpty() const;

  /* Check if intersects or touches another bounding box. */
  BOOL HasContactWith(const FLOATaabbox3D& b) const;
  BOOL HasContactWith(const FLOATaabbox3D& b, FLOAT tEpsilon) const;
  /* Check if intersects or touches a sphere. */
  BOOL TouchesSphere(
    const FLOAT3D& vSphereCenter, FLOAT fSphereRadius) const;

  // expand the bounding box by given size
  void Expand(FLOAT tEpsilon);
  // expand the bounding box by given factor of its size along each axis
  void ExpandByFactor(FLOAT tFactor);
  // stretch the bounding box by a given sizing factor
  void StretchByFactor(FLOAT tSizing);
  // stretch the bounding box by a given sizing vector
  void StretchByVector(FLOAT3D vSizing);

  inline FLOATaabbox3D_* C_Handle() { return mp_handle; }
  inline const FLOATaabbox3D_* C_Handle() const { return mp_handle; }
  inline operator FLOATaabbox3D_* () { return C_Handle(); }
  inline operator const FLOATaabbox3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  FLOATaabbox3D_* mp_handle = nullptr;

public:
  FLOAT3D minvect;
  FLOAT3D maxvect;
};

class DOUBLEaabbox2D
{
public:
  DOUBLEaabbox2D(DOUBLEaabbox2D_* p, bool owner = false);
  DOUBLEaabbox2D();
  DOUBLEaabbox2D(const DOUBLE2D& vPoint);
  DOUBLEaabbox2D(const DOUBLE2D& vPoint, const DOUBLE radius);
  DOUBLEaabbox2D(const DOUBLE2D& vPoint1, const DOUBLE2D& vPoint2);
  DOUBLEaabbox2D(const DOUBLEaabbox2D& o);
  ~DOUBLEaabbox2D();

  DOUBLEaabbox2D& operator=(const DOUBLEaabbox2D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  /* Bounding box for union. */
  DOUBLEaabbox2D& operator|=(const DOUBLEaabbox2D& b);
  /* Bounding box for intersection. */
  DOUBLEaabbox2D& operator&=(const DOUBLEaabbox2D& b);
  /* Bounding box for intersection. */
  DOUBLEaabbox2D operator&(const DOUBLEaabbox2D& b) const;
  /* Function for moving bounding box. */
  DOUBLEaabbox2D& operator+=(const DOUBLE2D& vct);
  DOUBLEaabbox2D& operator-=(const DOUBLE2D& vct);
  /* Function for testing equality of bounding boxes. */
  BOOL operator==(const DOUBLEaabbox2D& box2) const;
  /* Function for testing difference between bounding boxes. */
  BOOL operator!=(const DOUBLEaabbox2D& box2) const;
  /* Test if the bounding box contains another bounding box. */
  BOOL operator>=(const DOUBLEaabbox2D& b) const;
  /* Test if the bounding box is contained in another bounding box. */
  BOOL operator<=(const DOUBLEaabbox2D& b) const;

  /* Get diagonal vector (size of box). */
  const DOUBLE2D Size() const;
  /* Get center vector (middle of box). */
  const DOUBLE2D Center() const;
  /* Get minimal vector (lower left of box). */
  const DOUBLE2D& Min() const;
  /* Get maximal vector (upper right of box). */
  const DOUBLE2D& Max() const;
  /* Check if empty. */
  BOOL IsEmpty() const;

  /* Check if intersects or touches another bounding box. */
  BOOL HasContactWith(const DOUBLEaabbox2D& b) const;
  BOOL HasContactWith(const DOUBLEaabbox2D& b, DOUBLE tEpsilon) const;
  /* Check if intersects or touches a sphere. */
  BOOL TouchesSphere(
    const DOUBLE2D& vSphereCenter, DOUBLE fSphereRadius) const;

  // expand the bounding box by given size
  void Expand(DOUBLE tEpsilon);
  // expand the bounding box by given factor of its size along each axis
  void ExpandByFactor(DOUBLE tFactor);
  // stretch the bounding box by a given sizing factor
  void StretchByFactor(DOUBLE tSizing);
  // stretch the bounding box by a given sizing vector
  void StretchByVector(DOUBLE2D vSizing);

  inline DOUBLEaabbox2D_* C_Handle() { return mp_handle; }
  inline const DOUBLEaabbox2D_* C_Handle() const { return mp_handle; }
  inline operator DOUBLEaabbox2D_* () { return C_Handle(); }
  inline operator const DOUBLEaabbox2D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  DOUBLEaabbox2D_* mp_handle = nullptr;

public:
  DOUBLE2D minvect;
  DOUBLE2D maxvect;
};

class DOUBLEaabbox3D
{
public:
  DOUBLEaabbox3D(DOUBLEaabbox3D_* p, bool owner = false);
  DOUBLEaabbox3D();
  DOUBLEaabbox3D(const DOUBLE3D& vPoint);
  DOUBLEaabbox3D(const DOUBLE3D& vPoint, const DOUBLE radius);
  DOUBLEaabbox3D(const DOUBLE3D& vPoint1, const DOUBLE3D& vPoint2);
  DOUBLEaabbox3D(const DOUBLEaabbox3D& o);
  ~DOUBLEaabbox3D();

  DOUBLEaabbox3D& operator=(const DOUBLEaabbox3D& o);

  /* Clear to normalized empty bounding box. */
  void SetToNormalizedEmpty();
  /* Bounding box for union. */
  DOUBLEaabbox3D& operator|=(const DOUBLEaabbox3D& b);
  /* Bounding box for intersection. */
  DOUBLEaabbox3D& operator&=(const DOUBLEaabbox3D& b);
  /* Bounding box for intersection. */
  DOUBLEaabbox3D operator&(const DOUBLEaabbox3D& b) const;
  /* Function for moving bounding box. */
  DOUBLEaabbox3D& operator+=(const DOUBLE3D& vct);
  DOUBLEaabbox3D& operator-=(const DOUBLE3D& vct);
  /* Function for testing equality of bounding boxes. */
  BOOL operator==(const DOUBLEaabbox3D& box2) const;
  /* Function for testing difference between bounding boxes. */
  BOOL operator!=(const DOUBLEaabbox3D& box2) const;
  /* Test if the bounding box contains another bounding box. */
  BOOL operator>=(const DOUBLEaabbox3D& b) const;
  /* Test if the bounding box is contained in another bounding box. */
  BOOL operator<=(const DOUBLEaabbox3D& b) const;

  /* Get diagonal vector (size of box). */
  const DOUBLE3D Size() const;
  /* Get center vector (middle of box). */
  const DOUBLE3D Center() const;
  /* Get minimal vector (lower left of box). */
  const DOUBLE3D& Min() const;
  /* Get maximal vector (upper right of box). */
  const DOUBLE3D& Max() const;
  /* Check if empty. */
  BOOL IsEmpty() const;

  /* Check if intersects or touches another bounding box. */
  BOOL HasContactWith(const DOUBLEaabbox3D& b) const;
  BOOL HasContactWith(const DOUBLEaabbox3D& b, DOUBLE tEpsilon) const;
  /* Check if intersects or touches a sphere. */
  BOOL TouchesSphere(
    const DOUBLE3D& vSphereCenter, DOUBLE fSphereRadius) const;

  // expand the bounding box by given size
  void Expand(DOUBLE tEpsilon);
  // expand the bounding box by given factor of its size along each axis
  void ExpandByFactor(DOUBLE tFactor);
  // stretch the bounding box by a given sizing factor
  void StretchByFactor(DOUBLE tSizing);
  // stretch the bounding box by a given sizing vector
  void StretchByVector(DOUBLE3D vSizing);

  inline DOUBLEaabbox3D_* C_Handle() { return mp_handle; }
  inline const DOUBLEaabbox3D_* C_Handle() const { return mp_handle; }
  inline operator DOUBLEaabbox3D_* () { return C_Handle(); }
  inline operator const DOUBLEaabbox3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  DOUBLEaabbox3D_* mp_handle = nullptr;

public:
  DOUBLE3D minvect;
  DOUBLE3D maxvect;
};

// helper functions for converting between FLOAT and DOUBLE aabboxes
DOUBLEaabbox3D FLOATtoDOUBLE(const FLOATaabbox3D& plf);
FLOATaabbox3D DOUBLEtoFLOAT(const DOUBLEaabbox3D& pld);

#include "AABBox.inl"
