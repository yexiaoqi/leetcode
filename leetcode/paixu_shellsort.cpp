//������������ڲ���ʱ���ý�����
void shellsort(vector<int> &arr)
{
	//����gap��������С����
	for (int gap = arr.size() / 2; gap>0; gap /= 2)
	{
		//�ӵ�gap��Ԫ�أ�����������������ֱ�Ӳ����������
		for (int i = gap; i<arr.size(); i++)
		{
			int j = i;//����һ����ĵڶ���Ԫ�ؿ�ʼ
			//https://blog.csdn.net/MoreWindows/article/details/6668714
			//�����������ҳ�е������У�����gap=2ʱ��i=4,4�Ⱥ�49������Ȼ���ں�13����
			while (j - gap >= 0 && arr[j]<arr[j - gap])
			{
				//����������ý�����
				swap(arr[j], arr[j - gap]);
				j -= gap;//j -= gap������һ�����һ����
			}
		}
	}
}