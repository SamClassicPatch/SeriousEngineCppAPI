#pragma once

template<typename TObject, typename TObjectCHandle>
class TPointer
{
public:
  using TObjectType = TObject;
  using THandleType = TObjectCHandle;

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
    if (p && p->C_Handle())
      m_object.emplace((TObjectCHandle*)p->C_Handle(), false);
  }
  inline TPointer(const TPointer<TObject, TObjectCHandle>& o)
  {
    if (o)
      m_object.emplace(o.m_object->C_Handle(), false);
  }
  inline TPointer(TPointer<TObject, TObjectCHandle>&& o)
  {
    m_object = std::move(o.m_object);
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
    if (p && p->C_Handle())
      m_object.emplace((TObjectCHandle*)p->C_Handle(), false);
    return *this;
  }
  inline TPointer& operator=(const TPointer<TObject, TObjectCHandle>& o)
  {
    m_object.reset();
    if (o)
      m_object.emplace((TObjectCHandle*)o.m_object->C_Handle(), false);
    return *this;
  }
  inline TPointer& operator=(TPointer<TObject, TObjectCHandle>&& o)
  {
    m_object.reset();
    m_object = std::move(o.m_object);
    return *this;
  }
  inline operator bool() const
  {
    return m_object.has_value() && m_object->C_Handle();
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
  inline const TObject* operator->() const
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline operator const TObject* () const
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline const TObject& operator*() const
  {
    return *m_object;
  }
  inline void Reset()
  {
    m_object.reset();
  }
  inline TObject* get()
  {
    if (m_object.has_value())
      return &(*m_object);
    return nullptr;
  }
  inline bool operator==(const TObjectCHandle* p) const
  {
    const TObjectCHandle* thisp = (m_object.has_value() ? m_object->C_Handle() : nullptr);
    return thisp == p;
  }
  inline bool operator==(const TObject* p) const
  {
    const TObjectCHandle* thisp = (m_object.has_value() ? m_object->C_Handle() : nullptr);
    const TObjectCHandle* op = (p ? p->C_Handle() : nullptr);
    return thisp == op;
  }
  inline bool operator==(const TPointer<TObject, TObjectCHandle>& o) const
  {
    const TObjectCHandle* thisp = (m_object.has_value() ? m_object->C_Handle() : nullptr);
    const TObjectCHandle* op = (o.m_object.has_value() ? o.m_object->C_Handle() : nullptr);
    return thisp == op;
  }
  inline bool operator!=(const TObjectCHandle* p) const { return !((*this) == p); }
  inline bool operator!=(const TObject* p) const { return !((*this) == p); }
  inline bool operator!=(const TPointer<TObject, TObjectCHandle>& o) const { return !((*this) == o); }

private:
  std::optional<TObject> m_object;
};
