/*ð������(BubbleSort)���䡰���������������Ԫ�ز��Ͻ�����һЩԪ��������������󣬿�����������Ԫ����ð��һ��������������һ�ּ򵥵Ļ��ڹؼ��ʱȽϵ������㷨���㷨ԭ��
ð�������ԭ���Ե�����Ϊ������ÿ�δ�ͷ��ʼ���αȽ����ڵ�����Ԫ�أ��������һ��Ԫ�ر�ǰһ��Ҫ��˵��˳�򲻶ԣ������ǽ���������ѭ�����֮���ٴδ�ͷ��ʼɨ�裬ֱ��ĳ��ɨ����û��Ԫ�ؽ�����˵��ÿ��Ԫ�ض������������Ԫ�ش�����������ɡ�*/



//��ֹ�����������ϸ��³����̵�ð��
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
		//�ϸ�����
		//��ֹ�������ݣ����� 2 3 4 5 1
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




//����д������ʱ�临�Ӷ�0(n),������ʱ�临�Ӷ�o(n^2)��ƽʱд���ָо��Ϳ���
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










//����д�Ļ���������Ҳ��o(n^2)ʱ�临�Ӷ�
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


