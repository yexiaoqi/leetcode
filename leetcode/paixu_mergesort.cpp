// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;
void mergearray(int arr[], int start,int end,int mid,int tmp[])
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid&&j <= end)
	{
		if (arr[i] < arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}
	while (i <= mid)
	{
		tmp[k++] = arr[i++];
	}
	while (j <= end)
	{
		tmp[k++] = arr[j++];
	}
	for (int m = 0; m < k; ++m)
	{
		arr[start + m] = tmp[m];
	}
}
void mergesort(int arr[], int start, int end, int tmp[])
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(arr, start,  mid, tmp);//arr可以看成首地址的指针，所以这里是传指针的
		mergesort(arr, mid + 1, end, tmp);
		mergearray(arr, start, end, mid, tmp);
	}
}
void merge(int arr[], int len)
{
	int start = 0;
	int end = len - 1;
	int *tmp = new int[len];
	mergesort(arr, start, end, tmp);

}
int main()
{
	int arr[] = { 3,5,3,6,7,3,7,8,1 };
	merge(arr, 9);
	return 0;
}
