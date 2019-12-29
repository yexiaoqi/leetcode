//ͬleetcode 260
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int res = 0;
		for (int i = 0; i<data.size(); ++i)
		{
			res ^= data[i];
		}
		res &= -res;
		for (int i = 0; i<data.size(); ++i)
		{
			if (res&data[i])
			{
				*num1 ^= data[i];
			}
			else {
				*num2 ^= data[i];
			}
		}
	}
};