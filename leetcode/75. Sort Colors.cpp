//基于计数排序的两趟扫描算法
class Solution {
public:
	void sortColors(vector<int>& nums) {
		vector<int> color(3, 0);
		for (int i = 0; i<nums.size(); ++i)
		{
			++color[nums[i]];
		}
		int cur = 0;
		for (int i = 0; i<3; ++i)
		{
			for (int j = 0; j<color[i]; ++j)
			{
				nums[cur] = i;
				++cur;
			}
		}
	}
};

//一趟扫描，常数空间
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		//for(int i=0;i<nums.size();++i)
		for (int i = 0; i <= end; ++i)//不能遍历nums.size()次，本来对的顺序有调换了，end会变
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i--], nums[end--]);//注意i--，从end调回来的比如是0，它就应该被再处理一次调换到前面去
			}
		}
	}
};

//复习
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty())
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		int i = 0;
		while (i <= end)//注意是i <= end不是begin<=end
		{
			if (nums[i] == 0)
			{
				swap(nums[i++], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[end--]);
			}
			else
			{
				i++;
			}
		}
	}
};

//
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		int i = 0;
		while (i <= end)
		{
			if (nums[i] == 0)
			{
				swap(nums[i++], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[end--]);
			}
			else
			{
				++i;
			}
		}
	}
};