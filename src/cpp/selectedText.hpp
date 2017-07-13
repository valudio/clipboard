#pragma once
#include <atlstr.h>

class SelectedText
{
public:
    static void paste();
    static void copy();
    static std::string getTextFromClipboard();
    static bool setTextToClipboard(CStringW textToclipboard);
};
