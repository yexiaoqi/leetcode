/*冒泡排序(BubbleSort)以其“在排序过程中相邻元素不断交换，一些元素慢慢被换到最后，看起来就像是元素在冒泡一样”而得名，是一种简单的基于关键词比较的排序算法。算法原理
冒泡排序的原理（以递增序为例）是每次从头开始依次比较相邻的两个元素，如果后面一个元素比前一个要大，说明顺序不对，则将它们交换，本次循环完毕之后再次从头开始扫描，直到某次扫描中没有元素交换，说明每个元素都不比它后面的元素大，至此排序完成。*/



//防止特殊数据有上浮下沉过程的冒泡
void bubblesort(vector<int> &arr)
{
	bool flag = true;
	int begin = 1;
	int end = arr.size();
	while (flag)
	{
		flag = false;
		for (int j = begin; j < end; ++j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		--end;
		//上浮过程
		//防止特殊数据，例： 2 3 4 5 1
		for (int j = end - 1; j >= begin; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		++begin;
	}




//这样写最好情况时间复杂度0(n),最差情况时间复杂度o(n^2)，平时写这种感觉就可以
void bubblesort(vector<int> &arr)
{
	bool flag = true;
	int end = arr.size();
	while (flag)
	{
		flag = false;
		for (int j = 1; j < end; ++j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
		}
		--end;
	}
}










//这样写的话连最好情况也是o(n^2)时间复杂度
void bubblesort(vector<int> &arr, int len)
{
	int i, j;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}





const int MAXNUM = 100;
int main()
{
	srand((unsigned)time(NULL));
	vector<int> arr(MAXNUM, 0);
	for (int i = 0; i < MAXNUM; ++i)
	{
		arr[i] = rand() % 10000;
	}
	bubblesort(arr);
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			cout << "wrong";
			break;
		}
	}
	cout << "true";
	return 0;
}


