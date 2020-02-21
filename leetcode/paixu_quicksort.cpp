//https://www.cnblogs.com/TenosDoIt/p/3665038.html
//快速排序简单的说就是选择一个基准，将比基准大的数放在一边，小的数放到另一边。对这个数的两边再递归上述方法。
//标准一点的写法
int mypartition(vector<int>&arr, int low, int high)
{
	int pivot = arr[low];//选第一个元素作为枢纽元
	while (low < high)
	{
		while (low < high && arr[high] >= pivot)high--;//注意不要漏了low < high，否则比如1,2，high就超界了
		//一定得是arr[high] >= pivot，不能漏掉=，否则比如3,2,3
		arr[low] = arr[high];//从后面开始找到第一个小于pivot的元素，放到low位置，也就是先将pivot位置赋值
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


//自己比较习惯begin end
int partition(vector<int> &arr, int begin, int end)
{
	int key = arr[begin];
	while (begin<end)
	{
		while (begin<end&&arr[end] >= key)
		{
			--end;
		}
		arr[begin] = arr[end];
		while (begin<end&&arr[begin] <= key)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}
void quicksort(vector<int> &arr, int begin, int end)
{
	if (begin<end)
	{
		int mid = partition(arr, begin, end);
		quicksort(arr, begin, mid - 1);
		quicksort(arr, mid + 1, end);
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