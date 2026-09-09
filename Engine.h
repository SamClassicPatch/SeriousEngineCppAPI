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

#include "Base/Types.h"
#include "Base/Console.h"
#include <SeriousEngineCAPI/Base/KeyNames.h>
#include "Base/Input.h"
#include "Base/Updateable.h"
#include "Base/ErrorReporting.h"
#include "Base/Stream.h"
#include "Base/Lists.h"
#include "Base/ListIterator.h"
#include "Base/Timer.h"
#include "Base/Translation.h"
#include "Base/Shell.h"
#include "Base/Statistics.h"
#include <SeriousEngineCAPI/Base/Memory.h>
#include "Base/Profiling.h"

#include "Brushes/Brush.h"
#include "Brushes/BrushTransformed.h"

#include "Entities/EntityClass.h"
#include "Entities/EntityProperties.h"
#include "Entities/ShadingInfo.h"

#include "Math/Float.h"
#include "Math/Geometry.h"
#include <SeriousEngineCAPI/Math/Clipping.h>
#include "Math/Object3D.h"
#include "Math/Functions.h"
#include "Math/Projection.h"
#include "Math/Quaternion.h"

#include "Models/ModelObject.h"
#include "Models/ModelData.h"
#include "Models/Model_internal.h"
#include "Models/RenderModel.h"

#include "Rendering/Render.h"

#include "Sound/SoundObject.h"
#include "Sound/SoundLibrary.h"
#include "Sound/SoundListener.h"

#include "Graphics/Texture.h"
#include "Graphics/Color.h"
#include "Graphics/Font.h"
#include "Graphics/GfxLibrary.h"
#include "Graphics/ViewPort.h"
#include "Graphics/DrawPort.h"
#include "Graphics/ImageInfo.h"

#include "Light/LightSource.h"

#include "Templates/DynamicArray.h"
#include "Templates/DynamicStackArray.h"
#include "Templates/StaticArray.h"
#include "Templates/StaticStackArray.h"

#include "World/World.h"
#include "World/WorldSettings.h"

#include "Entities/EntityPointer.h"

// some global stuff
void SE_InitEngine(CTString strGameID);
void SE_InitEngineAtDirectory(CTString strGameID, const CTFileName& fnAppPath, const CTFileName& fnExePath);
void SE_EndEngine();
void SE_LoadDefaultFonts();
void SE_UpdateWindowHandle(HWND hwndWindowed);
void SE_PretouchIfNeeded();

#include "Engine.inl"
