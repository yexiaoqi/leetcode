//�Լ��Ľⷨͨ������
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		vector<int> delta;
		int res = 1;
		if (nums.size() <= 1)
		{
			return nums.size();
		}
		if (nums.size() == 2)
		{
			if (nums[0] != nums[1])
			{
				return 2;
			}
			return 1;
		}
		for (int i = 0; i<nums.size() - 1; ++i)
		{
			int onedelta = nums[i + 1] - nums[i];
			if (onedelta != 0)
			{
				delta.push_back(onedelta);
			}
		}
		if (delta.size() != 0)
		{
			++res;
		}
		for (int i = 0; i<int(delta.size() - 1); ++i)
			//(delta.size()-1�����int()���������delta.size()==0�����delta.size()-1�����unsigned int 0�ڼ�1֮�󲻻���-1���Ǳ��unsigned int���͵����ֵ��https://www.zhihu.com/question/27445331
		{
			if ((delta[i + 1]>0 && delta[i]<0) || (delta[i + 1]<0 && delta[i]>0))
			{
				res += 1;
			}
		}
		return res;
	}
};