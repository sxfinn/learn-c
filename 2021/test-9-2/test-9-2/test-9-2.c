#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	inite(mine,show, ROWS, COLS);
	set(mine, ROW, COL);
	print(show, ROW, COL);
	//print(mine, ROW, COL);
	search(mine,show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		maun();
		scanf("%d", &input);
		switch (input)
		{
		case 1:printf("ɨ����Ϸ��ʼ\n");
			game();
			break;
		case 0:printf("��Ϸ�˳�\n");
			break;
		default:printf("�����������������\n");
			break;
		}

	} while (input);
	return 0;
}