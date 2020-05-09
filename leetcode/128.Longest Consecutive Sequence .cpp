//同指南4_16
//使用一个集合HashSet存入所有的数字，然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，
//然后分别用两个变量pre和next算出其前一个数跟后一个数，然后在集合中循环查找，如果pre在集合中，
//那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，对next采用同样的方法，
//那么next - pre - 1就是当前数字的最长连续序列，更新res即可。
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int res = 0;
		unordered_set<int> us(nums.begin(), nums.end());
		// for(int i=0;i<nums.size();++i)
		// {
		//     us.insert(nums[i]);
		// }
		//for(auto a=us.begin();a!=us.end();++a)//因为后面有us.erase(nums[i]);这么写会到不可知域
		for (int i = 0; i<nums.size(); ++i)
		{
			//int num=*a;
			if (!us.count(nums[i]))
			{
				continue;
			}
			int pre = nums[i] - 1, next = nums[i] + 1;
			us.erase(nums[i]);
			while (us.count(pre))
			{
				us.erase(pre);
				--pre;
			}
			while (us.count(next))
			{
				us.erase(next);
				++next;
			}
			res = max(res, next - pre - 1);//注意是-1，因为pre和next是不符合条件的时候，pre的后一个和next的前一个才是符合条件的

		}
		return res;
	}
};


//复习
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			int cnt = 1;
			if (us.count(nums[i]))
			{
				int tmp = nums[i] + 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					++tmp;
				}
				tmp = nums[i] - 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					--tmp;
				}
			}
			if (res<cnt)
			{
				res = cnt;
			}
		}
		return res;
	}
};