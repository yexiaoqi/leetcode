//������arr�е�ֵ��0��maxval������и���Ӧ����maxval-minval+1
//��������
void count_sort(vector<int> &arr, int maxval)
{
	int len = arr.size();
	if (len == 0)
	{
		return;
	}
	vector<int> count(maxval + 1, 0);//����и���Ӧ����maxval-minval+1
	vector<int> tmp(arr.begin(), arr.end());
	for (int i = 0; i < len; ++i)
	{
		count[arr[i]]++;
	}
	for (int i = 1; i <= maxval; ++i)
	{
		count[i] += count[i - 1];
	}
	for (int i = len - 1; i >= 0; --i)
	{
		arr[count[tmp[i]] - 1] = tmp[i];
		--count[tmp[i]];
	}
}