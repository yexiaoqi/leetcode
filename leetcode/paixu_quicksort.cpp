//https://www.cnblogs.com/TenosDoIt/p/3665038.html
//标准一点的写法
int mypartition(vector<int>&arr, int low, int high)
{
	int pivot = arr[low];//选第一个元素作为枢纽元
	while (low < high)
	{
		while (low < high && arr[high] >= pivot)high--;
		arr[low] = arr[high];//从后面开始找到第一个小于pivot的元素，放到low位置
		while (low < high && arr[low] <= pivot)low++;
		arr[high] = arr[low];//从前面开始找到第一个大于pivot的元素，放到high位置
	}
	arr[low] = pivot;//最后枢纽元放到low的位置
	return low;
}
void quicksort(vector<int>&arr, int low, int high)
{
	if (low < high)
	{
		int middle = mypartition(arr, low, high);
		quicksort(arr, low, middle - 1);
		quicksort(arr, middle + 1, high);
	}
}




//http://data.biancheng.net/view/117.html
void quicksort(int arr[], int begin, int end)
{
	if (begin < end)
	{
		int key = arr[begin];
		int i = begin;
		int j = end;
		while (i < j)
		{
			while (i<j&&arr[j]>key)
			{
				--j;
			}
			if (i < j)
			{
				arr[i] = arr[j];
				++i;
			}
			while (i < j&&arr[i] < key)
			{
				++i;
			}
			if (i < j)
			{
				arr[j] = arr[i];
				--j;
			}
			arr[i] = key;
			quicksort(arr, begin, i - 1);
			quicksort(arr, i + 1, end);
		}
	}
}