#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 10
#include<stdio.h>
//��̬����
//��ͨ������ÿ���ڵ����ڴ��������岼����ɢ����������̬�������ڴ���һ���������ڴ�ռ�
//�洢�� �� �������ֱ������ݺ���һ���ڵ���±�
//�����ϵ�˳����߼��ϵ�˳���п��ܲ�ͬ
//������ķ�ʽʵ�ֵ�����ʽ

typedef struct Node
{
	int data;
	int next;
}SLinkList[MaxSize];
//��ʼ��
int InitList(struct Node a[], int sz)
{
	a[0].next = -1;
	for (int i = 1; i < sz; i++)
	{
		a[i].next = -2;
	}
}
int Insert(SLinkList a,int sz,int e,int i)
{
	int index = 0;
	for (int i = 0; i < sz; i++)
	{
		if (a[i].next == -2)
		{
			a[i].data = e;
		}
	}
	while (index < i)
	{
		index = a[index].next;
	}
	a[index].next = i;
	a[i].next = -1;
	return 1;
}
void test()
{
	SLinkList a;
	InitList(a,sizeof(a)/sizeof(a[0]));
}
//typedef struct Sdu
//{
//	int age;
//	char name[10];
//}a[10];
//typedef int arr[10];
//typedef int(*p)[3];
//int main()
//{
//	
//	p n = NULL;
//	arr c;
//	a b;
//	printf("%d ", sizeof(n));
//	printf("%d %d", sizeof(b), sizeof(c));
//	return 0;
//}
////ѭ��˫����
//struct DNode
//{
//	int data;
//	struct DNode* next;
//	struct DNode* prior;
//};
//int InitDList(struct DNode** L)
//{
//	*L = (struct DNode*)malloc(sizeof(struct DNode));
//	if (*L == NULL)
//		return 0;
//	(*L)->next = *L;
//	(*L)->prior = *L;
//	return 1;
//}//�п����ж�β�ķ�����ѭ������������ͬ
////��ָ���ڵ�󷽲����½ڵ�
//int InsertNextNode(struct DNode* p, struct DNode* s)
//{
//	s->next = p->next;
//	s->next->prior = s;
//	s->prior = p;
//	p->next = s;
//	return 1;
//}
////ɾ��p�ĺ�̽ڵ�
//int DeleteNextNode(struct DNode* p, struct DNode* s)
//{
//	p->next = s->next;
//	s->next->prior = p;
//	free(s);
//	return 1;
//}
//
////ѭ��������
//struct LNode
//{
//	int data;
//	struct LNode* next;
//};
//int InitList(struct LNode** L)
//{
//	*L = (struct LNode*)malloc(sizeof(struct LNode));
//	if (*L == NULL)
//		return 0;
//	(*L)->next = *L;
//	return 1;
//}
//int empty(struct LNode* L)
//{
//	if (L->next == L)
//		return 1;
//	return 0;
//}
//int isTail(struct LNode* p , struct LNode*L)
//{
//	if (p->next == L)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int a = 3;
//	a = 10;
//	a = 020;
//	a = 30;
//	printf("%d", a);
//	return 0;
//}