#pragma

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <playground.h>

#include "game.h"
#include "gui.h"

int get_center(const char *text)
{
    return WIDTH / 2 - (strlen(text) / 2);
}

int im_print_text_clicked(int x, int y, const char *text)
{
    int mX, mY;
    pg_get_mouse_coords(&mX, &mY);
    for (int i = 0; i < strlen(text); i++)
        pg_put_char_ex(x + i, y, text[i], 0xFFFFFFFF, 0xFF000000, PG_COL_REPLACE);
    return 0;
}

int im_print_text(int x, int y, const char *text)
{
    int mX, mY;
    pg_get_mouse_coords(&mX, &mY);
    for (int i = 0; i < strlen(text); i++)
        pg_put_char(x + i, y, text[i], PG_COL_DEFAULT);
    return 0;
}

int im_print(int x, int y, const char *format, ...)
{
    va_list info;
    va_start(info, format);
    char str[1024];
    vsprintf(str, format, info);
    im_print_text(x, y, str);
    va_end(info);
    return 0;
}

bool im_button(int x, int y, const char *text)
{
    int mX, mY;
    pg_get_mouse_coords(&mX, &mY);
    if ((mX >= x && mX <= (x + strlen(text) - 1)) && mY == y && pg_io_mouse_button_released(GLFW_MOUSE_BUTTON_LEFT))
    {
        im_print_text_clicked(x, y, text);
        return true;
    }
    else
    {
        im_print_text(x, y, text);
        return false;
    }
}