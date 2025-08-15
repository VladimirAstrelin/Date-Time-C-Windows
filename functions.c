/**
 * @file functions.c
 * @brief Реализация функций управления окнами и временем
 * @author Vladimir Astrelin
 * @email astrelin.vlad@gmail.com
 */

#include "functions.h"
#include <windows.h>
#include <stdio.h>
#include "resource.h"

void UpdateDateTime(HWND hwnd)
{
    SYSTEMTIME st;
    GetLocalTime(&st);

    WCHAR fullDateStr[100] = { 0 };
    WCHAR fullTimeStr[100] = { 0 };

    _snwprintf_s(fullDateStr, _countof(fullDateStr), _TRUNCATE,
        L"DAY: %02d.%02d.%04d", st.wDay, st.wMonth, st.wYear);

    _snwprintf_s(fullTimeStr, _countof(fullTimeStr), _TRUNCATE,
        L"TIME: %02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);

    SetDlgItemTextW(hwnd, IDC_STATIC_DATE, fullDateStr);
    SetDlgItemTextW(hwnd, IDC_STATIC_TIME, fullTimeStr);
}

void SetWindowPosition(HWND hwnd, int desiredX, int desiredY)
{
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    RECT rect;
    GetWindowRect(hwnd, &rect);
    const int windowWidth = rect.right - rect.left;
    const int windowHeight = rect.bottom - rect.top;

    // Коррекция координат с учетом границ экрана
    desiredX = max(0, min(desiredX, screenWidth - windowWidth));
    desiredY = max(0, min(desiredY, screenHeight - windowHeight));

    SetWindowPos(
        hwnd,
        NULL,
        desiredX, desiredY,
        0, 0,
        SWP_NOZORDER | SWP_NOSIZE
    );
}

void CenterWindow(HWND hwnd)
{
    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    RECT rect;
    GetWindowRect(hwnd, &rect);
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    SetWindowPos(
        hwnd,
        NULL,
        (screenWidth - width) / 2,
        (screenHeight - height) / 2,
        0, 0,
        SWP_NOZORDER | SWP_NOSIZE
    );
}