#pragma once
#include <SeriousEngineCAPI/Math/Matrix.h>
#include "../Base/API.h"

class SECPPAPI FLOATmatrix2D
{
public:
  inline FLOATmatrix2D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix2D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  FLOATmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI FLOATmatrix3D
{
public:
  inline FLOATmatrix3D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix3D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  FLOATmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI FLOATmatrix4D
{
public:
  inline FLOATmatrix4D_* C_Handle() { return mp_matrix; }
  inline const FLOATmatrix4D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  FLOATmatrix4D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix2D
{
public:
  inline DOUBLEmatrix2D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix2D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  DOUBLEmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix3D
{
public:
  inline DOUBLEmatrix3D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix3D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  DOUBLEmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI DOUBLEmatrix4D
{
public:
  inline DOUBLEmatrix4D_* C_Handle() { return mp_matrix; }
  inline const DOUBLEmatrix4D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  DOUBLEmatrix4D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix2D
{
public:
  inline INDEXmatrix2D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix2D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  INDEXmatrix2D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix3D
{
public:
  inline INDEXmatrix3D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix3D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  INDEXmatrix3D_* mp_matrix = nullptr;
};

class SECPPAPI INDEXmatrix4D
{
public:
  inline INDEXmatrix4D_* C_Handle() { return mp_matrix; }
  inline const INDEXmatrix4D_* C_Handle() const { return mp_matrix; }
private:
  const bool m_owner = true;
  INDEXmatrix4D_* mp_matrix = nullptr;
};
