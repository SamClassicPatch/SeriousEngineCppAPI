cmake_minimum_required(VERSION 3.12)

project(SeriousEngineCppAPI LANGUAGES CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(SRC_BASE
  Base/Anim.h
  Base/Anim.inl
  Base/Changeable.h
  Base/Changeable.inl
  Base/CTString.h
  Base/CTString.inl
  Base/CTStringDecl.h
  Base/FileName.h
  Base/FileName.inl
  Base/FileNameDecl.h
  Base/Lists.h
  Base/Lists.inl
  Base/Serial.h
  Base/Serial.inl
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
)
source_group("Base" FILES ${SRC_BASE})

set(SRC_GRAPHICS
  Graphics/DrawPort.h
  Graphics/Font.h
  Graphics/Font.inl
  Graphics/ImageInfo.h
  Graphics/ImageInfo.inl
  Graphics/Raster.h
  Graphics/Raster.inl
  Graphics/Texture.h
  Graphics/Texture.inl
  Graphics/ViewPort.h
  Graphics/ViewPort.inl
)
source_group("Graphics" FILES ${SRC_GRAPHICS})

set(SRC_MATH
  Math/AABBox.h
  Math/AABBox.inl
  Math/Matrix.h
  Math/Matrix.inl
  Math/MatrixDecl.h
  Math/OBBox.h
  Math/OBBox.inl
  Math/Object3D.h
  Math/Placement.h
  Math/Placement.inl
  Math/Plane.h
  Math/Plane.inl
  Math/Projection.h
  Math/Projection.inl
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
  Models/RenderModel.h
  Models/RenderModel.inl
)
source_group("Models" FILES ${SRC_MODELS})

set(SRC_TEMPLATES
  Templates/DynamicArray.h
  Templates/DynamicArray.inl
  Templates/DynamicStackArray.h
  Templates/DynamicStackArray.inl
  Templates/StaticArray.h
  Templates/StaticArray.inl
  Templates/StaticStackArray.h
  Templates/StaticStackArray.inl
)
source_group("Templates" FILES ${SRC_TEMPLATES})

add_library(${PROJECT_NAME} INTERFACE
  ${SRC_BASE}
  ${SRC_GRAPHICS}
  ${SRC_MATH}
  ${SRC_MODELS}
  ${SRC_TEMPLATES}
)
target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>)
