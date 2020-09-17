int GetMax(vector<int> &arr)
{
	int maxnum = arr[0];
	for (int i = 1; i < arr.size(); ++i)
	{
		if (maxnum < arr[i])
		{
			maxnum = arr[i];
		}
	}
	return maxnum;
}
void countsort(vector<int> &arr, int exp)
{
	vector<int> count(10, 0);
	vector<int> tmp = arr;
	for (int i = 0; i < arr.size(); i++)
	{
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[count[(tmp[i] / exp) % 10] - 1] = tmp[i];
		--count[(tmp[i] / exp) % 10];
	}
}
void radixsort(vector<int> &arr)
{
	int exp = 1;
	int maxnum = GetMax(arr);
	for (exp; maxnum / exp > 0; exp *= 10)
	{
		countsort(arr, exp);
	}
}






int GetMax(vector<int> &arr)
{
	int maxnum = arr[0];
	for (int i = 1; i < arr.size(); ++i)
	{
		if (maxnum < arr[i])
		{
			maxnum = arr[i];
		}
	}
	return maxnum;
}
void countsort(vector<int> &arr, int n, int exp)
{
	vector<int> count(10, 0);
	vector<int> tmp = arr;
	for (int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		arr[count[(tmp[i] / exp) % 10] - 1] = tmp[i];
		--count[(tmp[i] / exp) % 10];
	}
}
void radixsort(vector<int> &arr, int n)
{
	int exp = 1;
	int maxnum = GetMax(arr);
	for (exp; maxnum / exp > 0; exp *= 10)
	{
		countsort(arr, n, exp);
	}
}





















int getMax(vector<int> &a, int n)
{
	int i, max;

	max = a[0];
	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

/*
* �����鰴��"ĳ��λ��"��������(Ͱ����)
*
* ����˵����
*     a -- ����
*     n -- ���鳤��
*     exp -- ָ����������a���ո�ָ����������
*
* ���磬��������a={50, 3, 542, 745, 2014, 154, 63, 616}��
*    (01) ��exp=1��ʾ����"��λ"������a��������
*    (02) ��exp=10��ʾ����"ʮλ"������a��������
*    (03) ��exp=100��ʾ����"��λ"������a��������
*    ...
*/
void countSort(vector<int> &a, int n, int exp)
{
	vector<int> output(n, 0);
	//int output[n];             // �洢"����������"����ʱ����
	int i, buckets[10] = { 0 };

	// �����ݳ��ֵĴ����洢��buckets[]��
	for (i = 0; i < n; i++)
	{
		buckets[(a[i] / exp) % 10]++;
	}
	// ����buckets[i]��Ŀ�����ø��ĺ��buckets[i]��ֵ���Ǹ�������output[]�е�λ�á�
	for (i = 1; i < 10; i++)
	{
		buckets[i] += buckets[i - 1];
	}
	// �����ݴ洢����ʱ����output[]��
	for (i = n - 1; i >= 0; i--)
	{
		//output[buckets[(a[i] / exp) % 10] - 1].push_back(a[i]);
		output[buckets[(a[i] / exp) % 10] - 1] = a[i];
		buckets[(a[i] / exp) % 10]--;
	}

	// ������õ����ݸ�ֵ��a[]
	for (i = 0; i < n; i++)
	{
		a[i] = output[i];
	}

}

/*
* ��������
*
* ����˵����
*     a -- ����
*     n -- ���鳤��
*/
void radixSort(vector<int> &a, int n)
{
	int exp;    // ָ�����������鰴��λ��������ʱ��exp=1����ʮλ��������ʱ��exp=10��...
	int max = getMax(a, n);    // ����a�е����ֵ

							   // �Ӹ�λ��ʼ��������a��"ָ��"��������
	for (exp = 1; max / exp > 0; exp *= 10)
		countSort(a, n, exp);
}