//o(n)空间复杂度，o(nlogn)时间复杂度方法
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		//int begin=0,end=nums.size()-1;
		int j = (nums.size() + 1) / 2 - 1;//由于先放小的数，所以可能小的数要比大的数多1，所以总数是奇数个的时候，应该前半段比后半段多1
		int k = nums.size() - 1;
		//不能采用排序后，最小的放第一个，最大的放第二个，第二小的放第三个，第二大的放第四个，因为会有相等的数字被安排在相邻位置，比如1,1,2,2,3,3就会变成1,3,1,3,2，2
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[i] = i & 1 ? tmp[k--] : tmp[j--];
		}
	}
};


//解法II O(n)时间复杂度 + O(n)空间复杂度解法：
//https://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		auto midptr = nums.begin() + nums.size() / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;
		// 3-way-partition
		// 找到中位数后，我们需要利用3-way-partition算法将中位数放在数组中部，同时将小于中位数的数放在左侧，大于中位数的数放在右侧。3-way-partition 的典型例子是75题
		int begin = 0, i = 0, end = nums.size() - 1;
		while (i < end)
		{
			if (nums[i] > mid)
			{
				swap(nums[i], nums[end]);
				--end;
			}
			else if (nums[i] < mid)
			{
				swap(nums[i], nums[begin]);
				++begin;
				++i;
			}
			else
			{
				++i;
			}
		}//必须要有 3-way-partition，否则比如[1,3,2,2,3,1]，nth+element以后2 1 1 2 3 3 ，最终会得到[1,3,1,3,2,2]

		if (nums.size() % 2)
		{
			++midptr;
		} //因为tmp1(nums.begin(), midptr);是不包括midptr的，如果是奇数前半段应该多一个

		vector<int> tmp1(nums.begin(), midptr);
		vector<int> tmp2(midptr, nums.end());
		for (int i = 0; i < tmp1.size(); ++i)
		{
			nums[2 * i] = tmp1[tmp1.size() - 1 - i];//如果是奇数前半段应该多一个
		}
		for (int i = 0; i < tmp2.size(); ++i)
		{
			nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
		}
	}
};