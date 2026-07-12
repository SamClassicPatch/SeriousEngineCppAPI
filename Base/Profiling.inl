#pragma once

inline CProfileForm::CProfileForm(CProfileForm_* p)
  : mp_handle(p)
{
}

inline CProfileForm::~CProfileForm()
{
}

inline void CProfileForm::Reset()
{
  CProfileForm_Reset(mp_handle);
}

inline void CProfileForm::Report(CTString& strReport)
{
  CProfileForm_Report(mp_handle, strReport);
}
