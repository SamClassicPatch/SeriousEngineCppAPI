#pragma once
#include "Changeable.h"
#include "FileName.h"
#include <SeriousEngineCAPI/Base/Serial.h>

/*
* Abstract base class for objects that can be saved and loaded.
*/
class CSerial : public CChangeable
{
public:
  virtual ~CSerial() = 0;

  /* Get the file name of this object. */
  const CTFileName& GetName();
  /* Get the description of this object. */
  CTString GetDescription();
  /* Load from file. */
  void Load_t(const CTFileName fnFileName); // throw char *
  /* Save to file. */
  void Save_t(const CTFileName fnFileName); // throw char *
  /* Reload from file. */
  void Reload();
  /* Mark that object is used once more. */
  void MarkUsed();
  /* Mark that object is used once less. */
  void MarkUnused();
  /* Check if object is used at least once. */
  BOOL IsUsed();
  INDEX GetUsedCount();

  /* Clear the object. */
  void Clear();
  /* Read from stream. */
  void Read_t(CTStream* istrFile); // throw char *
  /* Write to stream. */
  void Write_t(CTStream* ostrFile); // throw char *
  // check if this kind of objects is auto-freed
  BOOL IsAutoFreed();
  // get amount of memory used by this object
  SLONG GetUsedMemory();
  // gather the CRC of the file
  void AddToCRCTable();

  inline CSerial_* C_Handle() { return CSerial_From_CChangeable(mp_handle); }
  inline const CSerial_* C_Handle() const { return CSerial_From_CChangeable_const(mp_handle); }
  inline operator CSerial_* () { return C_Handle(); }
  inline operator const CSerial_* () const { return C_Handle(); }

protected:
  CSerial(CSerial_* p, bool owner = false);

private:
  const CTFileName m_name;
};

#include "Serial.inl"
