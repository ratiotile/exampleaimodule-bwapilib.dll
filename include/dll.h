#pragma once
#ifdef EXPORTING_DLL
#define DLLEXPORT __declspec(dllexport)
#define DLLEXPORT_TEMPLATE
#else
#define DLLEXPORT __declspec(dllimport)
#define DLLEXPORT_TEMPLATE extern
#endif



;
