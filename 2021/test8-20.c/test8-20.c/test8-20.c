#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<string.h>
#include<stdlib.h>//system����ͷ�ļ�
//#include<windows.h>//Sleep����ͷ�ļ�
#include<time.h>//time����ͷ�ļ�
void sss(int arr[][3])
{
	
	printf("%p\n", arr);
	printf("%p", arr[0]);
}
int main()
{
	int a[][3] = { 1,2,3,4,5,6,6,7,8, };
	sss(a);
	printf("\n%p", a);
	return 0;
}