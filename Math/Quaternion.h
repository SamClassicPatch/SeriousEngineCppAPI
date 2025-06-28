#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <SeriousEngineCAPI/Math/Quaternion.h>

class FLOATquat3D
{
public:
  FLOATquat3D(FLOATquat3D_* p, bool owner = false);
  FLOATquat3D();
  FLOATquat3D(const FLOATquat3D& o);
  FLOATquat3D(FLOAT w, FLOAT x, FLOAT y, FLOAT z);
  ~FLOATquat3D();

  FLOATquat3D& operator=(const FLOATquat3D& o);

  FLOAT x() const;
  FLOAT y() const;
  FLOAT z() const;
  FLOAT w() const;
  void setx(FLOAT x);
  void sety(FLOAT y);
  void setz(FLOAT z);
  void setw(FLOAT w);

  // conversion from euler angles
  void FromEuler(const FLOAT3D& a);

  // conversion to matrix
  void ToMatrix(FLOATmatrix3D& m) const;
  // conversion from matrix
  void FromMatrix(FLOATmatrix3D& m);

  // conversion to/from axis-angle
  void FromAxisAngle(const FLOAT3D& n, FLOAT a);
  void ToAxisAngle(FLOAT3D& n, FLOAT& a);

  // unary minus (fliping of the quaternion)
  FLOATquat3D operator-() const;
  // conjugation
  FLOATquat3D operator~() const;
  // inversion
  FLOATquat3D Inv() const;

  // multiplication/division by a scalar
  FLOATquat3D operator*(FLOAT t) const;
  FLOATquat3D& operator*=(FLOAT t);
  friend FLOATquat3D operator*(FLOAT t, FLOATquat3D q);
  FLOATquat3D operator/(FLOAT t) const;
  FLOATquat3D& operator/=(FLOAT t);

  // addition/substraction
  FLOATquat3D operator+(const FLOATquat3D& q2) const;
  FLOATquat3D& operator+=(const FLOATquat3D& q2);
  FLOATquat3D operator-(const FLOATquat3D& q2) const;
  FLOATquat3D& operator-=(const FLOATquat3D& q2);
  // multiplication
  FLOATquat3D operator*(const FLOATquat3D& q2) const;
  FLOATquat3D& operator*=(const FLOATquat3D& q2);
  // dot product
  FLOAT operator%(const FLOATquat3D& q2) const;

  // quaternion norm (euclidian length of a 4d vector)
  FLOAT Norm() const;

  inline FLOATquat3D_* C_Handle() { return mp_handle; }
  inline const FLOATquat3D_* C_Handle() const { return mp_handle; }
  inline operator FLOATquat3D_* () { return C_Handle(); }
  inline operator const FLOATquat3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  FLOATquat3D_* mp_handle = nullptr;
};

// transcendental functions
FLOATquat3D Exp(const FLOATquat3D &q);
FLOATquat3D Log(const FLOATquat3D &q);

// spherical linear interpolation
FLOATquat3D Slerp(FLOAT tT,
  const FLOATquat3D &q1, const FLOATquat3D &q2);
// spherical quadratic interpolation
FLOATquat3D Squad(FLOAT tT,
  const FLOATquat3D &q1, const FLOATquat3D &q2,
  const FLOATquat3D &qa, const FLOATquat3D &qb);

class DOUBLEquat3D
{
public:
  DOUBLEquat3D(DOUBLEquat3D_* p, bool owner = false);
  DOUBLEquat3D();
  DOUBLEquat3D(const DOUBLEquat3D& o);
  DOUBLEquat3D(DOUBLE w, DOUBLE x, DOUBLE y, DOUBLE z);
  ~DOUBLEquat3D();

  DOUBLEquat3D& operator=(const DOUBLEquat3D& o);

  DOUBLE x() const;
  DOUBLE y() const;
  DOUBLE z() const;
  DOUBLE w() const;
  void setx(DOUBLE x);
  void sety(DOUBLE y);
  void setz(DOUBLE z);
  void setw(DOUBLE w);

  // conversion from euler angles
  void FromEuler(const DOUBLE3D& a);

  // conversion to matrix
  void ToMatrix(DOUBLEmatrix3D& m) const;
  // conversion from matrix
  void FromMatrix(DOUBLEmatrix3D& m);

  // conversion to/from axis-angle
  void FromAxisAngle(const DOUBLE3D& n, DOUBLE a);
  void ToAxisAngle(DOUBLE3D& n, DOUBLE& a);

  // unary minus (fliping of the quaternion)
  DOUBLEquat3D operator-() const;
  // conjugation
  DOUBLEquat3D operator~() const;
  // inversion
  DOUBLEquat3D Inv() const;

  // multiplication/division by a scalar
  DOUBLEquat3D operator*(DOUBLE t) const;
  DOUBLEquat3D& operator*=(DOUBLE t);
  friend DOUBLEquat3D operator*(DOUBLE t, DOUBLEquat3D q);
  DOUBLEquat3D operator/(DOUBLE t) const;
  DOUBLEquat3D& operator/=(DOUBLE t);

  // addition/substraction
  DOUBLEquat3D operator+(const DOUBLEquat3D& q2) const;
  DOUBLEquat3D& operator+=(const DOUBLEquat3D& q2);
  DOUBLEquat3D operator-(const DOUBLEquat3D& q2) const;
  DOUBLEquat3D& operator-=(const DOUBLEquat3D& q2);
  // multiplication
  DOUBLEquat3D operator*(const DOUBLEquat3D& q2) const;
  DOUBLEquat3D& operator*=(const DOUBLEquat3D& q2);
  // dot product
  DOUBLE operator%(const DOUBLEquat3D& q2) const;

  // quaternion norm (euclidian length of a 4d vector)
  DOUBLE Norm() const;

  inline DOUBLEquat3D_* C_Handle() { return mp_handle; }
  inline const DOUBLEquat3D_* C_Handle() const { return mp_handle; }
  inline operator DOUBLEquat3D_* () { return C_Handle(); }
  inline operator const DOUBLEquat3D_* () const { return C_Handle(); }

private:
  bool m_owner = true;
  DOUBLEquat3D_* mp_handle = nullptr;
};

// transcendental functions
DOUBLEquat3D Exp(const DOUBLEquat3D& q);
DOUBLEquat3D Log(const DOUBLEquat3D& q);

// spherical linear interpolation
DOUBLEquat3D Slerp(DOUBLE tT,
  const DOUBLEquat3D& q1, const DOUBLEquat3D& q2);
// spherical quadratic interpolation
DOUBLEquat3D Squad(DOUBLE tT,
  const DOUBLEquat3D& q1, const DOUBLEquat3D& q2,
  const DOUBLEquat3D& qa, const DOUBLEquat3D& qb);

#include "Quaternion.inl"
