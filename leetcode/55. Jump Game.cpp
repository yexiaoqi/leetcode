//�Լ�д�ķ�����˼����˵���ʱ�临�Ӷ�̫���޷�ͨ��
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int res = nums[0];
		int nochange = res;
		if (nums.size() == 1)
		{
			return true;
		}
		for (int i = 0; i<int(nums.size() - 1); i = res)
		{
			for (int j = i + 1; j <= i + nums[i]; ++j)
			{
				if (j >= nums.size() - 1)
				{
					return true;
				}
				if ((nums[i + j] + j)>res)
				{
					res = nums[i + j] + j;
				}
				if (res >= nums.size() - 1)
				{
					return true;
				}
			}
			if (res == nochange)
			{
				return false;
			}
			nochange = res;
		}
		return false;
	}
};


//ͬ����˼�룬ʱ�临�Ӷȵͣ�ͨ��
class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> index;
		for (int i = 0; i<int(nums.size() - 1); ++i)
		{
			index.push_back(i + nums[i]);
		}
		int jump = 0;
		int res = nums[0];
		while (jump<int(nums.size() - 1) && jump <= res)
		{
			if (index[jump]>res)
			{
				res = index[jump];
			}
			++jump;
		}
		if (res >= nums.size() - 1)
		{
			return true;
		}
		return false;
	}
};