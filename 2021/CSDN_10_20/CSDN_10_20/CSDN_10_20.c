#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�����ṹ������
struct student
{
	char name[20];
	int age;
	char sex[10];
	char id[10];
};
int main()
{
	struct student a = { "����",20,"��","2020088" };//��ʼ���ṹ�����
	struct student* pa = &a;//������a�ĵ�ַ���ṹ��ָ�����
	//ʹ��.���������ʽṹ��Ա��//��ӡ�ṹ����Ϣ
	printf(" %s %d %s %s\n", a.name, a.age, a.sex, a.id);
	//->��������//��ӡ�ṹ����Ϣ
	printf(" %s %d %s %s\n", pa->name, pa->age, pa->sex, pa->id);
	return 0;
}
//int main()
//{
//	int num = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	arr = &num;//���ܸ�ֵ����������ָ�볣��
//	return 0;
//}
////ָ������Ĵ�Сȡ���ڵ�ַ�Ĵ�С
//	//32Ϊƽ̨�ϵ�ַ�Ĵ�С��32bit
//	//64λƽ̨�ϵ�ַ�Ĵ�С��64bit
//int main()
//{
//	printf(" int*��С=%d\n", sizeof(int*));
//	printf(" char*��С=%d\n", sizeof(char*));
//	printf(" double*��С=%d\n", sizeof(double*));
//	printf(" short*��С=%d\n", sizeof(short*));
//
//	return 0;
//}
//int main()
//{
//	char ch = 'a';
//	char* pc = &ch;
//	*pc = 'h';
//	printf("ch= %c ", ch);
//	printf("*pc= %c ", *pc);
//	return 0;
//}
//int main()
//{
//	int num = 10;
//	int* p = &num;
//	*p = 20;
//	printf(" num=%d ", num);
//	printf("*p=%d", *p);
//	return 0;
//}
//int main()
//{
//	int num = 10;
//	int* p;//pΪһ�����ͱ�����ָ��
//	p = &num;//��ֵ
//	return 0;
//}
//int main()
//{
//	//��������
//	int i = 1;
//	//&��ȡ��ַ��������&i����i�ĵ�ַ
//	printf("%p", &i);
//	return 0;
//}
////#define�����ʶ������
//#define MAX 100
////#define�����
//# define BIG(x,y) (x>y?x:y)
//int main()
//{
//	int max = BIG(2, 3);
//	printf(" %d ", MAX);
//	printf(" %d ", max);
//	return 0;
//}
//extern n;
//int main()
//{
//	printf("%d", n);
//	return 0;
//}
//int main()
//{
//	int sum = Add(2, 3);
//	return 0;
//}
//static int i = 1;
//int main()
//{
//	int a = 0;
//	return 0;
//}
//int  Add(int x, int y);
//int main()
//{
//	int x = 3;
//	int y = 5;
//	int sum = Add(x, y);
//	printf(" %d", sum);
//	return 0;
//}
////����3
//void test()
//{//���ｫi��static����
//	static int i = 1;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
////��unsigned��������Ϊunsin������unsinҲ��һ��������
//typedef unsigned int unsin;
//int main()
//{
//	//�۲�a��b��������������������һ����
//	unsigned int a = 0;
//	unsin b = 0;
//	return 0;
//}