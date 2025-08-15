/**
 * @file functions.h
 * @brief Управление окнами и временем для WinAPI-приложений
 * @author Vladimir Astrelin
 * @email astrelin.vlad@gmail.com
 *
 * @details Содержит функции для:
 *          - Работы с датой/временем
 *          - Позиционирования окон
 *          - Центрирования интерфейса
 */

#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <windows.h>

#define TIMER_ID 1 ///< Идентификатор таймера для обновления времени

 /**
  * @brief Обновляет отображение даты и времени в диалоговом окне
  * @param[in] hwnd Дескриптор окна, содержащего элементы отображения
  *
  * @details Форматирует текущую дату и время в строки вида:
  *          - "DAY: DD.MM.YYYY"
  *          - "TIME: HH:MM:SS"
  *          и выводит их в элементы IDC_STATIC_DATE и IDC_STATIC_TIME
  * @note Использует безопасные функции форматирования строк
  */
void UpdateDateTime(HWND hwnd);

/**
 * @brief Устанавливает позицию окна с проверкой границ экрана
 * @param[in] hwnd Дескриптор окна для позиционирования
 * @param[in] desiredX Желаемая координата X (в пикселях)
 * @param[in] desiredY Желаемая координата Y (в пикселях)
 *
 * @details Автоматически корректирует позицию при выходе за границы экрана.
 *          Сохраняет текущий размер окна (SWP_NOSIZE).
 */
void SetWindowPosition(HWND hwnd, int desiredX, int desiredY);

/**
 * @brief Центрирует окно на экране
 * @param[in] hwnd Дескриптор окна для центрирования
 *
 * @details Вычисляет центр экрана с учетом:
 *          - Текущего разрешения
 *          - Размеров окна
 *          - Рабочей области (исключая панель задач)
 */
void CenterWindow(HWND hwnd);

#endif // FUNCTIONS_H