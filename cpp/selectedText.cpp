#include <Windows.h>
#include <iostream>
#include "SelectedText.h"
#include <string>
#include <atlstr.h>

using namespace std;


void SelectedText::paste()
{
    // Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "V" key
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "V" key
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    cout << "Paste from library \n";
}

void SelectedText::copy()
{
    // Create a generic keyboard event structure
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;


    // Press the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Press the "C" key
    ip.ki.wVk = 'C';
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "C" key
    ip.ki.wVk = 'C';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "Ctrl" key
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    cout << "Copy from library \n";
}

string SelectedText::getTextFromClipboard()
{
    if (!IsClipboardFormatAvailable(CF_UNICODETEXT))
    {
        return nullptr;
    }

    try
    {
        if (!OpenClipboard(nullptr))
            return nullptr;


        auto handle = GetClipboardData(CF_UNICODETEXT);
        if (handle == nullptr)
            return nullptr;

        WCHAR* ptr = nullptr;

        try
        {
            ptr = static_cast<WCHAR*>(GlobalLock(handle));
            GlobalUnlock(handle);
            CloseClipboard();
            // ReSharper disable CppJoinDeclarationAndAssignment
            string a;
            a = CW2A(ptr);
            // ReSharper enable CppJoinDeclarationAndAssignment
            return a;

        }
        catch (...)
        {
            if (ptr != nullptr)
                GlobalUnlock(handle);
        }

    }
    catch (...)
    {
    }

    CloseClipboard();
    return nullptr;
}

CStringW SelectedText::getTextFromClipboard2()
{
    CStringW strData;
    if (IsClipboardFormatAvailable(CF_UNICODETEXT) && OpenClipboard(nullptr))
    {
        auto handle = GetClipboardData(CF_UNICODETEXT);
        if (handle)
        {
            auto ptr = static_cast<WCHAR*>(GlobalLock(handle));
            if (ptr)
            {
                strData = ptr;
                GlobalUnlock(handle);
            }
        }
        CloseClipboard();
    }
    return strData;
}

bool SelectedText::setTextToClipboard(CStringW textToclipboard)
{
    auto success = true;

    if (OpenClipboard(nullptr))
    {
        EmptyClipboard();
        auto size = (textToclipboard.GetLength() + 1) * sizeof(WCHAR);
        auto hClipboardData = GlobalAlloc(NULL, size);
        if (hClipboardData)
        {
            auto pchData = static_cast<WCHAR*>(GlobalLock(hClipboardData));
            if (pchData)
            {
                memcpy(pchData, const_cast<WCHAR*>(textToclipboard.GetString()), size);
                GlobalUnlock(hClipboardData);
                SetClipboardData(CF_UNICODETEXT, hClipboardData);
            }
        }
        CloseClipboard();
    }
    return success;
}
