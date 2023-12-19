#include <Windows.h>
#include <iostream>

int main() {
    HDC hdc = GetDC(nullptr);

            std::cout << "check 1" << std::endl;


    // Specify the font and character
    HFONT hFont = CreateFont(24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                             OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                             VARIABLE_PITCH, TEXT("Arial"));  // Use TEXT() for character set compatibility

            std::cout << "worked!" << std::endl;


    SelectObject(hdc, hFont);

    // Specify the glyph index for 'A'
    WORD glyphIndex = 'A';

    // Get the glyph outline size
    DWORD outlineSize = GetGlyphOutline(hdc, glyphIndex, GGO_NATIVE, nullptr, 0, nullptr, nullptr);

    if (outlineSize != GDI_ERROR) {
        // Allocate memory for the outline data
        BYTE* outlineBuffer = new BYTE[outlineSize];

        // Retrieve the glyph outline
        DWORD result = GetGlyphOutline(hdc, glyphIndex, GGO_NATIVE, nullptr, outlineSize, outlineBuffer, nullptr);

        if (result != GDI_ERROR) {
            // 'outlineBuffer' now contains the glyph outline data
            std::cout << "Glyph outline retrieved successfully." << std::endl;
        } else {
            std::cerr << "Failed to retrieve glyph outline." << std::endl;
        }

        delete[] outlineBuffer;
    } else {
        std::cerr << "Failed to get glyph outline size." << std::endl;
    }

    // Cleanup
    DeleteObject(hFont);
    ReleaseDC(nullptr, hdc);

    return 0;
}

