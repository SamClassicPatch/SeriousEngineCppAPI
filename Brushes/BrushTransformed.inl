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
#include <SeriousEngineCAPI/Brushes/BrushTransformed.h>

inline CWorkingVertex::CWorkingVertex(CWorkingVertex_* p, bool)
  : mp_handle(p)
  , wvx_vRelative(CWorkingVertex_wvx_vRelative(p), false)
{
}

inline CWorkingVertex::~CWorkingVertex()
{
}

inline CWorkingPlane::CWorkingPlane(CWorkingPlane_* p, bool)
  : mp_handle(p)
  , wpl_plRelative(CWorkingPlane_wpl_plRelative(p), false)
  , wpl_mvRelative(CWorkingPlane_wpl_mvRelative(p), false)
  , wpl_plView(CWorkingPlane_wpl_plView(p), false)
  , wpl_mvView(CWorkingPlane_wpl_mvView(p), false)
  , wpl_pgOoK(CWorkingPlane_wpl_pgOoK(p), false)
  , wpl_bVisible(*CWorkingPlane_wpl_bVisible(p))
{
}

inline CWorkingPlane::~CWorkingPlane()
{
}

inline CWorkingEdge::CWorkingEdge(CWorkingEdge_* p, bool)
  : mp_handle(p)
  , wed_iwvx0(*CWorkingEdge_wed_iwvx0(p))
  , wed_iwvx1(*CWorkingEdge_wed_iwvx1(p))
{
}

inline CWorkingEdge::~CWorkingEdge()
{
}
