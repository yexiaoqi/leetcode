//适用于arr中的值从0到maxval，如果有负数应该用maxval-minval+1
//计数排序
void count_sort(vector<int> &arr, int maxval)
{
	int len = arr.size();
	if (len == 0)
	{
		return;
	}
	vector<int> count(maxval + 1, 0);//如果有负数应该用maxval-minval+1
	vector<int> tmp(arr.begin(), arr.end());
	for (int i = 0; i < len; ++i)
	{
		count[arr[i]]++;
	}
	/*
	int cur = 0;
	for (int i = 0; i < maxval; ++i)
	{
	for (int j = 0; j < count[i]; ++j)//比如10,20,30,。。。1000，只有100个数，但会执行1000次j < count[i]操作，复杂度高
	{
	arr[cur] = i;
	++cur;
	}
	}*/
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