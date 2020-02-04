//针对有序序列在插入时采用交换法
void shellsort(vector<int> &arr)
{
	//增量gap，并逐步缩小增量
	for (int gap = arr.size() / 2; gap>0; gap /= 2)
	{
		//从第gap个元素，逐个对其所在组进行直接插入排序操作
		for (int i = gap; i<arr.size(); i++)
		{
			int j = i;//从这一组里的第二个元素开始
			//https://blog.csdn.net/MoreWindows/article/details/6668714
			//在上面这个网页中的例子中，比如gap=2时，i=4,4先和49交换，然后在和13交换
			while (j - gap >= 0 && arr[j]<arr[j - gap])
			{
				//插入排序采用交换法
				swap(arr[j], arr[j - gap]);
				j -= gap;//j -= gap跳到这一组的下一个数
			}
		}
	}
}