#pragma once
#ifdef SERIOUSENGINECPPAPI_EXPORTS
#define SECPPAPI __declspec(dllexport)
#else
#define SECPPAPI __declspec(dllimport)
#endif
