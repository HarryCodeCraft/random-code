

// #include "pch.h"
#include <windows.h>
#include <iostream>
// #include <iomanip>
// #include <chrono>
// #include "atlimage.h"
// #include <gdiplus.h>

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT HBITMAP Dustin5(HWND hWnd, LONG* a2, int* a3, void** a4) {
    void **v4;
    int *v5;
    LONG *v6;
    HWND v7;
    int v8;
    HDC v9;
    HBITMAP v10;
    HDC v11;
    HDC v12;
    //struct tagRect Rect;
    RECT Rect;
    BITMAPINFO bmi;

    v4 = a4;
    v5 = a3;
    v6 = a2;
    v7 = hWnd;
    // if not hwnd return 0i64;
    //GetClientRect(v7, &Rect);
    //v8 = Rect.bottom - Rect.top;
    //*v6 = Rect.right - Rect.left;
    //*v5 = v8;
    if (GetWindowRect(hWnd, &Rect))
    {
        v8 = Rect.bottom - Rect.top - 39;
        *v6 = Rect.right - Rect.left - 16;
        /*width = 300;
        height = 200;*/
        *v5 = v8;
    }
    ZeroMemory(&bmi, sizeof(BITMAPINFO));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biXPelsPerMeter = 0;
    bmi.bmiHeader.biClrImportant = 0;
    //
    bmi.bmiHeader.biWidth = *v6;
    bmi.bmiHeader.biSize = 40;
    bmi.bmiHeader.biHeight = -v8;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biXPelsPerMeter = 0i64;
    bmi.bmiHeader.biSizeImage = 4*(v8)*(*v6);
    bmi.bmiHeader.biClrUsed = 0i64;

    v9 = GetDC(v7);
    v10 = CreateDIBSection(v9,&bmi,0,v4,0i64,0);
    if (v10) {
        v11 = CreateCompatibleDC(v9);
        v12 = v11;
        if (v11) {
            if (SelectObject(v11, v10) && BitBlt(v12, 0, 0, *v6, *v5, v9, 0, 0, 0xcc0020u)) { //BitBlt(v12, 0, 0, *v6, *v5, v9, 0, 0, srccopy);
                //std::cout << "success" << std::endl;
                DeleteDC(v12);
                ReleaseDC(0i64, v9);
                return v10;
            }
            std::cout << "fail selectobjct" << std::endl;
            DeleteDC(v12);
        }
        std::cout << "fail createcompatiibledc" << std::endl;
        DeleteObject(v10);
    }
    std::cout << "fail createdibsection: " << 0i64 << std::endl;
    ReleaseDC(0i64, v9);
    return 0i64;
}
