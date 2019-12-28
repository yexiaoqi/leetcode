//https://www.cnblogs.com/TenosDoIt/p/3665038.html
//��׼һ���д��
int mypartition(vector<int>&arr, int low, int high)
{
	int pivot = arr[low];//ѡ��һ��Ԫ����Ϊ��ŦԪ
	while (low < high)
	{
		while (low < high && arr[high] >= pivot)high--;
		arr[low] = arr[high];//�Ӻ��濪ʼ�ҵ���һ��С��pivot��Ԫ�أ��ŵ�lowλ��
		while (low < high && arr[low] <= pivot)low++;
		arr[high] = arr[low];//��ǰ�濪ʼ�ҵ���һ������pivot��Ԫ�أ��ŵ�highλ��
	}
	arr[low] = pivot;//�����ŦԪ�ŵ�low��λ��
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