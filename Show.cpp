#include "Show.h"
#include "GameSetting.h"
#include <cstdio>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
extern int game_speed;
extern int score;
void Show::show_start()
{
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 5);
    cout << "��ѡ����Ϸģʽ��" << endl;
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 3);
    cout << "1. �ֶ�����ģʽ" << endl;
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 - 1);
    cout << "2. AI����ģʽ" << endl;
    gotoxy(GameSetting::window_width / 2 - 10, GameSetting::window_height / 2 + 1);
    cout << "����������ѡ��-> ";
}
void Show::show_map()
{
    gotoxy(0, 0);
    // �ϱ߿�
    for (int i = 0; i < GameSetting::window_width; i++) {
        if (i == 0)
			cout << "#";
        else if (i == GameSetting::window_width - 1)
			cout << "#";
        else if (i == GameSetting::window_width - 29)
			cout << "#";
        else
			cout << "#";
    }
    // ��߿�
    for (int i = 1; i < GameSetting::window_height - 1; i++) {
        gotoxy(0, i);
		cout << "#";
    }

    // �м�ֽ���
    for (int i = 1; i < GameSetting::window_height - 1; i++) {
        gotoxy(GameSetting::window_width - 29, i);
		cout << "#";
    }
    for (int i = GameSetting::window_width - 29; i < GameSetting::window_width; i++) {
        gotoxy(i, GameSetting::window_height -10);
        if (i == GameSetting::window_width - 29)
			cout << "#";
        else
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
        if (i == 0)
			cout << "#";
        else if (i == GameSetting::window_width - 1)
			cout << "#";
        else if (i == GameSetting::window_width - 29)
			cout << "#";
        else
			cout << "#";
    }
}
void Show::show_score()
{
	
	
    gotoxy(GameSetting::window_width - 22, 4);
    cout << "��ǰ��Ϸ�ٶ�: " << 100 - game_speed / 10 << endl;
    gotoxy(GameSetting::window_width - 22, 6);
    cout << "��ǰ��ҷ���: " << score << endl;
}

void Show::show_last_score()
{
    gotoxy(GameSetting::window_width - 22, 10);
    cout << "��ʷ�������а�: " << endl;
    int k = 1;
    int last_score[11] = { 0 };
    ifstream fin("last-score.txt");
    for (int i = 0; i < 5; i++) {
        fin >> last_score[i];
	}
    fin.close();
    for (int i = 12; i < 12 + 2 * 8; i += 2, k++) {
        gotoxy(GameSetting::window_width - 20, i);
        cout << k << ": " << last_score[k]<< endl;
    }
    
}

void Show::show_gameinfo()
{
    gotoxy(GameSetting::window_width - 22, 32);
    cout << "��Ϸ����˵����" << endl;
    gotoxy(GameSetting::window_width - 22, 34);
    cout << "W: ��    S: ��" << endl;
    gotoxy(GameSetting::window_width - 22, 36);
    cout << "A: ��    D: ��" << endl;
}

void Show::show_game_over() {

}

