#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 100

int max_subarru(int* a, int l, int mid, int r)
{
	int sum = 0;
	int left_max = -9999;
	for (int i = mid; i >= l; i--)
	{
		sum = sum + a[i];
		if (sum > left_max)
		{
			left_max = sum;
		}
	}
	sum = 0;
	int right_max = -9999;
	for (int i = mid + 1; i <= r; i++)
	{
		sum = sum + a[i];
		if (sum > right_max)
		{
			right_max = sum;
		}
	}
	return right_max + left_max;
}

int maxsubarru(int* a, int l, int r)
{
	if (l >= r)
		return a[l];
	int mid = (l + r) / 2;
	int left_max = maxsubarru(a, l, mid);
	int right_max = maxsubarru(a, mid + 1, r);
	int mid_max = max_subarru(a, l, mid, r);
	if (left_max > right_max && left_max > mid_max)
		return left_max;
	else if (right_max > left_max && right_max > mid_max)
		return right_max;
	else
		return mid_max;
}

int subarry(int* a, int l, int r)
{
	return maxsubarru(a, l, r - 1);
}

void findpoint(int* a, int n, int max)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			if (sum == max)
			{
				cout << "X[" << i << "," << j << "]" << "=" << max;
				return;
			}
		}
	}
}

//最大子数组分治算法
int main()
{
	//int a[MAX] = { 0 };
	int* a;
	int n = 0;
	char o;
	a = (int*)malloc(MAX * sizeof(int));
	cout << "请输入一组数以，分割" << endl;
	do
	{	
		cin >> a[n++];
	} while ((o = getchar()) == ',');

	int max= subarry(a, 0, n);

	findpoint(a, n,max);

	return 0;
}
