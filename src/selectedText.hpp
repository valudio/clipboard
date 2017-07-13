#pragma once
#include <atlstr.h>

class SelectedText
{
public:
    static void paste();
    static void copy();
    static std::string getTextFromClipboard();
    static CStringW getTextFromClipboard2();
    static bool setTextToClipboard(CStringW textToclipboard);
};
