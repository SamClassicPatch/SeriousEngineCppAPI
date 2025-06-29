#pragma once

inline INDEXaabbox2D::INDEXaabbox2D(INDEXaabbox2D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , minvect(INDEXaabbox2D_minvect(p), false)
  , maxvect(INDEXaabbox2D_maxvect(p), false)
{
}

inline INDEXaabbox2D::INDEXaabbox2D()
  : m_owner(true)
  , mp_handle(INDEXaabbox2D_new())
  , minvect(INDEXaabbox2D_minvect(mp_handle), false)
  , maxvect(INDEXaabbox2D_maxvect(mp_handle), false)
{
}

inline INDEXaabbox2D::INDEXaabbox2D(const INDEX2D& vPoint)
  : m_owner(true)
  , mp_handle(INDEXaabbox2D_new_p(vPoint))
  , minvect(INDEXaabbox2D_minvect(mp_handle), false)
  , maxvect(INDEXaabbox2D_maxvect(mp_handle), false)
{
}

inline INDEXaabbox2D::INDEXaabbox2D(const INDEX2D& vPoint, const INDEX radius)
  : m_owner(true)
  , mp_handle(INDEXaabbox2D_new_pr(vPoint, radius))
  , minvect(INDEXaabbox2D_minvect(mp_handle), false)
  , maxvect(INDEXaabbox2D_maxvect(mp_handle), false)
{
}

inline INDEXaabbox2D::INDEXaabbox2D(const INDEX2D& vPoint1, const INDEX2D& vPoint2)
  : m_owner(true)
  , mp_handle(INDEXaabbox2D_new_pp(vPoint1, vPoint2))
  , minvect(INDEXaabbox2D_minvect(mp_handle), false)
  , maxvect(INDEXaabbox2D_maxvect(mp_handle), false)
{
}

inline INDEXaabbox2D::INDEXaabbox2D(const INDEXaabbox2D& o)
  : m_owner(true)
  , mp_handle(INDEXaabbox2D_clone(o))
  , minvect(INDEXaabbox2D_minvect(mp_handle), false)
  , maxvect(INDEXaabbox2D_maxvect(mp_handle), false)
{
}

inline INDEXaabbox2D::~INDEXaabbox2D()
{
  if (m_owner)
    INDEXaabbox2D_delete(mp_handle);
}

inline INDEXaabbox2D& INDEXaabbox2D::operator=(const INDEXaabbox2D& o)
{
  INDEXaabbox2D_copy(mp_handle, o);
}

inline void INDEXaabbox2D::SetToNormalizedEmpty()
{
  INDEXaabbox2D_SetToNormalizedEmpty(mp_handle);
}

inline INDEXaabbox2D& INDEXaabbox2D::operator|=(const INDEXaabbox2D& b)
{
  INDEXaabbox2D_UniteInplace(mp_handle, b);
  return *this;
}

inline INDEXaabbox2D& INDEXaabbox2D::operator&=(const INDEXaabbox2D& b)
{
  INDEXaabbox2D_IntersectInplace(mp_handle, b);
  return *this;
}

__forceinline INDEXaabbox2D INDEXaabbox2D::operator&(const INDEXaabbox2D& b) const
{
  return INDEXaabbox2D(INDEXaabbox2D_Intersect(mp_handle, b), true);
}

inline INDEXaabbox2D& INDEXaabbox2D::operator+=(const INDEX2D& vct)
{
  INDEXaabbox2D_MoveAdd(mp_handle, vct);
  return *this;
}

inline INDEXaabbox2D& INDEXaabbox2D::operator-=(const INDEX2D& vct)
{
  INDEXaabbox2D_MoveSub(mp_handle, vct);
  return *this;
}

inline BOOL INDEXaabbox2D::operator==(const INDEXaabbox2D& box2) const
{
  return INDEXaabbox2D_equal(mp_handle, box2);
}

inline BOOL INDEXaabbox2D::operator!=(const INDEXaabbox2D& box2) const
{
  return INDEXaabbox2D_notequal(mp_handle, box2);
}

inline BOOL INDEXaabbox2D::operator>=(const INDEXaabbox2D& b) const
{
  return INDEXaabbox2D_Contains(mp_handle, b);
}

inline BOOL INDEXaabbox2D::operator<=(const INDEXaabbox2D& b) const
{
  return INDEXaabbox2D_Contained(mp_handle, b);
}

__forceinline const INDEX2D INDEXaabbox2D::Size() const
{
  return INDEX2D(INDEXaabbox2D_Size(mp_handle), true);
}

__forceinline const INDEX2D INDEXaabbox2D::Center() const
{
  return INDEX2D(INDEXaabbox2D_Center(mp_handle), true);
}

inline const INDEX2D& INDEXaabbox2D::Min() const
{
  return minvect;
}

inline const INDEX2D& INDEXaabbox2D::Max() const
{
  return maxvect;
}

inline BOOL INDEXaabbox2D::IsEmpty() const
{
  return INDEXaabbox2D_IsEmpty(mp_handle);
}

inline BOOL INDEXaabbox2D::HasContactWith(const INDEXaabbox2D& b) const
{
  return INDEXaabbox2D_HasContactWith(mp_handle, b);
}

inline BOOL INDEXaabbox2D::HasContactWith(const INDEXaabbox2D& b, INDEX tEpsilon) const
{
  return INDEXaabbox2D_HasContactWith_fuzzy(mp_handle, b, tEpsilon);
}

inline BOOL INDEXaabbox2D::TouchesSphere(const INDEX2D& vSphereCenter, INDEX fSphereRadius) const
{
  return INDEXaabbox2D_TouchesSphere(mp_handle, vSphereCenter, fSphereRadius);
}

inline void INDEXaabbox2D::Expand(INDEX tEpsilon)
{
  INDEXaabbox2D_Expand(mp_handle, tEpsilon);
}

inline void INDEXaabbox2D::ExpandByFactor(INDEX tFactor)
{
  INDEXaabbox2D_ExpandByFactor(mp_handle, tFactor);
}

inline void INDEXaabbox2D::StretchByFactor(INDEX tSizing)
{
  INDEXaabbox2D_StretchByFactor(mp_handle, tSizing);
}

inline void INDEXaabbox2D::StretchByVector(INDEX2D vSizing)
{
  INDEXaabbox2D_StretchByVector(mp_handle, vSizing);
}

inline FLOATaabbox2D::FLOATaabbox2D(FLOATaabbox2D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , minvect(FLOATaabbox2D_minvect(p), false)
  , maxvect(FLOATaabbox2D_maxvect(p), false)
{
}

inline FLOATaabbox2D::FLOATaabbox2D()
  : m_owner(true)
  , mp_handle(FLOATaabbox2D_new())
  , minvect(FLOATaabbox2D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox2D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox2D::FLOATaabbox2D(const FLOAT2D& vPoint)
  : m_owner(true)
  , mp_handle(FLOATaabbox2D_new_p(vPoint))
  , minvect(FLOATaabbox2D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox2D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox2D::FLOATaabbox2D(const FLOAT2D& vPoint, const FLOAT radius)
  : m_owner(true)
  , mp_handle(FLOATaabbox2D_new_pr(vPoint, radius))
  , minvect(FLOATaabbox2D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox2D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox2D::FLOATaabbox2D(const FLOAT2D& vPoint1, const FLOAT2D& vPoint2)
  : m_owner(true)
  , mp_handle(FLOATaabbox2D_new_pp(vPoint1, vPoint2))
  , minvect(FLOATaabbox2D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox2D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox2D::FLOATaabbox2D(const FLOATaabbox2D& o)
  : m_owner(true)
  , mp_handle(FLOATaabbox2D_clone(o))
  , minvect(FLOATaabbox2D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox2D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox2D::~FLOATaabbox2D()
{
  if (m_owner)
    FLOATaabbox2D_delete(mp_handle);
}

inline FLOATaabbox2D& FLOATaabbox2D::operator=(const FLOATaabbox2D& o)
{
  FLOATaabbox2D_copy(mp_handle, o);
}

inline void FLOATaabbox2D::SetToNormalizedEmpty()
{
  FLOATaabbox2D_SetToNormalizedEmpty(mp_handle);
}

inline FLOATaabbox2D& FLOATaabbox2D::operator|=(const FLOATaabbox2D& b)
{
  FLOATaabbox2D_UniteInplace(mp_handle, b);
  return *this;
}

inline FLOATaabbox2D& FLOATaabbox2D::operator&=(const FLOATaabbox2D& b)
{
  FLOATaabbox2D_IntersectInplace(mp_handle, b);
  return *this;
}

__forceinline FLOATaabbox2D FLOATaabbox2D::operator&(const FLOATaabbox2D& b) const
{
  return FLOATaabbox2D(FLOATaabbox2D_Intersect(mp_handle, b), true);
}

inline FLOATaabbox2D& FLOATaabbox2D::operator+=(const FLOAT2D& vct)
{
  FLOATaabbox2D_MoveAdd(mp_handle, vct);
  return *this;
}

inline FLOATaabbox2D& FLOATaabbox2D::operator-=(const FLOAT2D& vct)
{
  FLOATaabbox2D_MoveSub(mp_handle, vct);
  return *this;
}

inline BOOL FLOATaabbox2D::operator==(const FLOATaabbox2D& box2) const
{
  return FLOATaabbox2D_equal(mp_handle, box2);
}

inline BOOL FLOATaabbox2D::operator!=(const FLOATaabbox2D& box2) const
{
  return FLOATaabbox2D_notequal(mp_handle, box2);
}

inline BOOL FLOATaabbox2D::operator>=(const FLOATaabbox2D& b) const
{
  return FLOATaabbox2D_Contains(mp_handle, b);
}

inline BOOL FLOATaabbox2D::operator<=(const FLOATaabbox2D& b) const
{
  return FLOATaabbox2D_Contained(mp_handle, b);
}

__forceinline const FLOAT2D FLOATaabbox2D::Size() const
{
  return FLOAT2D(FLOATaabbox2D_Size(mp_handle), true);
}

__forceinline const FLOAT2D FLOATaabbox2D::Center() const
{
  return FLOAT2D(FLOATaabbox2D_Center(mp_handle), true);
}

inline const FLOAT2D& FLOATaabbox2D::Min() const
{
  return minvect;
}

inline const FLOAT2D& FLOATaabbox2D::Max() const
{
  return maxvect;
}

inline BOOL FLOATaabbox2D::IsEmpty() const
{
  return FLOATaabbox2D_IsEmpty(mp_handle);
}

inline BOOL FLOATaabbox2D::HasContactWith(const FLOATaabbox2D& b) const
{
  return FLOATaabbox2D_HasContactWith(mp_handle, b);
}

inline BOOL FLOATaabbox2D::HasContactWith(const FLOATaabbox2D& b, FLOAT tEpsilon) const
{
  return FLOATaabbox2D_HasContactWith_fuzzy(mp_handle, b, tEpsilon);
}

inline BOOL FLOATaabbox2D::TouchesSphere(const FLOAT2D& vSphereCenter, FLOAT fSphereRadius) const
{
  return FLOATaabbox2D_TouchesSphere(mp_handle, vSphereCenter, fSphereRadius);
}

inline void FLOATaabbox2D::Expand(FLOAT tEpsilon)
{
  FLOATaabbox2D_Expand(mp_handle, tEpsilon);
}

inline void FLOATaabbox2D::ExpandByFactor(FLOAT tFactor)
{
  FLOATaabbox2D_ExpandByFactor(mp_handle, tFactor);
}

inline void FLOATaabbox2D::StretchByFactor(FLOAT tSizing)
{
  FLOATaabbox2D_StretchByFactor(mp_handle, tSizing);
}

inline void FLOATaabbox2D::StretchByVector(FLOAT2D vSizing)
{
  FLOATaabbox2D_StretchByVector(mp_handle, vSizing);
}

inline FLOATaabbox3D::FLOATaabbox3D(FLOATaabbox3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , minvect(FLOATaabbox3D_minvect(p), false)
  , maxvect(FLOATaabbox3D_maxvect(p), false)
{
}

inline FLOATaabbox3D::FLOATaabbox3D()
  : m_owner(true)
  , mp_handle(FLOATaabbox3D_new())
  , minvect(FLOATaabbox3D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox3D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox3D::FLOATaabbox3D(const FLOAT3D& vPoint)
  : m_owner(true)
  , mp_handle(FLOATaabbox3D_new_p(vPoint))
  , minvect(FLOATaabbox3D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox3D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox3D::FLOATaabbox3D(const FLOAT3D& vPoint, const FLOAT radius)
  : m_owner(true)
  , mp_handle(FLOATaabbox3D_new_pr(vPoint, radius))
  , minvect(FLOATaabbox3D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox3D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox3D::FLOATaabbox3D(const FLOAT3D& vPoint1, const FLOAT3D& vPoint2)
  : m_owner(true)
  , mp_handle(FLOATaabbox3D_new_pp(vPoint1, vPoint2))
  , minvect(FLOATaabbox3D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox3D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox3D::FLOATaabbox3D(const FLOATaabbox3D& o)
  : m_owner(true)
  , mp_handle(FLOATaabbox3D_clone(o))
  , minvect(FLOATaabbox3D_minvect(mp_handle), false)
  , maxvect(FLOATaabbox3D_maxvect(mp_handle), false)
{
}

inline FLOATaabbox3D::~FLOATaabbox3D()
{
  if (m_owner)
    FLOATaabbox3D_delete(mp_handle);
}

inline FLOATaabbox3D& FLOATaabbox3D::operator=(const FLOATaabbox3D& o)
{
  FLOATaabbox3D_copy(mp_handle, o);
}

inline void FLOATaabbox3D::SetToNormalizedEmpty()
{
  FLOATaabbox3D_SetToNormalizedEmpty(mp_handle);
}

inline FLOATaabbox3D& FLOATaabbox3D::operator|=(const FLOATaabbox3D& b)
{
  FLOATaabbox3D_UniteInplace(mp_handle, b);
  return *this;
}

inline FLOATaabbox3D& FLOATaabbox3D::operator&=(const FLOATaabbox3D& b)
{
  FLOATaabbox3D_IntersectInplace(mp_handle, b);
  return *this;
}

__forceinline FLOATaabbox3D FLOATaabbox3D::operator&(const FLOATaabbox3D& b) const
{
  return FLOATaabbox3D(FLOATaabbox3D_Intersect(mp_handle, b), true);
}

inline FLOATaabbox3D& FLOATaabbox3D::operator+=(const FLOAT3D& vct)
{
  FLOATaabbox3D_MoveAdd(mp_handle, vct);
  return *this;
}

inline FLOATaabbox3D& FLOATaabbox3D::operator-=(const FLOAT3D& vct)
{
  FLOATaabbox3D_MoveSub(mp_handle, vct);
  return *this;
}

inline BOOL FLOATaabbox3D::operator==(const FLOATaabbox3D& box2) const
{
  return FLOATaabbox3D_equal(mp_handle, box2);
}

inline BOOL FLOATaabbox3D::operator!=(const FLOATaabbox3D& box2) const
{
  return FLOATaabbox3D_notequal(mp_handle, box2);
}

inline BOOL FLOATaabbox3D::operator>=(const FLOATaabbox3D& b) const
{
  return FLOATaabbox3D_Contains(mp_handle, b);
}

inline BOOL FLOATaabbox3D::operator<=(const FLOATaabbox3D& b) const
{
  return FLOATaabbox3D_Contained(mp_handle, b);
}

__forceinline const FLOAT3D FLOATaabbox3D::Size() const
{
  return FLOAT3D(FLOATaabbox3D_Size(mp_handle), true);
}

__forceinline const FLOAT3D FLOATaabbox3D::Center() const
{
  return FLOAT3D(FLOATaabbox3D_Center(mp_handle), true);
}

inline const FLOAT3D& FLOATaabbox3D::Min() const
{
  return minvect;
}

inline const FLOAT3D& FLOATaabbox3D::Max() const
{
  return maxvect;
}

inline BOOL FLOATaabbox3D::IsEmpty() const
{
  return FLOATaabbox3D_IsEmpty(mp_handle);
}

inline BOOL FLOATaabbox3D::HasContactWith(const FLOATaabbox3D& b) const
{
  return FLOATaabbox3D_HasContactWith(mp_handle, b);
}

inline BOOL FLOATaabbox3D::HasContactWith(const FLOATaabbox3D& b, FLOAT tEpsilon) const
{
  return FLOATaabbox3D_HasContactWith_fuzzy(mp_handle, b, tEpsilon);
}

inline BOOL FLOATaabbox3D::TouchesSphere(const FLOAT3D& vSphereCenter, FLOAT fSphereRadius) const
{
  return FLOATaabbox3D_TouchesSphere(mp_handle, vSphereCenter, fSphereRadius);
}

inline void FLOATaabbox3D::Expand(FLOAT tEpsilon)
{
  FLOATaabbox3D_Expand(mp_handle, tEpsilon);
}

inline void FLOATaabbox3D::ExpandByFactor(FLOAT tFactor)
{
  FLOATaabbox3D_ExpandByFactor(mp_handle, tFactor);
}

inline void FLOATaabbox3D::StretchByFactor(FLOAT tSizing)
{
  FLOATaabbox3D_StretchByFactor(mp_handle, tSizing);
}

inline void FLOATaabbox3D::StretchByVector(FLOAT3D vSizing)
{
  FLOATaabbox3D_StretchByVector(mp_handle, vSizing);
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D(DOUBLEaabbox2D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , minvect(DOUBLEaabbox2D_minvect(p), false)
  , maxvect(DOUBLEaabbox2D_maxvect(p), false)
{
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D()
  : m_owner(true)
  , mp_handle(DOUBLEaabbox2D_new())
  , minvect(DOUBLEaabbox2D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox2D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D(const DOUBLE2D& vPoint)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox2D_new_p(vPoint))
  , minvect(DOUBLEaabbox2D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox2D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D(const DOUBLE2D& vPoint, const DOUBLE radius)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox2D_new_pr(vPoint, radius))
  , minvect(DOUBLEaabbox2D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox2D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D(const DOUBLE2D& vPoint1, const DOUBLE2D& vPoint2)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox2D_new_pp(vPoint1, vPoint2))
  , minvect(DOUBLEaabbox2D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox2D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox2D::DOUBLEaabbox2D(const DOUBLEaabbox2D& o)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox2D_clone(o))
  , minvect(DOUBLEaabbox2D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox2D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox2D::~DOUBLEaabbox2D()
{
  if (m_owner)
    DOUBLEaabbox2D_delete(mp_handle);
}

inline DOUBLEaabbox2D& DOUBLEaabbox2D::operator=(const DOUBLEaabbox2D& o)
{
  DOUBLEaabbox2D_copy(mp_handle, o);
}

inline void DOUBLEaabbox2D::SetToNormalizedEmpty()
{
  DOUBLEaabbox2D_SetToNormalizedEmpty(mp_handle);
}

inline DOUBLEaabbox2D& DOUBLEaabbox2D::operator|=(const DOUBLEaabbox2D& b)
{
  DOUBLEaabbox2D_UniteInplace(mp_handle, b);
  return *this;
}

inline DOUBLEaabbox2D& DOUBLEaabbox2D::operator&=(const DOUBLEaabbox2D& b)
{
  DOUBLEaabbox2D_IntersectInplace(mp_handle, b);
  return *this;
}

__forceinline DOUBLEaabbox2D DOUBLEaabbox2D::operator&(const DOUBLEaabbox2D& b) const
{
  return DOUBLEaabbox2D(DOUBLEaabbox2D_Intersect(mp_handle, b), true);
}

inline DOUBLEaabbox2D& DOUBLEaabbox2D::operator+=(const DOUBLE2D& vct)
{
  DOUBLEaabbox2D_MoveAdd(mp_handle, vct);
  return *this;
}

inline DOUBLEaabbox2D& DOUBLEaabbox2D::operator-=(const DOUBLE2D& vct)
{
  DOUBLEaabbox2D_MoveSub(mp_handle, vct);
  return *this;
}

inline BOOL DOUBLEaabbox2D::operator==(const DOUBLEaabbox2D& box2) const
{
  return DOUBLEaabbox2D_equal(mp_handle, box2);
}

inline BOOL DOUBLEaabbox2D::operator!=(const DOUBLEaabbox2D& box2) const
{
  return DOUBLEaabbox2D_notequal(mp_handle, box2);
}

inline BOOL DOUBLEaabbox2D::operator>=(const DOUBLEaabbox2D& b) const
{
  return DOUBLEaabbox2D_Contains(mp_handle, b);
}

inline BOOL DOUBLEaabbox2D::operator<=(const DOUBLEaabbox2D& b) const
{
  return DOUBLEaabbox2D_Contained(mp_handle, b);
}

__forceinline const DOUBLE2D DOUBLEaabbox2D::Size() const
{
  return DOUBLE2D(DOUBLEaabbox2D_Size(mp_handle), true);
}

__forceinline const DOUBLE2D DOUBLEaabbox2D::Center() const
{
  return DOUBLE2D(DOUBLEaabbox2D_Center(mp_handle), true);
}

inline const DOUBLE2D& DOUBLEaabbox2D::Min() const
{
  return minvect;
}

inline const DOUBLE2D& DOUBLEaabbox2D::Max() const
{
  return maxvect;
}

inline BOOL DOUBLEaabbox2D::IsEmpty() const
{
  return DOUBLEaabbox2D_IsEmpty(mp_handle);
}

inline BOOL DOUBLEaabbox2D::HasContactWith(const DOUBLEaabbox2D& b) const
{
  return DOUBLEaabbox2D_HasContactWith(mp_handle, b);
}

inline BOOL DOUBLEaabbox2D::HasContactWith(const DOUBLEaabbox2D& b, DOUBLE tEpsilon) const
{
  return DOUBLEaabbox2D_HasContactWith_fuzzy(mp_handle, b, tEpsilon);
}

inline BOOL DOUBLEaabbox2D::TouchesSphere(const DOUBLE2D& vSphereCenter, DOUBLE fSphereRadius) const
{
  return DOUBLEaabbox2D_TouchesSphere(mp_handle, vSphereCenter, fSphereRadius);
}

inline void DOUBLEaabbox2D::Expand(DOUBLE tEpsilon)
{
  DOUBLEaabbox2D_Expand(mp_handle, tEpsilon);
}

inline void DOUBLEaabbox2D::ExpandByFactor(DOUBLE tFactor)
{
  DOUBLEaabbox2D_ExpandByFactor(mp_handle, tFactor);
}

inline void DOUBLEaabbox2D::StretchByFactor(DOUBLE tSizing)
{
  DOUBLEaabbox2D_StretchByFactor(mp_handle, tSizing);
}

inline void DOUBLEaabbox2D::StretchByVector(DOUBLE2D vSizing)
{
  DOUBLEaabbox2D_StretchByVector(mp_handle, vSizing);
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D(DOUBLEaabbox3D_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , minvect(DOUBLEaabbox3D_minvect(p), false)
  , maxvect(DOUBLEaabbox3D_maxvect(p), false)
{
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D()
  : m_owner(true)
  , mp_handle(DOUBLEaabbox3D_new())
  , minvect(DOUBLEaabbox3D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox3D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D(const DOUBLE3D& vPoint)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox3D_new_p(vPoint))
  , minvect(DOUBLEaabbox3D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox3D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D(const DOUBLE3D& vPoint, const DOUBLE radius)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox3D_new_pr(vPoint, radius))
  , minvect(DOUBLEaabbox3D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox3D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D(const DOUBLE3D& vPoint1, const DOUBLE3D& vPoint2)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox3D_new_pp(vPoint1, vPoint2))
  , minvect(DOUBLEaabbox3D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox3D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox3D::DOUBLEaabbox3D(const DOUBLEaabbox3D& o)
  : m_owner(true)
  , mp_handle(DOUBLEaabbox3D_clone(o))
  , minvect(DOUBLEaabbox3D_minvect(mp_handle), false)
  , maxvect(DOUBLEaabbox3D_maxvect(mp_handle), false)
{
}

inline DOUBLEaabbox3D::~DOUBLEaabbox3D()
{
  if (m_owner)
    DOUBLEaabbox3D_delete(mp_handle);
}

inline DOUBLEaabbox3D& DOUBLEaabbox3D::operator=(const DOUBLEaabbox3D& o)
{
  DOUBLEaabbox3D_copy(mp_handle, o);
}

inline void DOUBLEaabbox3D::SetToNormalizedEmpty()
{
  DOUBLEaabbox3D_SetToNormalizedEmpty(mp_handle);
}

inline DOUBLEaabbox3D& DOUBLEaabbox3D::operator|=(const DOUBLEaabbox3D& b)
{
  DOUBLEaabbox3D_UniteInplace(mp_handle, b);
  return *this;
}

inline DOUBLEaabbox3D& DOUBLEaabbox3D::operator&=(const DOUBLEaabbox3D& b)
{
  DOUBLEaabbox3D_IntersectInplace(mp_handle, b);
  return *this;
}

__forceinline DOUBLEaabbox3D DOUBLEaabbox3D::operator&(const DOUBLEaabbox3D& b) const
{
  return DOUBLEaabbox3D(DOUBLEaabbox3D_Intersect(mp_handle, b), true);
}

inline DOUBLEaabbox3D& DOUBLEaabbox3D::operator+=(const DOUBLE3D& vct)
{
  DOUBLEaabbox3D_MoveAdd(mp_handle, vct);
  return *this;
}

inline DOUBLEaabbox3D& DOUBLEaabbox3D::operator-=(const DOUBLE3D& vct)
{
  DOUBLEaabbox3D_MoveSub(mp_handle, vct);
  return *this;
}

inline BOOL DOUBLEaabbox3D::operator==(const DOUBLEaabbox3D& box2) const
{
  return DOUBLEaabbox3D_equal(mp_handle, box2);
}

inline BOOL DOUBLEaabbox3D::operator!=(const DOUBLEaabbox3D& box2) const
{
  return DOUBLEaabbox3D_notequal(mp_handle, box2);
}

inline BOOL DOUBLEaabbox3D::operator>=(const DOUBLEaabbox3D& b) const
{
  return DOUBLEaabbox3D_Contains(mp_handle, b);
}

inline BOOL DOUBLEaabbox3D::operator<=(const DOUBLEaabbox3D& b) const
{
  return DOUBLEaabbox3D_Contained(mp_handle, b);
}

__forceinline const DOUBLE3D DOUBLEaabbox3D::Size() const
{
  return DOUBLE3D(DOUBLEaabbox3D_Size(mp_handle), true);
}

__forceinline const DOUBLE3D DOUBLEaabbox3D::Center() const
{
  return DOUBLE3D(DOUBLEaabbox3D_Center(mp_handle), true);
}

inline const DOUBLE3D& DOUBLEaabbox3D::Min() const
{
  return minvect;
}

inline const DOUBLE3D& DOUBLEaabbox3D::Max() const
{
  return maxvect;
}

inline BOOL DOUBLEaabbox3D::IsEmpty() const
{
  return DOUBLEaabbox3D_IsEmpty(mp_handle);
}

inline BOOL DOUBLEaabbox3D::HasContactWith(const DOUBLEaabbox3D& b) const
{
  return DOUBLEaabbox3D_HasContactWith(mp_handle, b);
}

inline BOOL DOUBLEaabbox3D::HasContactWith(const DOUBLEaabbox3D& b, DOUBLE tEpsilon) const
{
  return DOUBLEaabbox3D_HasContactWith_fuzzy(mp_handle, b, tEpsilon);
}

inline BOOL DOUBLEaabbox3D::TouchesSphere(const DOUBLE3D& vSphereCenter, DOUBLE fSphereRadius) const
{
  return DOUBLEaabbox3D_TouchesSphere(mp_handle, vSphereCenter, fSphereRadius);
}

inline void DOUBLEaabbox3D::Expand(DOUBLE tEpsilon)
{
  DOUBLEaabbox3D_Expand(mp_handle, tEpsilon);
}

inline void DOUBLEaabbox3D::ExpandByFactor(DOUBLE tFactor)
{
  DOUBLEaabbox3D_ExpandByFactor(mp_handle, tFactor);
}

inline void DOUBLEaabbox3D::StretchByFactor(DOUBLE tSizing)
{
  DOUBLEaabbox3D_StretchByFactor(mp_handle, tSizing);
}

inline void DOUBLEaabbox3D::StretchByVector(DOUBLE3D vSizing)
{
  DOUBLEaabbox3D_StretchByVector(mp_handle, vSizing);
}

__forceinline DOUBLEaabbox3D FLOATtoDOUBLE(const FLOATaabbox3D& plf)
{
  return DOUBLEaabbox3D(FLOATtoDOUBLEaabb(plf), true);
}

__forceinline FLOATaabbox3D DOUBLEtoFLOAT(const DOUBLEaabbox3D& pld)
{
  return FLOATaabbox3D(DOUBLEtoFLOATaabb(pld), true);
}
