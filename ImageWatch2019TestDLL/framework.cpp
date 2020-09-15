#include "framework.h"
#include <algorithm>
#include <iostream>

img_base::img_base()
{
}

img_base::~img_base()
{
}

void __stdcall img_base::Reset()
{
    m_rect.X = 0;
    m_rect.Y = 0;
    m_rect.Width = 0;
    m_rect.Height = 0;
}

BOOL __stdcall img_base::Set(const int nX, const int nY, const int nWidth, const int nHeight)
{
    m_rect.X = nX;
    m_rect.Y = nY;
    m_rect.Width = nWidth;
    m_rect.Height = nHeight;
    return TRUE;
}

BOOL img_base::Equals(const img_base& cItem) const
{
    return 0;
}

test_img::test_img() : m_pDots(nullptr), m_bAttached(FALSE)
{
}

test_img::~test_img()
{
    test_img::Clear();
}

void test_img::Free()
{
    if (!m_bAttached)
        free(m_pDots);
    m_bAttached = FALSE;
    m_pDots = nullptr;
}

bool test_img::operator==(const test_img& other) const
{
    return this->Equals(other) == TRUE;
}

bool test_img::operator!=(const test_img& other) const
{
    return !(*this == other);
}

void test_img::Clear()
{
    img_base::Reset();
    Free();
}

BOOL test_img::Create(const int nWidth, const int nHeight)
{
    Free();
    m_pDots = static_cast<BYTE*>(malloc(static_cast<std::size_t>(nWidth) *
        static_cast<std::size_t>(nHeight)));
    if (m_pDots == nullptr)
    {
        return FALSE;
    }
    m_rect.Height = nHeight;
    m_rect.Width = nWidth;
    m_nPitch = nWidth;
    return TRUE;
}
bool test_img::Create(const test_img& source)
{
    if (!Create(source.m_rect.Width, source.m_rect.Height))
    { //
        return false;
    }
    // Have source and destination same pitch?
    bool bEqualPitch = (source.m_nPitch == this->m_nPitch) ? true : false;
    // Copy picture data.
    if (bEqualPitch == TRUE)
    { // Complete block.
        memcpy(this->m_pDots, source.m_pDots,
            this->m_nPitch * this->m_rect.Height * sizeof(*this->m_pDots));
    }
    else
    { // Line by line.
        LPBYTE pS = source.m_pDots;
        LPBYTE pD = this->m_pDots;
        for (int nRow = 0; nRow < this->m_rect.Height; nRow++)
        {
            memcpy(pD, pS, this->m_rect.Width * sizeof(*pD));

            pS += source.m_nPitch;
            pD += this->m_nPitch;
        }
    }
    return true;
}

BOOL test_img::CreateAndFill(const int nWidth, const int nHeight, BYTE value)
{
    if (Create(nWidth, nHeight))
    {
        std::uninitialized_fill(m_pDots, m_pDots + (nWidth * nHeight), value);
        return TRUE;
    }
    return FALSE;
}

void test_img::Attach(const int nX,
    const int nY,
    const int nWidth,
    const int nHeight,
    const int nPitch,
    LPBYTE    pDots)
{
    Free();
    m_bAttached = TRUE;
    m_pDots = pDots;
    m_nPitch = nPitch;
    Set(nX, nY, nWidth, nHeight);
}

BOOL test_img::Equals(const test_img& cItem) const
{
    if (img_base::Equals(cItem) == FALSE)
        return FALSE;
    if (m_pDots == nullptr)
        if (cItem.m_pDots != nullptr)
            return FALSE;
    if (cItem.m_pDots == nullptr)
        if (m_pDots != nullptr)
            return FALSE;

    if ((cItem.m_pDots != nullptr) && (m_pDots != nullptr))
    {
        for (int nRow = m_rect.Height - 1; nRow >= 0; nRow--)
        {
            const int nOffset = nRow * m_nPitch;
            if (memcmp(m_pDots + nOffset, cItem.m_pDots + nOffset,
                m_rect.Width * sizeof(*m_pDots)) != 0)
                return FALSE;
        }
    }
    return TRUE;
}

bool test_img::CopyTo(test_img& other) const
{
    other.Clear();

    if (this != nullptr)
    {
        return other.Create(*this);
    }

    return false;
}

void step_into_this_function_to_see_image_watch_work(const test_img& img)
{
    std::cout << "Set breakpoint here, ImageWatch will show CORRECT data!\n";
}