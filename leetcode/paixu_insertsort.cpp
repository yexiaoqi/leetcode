void insertsort(vector<int> &arr)
{
	for (int i = 1; i < arr.size(); ++i) //n-1��ɨ�裬������ǰ����n-1��Ԫ��
	{
		int tmp = arr[i]; //ÿ�˽�a[i]���뵽ǰ���������������
		int j;
		for (j = i - 1; j >= 0 && tmp < arr[j]; --j)
		{
			arr[j + 1] = arr[j];//��ǰ��ϴ��Ԫ������ƶ� 
		}
		arr[j + 1] = tmp;//tempֵ�������λ��
	}
}