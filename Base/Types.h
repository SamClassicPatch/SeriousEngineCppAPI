#pragma once
#include <SeriousEngineCAPI/Base/Types.h>

class FLOAT2D;
class FLOAT3D;
class FLOAT4D;
class DOUBLE2D;
class DOUBLE3D;
class DOUBLE4D;
class INDEX2D;
class INDEX3D;
class INDEX4D;
using ANGLE3D = FLOAT3D;
using PIX2D = INDEX2D;
using MEX2D = INDEX2D;
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
class CDynamicStackArray_FLOAT;
class CDynamicStackArray_CTString;
class CDynamicStackArray_CTFileName;

inline void SECppAPI_CheckException()
{
  if (HasException())
    throw GrabException();
}
