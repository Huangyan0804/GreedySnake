#pragma once


using namespace std;

struct Cor {
    int x, y;
    Cor(int a = 0, int b = 0)
    {
        x = a, y = b;
    }
};


class GameSetting {
	
public:
	// ���ؿ�߱� 12:16
	static const int window_width = 42; // ��Ҫ�ķ�Χ + 22
	static const int window_height = 22; // ��Ҫ�ķ�Χ + 2
	// Ĭ�Ϸ�Χ�� 20  20
	// ע���޸ĺ���Ļ��Ϣ��ƫ�ƣ���Ҫ�Լ�����
	
	void init(); // ��ʼ��
};