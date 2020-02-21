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

//
//归并排序（MERGE - SORT）是建立在归并操作上的一种有效的排序算法, 该算法是采用分治法（Divide and Conquer）
//的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
//若将两个有序表合并成一个有序表，称为二路归并。归并排序是一种稳定的排序方法。



//用这种写法
void mergearray(vector<int> &arr, int begin, int end, int mid, vector<int> &tmp)
{
	int i = begin, j = mid + 1;
	int k = begin;
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
	for (int m = begin; m <= end; ++m)
	{
		arr[m] = tmp[m];
	}
}
void mergesort(vector<int> &arr, int begin, int end, vector<int> &tmp)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergesort(arr, begin, mid, tmp);
		mergesort(arr, mid + 1, end, tmp);
		mergearray(arr, begin, end, mid, tmp);
	}
}
void merge(vector<int> &arr)
{
	if (arr.size() == 0)
	{
		return;
	}
	int size = arr.size();
	int begin = 0, end = size - 1;
	vector<int> tmp = arr;
	mergesort(arr, begin, end, tmp);

}










//vector<int>写法
void mergearray(vector<int> &arr, int start, int end, int mid, vector<int> &tmp)//注意&
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
void mergesort(vector<int> &arr, int start, int end, vector<int> &tmp)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(arr, start, mid, tmp);
		mergesort(arr, mid + 1, end, tmp);
		mergearray(arr, start, end, mid, tmp);
	}
}
void merge(vector<int> &arr, int len)
{
	int start = 0;
	int end = len - 1;
	vector<int> tmp(arr.begin(), arr.end());
	mergesort(arr, start, end, tmp);

}
int main()
{
	vector<int> arr = { 3,5,3,6,7,3,7,8,1 };
	merge(arr, 9);
	return 0;
}
























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
