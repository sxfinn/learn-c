#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"game.h"
void game()
{
	char ret = '\0';
	char board[AX][AY];//�����������
	in_board(board,AX,AY);//��ʼ������
	print(board, AX, AY);//��ӡ����
	while (1)
	{
		player(board, AX, AY);//�������
		print(board, AX, AY);
		ret=judge(board, AX, AY);
		if (ret != 'c')
			break;
		computer(board, AX, AY);//��������
		print(board, AX, AY);
		ret=judge(board, AX, AY);
		if (ret != 'c')
			break;
			
	}
	if (ret == '#')
	{
		printf("���Ӯ\n");
		print(board, AX, AY);
	}
	else if (ret == '*')
	{
		printf("����Ӯ\n");
		print(board, AX, AY);
	}
	else if (ret == 'p')
	{
		printf("ƽ��\n");
		print(board, AX, AY);
	}
	

	

		

}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		printf("*************\n");
		printf("****1>play***\n");
		printf("****0.exit***\n");
		printf("*************\n");
		printf("������1����0��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:printf("��������Ϸ��ʼ\n");
			game();
			break;
		case 0:printf("��Ϸ�˳�");
			break;
		default:printf("�����������������");
			break;
		}

	} while (input);
	return 0;
}