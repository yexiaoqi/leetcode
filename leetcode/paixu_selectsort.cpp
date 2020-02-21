//，基本思想为每一趟从待排序的数据元素中选择最小（或最大）的一个元素作为首元素
void selectsort(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		int min = i;
		for (int j = i; j < arr.size(); ++j)
		{
			if (arr[min] >arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr[i], arr[min]);
		}
	}
}
/*选择排序不稳定，比如3,2,2,3,1，第一次交换后，
本来在前面的那个3和最后一个1交换，本来在前面的3到了后面那个3的后面*/