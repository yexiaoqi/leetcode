//每一步将一个待排序的记录，插入到前面已经排好序的有序序列中去，直到插完所有元素为止。
void insertsort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i) //n-1次扫描，依次向前插入n-1个元素
	{
		int tmp = arr[i]; //每趟将a[i]插入到前面的排序子序列中
		int j = i - 1;
		while (j >= 0 && tmp < arr[j])
		{
			arr[j + 1] = arr[j];//将前面较大的元素向后移动 
			--j;
		}
		arr[j + 1] = tmp;//temp值到达插入位置
	}
}







void insertsort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i) //n-1次扫描，依次向前插入n-1个元素
	{
		int tmp = arr[i]; //每趟将a[i]插入到前面的排序子序列中
		int j;
		for (j = i - 1; j >= 0 && tmp < arr[j]; --j)
		{
			arr[j + 1] = arr[j];//将前面较大的元素向后移动 
		}
		arr[j + 1] = tmp;//temp值到达插入位置
	}
}