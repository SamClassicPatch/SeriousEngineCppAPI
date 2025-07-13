#pragma once
#include <SeriousEngineCAPI/Base/Types.h>
#include <optional>

class FLOAT2D;
class FLOAT3D;
class FLOAT4D;
class DOUBLE2D;
class DOUBLE3D;
class DOUBLE4D;
class INDEX2D;
class INDEX3D;
class INDEX4D;
class SWORD3D;
class SBYTE3D;
using ANGLE3D = FLOAT3D;
using PIX2D = INDEX2D;
using MEX2D = INDEX2D;
using SWPOINT3D = SWORD3D;
using SBPOINT3D = SBYTE3D;
class INDEXaabbox2D;
class FLOATaabbox2D;
class FLOATaabbox3D;
class DOUBLEaabbox2D;
class DOUBLEaabbox3D;
using MEXaabbox2D = INDEXaabbox2D;
using PIXaabbox2D = INDEXaabbox2D;
class FLOATobbox3D;
class DOUBLEobbox3D;
class FLOATmatrix2D;
class FLOATmatrix3D;
class FLOATmatrix4D;
class DOUBLEmatrix2D;
class DOUBLEmatrix3D;
class DOUBLEmatrix4D;
class INDEXmatrix2D;
class INDEXmatrix3D;
class INDEXmatrix4D;
class FLOATquat3D;
class DOUBLEquat3D;
class CPlacement3D;
class FLOATplane3D;
class DOUBLEplane3D;
class CPlanarGradients;
class CMappingDefinitionUI;
class CMappingVectors;
class CMappingDefinition;
class CTCriticalSection;
class CTSingleLock;
class CTimerValue;
class CTimerHandler;
class CChangeable;
class CUpdateable;
class CSerial;
class CAnimInfo;
class COneAnim;
class CAnimData;
class CAnimObject;
class CImageInfo;
class CTextureData;
class CTextureObject;
class ModelPolygonVertex;
class PolygonsPerPatch;
class ModelPolygon;
class ModelTextureVertex;
class MappingSurface;
class ModelFrameVertex8;
class ModelFrameVertex16;
class ModelFrameInfo;
class TransformedVertexData;
class CModelCollisionBox;
class CAttachedModelPosition;
class CMipInfo;
class CModelInfo;
class CModelPatch;
class ModelMipInfo;
class CModelData;
class CTString;
class CTFileName;
class CChunkID;
class CTStream;
class CTranslationPair;
class CListHead;
class CListNode;
class CDynamicArray_FLOAT;
class CDynamicArray_CTString;
class CDynamicArray_CTFileName;
class CDynamicArray_CTranslationPair;
class CDynamicArray_CModelCollisionBox;
class CDynamicArray_CAttachedModelPosition;
class CDynamicStackArray_FLOAT;
class CDynamicStackArray_CTString;
class CDynamicStackArray_CTFileName;
class CStaticArray_PolygonsPerPatch;
class CStaticArray_ModelPolygon;
class CStaticArray_ModelTextureVertex;
class CStaticArray_MappingSurface;
class CStaticArray_ModelFrameVertex8;
class CStaticArray_ModelFrameVertex16;
class CStaticArray_ModelFrameInfo;
class CStaticArray_TransformedVertexData;
class CStaticArray_ModelPolygonVertex;
class CStaticArray_PIX2D;
class CStaticArray_FLOAT2D;
class CStaticArray_FLOAT3D;
class CStaticArray_UWORD;
class CStaticArray_ULONG;
class CStaticArray_INDEX;
class CStaticArray_SLONG;
class CStaticStackArray_INDEX;
class CStaticStackArray_SLONG;
class CStaticStackArray_FLOAT3D;
class CStaticStackArray_PIX2D;
class CModelRenderPrefs;
class CRenderModel;
class CModelObject;
class CAttachmentModelObject;
class CDrawPort;
class CViewPort;
class CRaster;
class CSoundData;
class CSoundObject;
class CFontData;
class CFontCharData;
class CEntity;

template<typename TObject, typename TObjectCHandle>
class TPointer
{
public:
  inline TPointer()
  {
  }
  inline TPointer(TObjectCHandle* p)
  {
    if (p)
      m_object.emplace(p, false);
  }
  inline TPointer(TObject* p)
  {
    if (p)
      m_object.emplace(p->C_Handle(), false);
  }
  inline TPointer(const TPointer<TObject, TObjectCHandle>& o)
  {
    if (o)
      m_object.emplace(o.m_object->C_Handle(), false);
  }
  inline ~TPointer() = default;
  inline TPointer& operator=(TObjectCHandle* p)
  {
    m_object.reset();
    if (p)
      m_object.emplace(p, false);
    return *this;
  }
  inline TPointer& operator=(TObject* p)
  {
    m_object.reset();
    if (p)
      m_object.emplace(p, false);
    return *this;
  }
  inline TPointer& operator=(const TPointer<TObject, TObjectCHandle>& o)
  {
    m_object.reset();
    if (o)
      m_object.emplace(o.m_object->C_Handle(), false);
    return *this;
  }
  inline operator bool() const
  {
    return m_object.has_value();
  }
  inline TObject* operator->()
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline operator TObject* ()
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline TObject& operator*()
  {
    return *m_object;
  }
  inline void Reset()
  {
    m_object.reset();
  }

private:
  std::optional<TObject> m_object;
};

using CTextureDataPtr = TPointer<CTextureData, CTextureData_>;
using CTextureObjectPtr = TPointer<CTextureObject, CTextureObject_>;
using CModelDataPtr = TPointer<CModelData, CModelData_>;
using CModelObjectPtr = TPointer<CModelObject, CModelObject_>;
using ModelTextureVertexPtr = TPointer<ModelTextureVertex, ModelTextureVertex_>;
using CDrawPortPtr = TPointer<CDrawPort, CDrawPort_>;
using CViewPortPtr = TPointer<CViewPort, CViewPort_>;
using CFontDataPtr = TPointer<CFontData, CFontData_>;

inline void SECppAPI_CheckException()
{
  if (HasException())
    throw GrabException();
}
