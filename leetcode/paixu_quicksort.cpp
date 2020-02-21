//https://www.cnblogs.com/TenosDoIt/p/3665038.html
//��������򵥵�˵����ѡ��һ����׼�����Ȼ�׼���������һ�ߣ�С�����ŵ���һ�ߡ���������������ٵݹ�����������
//��׼һ���д��
int mypartition(vector<int>&arr, int low, int high)
{
	int pivot = arr[low];//ѡ��һ��Ԫ����Ϊ��ŦԪ
	while (low < high)
	{
		while (low < high && arr[high] >= pivot)high--;//ע�ⲻҪ©��low < high���������1,2��high�ͳ�����
		//һ������arr[high] >= pivot������©��=���������3,2,3
		arr[low] = arr[high];//�Ӻ��濪ʼ�ҵ���һ��С��pivot��Ԫ�أ��ŵ�lowλ�ã�Ҳ�����Ƚ�pivotλ�ø�ֵ
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


//�Լ��Ƚ�ϰ��begin end
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