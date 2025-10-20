cmake_minimum_required(VERSION 3.12)

project(SeriousEngineCppAPI LANGUAGES CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SRC_BASE
  Base/Anim.h
  Base/Anim.inl
  Base/Changeable.h
  Base/Changeable.inl
  Base/ChangeableRT.h
  Base/ChangeableRT.inl
  Base/CTString.h
  Base/CTString.inl
  Base/CTStringDecl.h
  Base/ErrorReporting.h
  Base/ErrorReporting.inl
  Base/FileName.h
  Base/FileName.inl
  Base/FileNameDecl.h
  Base/Input.h
  Base/Input.inl
  Base/ListIterator.h
  Base/Lists.h
  Base/Lists.inl
  Base/Pointer.h
  Base/Serial.h
  Base/Serial.inl
  Base/Shell.h
  Base/Shell.inl
  Base/Statistics.h
  Base/Stream.h
  Base/Stream.inl
  Base/Synchronization.h
  Base/Synchronization.inl
  Base/Timer.h
  Base/Timer.inl
  Base/Translation.h
  Base/Translation.inl
  Base/TranslationPair.h
  Base/TranslationPair.inl
  Base/Types.h
  Base/Updateable.h
  Base/Updateable.inl
  Base/UpdateableRT.h
  Base/UpdateableRT.inl
)
source_group("Base" FILES ${SRC_BASE})

set(SRC_ENTITIES
  Entities/ShadingInfo.h
  Entities/ShadingInfo.inl
)
source_group("Entities" FILES ${SRC_ENTITIES})

set(SRC_GRAPHICS
  Graphics/Color.h
  Graphics/Color.inl
  Graphics/DisplayMode.h
  Graphics/DisplayMode.inl
  Graphics/DrawPort.h
  Graphics/DrawPort.inl
  Graphics/Font.h
  Graphics/Font.inl
  Graphics/GfxLibrary.h
  Graphics/GfxLibrary.inl
  Graphics/ImageInfo.h
  Graphics/ImageInfo.inl
  Graphics/Raster.h
  Graphics/Raster.inl
  Graphics/Texture.h
  Graphics/Texture.inl
  Graphics/Vertex.h
  Graphics/Vertex.inl
  Graphics/ViewPort.h
  Graphics/ViewPort.inl
)
source_group("Graphics" FILES ${SRC_GRAPHICS})

set(SRC_MATH
  Math/AABBox.h
  Math/AABBox.inl
  Math/Functions.h
  Math/Functions.inl
  Math/Geometry.h
  Math/Geometry.inl
  Math/Matrix.h
  Math/Matrix.inl
  Math/MatrixDecl.h
  Math/OBBox.h
  Math/OBBox.inl
  Math/Object3D.h
  Math/Object3D.inl
  Math/Placement.h
  Math/Placement.inl
  Math/Plane.h
  Math/Plane.inl
  Math/Projection.h
  Math/Projection.inl
  Math/Projection_DOUBLE.h
  Math/Projection_DOUBLE.inl
  Math/Quaternion.h
  Math/Quaternion.inl
  Math/TextureMapping.h
  Math/TextureMapping.inl
  Math/Vector.h
  Math/Vector.inl
  Math/VectorDecl.h
)
source_group("Math" FILES ${SRC_MATH})

set(SRC_MODELS
  Models/Model_internal.h
  Models/Model_internal.inl
  Models/ModelData.h
  Models/ModelData.inl
  Models/ModelObject.h
  Models/ModelObject.inl
  Models/Normals.h
  Models/Normals.inl
  Models/RenderModel.h
  Models/RenderModel.inl
)
source_group("Models" FILES ${SRC_MODELS})

set(SRC_SOUND
  Sound/SoundData.h
  Sound/SoundData.inl
  Sound/SoundLibrary.h
  Sound/SoundLibrary.inl
  Sound/SoundListener.h
  Sound/SoundListener.inl
  Sound/SoundObject.h
  Sound/SoundObject.inl
)
source_group("Sound" FILES ${SRC_SOUND})

set(SRC_TEMPLATES
  Templates/DynamicArray.h
  Templates/DynamicArray.inl
  Templates/DynamicContainer.h
  Templates/DynamicContainer.inl
  Templates/DynamicStackArray.h
  Templates/DynamicStackArray.inl
  Templates/StaticArray.h
  Templates/StaticArray.inl
  Templates/StaticStackArray.h
  Templates/StaticStackArray.inl
  Templates/Stock_CAnimData.h
  Templates/Stock_CModelData.h
  Templates/Stock_CSoundData.h
  Templates/Stock_CTextureData.h
)
source_group("Templates" FILES ${SRC_TEMPLATES})

set(SRC_TERRAIN
  Terrain/ArrayHolder.h
  Terrain/ArrayHolder.inl
  Terrain/Terrain.h
  Terrain/Terrain.inl
  Terrain/TerrainLayer.h
  Terrain/TerrainLayer.inl
  Terrain/TerrainMisc.h
  Terrain/TerrainMisc.inl
  Terrain/TerrainTile.h
  Terrain/TerrainTile.inl
)
source_group("Terrain" FILES ${SRC_TERRAIN})

add_library(${PROJECT_NAME} INTERFACE
  ${SRC_BASE}
  ${SRC_ENTITIES}
  ${SRC_GRAPHICS}
  ${SRC_MATH}
  ${SRC_MODELS}
  ${SRC_SOUND}
  ${SRC_TEMPLATES}
  ${SRC_TERRAIN}
  Engine.h
  Engine.inl
  GameShell.h
  GameShell.inl
)
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>)
