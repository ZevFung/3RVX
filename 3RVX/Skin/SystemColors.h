#pragma once

#include <Windows.h>
#include "../Logger.h"
#include <math.h>
#include <algorithm>

#include <dwmapi.h>

class SystemColors {

    struct DwmColorizationParams {
        UINT ColorizationColor;
        UINT ColorizationAfterglow;
        UINT ColorizationColorBalance;
        UINT ColorizationAfterglowBalance;
        UINT ColorizationBlurBalance;
        UINT ColorizationGlassReflectionIntensity;
        UINT ColorizationOpaqueBlend;
    };

public:
    SystemColors() {
        HMODULE dwm = LoadLibrary(L"dwmapi.dll");
        *(FARPROC *) &DwmGetColorizationParameters = GetProcAddress(dwm, (LPCSTR) 127);
        DwmColorizationParams params = { 0 };
        HRESULT hr = DwmGetColorizationParameters(&params);
        if (FAILED(hr)) {
            CLOG(L"couldn't get dwm params");
        }

        CLOG(L"-> %x", params.ColorizationColor);
        CLOG(L"-> %x", params.ColorizationAfterglow);
        CLOG(L"-> %d", params.ColorizationColorBalance);
        CLOG(L"-> %d", params.ColorizationAfterglowBalance);
        CLOG(L"-> %x", params.ColorizationBlurBalance);
        CLOG(L"-> %x", params.ColorizationGlassReflectionIntensity);
        CLOG(L"-> %x", params.ColorizationOpaqueBlend);

        DWORD val;
        BOOL opaque;
        DwmGetColorizationColor(&val, &opaque);

        CLOG(L"=> %x", val);
    }

private:
    HRESULT(WINAPI *DwmGetColorizationParameters)
        (DwmColorizationParams *colorParams);


};