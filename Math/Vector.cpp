#include "Vector.h"

FLOAT2D::FLOAT2D(FLOAT2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

FLOAT2D::FLOAT2D()
  : m_owner(true)
  , mp_vector(FLOAT2D_new())
{
}

FLOAT2D::FLOAT2D(FLOAT x, FLOAT y)
  : m_owner(true)
  , mp_vector(FLOAT2D_new_xy(x, y))
{
}

FLOAT2D::FLOAT2D(const FLOAT2D& o)
  : m_owner(true)
  , mp_vector(FLOAT2D_clone(o.mp_vector))
{
}

FLOAT2D::~FLOAT2D()
{
  if (m_owner)
    FLOAT2D_delete(mp_vector);
}

void FLOAT2D::Clear()
{
  FLOAT2D_Clear(mp_vector);
}

FLOAT FLOAT2D::Length() const
{
  return FLOAT2D_Length(mp_vector);
}

FLOAT FLOAT2D::ManhattanNorm() const
{
  return FLOAT2D_ManhattanNorm(mp_vector);
}

FLOAT FLOAT2D::MaxNorm() const
{
  return FLOAT2D_MaxNorm(mp_vector);
}

FLOAT& FLOAT2D::operator()(INDEX i)
{
  return *FLOAT2D_operator_braces(mp_vector, i);
}

FLOAT FLOAT2D::operator()(INDEX i) const
{
  return FLOAT2D_operator_braces_const(mp_vector, i);
}

FLOAT2D& FLOAT2D::Normalize()
{
  FLOAT2D_Normalize(mp_vector);
  return *this;
}

FLOAT2D& FLOAT2D::SafeNormalize()
{
  FLOAT2D_SafeNormalize(mp_vector);
  return *this;
}

FLOAT2D& FLOAT2D::Flip()
{
  FLOAT2D_Flip(mp_vector);
  return *this;
}

FLOAT2D FLOAT2D::operator-() const
{
  return FLOAT2D(FLOAT2D_operator_unary_minus(mp_vector), true);
}

FLOAT2D FLOAT2D::operator+(const FLOAT2D& vector2) const
{
  return FLOAT2D(FLOAT2D_operator_plus(mp_vector, vector2.mp_vector), true);
}

FLOAT2D& FLOAT2D::operator+=(const FLOAT2D& vector2)
{
  FLOAT2D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT2D FLOAT2D::operator-(const FLOAT2D& vector2) const
{
  return FLOAT2D(FLOAT2D_operator_minus(mp_vector, vector2.mp_vector), true);
}

FLOAT2D& FLOAT2D::operator-=(const FLOAT2D& vector2)
{
  FLOAT2D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT2D FLOAT2D::operator*(const FLOAT scalar) const
{
  return FLOAT2D(FLOAT2D_operator_mul(mp_vector, scalar), true);
}

FLOAT2D& FLOAT2D::operator*=(const FLOAT scalar)
{
  FLOAT2D_operator_mulequal(mp_vector, scalar);
  return *this;
}

FLOAT2D FLOAT2D::operator/(const FLOAT scalar) const
{
  return FLOAT2D(FLOAT2D_operator_div(mp_vector, scalar), true);
}

FLOAT2D& FLOAT2D::operator/=(const FLOAT scalar)
{
  FLOAT2D_operator_divequal(mp_vector, scalar);
  return *this;
}

FLOAT2D FLOAT2D::operator*(const FLOATmatrix2D& matrix2) const
{
  return FLOAT2D(FLOAT2D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

FLOAT2D& FLOAT2D::operator*=(const FLOATmatrix2D& matrix2)
{
  FLOAT2D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

FLOAT FLOAT2D::operator%(const FLOAT2D& vector2) const
{
  return FLOAT2D_Dot(mp_vector, vector2.mp_vector);
}

FLOAT2D FLOAT2D::operator*(const FLOAT2D& vector2) const
{
  return FLOAT2D(FLOAT2D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

FLOAT2D& FLOAT2D::operator*=(const FLOAT2D& vector2)
{
  FLOAT2D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL FLOAT2D::operator==(const FLOAT2D& vector2) const
{
  return FLOAT2D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL FLOAT2D::operator!=(const FLOAT2D& vector2) const
{
  return FLOAT2D_operator_notequals(mp_vector, vector2.mp_vector);
}

FLOAT3D::FLOAT3D(FLOAT3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

FLOAT3D::FLOAT3D()
  : m_owner(true)
  , mp_vector(FLOAT3D_new())
{
}

FLOAT3D::FLOAT3D(FLOAT x, FLOAT y, FLOAT z)
  : m_owner(true)
  , mp_vector(FLOAT3D_new_xyz(x, y, z))
{
}

FLOAT3D::FLOAT3D(const FLOAT3D& o)
  : m_owner(true)
  , mp_vector(FLOAT3D_clone(o.mp_vector))
{
}

FLOAT3D::~FLOAT3D()
{
  if (m_owner)
    FLOAT3D_delete(mp_vector);
}

void FLOAT3D::Clear()
{
  FLOAT3D_Clear(mp_vector);
}

FLOAT FLOAT3D::Length() const
{
  return FLOAT3D_Length(mp_vector);
}

FLOAT FLOAT3D::ManhattanNorm() const
{
  return FLOAT3D_ManhattanNorm(mp_vector);
}

FLOAT FLOAT3D::MaxNorm() const
{
  return FLOAT3D_MaxNorm(mp_vector);
}

FLOAT& FLOAT3D::operator()(INDEX i)
{
  return *FLOAT3D_operator_braces(mp_vector, i);
}

FLOAT FLOAT3D::operator()(INDEX i) const
{
  return FLOAT3D_operator_braces_const(mp_vector, i);
}

FLOAT3D& FLOAT3D::Normalize()
{
  FLOAT3D_Normalize(mp_vector);
  return *this;
}

FLOAT3D& FLOAT3D::SafeNormalize()
{
  FLOAT3D_SafeNormalize(mp_vector);
  return *this;
}

FLOAT3D& FLOAT3D::Flip()
{
  FLOAT3D_Flip(mp_vector);
  return *this;
}

FLOAT3D FLOAT3D::operator-() const
{
  return FLOAT3D(FLOAT3D_operator_unary_minus(mp_vector), true);
}

FLOAT3D FLOAT3D::operator+(const FLOAT3D& vector2) const
{
  return FLOAT3D(FLOAT3D_operator_plus(mp_vector, vector2.mp_vector), true);
}

FLOAT3D& FLOAT3D::operator+=(const FLOAT3D& vector2)
{
  FLOAT3D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT3D FLOAT3D::operator-(const FLOAT3D& vector2) const
{
  return FLOAT3D(FLOAT3D_operator_minus(mp_vector, vector2.mp_vector), true);
}

FLOAT3D& FLOAT3D::operator-=(const FLOAT3D& vector2)
{
  FLOAT3D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT3D FLOAT3D::operator*(const FLOAT scalar) const
{
  return FLOAT3D(FLOAT3D_operator_mul(mp_vector, scalar), true);
}

FLOAT3D& FLOAT3D::operator*=(const FLOAT scalar)
{
  FLOAT3D_operator_mulequal(mp_vector, scalar);
  return *this;
}

FLOAT3D FLOAT3D::operator/(const FLOAT scalar) const
{
  return FLOAT3D(FLOAT3D_operator_div(mp_vector, scalar), true);
}

FLOAT3D& FLOAT3D::operator/=(const FLOAT scalar)
{
  FLOAT3D_operator_divequal(mp_vector, scalar);
  return *this;
}

FLOAT3D FLOAT3D::operator*(const FLOATmatrix3D& matrix2) const
{
  return FLOAT3D(FLOAT3D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

FLOAT3D& FLOAT3D::operator*=(const FLOATmatrix3D& matrix2)
{
  FLOAT3D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

FLOAT FLOAT3D::operator%(const FLOAT3D& vector2) const
{
  return FLOAT3D_Dot(mp_vector, vector2.mp_vector);
}

FLOAT3D FLOAT3D::operator*(const FLOAT3D& vector2) const
{
  return FLOAT3D(FLOAT3D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

FLOAT3D& FLOAT3D::operator*=(const FLOAT3D& vector2)
{
  FLOAT3D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL FLOAT3D::operator==(const FLOAT3D& vector2) const
{
  return FLOAT3D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL FLOAT3D::operator!=(const FLOAT3D& vector2) const
{
  return FLOAT3D_operator_notequals(mp_vector, vector2.mp_vector);
}

FLOAT4D::FLOAT4D(FLOAT4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

FLOAT4D::FLOAT4D()
  : m_owner(true)
  , mp_vector(FLOAT4D_new())
{
}

FLOAT4D::FLOAT4D(FLOAT x, FLOAT y, FLOAT z, FLOAT w)
  : m_owner(true)
  , mp_vector(FLOAT4D_new_xyzw(x, y, z, w))
{
}

FLOAT4D::FLOAT4D(const FLOAT4D& o)
  : m_owner(true)
  , mp_vector(FLOAT4D_clone(o.mp_vector))
{
}

FLOAT4D::~FLOAT4D()
{
  if (m_owner)
    FLOAT4D_delete(mp_vector);
}

void FLOAT4D::Clear()
{
  FLOAT4D_Clear(mp_vector);
}

FLOAT FLOAT4D::Length() const
{
  return FLOAT4D_Length(mp_vector);
}

FLOAT FLOAT4D::ManhattanNorm() const
{
  return FLOAT4D_ManhattanNorm(mp_vector);
}

FLOAT FLOAT4D::MaxNorm() const
{
  return FLOAT4D_MaxNorm(mp_vector);
}

FLOAT& FLOAT4D::operator()(INDEX i)
{
  return *FLOAT4D_operator_braces(mp_vector, i);
}

FLOAT FLOAT4D::operator()(INDEX i) const
{
  return FLOAT4D_operator_braces_const(mp_vector, i);
}

FLOAT4D& FLOAT4D::Normalize()
{
  FLOAT4D_Normalize(mp_vector);
  return *this;
}

FLOAT4D& FLOAT4D::SafeNormalize()
{
  FLOAT4D_SafeNormalize(mp_vector);
  return *this;
}

FLOAT4D& FLOAT4D::Flip()
{
  FLOAT4D_Flip(mp_vector);
  return *this;
}

FLOAT4D FLOAT4D::operator-() const
{
  return FLOAT4D(FLOAT4D_operator_unary_minus(mp_vector), true);
}

FLOAT4D FLOAT4D::operator+(const FLOAT4D& vector2) const
{
  return FLOAT4D(FLOAT4D_operator_plus(mp_vector, vector2.mp_vector), true);
}

FLOAT4D& FLOAT4D::operator+=(const FLOAT4D& vector2)
{
  FLOAT4D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT4D FLOAT4D::operator-(const FLOAT4D& vector2) const
{
  return FLOAT4D(FLOAT4D_operator_minus(mp_vector, vector2.mp_vector), true);
}

FLOAT4D& FLOAT4D::operator-=(const FLOAT4D& vector2)
{
  FLOAT4D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

FLOAT4D FLOAT4D::operator*(const FLOAT scalar) const
{
  return FLOAT4D(FLOAT4D_operator_mul(mp_vector, scalar), true);
}

FLOAT4D& FLOAT4D::operator*=(const FLOAT scalar)
{
  FLOAT4D_operator_mulequal(mp_vector, scalar);
  return *this;
}

FLOAT4D FLOAT4D::operator/(const FLOAT scalar) const
{
  return FLOAT4D(FLOAT4D_operator_div(mp_vector, scalar), true);
}

FLOAT4D& FLOAT4D::operator/=(const FLOAT scalar)
{
  FLOAT4D_operator_divequal(mp_vector, scalar);
  return *this;
}

FLOAT4D FLOAT4D::operator*(const FLOATmatrix4D& matrix2) const
{
  return FLOAT4D(FLOAT4D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

FLOAT4D& FLOAT4D::operator*=(const FLOATmatrix4D& matrix2)
{
  FLOAT4D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

FLOAT FLOAT4D::operator%(const FLOAT4D& vector2) const
{
  return FLOAT4D_Dot(mp_vector, vector2.mp_vector);
}

FLOAT4D FLOAT4D::operator*(const FLOAT4D& vector2) const
{
  return FLOAT4D(FLOAT4D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

FLOAT4D& FLOAT4D::operator*=(const FLOAT4D& vector2)
{
  FLOAT4D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL FLOAT4D::operator==(const FLOAT4D& vector2) const
{
  return FLOAT4D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL FLOAT4D::operator!=(const FLOAT4D& vector2) const
{
  return FLOAT4D_operator_notequals(mp_vector, vector2.mp_vector);
}

DOUBLE2D::DOUBLE2D(DOUBLE2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

DOUBLE2D::DOUBLE2D()
  : m_owner(true)
  , mp_vector(DOUBLE2D_new())
{
}

DOUBLE2D::DOUBLE2D(DOUBLE x, DOUBLE y)
  : m_owner(true)
  , mp_vector(DOUBLE2D_new_xy(x, y))
{
}

DOUBLE2D::DOUBLE2D(const DOUBLE2D& o)
  : m_owner(true)
  , mp_vector(DOUBLE2D_clone(o.mp_vector))
{
}

DOUBLE2D::~DOUBLE2D()
{
  if (m_owner)
    DOUBLE2D_delete(mp_vector);
}

void DOUBLE2D::Clear()
{
  DOUBLE2D_Clear(mp_vector);
}

DOUBLE DOUBLE2D::Length() const
{
  return DOUBLE2D_Length(mp_vector);
}

DOUBLE DOUBLE2D::ManhattanNorm() const
{
  return DOUBLE2D_ManhattanNorm(mp_vector);
}

DOUBLE DOUBLE2D::MaxNorm() const
{
  return DOUBLE2D_MaxNorm(mp_vector);
}

DOUBLE& DOUBLE2D::operator()(INDEX i)
{
  return *DOUBLE2D_operator_braces(mp_vector, i);
}

DOUBLE DOUBLE2D::operator()(INDEX i) const
{
  return DOUBLE2D_operator_braces_const(mp_vector, i);
}

DOUBLE2D& DOUBLE2D::Normalize()
{
  DOUBLE2D_Normalize(mp_vector);
  return *this;
}

DOUBLE2D& DOUBLE2D::SafeNormalize()
{
  DOUBLE2D_SafeNormalize(mp_vector);
  return *this;
}

DOUBLE2D& DOUBLE2D::Flip()
{
  DOUBLE2D_Flip(mp_vector);
  return *this;
}

DOUBLE2D DOUBLE2D::operator-() const
{
  return DOUBLE2D(DOUBLE2D_operator_unary_minus(mp_vector), true);
}

DOUBLE2D DOUBLE2D::operator+(const DOUBLE2D& vector2) const
{
  return DOUBLE2D(DOUBLE2D_operator_plus(mp_vector, vector2.mp_vector), true);
}

DOUBLE2D& DOUBLE2D::operator+=(const DOUBLE2D& vector2)
{
  DOUBLE2D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE2D DOUBLE2D::operator-(const DOUBLE2D& vector2) const
{
  return DOUBLE2D(DOUBLE2D_operator_minus(mp_vector, vector2.mp_vector), true);
}

DOUBLE2D& DOUBLE2D::operator-=(const DOUBLE2D& vector2)
{
  DOUBLE2D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE2D DOUBLE2D::operator*(const DOUBLE scalar) const
{
  return DOUBLE2D(DOUBLE2D_operator_mul(mp_vector, scalar), true);
}

DOUBLE2D& DOUBLE2D::operator*=(const DOUBLE scalar)
{
  DOUBLE2D_operator_mulequal(mp_vector, scalar);
  return *this;
}

DOUBLE2D DOUBLE2D::operator/(const DOUBLE scalar) const
{
  return DOUBLE2D(DOUBLE2D_operator_div(mp_vector, scalar), true);
}

DOUBLE2D& DOUBLE2D::operator/=(const DOUBLE scalar)
{
  DOUBLE2D_operator_divequal(mp_vector, scalar);
  return *this;
}

DOUBLE2D DOUBLE2D::operator*(const DOUBLEmatrix2D& matrix2) const
{
  return DOUBLE2D(DOUBLE2D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

DOUBLE2D& DOUBLE2D::operator*=(const DOUBLEmatrix2D& matrix2)
{
  DOUBLE2D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

DOUBLE DOUBLE2D::operator%(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_Dot(mp_vector, vector2.mp_vector);
}

DOUBLE2D DOUBLE2D::operator*(const DOUBLE2D& vector2) const
{
  return DOUBLE2D(DOUBLE2D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

DOUBLE2D& DOUBLE2D::operator*=(const DOUBLE2D& vector2)
{
  DOUBLE2D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL DOUBLE2D::operator==(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL DOUBLE2D::operator!=(const DOUBLE2D& vector2) const
{
  return DOUBLE2D_operator_notequals(mp_vector, vector2.mp_vector);
}

DOUBLE3D::DOUBLE3D(DOUBLE3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

DOUBLE3D::DOUBLE3D()
  : m_owner(true)
  , mp_vector(DOUBLE3D_new())
{
}

DOUBLE3D::DOUBLE3D(DOUBLE x, DOUBLE y, DOUBLE z)
  : m_owner(true)
  , mp_vector(DOUBLE3D_new_xyz(x, y, z))
{
}

DOUBLE3D::DOUBLE3D(const DOUBLE3D& o)
  : m_owner(true)
  , mp_vector(DOUBLE3D_clone(o.mp_vector))
{
}

DOUBLE3D::~DOUBLE3D()
{
  if (m_owner)
    DOUBLE3D_delete(mp_vector);
}

void DOUBLE3D::Clear()
{
  DOUBLE3D_Clear(mp_vector);
}

DOUBLE DOUBLE3D::Length() const
{
  return DOUBLE3D_Length(mp_vector);
}

DOUBLE DOUBLE3D::ManhattanNorm() const
{
  return DOUBLE3D_ManhattanNorm(mp_vector);
}

DOUBLE DOUBLE3D::MaxNorm() const
{
  return DOUBLE3D_MaxNorm(mp_vector);
}

DOUBLE& DOUBLE3D::operator()(INDEX i)
{
  return *DOUBLE3D_operator_braces(mp_vector, i);
}

DOUBLE DOUBLE3D::operator()(INDEX i) const
{
  return DOUBLE3D_operator_braces_const(mp_vector, i);
}

DOUBLE3D& DOUBLE3D::Normalize()
{
  DOUBLE3D_Normalize(mp_vector);
  return *this;
}

DOUBLE3D& DOUBLE3D::SafeNormalize()
{
  DOUBLE3D_SafeNormalize(mp_vector);
  return *this;
}

DOUBLE3D& DOUBLE3D::Flip()
{
  DOUBLE3D_Flip(mp_vector);
  return *this;
}

DOUBLE3D DOUBLE3D::operator-() const
{
  return DOUBLE3D(DOUBLE3D_operator_unary_minus(mp_vector), true);
}

DOUBLE3D DOUBLE3D::operator+(const DOUBLE3D& vector2) const
{
  return DOUBLE3D(DOUBLE3D_operator_plus(mp_vector, vector2.mp_vector), true);
}

DOUBLE3D& DOUBLE3D::operator+=(const DOUBLE3D& vector2)
{
  DOUBLE3D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE3D DOUBLE3D::operator-(const DOUBLE3D& vector2) const
{
  return DOUBLE3D(DOUBLE3D_operator_minus(mp_vector, vector2.mp_vector), true);
}

DOUBLE3D& DOUBLE3D::operator-=(const DOUBLE3D& vector2)
{
  DOUBLE3D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE3D DOUBLE3D::operator*(const DOUBLE scalar) const
{
  return DOUBLE3D(DOUBLE3D_operator_mul(mp_vector, scalar), true);
}

DOUBLE3D& DOUBLE3D::operator*=(const DOUBLE scalar)
{
  DOUBLE3D_operator_mulequal(mp_vector, scalar);
  return *this;
}

DOUBLE3D DOUBLE3D::operator/(const DOUBLE scalar) const
{
  return DOUBLE3D(DOUBLE3D_operator_div(mp_vector, scalar), true);
}

DOUBLE3D& DOUBLE3D::operator/=(const DOUBLE scalar)
{
  DOUBLE3D_operator_divequal(mp_vector, scalar);
  return *this;
}

DOUBLE3D DOUBLE3D::operator*(const DOUBLEmatrix3D& matrix2) const
{
  return DOUBLE3D(DOUBLE3D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

DOUBLE3D& DOUBLE3D::operator*=(const DOUBLEmatrix3D& matrix2)
{
  DOUBLE3D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

DOUBLE DOUBLE3D::operator%(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_Dot(mp_vector, vector2.mp_vector);
}

DOUBLE3D DOUBLE3D::operator*(const DOUBLE3D& vector2) const
{
  return DOUBLE3D(DOUBLE3D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

DOUBLE3D& DOUBLE3D::operator*=(const DOUBLE3D& vector2)
{
  DOUBLE3D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL DOUBLE3D::operator==(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL DOUBLE3D::operator!=(const DOUBLE3D& vector2) const
{
  return DOUBLE3D_operator_notequals(mp_vector, vector2.mp_vector);
}

DOUBLE4D::DOUBLE4D(DOUBLE4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

DOUBLE4D::DOUBLE4D()
  : m_owner(true)
  , mp_vector(DOUBLE4D_new())
{
}

DOUBLE4D::DOUBLE4D(DOUBLE x, DOUBLE y, DOUBLE z, DOUBLE w)
  : m_owner(true)
  , mp_vector(DOUBLE4D_new_xyzw(x, y, z, w))
{
}

DOUBLE4D::DOUBLE4D(const DOUBLE4D& o)
  : m_owner(true)
  , mp_vector(DOUBLE4D_clone(o.mp_vector))
{
}

DOUBLE4D::~DOUBLE4D()
{
  if (m_owner)
    DOUBLE4D_delete(mp_vector);
}

void DOUBLE4D::Clear()
{
  DOUBLE4D_Clear(mp_vector);
}

DOUBLE DOUBLE4D::Length() const
{
  return DOUBLE4D_Length(mp_vector);
}

DOUBLE DOUBLE4D::ManhattanNorm() const
{
  return DOUBLE4D_ManhattanNorm(mp_vector);
}

DOUBLE DOUBLE4D::MaxNorm() const
{
  return DOUBLE4D_MaxNorm(mp_vector);
}

DOUBLE& DOUBLE4D::operator()(INDEX i)
{
  return *DOUBLE4D_operator_braces(mp_vector, i);
}

DOUBLE DOUBLE4D::operator()(INDEX i) const
{
  return DOUBLE4D_operator_braces_const(mp_vector, i);
}

DOUBLE4D& DOUBLE4D::Normalize()
{
  DOUBLE4D_Normalize(mp_vector);
  return *this;
}

DOUBLE4D& DOUBLE4D::SafeNormalize()
{
  DOUBLE4D_SafeNormalize(mp_vector);
  return *this;
}

DOUBLE4D& DOUBLE4D::Flip()
{
  DOUBLE4D_Flip(mp_vector);
  return *this;
}

DOUBLE4D DOUBLE4D::operator-() const
{
  return DOUBLE4D(DOUBLE4D_operator_unary_minus(mp_vector), true);
}

DOUBLE4D DOUBLE4D::operator+(const DOUBLE4D& vector2) const
{
  return DOUBLE4D(DOUBLE4D_operator_plus(mp_vector, vector2.mp_vector), true);
}

DOUBLE4D& DOUBLE4D::operator+=(const DOUBLE4D& vector2)
{
  DOUBLE4D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE4D DOUBLE4D::operator-(const DOUBLE4D& vector2) const
{
  return DOUBLE4D(DOUBLE4D_operator_minus(mp_vector, vector2.mp_vector), true);
}

DOUBLE4D& DOUBLE4D::operator-=(const DOUBLE4D& vector2)
{
  DOUBLE4D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

DOUBLE4D DOUBLE4D::operator*(const DOUBLE scalar) const
{
  return DOUBLE4D(DOUBLE4D_operator_mul(mp_vector, scalar), true);
}

DOUBLE4D& DOUBLE4D::operator*=(const DOUBLE scalar)
{
  DOUBLE4D_operator_mulequal(mp_vector, scalar);
  return *this;
}

DOUBLE4D DOUBLE4D::operator/(const DOUBLE scalar) const
{
  return DOUBLE4D(DOUBLE4D_operator_div(mp_vector, scalar), true);
}

DOUBLE4D& DOUBLE4D::operator/=(const DOUBLE scalar)
{
  DOUBLE4D_operator_divequal(mp_vector, scalar);
  return *this;
}

DOUBLE4D DOUBLE4D::operator*(const DOUBLEmatrix4D& matrix2) const
{
  return DOUBLE4D(DOUBLE4D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

DOUBLE4D& DOUBLE4D::operator*=(const DOUBLEmatrix4D& matrix2)
{
  DOUBLE4D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

DOUBLE DOUBLE4D::operator%(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_Dot(mp_vector, vector2.mp_vector);
}

DOUBLE4D DOUBLE4D::operator*(const DOUBLE4D& vector2) const
{
  return DOUBLE4D(DOUBLE4D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

DOUBLE4D& DOUBLE4D::operator*=(const DOUBLE4D& vector2)
{
  DOUBLE4D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL DOUBLE4D::operator==(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL DOUBLE4D::operator!=(const DOUBLE4D& vector2) const
{
  return DOUBLE4D_operator_notequals(mp_vector, vector2.mp_vector);
}

INDEX2D::INDEX2D(INDEX2D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

INDEX2D::INDEX2D()
  : m_owner(true)
  , mp_vector(INDEX2D_new())
{
}

INDEX2D::INDEX2D(INDEX x, INDEX y)
  : m_owner(true)
  , mp_vector(INDEX2D_new_xy(x, y))
{
}

INDEX2D::INDEX2D(const INDEX2D& o)
  : m_owner(true)
  , mp_vector(INDEX2D_clone(o.mp_vector))
{
}

INDEX2D::~INDEX2D()
{
  if (m_owner)
    INDEX2D_delete(mp_vector);
}

void INDEX2D::Clear()
{
  INDEX2D_Clear(mp_vector);
}

INDEX INDEX2D::Length() const
{
  return INDEX2D_Length(mp_vector);
}

INDEX INDEX2D::ManhattanNorm() const
{
  return INDEX2D_ManhattanNorm(mp_vector);
}

INDEX INDEX2D::MaxNorm() const
{
  return INDEX2D_MaxNorm(mp_vector);
}

INDEX& INDEX2D::operator()(INDEX i)
{
  return *INDEX2D_operator_braces(mp_vector, i);
}

INDEX INDEX2D::operator()(INDEX i) const
{
  return INDEX2D_operator_braces_const(mp_vector, i);
}

INDEX2D& INDEX2D::Normalize()
{
  INDEX2D_Normalize(mp_vector);
  return *this;
}

INDEX2D& INDEX2D::SafeNormalize()
{
  INDEX2D_SafeNormalize(mp_vector);
  return *this;
}

INDEX2D& INDEX2D::Flip()
{
  INDEX2D_Flip(mp_vector);
  return *this;
}

INDEX2D INDEX2D::operator-() const
{
  return INDEX2D(INDEX2D_operator_unary_minus(mp_vector), true);
}

INDEX2D INDEX2D::operator+(const INDEX2D& vector2) const
{
  return INDEX2D(INDEX2D_operator_plus(mp_vector, vector2.mp_vector), true);
}

INDEX2D& INDEX2D::operator+=(const INDEX2D& vector2)
{
  INDEX2D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX2D INDEX2D::operator-(const INDEX2D& vector2) const
{
  return INDEX2D(INDEX2D_operator_minus(mp_vector, vector2.mp_vector), true);
}

INDEX2D& INDEX2D::operator-=(const INDEX2D& vector2)
{
  INDEX2D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX2D INDEX2D::operator*(const INDEX scalar) const
{
  return INDEX2D(INDEX2D_operator_mul(mp_vector, scalar), true);
}

INDEX2D& INDEX2D::operator*=(const INDEX scalar)
{
  INDEX2D_operator_mulequal(mp_vector, scalar);
  return *this;
}

INDEX2D INDEX2D::operator/(const INDEX scalar) const
{
  return INDEX2D(INDEX2D_operator_div(mp_vector, scalar), true);
}

INDEX2D& INDEX2D::operator/=(const INDEX scalar)
{
  INDEX2D_operator_divequal(mp_vector, scalar);
  return *this;
}

INDEX2D INDEX2D::operator*(const INDEXmatrix2D& matrix2) const
{
  return INDEX2D(INDEX2D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

INDEX2D& INDEX2D::operator*=(const INDEXmatrix2D& matrix2)
{
  INDEX2D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

INDEX INDEX2D::operator%(const INDEX2D& vector2) const
{
  return INDEX2D_Dot(mp_vector, vector2.mp_vector);
}

INDEX2D INDEX2D::operator*(const INDEX2D& vector2) const
{
  return INDEX2D(INDEX2D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

INDEX2D& INDEX2D::operator*=(const INDEX2D& vector2)
{
  INDEX2D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL INDEX2D::operator==(const INDEX2D& vector2) const
{
  return INDEX2D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL INDEX2D::operator!=(const INDEX2D& vector2) const
{
  return INDEX2D_operator_notequals(mp_vector, vector2.mp_vector);
}

INDEX3D::INDEX3D(INDEX3D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

INDEX3D::INDEX3D()
  : m_owner(true)
  , mp_vector(INDEX3D_new())
{
}

INDEX3D::INDEX3D(INDEX x, INDEX y, INDEX z)
  : m_owner(true)
  , mp_vector(INDEX3D_new_xyz(x, y, z))
{
}

INDEX3D::INDEX3D(const INDEX3D& o)
  : m_owner(true)
  , mp_vector(INDEX3D_clone(o.mp_vector))
{
}

INDEX3D::~INDEX3D()
{
  if (m_owner)
    INDEX3D_delete(mp_vector);
}

void INDEX3D::Clear()
{
  INDEX3D_Clear(mp_vector);
}

INDEX INDEX3D::Length() const
{
  return INDEX3D_Length(mp_vector);
}

INDEX INDEX3D::ManhattanNorm() const
{
  return INDEX3D_ManhattanNorm(mp_vector);
}

INDEX INDEX3D::MaxNorm() const
{
  return INDEX3D_MaxNorm(mp_vector);
}

INDEX& INDEX3D::operator()(INDEX i)
{
  return *INDEX3D_operator_braces(mp_vector, i);
}

INDEX INDEX3D::operator()(INDEX i) const
{
  return INDEX3D_operator_braces_const(mp_vector, i);
}

INDEX3D& INDEX3D::Normalize()
{
  INDEX3D_Normalize(mp_vector);
  return *this;
}

INDEX3D& INDEX3D::SafeNormalize()
{
  INDEX3D_SafeNormalize(mp_vector);
  return *this;
}

INDEX3D& INDEX3D::Flip()
{
  INDEX3D_Flip(mp_vector);
  return *this;
}

INDEX3D INDEX3D::operator-() const
{
  return INDEX3D(INDEX3D_operator_unary_minus(mp_vector), true);
}

INDEX3D INDEX3D::operator+(const INDEX3D& vector2) const
{
  return INDEX3D(INDEX3D_operator_plus(mp_vector, vector2.mp_vector), true);
}

INDEX3D& INDEX3D::operator+=(const INDEX3D& vector2)
{
  INDEX3D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX3D INDEX3D::operator-(const INDEX3D& vector2) const
{
  return INDEX3D(INDEX3D_operator_minus(mp_vector, vector2.mp_vector), true);
}

INDEX3D& INDEX3D::operator-=(const INDEX3D& vector2)
{
  INDEX3D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX3D INDEX3D::operator*(const INDEX scalar) const
{
  return INDEX3D(INDEX3D_operator_mul(mp_vector, scalar), true);
}

INDEX3D& INDEX3D::operator*=(const INDEX scalar)
{
  INDEX3D_operator_mulequal(mp_vector, scalar);
  return *this;
}

INDEX3D INDEX3D::operator/(const INDEX scalar) const
{
  return INDEX3D(INDEX3D_operator_div(mp_vector, scalar), true);
}

INDEX3D& INDEX3D::operator/=(const INDEX scalar)
{
  INDEX3D_operator_divequal(mp_vector, scalar);
  return *this;
}

INDEX3D INDEX3D::operator*(const INDEXmatrix3D& matrix2) const
{
  return INDEX3D(INDEX3D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

INDEX3D& INDEX3D::operator*=(const INDEXmatrix3D& matrix2)
{
  INDEX3D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

INDEX INDEX3D::operator%(const INDEX3D& vector2) const
{
  return INDEX3D_Dot(mp_vector, vector2.mp_vector);
}

INDEX3D INDEX3D::operator*(const INDEX3D& vector2) const
{
  return INDEX3D(INDEX3D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

INDEX3D& INDEX3D::operator*=(const INDEX3D& vector2)
{
  INDEX3D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL INDEX3D::operator==(const INDEX3D& vector2) const
{
  return INDEX3D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL INDEX3D::operator!=(const INDEX3D& vector2) const
{
  return INDEX3D_operator_notequals(mp_vector, vector2.mp_vector);
}

INDEX4D::INDEX4D(INDEX4D_* p, bool owner)
  : m_owner(owner)
  , mp_vector(p)
{
}

INDEX4D::INDEX4D()
  : m_owner(true)
  , mp_vector(INDEX4D_new())
{
}

INDEX4D::INDEX4D(INDEX x, INDEX y, INDEX z, INDEX w)
  : m_owner(true)
  , mp_vector(INDEX4D_new_xyzw(x, y, z, w))
{
}

INDEX4D::INDEX4D(const INDEX4D& o)
  : m_owner(true)
  , mp_vector(INDEX4D_clone(o.mp_vector))
{
}

INDEX4D::~INDEX4D()
{
  if (m_owner)
    INDEX4D_delete(mp_vector);
}

void INDEX4D::Clear()
{
  INDEX4D_Clear(mp_vector);
}

INDEX INDEX4D::Length() const
{
  return INDEX4D_Length(mp_vector);
}

INDEX INDEX4D::ManhattanNorm() const
{
  return INDEX4D_ManhattanNorm(mp_vector);
}

INDEX INDEX4D::MaxNorm() const
{
  return INDEX4D_MaxNorm(mp_vector);
}

INDEX& INDEX4D::operator()(INDEX i)
{
  return *INDEX4D_operator_braces(mp_vector, i);
}

INDEX INDEX4D::operator()(INDEX i) const
{
  return INDEX4D_operator_braces_const(mp_vector, i);
}

INDEX4D& INDEX4D::Normalize()
{
  INDEX4D_Normalize(mp_vector);
  return *this;
}

INDEX4D& INDEX4D::SafeNormalize()
{
  INDEX4D_SafeNormalize(mp_vector);
  return *this;
}

INDEX4D& INDEX4D::Flip()
{
  INDEX4D_Flip(mp_vector);
  return *this;
}

INDEX4D INDEX4D::operator-() const
{
  return INDEX4D(INDEX4D_operator_unary_minus(mp_vector), true);
}

INDEX4D INDEX4D::operator+(const INDEX4D& vector2) const
{
  return INDEX4D(INDEX4D_operator_plus(mp_vector, vector2.mp_vector), true);
}

INDEX4D& INDEX4D::operator+=(const INDEX4D& vector2)
{
  INDEX4D_operator_plusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX4D INDEX4D::operator-(const INDEX4D& vector2) const
{
  return INDEX4D(INDEX4D_operator_minus(mp_vector, vector2.mp_vector), true);
}

INDEX4D& INDEX4D::operator-=(const INDEX4D& vector2)
{
  INDEX4D_operator_minusequal(mp_vector, vector2.mp_vector);
  return *this;
}

INDEX4D INDEX4D::operator*(const INDEX scalar) const
{
  return INDEX4D(INDEX4D_operator_mul(mp_vector, scalar), true);
}

INDEX4D& INDEX4D::operator*=(const INDEX scalar)
{
  INDEX4D_operator_mulequal(mp_vector, scalar);
  return *this;
}

INDEX4D INDEX4D::operator/(const INDEX scalar) const
{
  return INDEX4D(INDEX4D_operator_div(mp_vector, scalar), true);
}

INDEX4D& INDEX4D::operator/=(const INDEX scalar)
{
  INDEX4D_operator_divequal(mp_vector, scalar);
  return *this;
}

INDEX4D INDEX4D::operator*(const INDEXmatrix4D& matrix2) const
{
  return INDEX4D(INDEX4D_operator_mul_matrix(mp_vector, matrix2.C_Handle()), true);
}

INDEX4D& INDEX4D::operator*=(const INDEXmatrix4D& matrix2)
{
  INDEX4D_operator_mulequal_matrix(mp_vector, matrix2.C_Handle());
  return *this;
}

INDEX INDEX4D::operator%(const INDEX4D& vector2) const
{
  return INDEX4D_Dot(mp_vector, vector2.mp_vector);
}

INDEX4D INDEX4D::operator*(const INDEX4D& vector2) const
{
  return INDEX4D(INDEX4D_operator_mul_vector(mp_vector, vector2.mp_vector), true);
}

INDEX4D& INDEX4D::operator*=(const INDEX4D& vector2)
{
  INDEX4D_operator_mulequal_vector(mp_vector, vector2.mp_vector);
  return *this;
}

BOOL INDEX4D::operator==(const INDEX4D& vector2) const
{
  return INDEX4D_operator_equals(mp_vector, vector2.mp_vector);
}

BOOL INDEX4D::operator!=(const INDEX4D& vector2) const
{
  return INDEX4D_operator_notequals(mp_vector, vector2.mp_vector);
}
