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

//��ϰ
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size()<2)
		{
			return true;
		}
		vector<int> res(nums.size() - 1, 0);
		int max = 0;
		for (int i = 0; i<nums.size() - 1; ++i)
		{
			res[i] = i + nums[i];
		}
		int i = 0;
		while (i<(nums.size() - 1) && i <= max)//iĿǰ���ߵ�����Զ��max��������i<=res
		{
			if (res[i]>max)
			{
				max = res[i];
			}
			++i;
		}
		if (max >= nums.size() - 1)
		{
			return true;
		}
		return false;
	}
};