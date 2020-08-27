//https://www.nowcoder.com/questionTerminal/0da19cbd75ed45dcaa59261c9d15a5d6

#include<unordered_set>
class Solution {
public:
	/**
	*	在数组中求长度最大的可整合子数组长度
	*	arr：输入数组
	*	返回：最大的可整合子数组的长度
	*/
	int getMaxLength(vector<int> arr, int len) {
		if (len == 0)
		{
			return 0;
		}
		int res = INT_MIN;
		unordered_set<int> us;
		for (int i = 0; i<len; ++i)
		{
			int mx = INT_MIN;
			int mn = INT_MAX;
			for (int j = i; j<len; ++j)
			{
				if (us.count(arr[j]))
				{
					break;
				}
				us.insert(arr[j]);
				mx = max(mx, arr[j]);
				mn = min(mn, arr[j]);
				if (mx - mn == j - i)
				{
					res = max(res, j - i + 1);
				}
			}
			us.clear();
		}
		return res;
	}
};