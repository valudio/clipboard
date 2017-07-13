#pragma once
#include <atlstr.h>

class clipboard
{
public:
    static void paste();
    static void copy();
    static std::string getTextFromClipboard();
    static bool setTextToClipboard(CStringW textToclipboard);
};
