//堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。
//将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n - 1个元素重新构造成一个堆，这样会得到n个元素的次小值。
//如此反复执行，便能得到一个有序序列了
void adjustheap(vector<int> &arr, int i, int len)//len在调整中会减小，所以不能不用它，只用arr.size()是错的
{
	int tmp = arr[i];
	for (int k = 2 * i + 1; k < len; k = 2 * k + 1)
	{
		if (k + 1 < len && arr[k] < arr[k + 1])
		{
			k++;
		}
		if (tmp< arr[k])
		{
			arr[i] = arr[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	arr[i] = tmp;
}
void heapsort(vector<int> &arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0; --i)
	{
		adjustheap(arr, i, arr.size());
	}
	for (int i = arr.size() - 1; i > 0; --i)
	{
		swap(arr[0], arr[i]);
		adjustheap(arr, 0, i);
	}
}














/**
* 调整大顶堆（仅是调整过程，建立在大顶堆已构建的基础上）
* @param arr
* @param i
* @param length
*/
void adjustHeap(vector<int> &arr, int i, int length)
{
	int temp = arr[i];//先取出当前元素i
	for (int k = i * 2 + 1; k<length; k = k * 2 + 1)
	{
		//从i结点的左子结点开始，也就是2i+1处开始
		if (k + 1<length && arr[k]<arr[k + 1])//挑i的左子节点和右子节点中较大的一个
		{
			//如果左子结点小于右子结点，k指向右子结点
			k++;
		}
		if (arr[k] >temp)
		{
			//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
			arr[i] = arr[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	arr[i] = temp;//将temp值放到最终的位置
}

void heapsort(vector<int> &arr)
{
	//1.构建大顶堆
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		//从第一个非叶子结点从下至上，从左往右调整结构
		adjustHeap(arr, i, arr.size());
	}
	//2.调整堆结构+交换堆顶元素与末尾元素
	for (int j = arr.size() - 1; j>0; j--)
	{
		swap(arr[0], arr[j]);//将堆顶元素与末尾元素进行交换
		adjustHeap(arr, 0, j);//重新对堆进行调整
	}

}