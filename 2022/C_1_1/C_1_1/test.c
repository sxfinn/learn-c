#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
//������Ĳ���
//struct LNode
//{
//	int data;
//	struct LNode* next;
//};
//typedef struct LNode LNode;
//typedef struct LNode* LinkList;
////��ʼ��
//int init_List(struct LNode* head)
//{
//	head = (struct LNode*)malloc(sizeof(struct LNode));
//	if (head == NULL)
//		return 0;
//	head->next = NULL;
//	return 1;
//}
////���ڵ�
//int ListInsert(LinkList head, int i, int e)
//{
//	if (i < 1)
//		return 0;
//	int j = 0;
//	while (j < i - 1 && head)
//	{
//		head = head->next;
//		j++;
//	}
//	if (head == NULL)
//		return 0;
//	struct LNode* element = NULL;
//	element = (LinkList)malloc(sizeof(LNode));
//	element->data = e;
//	element->next = head->next;
//	head->next = element;
//	return 1;
//}
////ǰ��ڵ�
//int	InsertPriorNode(struct LNode* p, int e)
//{
//	if (p == NULL)
//		return 0;
//	struct LNode* s = (struct LNode*)malloc(sizeof(struct LNode));
//	s->data = p->data;
//	p->data = e;
//	s->next = p->next;
//	p->next = s;
//	return 1;
//}
////��λ��ɾ���ڵ�
//int ListDelete(struct LNode* head, int i, int* ret)
//{
//	if (i < 1)
//		return 0;
//	int j = 0;
//	while (j < i - 1 && head)
//	{
//		head = head->next;
//		j++;
//	}
//	if (head == NULL || head->next == NULL)
//		return 0;
//	*ret = head->next->data;
//	head->next = head->next->next;
//	free(head->next);
//	return 1;
//}
////ָ���ڵ��ɾ��
//int DeleteNode(struct LNode* p)
//{
//	if (p == NULL)
//		return 0;
//	if (p->next == NULL)
//	{
//
//	}
//	struct LNode* q = p->next;
//	p->data = q->data;
//	p->next = q->next;
//	free(q);
//	return 1;
//}
////ָ���ڵ�Ĳ���
//struct LNode* GetElem(struct LNode* head, int i)
//{
//	if (i < 0)
//		return 0;
//	int j = 0;
//	struct LNode* p = head;
//	while (j < i && p)
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}
////��ֵ����
//struct LNode* LocateElem(struct LNode* head, int e)
//{
//	struct LNode* p = head->next;
//	while (p && p->data != e)
//	{
//		p = p->next;
//	}
//	return p;
//}
//
////���������
//int Length(struct LNode* head)
//{
//	int cnt = 0;
//	struct LNode* p = head;
//	while (p)
//	{
//		p = p->next;
//		cnt++;
//	}
//	return cnt;
//}
////������Ľ���
////ͷ�巨
////β�巨����������
//struct LNode* InsertList(struct LNode* head)
//{
//	struct LNode* r = head;
//	int x = 0;
//	scanf("%d", &x);
//	while (x != 9999)
//	{
//		struct LNode* s = (struct LNode*)malloc(sizeof(struct LNode));
//		s->data = x;
//		r->next = s;
//		r = s;
//		scanf("%d", &x);
//	}
//	r->next = NULL;
//	return head;
//}
////ͷ�巨����������
//struct LNode* InsertNextNode(struct LNode* head)
//{
//	int x = 0;
//	struct LNode* p = head;
//	scanf("%d", &x);
//	while (x != 9999)
//	{
//		struct LNode* s = (struct LNode*)malloc(sizeof(struct LNode));
//		s->data = x;
//		s->next = p->next;
//		p->next = s;
//		scanf("%d", &x);
//	}
//	return head;
//}
//
////��ʼ��
//int InitList(struct LNode* head)
//{
//	head = (struct LNode*)malloc(sizeof(struct LNode));
//	if (head == NULL)
//		return 0;
//	head->next = NULL;
//	return 1;
//}
//void test()
//{
//	struct LNode* L = NULL;
//	InitList(L);
//	InsertList(L);
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//
//˫����
struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prior;
};
//�п�
_Bool Empty(struct DNode* L)
{
	if (L->next == NULL)
		return true;
	return false;
}
//˫����ĳ�ʼ��
int InitNode(struct DNode** head)
{
	*head = (struct DNode*)malloc(sizeof(struct DNode));
	if (*head == NULL)
		return 0;
	(*head)->next = NULL;
	(*head)->prior = NULL;
	return 1;
}
//˫����Ĳ���
int InsertNextNode(struct DNode* p, struct DNode* s)
{				
	//��s�ڵ���뵽p�ڵ����
	if (s == NULL || p == NULL)
		return 0;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return 1;
}
//˫�����ǰ��������ҵ���ǰ���ڵ㣬��ǰ���ڵ���к�壬���ɴﵽǰ���Ч����
int InsertPriorNode(struct DNode* p, struct DNode* s)
{
	struct DNode* tmp = p->prior;
	if (tmp!= NULL)
	{
		InsertNextNode(tmp, s);
		return 1;
	}
	else
		return 0;
}
//˫�����ɾ��
int DeleteDNode(struct DNode* p)
{
	if (p == NULL)
		return false;
	if (p->next == NULL)
	{
		p->prior->next = NULL;
		return 1;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}
//ɾ��һ���ڵ�ĺ�̽ڵ�
int DeleteNextNode(struct DNode* p)
{
	if (p == NULL)
		return 0;
	struct DNode* q = p->next;
	if (q == NULL)
		return 0;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return 1;
}
//˫����ı��� ǰ�����ַ�ʽ

void test()
{
	struct DNode* L = NULL;
	InitNode(&L);

}
int main()
{
	int a = 3;
	a = 10;
	printf("%d", a);
}
//typedef struct Std
//{
//	int age;
//	char name[20];
//}Std;
// 
//int main()
//{
//	Std a = { 19,"songxin" };
//	Std b = { 17,"song" };
//	if (a.age != b.age)					//�ṹ��ıȽ�
//		a = b;
//	printf("%d\n", a.age);
//	printf("%s", a.name);
//	return 0;
//}
