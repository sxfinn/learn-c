#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	printf("����Ҳ��ѧϰ��һ�죡");
	return 0;
}
//struct book		//����һ���ṹ������
//{
//	int price;
//	char name[20];
//	int number;
//};
//int main()
//{
//	struct book C = { 22,"C����",002233 };//����һ���ṹ����� 
//	struct book* pc = &C;
//	printf("ֱ��ͨ���������ʳ�Ա��\n");
//	printf(" price=%d\n", C.price);//ͨ��.���������ʱ�����Ա
//	printf(" name=%s\n", C.name);
//	printf(" number=%d\n", C.number);
//	printf("ͨ���ṹ�������ָ����ʳ�Ա��\n");
//	printf(" price=%d\n", pc->price);//ͨ��->���������ʱ�����Ա
//	printf(" name=%s\n", pc->name);
//	printf(" number=%d\n", pc->number);
//	return 0;
//}
//int main()
//{
//	int a = (1 && 0);
//	int b = (1 || 0);
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}
//int main()
//{
//	int a = 3; //��ֵ
//	int b = 5;
//	int c = a & b;//��3��5��λ��Ľṹ��ֵ��c
//	printf(" c=%d", c);
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	a += 1;
//	printf("a+=1��a=%d\n", a);
//	a += 1;
//	printf("a+=1��a=%d\n", a);
//	return 0;
//}
//int main()
//{
//	char a = 1 << 1;
//	printf(" %d", a);
//	return 0;
//}
//int main()
//{
//	int i= 0;
//	int arr[5] = { 4,6,8,10,12 };
//	for (i = 0; i < 5;i++)
//	{
//		printf("a[%d]= %d\n",i, arr[i]);
//	}
//	return 0;
//}
//int ADD(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("������x��y\n");
//	scanf("%d %d", &x, &y);
//	int sum = ADD(x, y);
//	printf("x+y=%d\n", sum);
//	return 0;
//}
//int main()
//{
//	printf("��ʼѧϰ��\n");
//	int study_time = 0;//ѧϰ����
//	while (study_time < 5000)
//	{
//		study_time++;//�ظ�ѧϰ
//	}
//	if(study_time>=5000)
//	printf("�Ѿ��չ�5000�죬��offer");
//	return 0;
//}
//enum select	//ö�ٹؼ�
//{
//	Play_game,//ö�ٳ����ܵ����
//	Study_hard,
//};
//int main()
//{
//	int My_Choice = 0;
//	printf("���Ŭ��ѧϰ�����?��ѡ��->(1.Study_hard or 0.Play_game)\n");
//	printf("������");
//	scanf("%d", &My_Choice);
//	if (My_Choice)  //ѡ�����
//		printf("��Ϊ��ţ�����������۷壡");
//	else  //ѡ�����
//		printf("µµ��Ϊ����ʵ�ֵأ�");
//	return 0;
//}