#pragma once
#include "pch.h"

#ifdef CONVERT_EXPORTS
#define CONVERT_API __declspec(dllexport)
#else
#define CONVERT_API __declspec(dllimport)
#endif

extern "C" CONVERT_API long long stringtohex(LPCTSTR szSource, LPTSTR szDestination,const UINT rate);


