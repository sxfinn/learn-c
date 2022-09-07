#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

char* reorganizeString(char* s)
{
    char* ret = (char*)malloc(sizeof(char) * 501);
    memset(ret, 0, sizeof(ret));
    int sz = strlen(s);
    int i = 0;
    int j = 0;
    for (i = 0; i < sz; i++)
    {
        int minid = i;
        for (j = 0; j < sz; j++)
        {
            char tmp = 0;
            if (s[j] < s[minid])
            {
                tmp = s[j];
                s[j] = s[minid];
                s[minid] = tmp;
            }
        }
    }

    int fast = 0, slow = 1;
    ret[0] = s[0];
    while (slow < sz)
    {
        int flag = 0;
        while (fast < sz)
        {
            if (ret[slow - 1] != s[fast] && s[fast])
            {
                flag = 1;
                ret[slow] = s[fast];
                slow++;
                s[fast] = 0;
            }
            fast++;
        }
        fast = 0;
        if (flag == 0)
            break;
    }
    if (slow == sz)
        return ret;
    return "";
}

//void swap(int* a, int* b)
//{
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//void triangleNumber(int* nums, int numsSize)
//{
//    int i = 0;
//    int j = 0;
//    int minid = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        minid = i;
//        for (j = i; j < numsSize; j++)
//        {
//            if (nums[j] < nums[minid])
//                minid = j;
//        }
//        swap(nums + i, nums + minid);
//    }
//}
//int main()
//{
//    int arr[] = { 3,4,2,2};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    triangleNumber(arr, sz);
//    for (int i = 0; i < sz; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//34,45,2,46,57,2,19,0,25,14,6
//int checkData(int* p)
//{
//	char tmp = 0;
//
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		tmp |= 1 << p[i];
//		//tmpÿ�λ���һλ1��p[i]�����1~5���У�
//		/*��1<<1��1<<5�����ϵĽ��������00111110������в��У�
//			��һ��������ȴ����һ��1������Ͳ�����00111110��
//			���Կ����ж�tmp���յĽ���ǲ�������������ж���û���ظ���*/
//	}
//	return tmp == 0x3E;
//}
//void diveRank(int* p, int n)
//{
//	if (n >= 5) //��ʱ��n����������ѭ�������ġ�
//	{
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
//			(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
//			(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
//			(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
//			(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
//			checkData(p)) //����
//		{
//			for (int i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			putchar('\n');
//		}
//		return;
//	}
//
//	for (p[n] = 1; p[n] <= 5; p[n]++)
//	{
//		diveRank(p, n + 1); //ͨ���ݹ�ģ����ѭ����ÿ��һ�εݹ��൱�ڽ���һ���µ�ѭ����
//	}
//}
//int main()
//{
//	int p[5];
//
//	diveRank(p, 0);
//
//	return 0;
//}
//#include <stdio.h>
//
//void swapArgs(int* a, int* b) //��������
//{
//	int tmp;
//
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//void diveRank(int* p, int n)
//{
//	if (n >= 5) //��ʱ��nҲ����������ѭ�������ġ�
//	{
//		if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
//			(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
//			(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
//			(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
//			(p[4] == 4) + (p[0] == 1) == 1)   //�ҵ��ģ�A��һ
//			//���ڴ�ʱ��ִ�е�ȫ���У����Բ���Ҳʡ�ˡ�
//		{
//			for (int i = 0; i < 5; i++)
//			{
//				printf("%d ", p[i]);
//			}
//			putchar('\n');
//		}
//		return;
//	}
//
//	int i;
//	for (i = n; i < 5; i++) //����ݹ鷽ʽ������˶�1~5��ȫ���У������ǴӺ���ǰ��ͣ��ִ�н�����
//		//���Բο��Ľ�����ԭ���룬������ݹ����д�س�ѭ���󣬿��Ը��õ���⡣
//	{
//		swapArgs(p + i, p + n);
//		diveRank(p, n + 1);
//		swapArgs(p + i, p + n);
//	}
//}
//
//int main()
//{
//	int p[5] = { 1, 2, 3, 4, 5 }; //��Ȼ������ȫ���У����Գ�ֵ������á�
//
//	diveRank(p, 0);
//
//	return 0;
//}


//int is_leap_year(int n)
//{
//	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int day = 0;
//	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int year = 0, month = 0;
//	while (scanf("%d %d", &year, &month) != EOF)
//	{
//		if (is_leap_year(year) && month == 2)
//		{
//			day = 29;
//		}
//		else
//		{
//			day = arr[month];
//		}
//		printf("%d\n", day);
//	}
//	return 0;
//}
//int main()
//{
//	double a = 0, b = 0, c = 0;
//	double ans1 = 0, ans2 = 0;
//	double imaginary = 0;
//	double real = 0;
//	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
//	{
//		if (a == 0)
//		{
//			printf("Not quadratic equation");
//			return 0;
//		}
//		double delt = b * b - 4 * a * c;
//		if (delt > 0)
//		{
//			ans1 = (-b + sqrt(delt)) / 2 / a;
//			ans2 = (-b - sqrt(delt)) / 2 / a;
//			printf("x1=%.2lf;x2=%.2lf", ans1, ans2);
//		}
//		else if (delt == 0)
//		{
//			ans1 = (-b + sqrt(delt)) / 2 / a;
//			printf("x1=x2=%.2lf", ans1);
//		}
//		else
//		{
//			real = -b / 2 / a;
//			imaginary = sqrt(delt);
//			printf("x1=%.2lf+%.2lf;x2=%.2lf-%.2lf", real, imaginary, real, imaginary);
//		}
//	}
//	return 0;
//}
//���üӷ��ļӷ�
//int getSum(int a, int b)
//{
//    while (b)
//    {
//        int carry = (unsigned int)(a & b) << 1;
//        a = (a ^ b);
//        b = carry;
//    }
//    return a;
//}
