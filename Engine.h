#pragma once

#include "Base/Types.h"
#include "Base/Updateable.h"
#include "Base/Stream.h"
#include "Base/Lists.h"
#include "Base/Timer.h"
#include "Base/Translation.h"
#include "Base/Shell.h"

#include "Math/Object3D.h"
#include "Math/Projection.h"

#include "Models/ModelObject.h"
#include "Models/ModelData.h"
#include "Models/Model_internal.h"
#include "Models/RenderModel.h"

#include "Sound/SoundObject.h"

#include "Graphics/Texture.h"
#include "Graphics/Font.h"
#include "Graphics/GfxLibrary.h"
#include "Graphics/ViewPort.h"
#include "Graphics/DrawPort.h"
#include "Graphics/ImageInfo.h"

#include "Templates/DynamicArray.h"
#include "Templates/DynamicStackArray.h"
#include "Templates/StaticArray.h"
#include "Templates/StaticStackArray.h"

// some global stuff
void SE_InitEngine(CTString strGameID);
void SE_EndEngine();
void SE_LoadDefaultFonts();
void SE_UpdateWindowHandle(HWND hwndWindowed);
void SE_PretouchIfNeeded();

#include "Engine.inl"
