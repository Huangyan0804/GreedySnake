﻿#include "GameSetting.h"
#include <Windows.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int game_speed;
void GameSetting::init()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //隐藏输入符号

	char buffer[32];
	sprintf_s(buffer, "mode con cols=%d lines=%d", window_width + 2, window_height + 1);
	system(buffer);
	::SetConsoleOutputCP(936);
	game_speed = 100;
	srand((unsigned int)time(0));

	
}