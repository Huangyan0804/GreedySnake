#include "GameSetting.h"
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int game_speed = 50;
int score = 0;
void GameSetting::init()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //隐藏输入符号

    char buffer[32];
    sprintf_s(buffer, "mode con cols=%d lines=%d", window_width + 2, window_height + 1);
    system(buffer);

    srand((unsigned int)time(0));

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
}