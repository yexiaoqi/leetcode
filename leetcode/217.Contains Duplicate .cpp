//�Լ�����
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> numset;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (numset.find(nums[i]) == numset.end())
			{
				numset.insert(nums[i]);//set�õ���insert
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};