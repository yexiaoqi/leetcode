//������˼��Ϊÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ����Ϊ��Ԫ��
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
/*ѡ�������ȶ�������3,2,2,3,1����һ�ν�����
������ǰ����Ǹ�3�����һ��1������������ǰ���3���˺����Ǹ�3�ĺ���*/