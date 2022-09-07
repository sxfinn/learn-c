#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid + 1, right, tmp);
	int begin1 = left;
	int begin2 = mid + 1;
	int index = left;
	while (begin1 <= mid && begin2 <= right)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= mid)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= right)
	{
		tmp[index++] = arr[begin2++];
	}
	for (int i = left; i < index; i++)
	{
		arr[i] = tmp[i];
	}
}

void MergeSort(int* arr, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (!tmp)
		return;
	_MergeSort(arr, 0, sz - 1, tmp);
}

void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int end1 = begin1 + gap - 1;
			int begin2 = end1 + 1;
			int end2 = begin2 + gap - 1;
			int index = i;
			if (end1 >= n)
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
					tmp[index++] = arr[begin1++];
				else
					tmp[index++] = arr[begin2++];
			}
			while(begin1 <= end1)
				tmp[index++] = arr[begin1++];
			while (begin2 <= end2)
				tmp[index++] = arr[begin2++];		
		}
		memcpy(arr, tmp, sizeof(int) * n);
		gap *= 2;
	}
}

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = min;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			min = a[i];
	}
	int sz = max - min + 1;
	int* countarry = (int*)malloc(sizeof(int) * sz);
	assert(countarry);
	memset(countarry, 0, sizeof(int) * sz);
	for (int i = 0; i < n; i++)
	{
		countarry[a[i] - min]++;
	}
	int index = 0;
	for (int i = 0; i < sz; i++)
	{
		while (countarry[i] > 0)
		{
			a[index++] = i + min;
			countarry[i]--;
		}
	}
	free(countarry);
}

#include <stdio.h>
#include <string.h>

#define MAXN  100005
#define MAXT 8
#define BASE 10
//const int MAXN = 100005;          // (1) ���������Ԫ��������
//const int MAXT = 8;               // (2) ����Ԫ�ص����ֵ����λ��
//const int BASE = 10;              // (3) ����Ԫ�صĽ��ƣ�����Ϊʮ���ƣ�
int PowOfBase[MAXT];              // (4) Powofbase[i]����BASE��������
int RadixBucket[BASE][MAXN];      // (5) Radixbucket[i]�����i������
int RadixBucketTop[BASE];         // (6) Radixbuckettop[i]�����i�����е�βָ��

void InitPowOfBase()
{
	int i;
	PowOfBase[0] = 1;
	for (i = 1; i < MAXT; ++i)
	{
		PowOfBase[i] = PowOfBase[i - 1] * BASE;   // (7)��ʼ��BASE��������
	}
}

int getRadix(int value, int pos)
{
	return value / PowOfBase[pos] % BASE;            // (8)���� value ��posλ��ֵ
}

void RadixSort(int n, int* a)
{                                   // (9)void Radixsort(intn,int*a)Ϊ���������ʵ
									//�֣������a[]���������������
	int i, j, top = 0, pos = 0;
	while (pos < MAXT)
	{                                           // (10)����MAXT�ֵ�����
		memset(RadixBucketTop, 0, sizeof(RadixBucketTop));
		// (11)����ǰ��ն��У�ֻ��Ҫ����                                                         //��βָ�����㼴��
		for (i = 0; i < n; ++i)
		{
			int rdx = getRadix(a[i], pos);
			RadixBucket[rdx][RadixBucketTop[rdx]++] = a[i];// (12)��Ӳ���
		}
		top = 0;
		for (i = 0; i < BASE; ++i)
		{
			for (j = 0; j < RadixBucketTop[i]; ++j)
			{
				a[top++] = RadixBucket[i][j];        // (13)�������е�Ԫ�ذ�˳������ԭ����
			}
		}
		++pos;
	}
}

int a[MAXN];

int main()
{
	InitPowOfBase();
	int a[] = { 98,7,6,5,3,3,1,678,23,6,78,32,3,65,};
	int n = sizeof(a) / sizeof(int);
	
	
		//Input(n, a);
		RadixSort(n, a);
		//Output(n, a);
	
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}