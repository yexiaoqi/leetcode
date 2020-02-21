//������Ļ���˼���ǣ������������й����һ���󶥶ѣ���ʱ���������е����ֵ���ǶѶ��ĸ��ڵ㡣
//������ĩβԪ�ؽ��н�������ʱĩβ��Ϊ���ֵ��Ȼ��ʣ��n - 1��Ԫ�����¹����һ���ѣ�������õ�n��Ԫ�صĴ�Сֵ��
//��˷���ִ�У����ܵõ�һ������������
void adjustheap(vector<int> &arr, int i, int len)//len�ڵ����л��С�����Բ��ܲ�������ֻ��arr.size()�Ǵ��
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
* �����󶥶ѣ����ǵ������̣������ڴ󶥶��ѹ����Ļ����ϣ�
* @param arr
* @param i
* @param length
*/
void adjustHeap(vector<int> &arr, int i, int length)
{
	int temp = arr[i];//��ȡ����ǰԪ��i
	for (int k = i * 2 + 1; k<length; k = k * 2 + 1)
	{
		//��i�������ӽ�㿪ʼ��Ҳ����2i+1����ʼ
		if (k + 1<length && arr[k]<arr[k + 1])//��i�����ӽڵ�����ӽڵ��нϴ��һ��
		{
			//������ӽ��С�����ӽ�㣬kָ�����ӽ��
			k++;
		}
		if (arr[k] >temp)
		{
			//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ㣨���ý��н�����
			arr[i] = arr[k];
			i = k;
		}
		else
		{
			break;
		}
	}
	arr[i] = temp;//��tempֵ�ŵ����յ�λ��
}

void heapsort(vector<int> &arr)
{
	//1.�����󶥶�
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		//�ӵ�һ����Ҷ�ӽ��������ϣ��������ҵ����ṹ
		adjustHeap(arr, i, arr.size());
	}
	//2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
	for (int j = arr.size() - 1; j>0; j--)
	{
		swap(arr[0], arr[j]);//���Ѷ�Ԫ����ĩβԪ�ؽ��н���
		adjustHeap(arr, 0, j);//���¶Զѽ��е���
	}

}