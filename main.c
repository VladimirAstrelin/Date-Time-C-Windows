/**
 * @file main.c
 * @brief Главный модуль приложения с оконной процедурой
 * @author Vladimir Astrelin
 * @email astrelin.vlad@gmail.com
 */

#include <windows.h>
#include "resource.h"
#include "functions.h"

 /**
  * @brief Оконная процедура для диалогового окна
  * @param[in] hwnd Дескриптор окна
  * @param[in] uMsg Идентификатор сообщения
  * @param[in] wParam Параметр сообщения
  * @param[in] lParam Параметр сообщения
  * @return Результат обработки сообщения
  */
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_GETMINMAXINFO: {
        MINMAXINFO* pMMI = (MINMAXINFO*)lParam;
        pMMI->ptMinTrackSize.x = 450;  // Минимальная ширина
        pMMI->ptMinTrackSize.y = 450;  // Минимальная высота
		pMMI->ptMaxTrackSize.x = 750;  // Максимальная ширина
		pMMI->ptMaxTrackSize.y = 650;  // Максимальная высота
        return TRUE;  
    }
    case WM_INITDIALOG:
        SetTimer(hwnd, TIMER_ID, 1000, NULL);
        CenterWindow(hwnd);
        UpdateDateTime(hwnd);
        return TRUE;

    case WM_TIMER:
        if (wParam == TIMER_ID) {
            UpdateDateTime(hwnd);
        }
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK:
        case IDCANCEL:
            KillTimer(hwnd, TIMER_ID);
            EndDialog(hwnd, (LOWORD(wParam) == IDOK));
            return TRUE;
        }
        break;

    case WM_DESTROY:
        KillTimer(hwnd, TIMER_ID);
        break;
    }
    return FALSE;
}

/**
 * @brief Точка входа Win32-приложения
 */
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    DialogBoxParamW(hInstance, MAKEINTRESOURCEW(IDD_DIALOG1), NULL, DialogProc, 0);
    return 0;
}

