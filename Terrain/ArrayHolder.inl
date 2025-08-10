#pragma once

IMPL_CStaticArray(GFXColor)
IMPL_CStaticArray(GFXTexCoord)
IMPL_CStaticArray(GFXVertex4)

IMPL_CStaticStackArray(GFXColor)
IMPL_CStaticStackArray(GFXTexCoord)
IMPL_CStaticStackArray(GFXVertex4)


inline TileLayer::TileLayer(TileLayer_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , tl_auiIndices(TileLayer_tl_auiIndices(mp_handle), false)
  , tl_acColors(TileLayer_tl_acColors(mp_handle), false)
  , tl_atcTexCoords(TileLayer_tl_atcTexCoords(mp_handle), false)
  , tl_avVertices(TileLayer_tl_avVertices(mp_handle), false)
{
}

inline TileLayer::TileLayer()
  : TileLayer(TileLayer_new(), true)
{
}

inline TileLayer::TileLayer(const TileLayer& o)
  : TileLayer(TileLayer_clone(o), true)
{
}

inline TileLayer::~TileLayer()
{
  if (m_owner)
    TileLayer_delete(mp_handle);
}

inline TileLayer& TileLayer::operator=(const TileLayer& o)
{
  TileLayer_copy(mp_handle, o);
  return *this;
}

IMPL_CStaticArray(TileLayer)
IMPL_CStaticStackArray(TileLayer)

inline TileArrays::TileArrays(TileArrays_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ta_avVertices(TileArrays_ta_avVertices(mp_handle), false)
  , ta_auvTexCoords(TileArrays_ta_auvTexCoords(mp_handle), false)
  , ta_auvShadowMap(TileArrays_ta_auvShadowMap(mp_handle), false)
  , ta_auvDetailMap(TileArrays_ta_auvDetailMap(mp_handle), false)
  , ta_auiIndices(TileArrays_ta_auiIndices(mp_handle), false)
  , ta_atlLayers(TileArrays_ta_atlLayers(mp_handle), false)
  , ta_ptdTopMap(*TileArrays_ta_ptdTopMap(mp_handle))
{
}

inline TileArrays::TileArrays()
  : TileArrays(TileArrays_new(), true)
{
}

inline TileArrays::TileArrays(const TileArrays& o)
  : TileArrays(TileArrays_clone(o), true)
{
}

inline TileArrays::~TileArrays()
{
  if (m_owner)
    TileArrays_delete(mp_handle);
}

inline TileArrays& TileArrays::operator=(const TileArrays& o)
{
  TileArrays_copy(mp_handle, o);
  return *this;
}

IMPL_CStaticArray(TileArrays)
IMPL_CStaticStackArray(TileArrays)


inline CArrayHolder::CArrayHolder(CArrayHolder_* p, bool owner)
  : m_owner(owner)
  , mp_handle(p)
  , ah_ptrTerrain(*CArrayHolder_ah_ptrTerrain(mp_handle))
  , ah_ataTileArrays(CArrayHolder_ah_ataTileArrays(mp_handle), false)
  , ah_aiFreeArrays(CArrayHolder_ah_aiFreeArrays(mp_handle), false)
  , ah_iLod(*CArrayHolder_ah_iLod(mp_handle))
{
}

inline CArrayHolder::CArrayHolder()
  : CArrayHolder(CArrayHolder_new(), true)
{
}

inline CArrayHolder::CArrayHolder(const CArrayHolder& o)
  : CArrayHolder(CArrayHolder_clone(o), true)
{
}

inline CArrayHolder::~CArrayHolder()
{
  if (m_owner)
    CArrayHolder_delete(mp_handle);
}

inline CArrayHolder& CArrayHolder::operator=(const CArrayHolder& o)
{
  CArrayHolder_copy(mp_handle, o);
  return *this;
}

inline INDEX CArrayHolder::GetNewArrays()
{
  return CArrayHolder_GetNewArrays(mp_handle);
}

inline void CArrayHolder::FreeArrays(INDEX iOldArraysIndex)
{
  CArrayHolder_FreeArrays(mp_handle, iOldArraysIndex);
}

inline void CArrayHolder::EmptyArrays(INDEX iArrayIndex)
{
  CArrayHolder_EmptyArrays(mp_handle, iArrayIndex);
}

inline void CArrayHolder::Clear()
{
  CArrayHolder_Clear(mp_handle);
}

inline SLONG CArrayHolder::GetUsedMemory()
{
  return CArrayHolder_GetUsedMemory(mp_handle);
}
