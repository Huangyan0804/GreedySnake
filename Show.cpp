#pragma once
#include "Show.h"
#include "Food.h"
#include "GameSetting.h"
#include "Snake.h"
#include <Windows.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

extern int score;
void Show::show_start(Snake& snake)
{
    gotoxy(0, 5);
    printf("  ########################################\n");
    printf("  #                                      #\n");
    printf("  #         ��ӭ����̰������Ϸ           #\n");
    printf("  #                                      #\n");
    printf("  #           ��ѡ����Ϸģʽ��           #\n");
    printf("  #                                      #\n");
    printf("  #           1. �ֶ�����ģʽ            #\n");
    printf("  #                                      #\n");
    printf("  #           2. AI����ģʽ              #\n");
    printf("  #                                      #\n");
    printf("  ########################################\n");

    while (true) {
        gotoxy(12, 17);
        
        char input = _getch();
        if (input == '1') {
            snake.model = true;
            break;
        } else if (input == '2') {
            snake.model = false;
            break;
        } else {
            cout << "�����������������" << endl;
        }
    }
    system("cls");
    gotoxy(0, 5);
    printf("  ########################################\n");
    printf("  #                                      #\n");
    printf("  #        ���� W A S D ���Ʒ���         #\n");
    printf("  #                                      #\n");
    printf("  #         + / - ������Ϸ�ٶ�           #\n");
    printf("  #                                      #\n");
    printf("  #         �ո��л�AI/�˹�ģʽ          #\n");
    printf("  #                                      #\n");
    printf("  #          ���������ʼ��Ϸ            #\n");
    printf("  #                                      #\n");
    printf("  ########################################\n");
    _getch();
    system("cls");
}
void Show::show_map()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 119); // ���ð�ɫ
    // �ϱ߿�
    for (int i = 0; i < GameSetting::window_width; i++) {

        cout << "#";
    }
    // ��߿�
    for (int i = 1; i < GameSetting::window_height - 1; i++) {
        gotoxy(0, i);
        cout << "#";
    }

    // �м�ֽ���
    for (int i = 1; i < GameSetting::window_height - 1; i++) {
        gotoxy(GameSetting::window_width - 21, i);
        cout << "#";
    }
    for (int i = GameSetting::window_width - 21; i < GameSetting::window_width; i++) {
        gotoxy(i, GameSetting::window_height - 9);

        cout << "#";
    }

    // �ұ߿�
    for (int i = 1; i < GameSetting::window_height - 1; i++) {
        gotoxy(GameSetting::window_width - 1, i);
        cout << "#";
    }

    // �±߿�
    gotoxy(0, GameSetting::window_height - 1);
    for (int i = 0; i < GameSetting::window_width; i++) {
        cout << "#";
    }
    SetConsoleTextAttribute(handle, 7);
}
void Show::show_score(Snake& s)
{

    gotoxy(GameSetting::window_width - 19, 2);
    cout << "��ǰ��Ϸ�ٶ�: " << setfill('0') << setw(3) << 100 - (s.get_speed() / 10) << endl;
    gotoxy(GameSetting::window_width - 19, 4);
    cout << "��ǰ��ҷ���: " << score << endl;
}

int last_score[10] = { 0 };
void Show::show_last_score()
{
    gotoxy(GameSetting::window_width - 18, 6);
    cout << "��ʷ�������а�: " << endl;
    int num = 3;
    int k = 1;
    ifstream fin("last-score.txt");
    for (int i = 0; i < num; i++) {
        fin >> last_score[i + 1];
    }
    fin.close();
    for (int i = 8; i < 8 + 2 * num; i += 2, k++) {
        gotoxy(GameSetting::window_width - 14, i);
        cout << k << ": " << last_score[k] << endl;
    }
}

void Show::show_gameinfo()
{
    gotoxy(GameSetting::window_width - 17, GameSetting::window_height - 7);
    cout << "��Ϸ����˵����" << endl;
    gotoxy(GameSetting::window_width - 20, GameSetting::window_height - 5);
    cout << "W �� S �� A �� D ��" << endl;
    gotoxy(GameSetting::window_width - 20, GameSetting::window_height - 4);
    cout << "  +  ���� -  ����" << endl;
    gotoxy(GameSetting::window_width - 20, GameSetting::window_height - 3);
    cout << "   �ո� �л�ģʽ" << endl;
}

bool Show::show_game_over()
{
    system("cls");
    //HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(handle, 119);
    last_score[3] = score;
    sort(last_score, last_score + 4, greater<int>());
    ofstream fout("last-score.txt");
    if (fout) {
        for (int i = 0; i < 3; i++) {
            fout << last_score[i] << endl;
        }
    }
    fout.close();

    gotoxy(0, 7);
    printf("  ########################################\n");
    printf("  #                                      #\n");
    printf("  #             ������Ϸ����             #\n");
    printf("  #                                      #\n");
    printf("  #           ���ε÷֣�%03d ��           #\n", score);
    printf("  #                                      #\n");
    printf("  #           ���س���������Ϸ           #\n");
    printf("  #                                      #\n");
    printf("  ########################################\n");
	
	char input = '1';
    while (input != 13) {
		input = _getch();
	}
    return true;
    //SetConsoleTextAttribute(handle, 7);
}
