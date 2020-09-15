// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#ifdef IMAGEWATCH2019TESTDLL_EXPORTS
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

struct DLLAPI img_rect
{
    int X;
    int Y;
    int Width;
    int Height;
};

struct DLLAPI img_base
{
    img_rect m_rect;
    int m_nPitch;

    img_base();
    virtual ~img_base();

    void __stdcall Reset();

    virtual BOOL __stdcall Set(
        const int      nX,
        const int      nY,
        const int      nWidth,
        const int      nHeight);
    virtual BOOL Equals(const img_base& cItem) const;

};

class DLLAPI test_img : public img_base
{
public:
    test_img();
    virtual ~test_img();

    void Clear();

    BOOL Create(const int nWidth, const int nHeight);
    bool Create(const test_img& source);
    BOOL CreateAndFill(const int nWidth, const int nHeight, BYTE value);
    void Attach(const int nX,
        const int nY,
        const int nWidth,
        const int nHeight,
        const int nPitch,
        LPBYTE    pDots);
    void Free();

    bool operator==(const test_img& other) const;
    bool operator!=(const test_img& other) const;
    //bool Equals(const CThisInfo* info) const override;
    BOOL Equals(const test_img& cItem) const;

    bool CopyTo(test_img& other) const;

    LPBYTE m_pDots; // Image.
    BOOL   m_bAttached;
    // Additional information (currently only used for templates)
    // Only read from xml, no ITransformer implementation yet
    //CCustomProperties* m_pCustom;
};

DLLAPI
void step_into_this_function_to_see_image_watch_work(const test_img& img);