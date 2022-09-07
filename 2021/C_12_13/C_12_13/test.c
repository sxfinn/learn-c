#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define MAXN 100005

#define MAXT 8

#define BASE 10

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
{                                               // (9)void Radixsort(intn,int*a)Ϊ���������ʵ
                                                //�֣������a[]���������������
    int i, j, top = 0, pos = 0;
    while (pos < MAXT)
    {                                           // (10)����MAXT�ֵ�����
        memset(RadixBucketTop, 0, sizeof(RadixBucketTop));  // (11)����ǰ��ն��У�ֻ��Ҫ����
                                                            //��βָ�����㼴��
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
                a[top++] = RadixBucket[i][j];               // (13)�������е�Ԫ�ذ�˳������ԭ����
            }
        }
        ++pos;
    }
}


int main()
{
    InitPowOfBase();
	int arr[] = {1,2,3,-1};
    RadixSort(4, arr);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
