#include <Windows.h>
#include <iostream>
#include <string>
#include <atlstr.h>
#include "clipboard.hpp"

using namespace std;

void clipboard::paste()
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
}

void clipboard::copy()
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
}

string clipboard::getTextFromClipboard()
{

    if (!IsClipboardFormatAvailable(CF_UNICODETEXT) || !OpenClipboard(nullptr))
        return nullptr;

    try
    {
        auto handle = GetClipboardData(CF_UNICODETEXT);
        if (!handle)
            return nullptr;

        WCHAR *ptr = nullptr;

        try
        {
            ptr = static_cast<WCHAR *>(GlobalLock(handle));
            if (ptr)
            {
                GlobalUnlock(handle);
                CloseClipboard();
                // ReSharper disable CppJoinDeclarationAndAssignment
                string a;
                a = CW2A(ptr);
                // ReSharper enable CppJoinDeclarationAndAssignment
                return a;
            }
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

bool clipboard::setTextToClipboard(CStringW textToclipboard)
{
    auto success = false;

    if (OpenClipboard(nullptr))
    {
        try
        {
            EmptyClipboard();
            auto size = (textToclipboard.GetLength() + 1) * sizeof(WCHAR);
            auto hClipboardData = GlobalAlloc(NULL, size);
            if (hClipboardData)
            {
                auto pchData = static_cast<WCHAR *>(GlobalLock(hClipboardData));
                if (pchData)
                {
                    memcpy(pchData, const_cast<WCHAR *>(textToclipboard.GetString()), size);
                    GlobalUnlock(hClipboardData);
                    SetClipboardData(CF_UNICODETEXT, hClipboardData);
                    success = true;
                }
            }
        }
        catch (...)
        {
        }

        CloseClipboard();
    }
    return success;
}
