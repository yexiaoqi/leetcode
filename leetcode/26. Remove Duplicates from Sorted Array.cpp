//Given a sorted array, remove the duplicates in-place such that each element appear
//only once and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the
//input array in - place with O(1) extra memory.

//sulution1
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())return 0;
		/*或者可以 
		if (nums.size()<=1)
        {
            return nums.size();
        }*/
		int index = 0;
		for (int i = 1;i<nums.size();++i)
		{
			if (nums[index] != nums[i])
			{
				/*i++ 与 ++i 的主要区别有两个：
1、 i++ 返回原来的值，++i 返回加1后的值。
2、 i++ 不能作为左值，而++i 可以。*/
				nums[++index] = nums[i];
			}
		}
		return index + 1;
	}
};

//solution 2
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		// distance主要是用来求两个迭代器之间的元素个数
		//该函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素,这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。
		return distance(nums.begin(), unique(nums.begin(), nums.end()));
	}
};

//solution 3  这个方法易懂以扩展
//看到原地操作一般会想到指针，这个题目需要双指针。
//使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，如果两个指针指的数字相同，则快指针向前走一步，
//如果不同，则两个指针都向前走一步，这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.empty())
		{
			return 0;
		}
		int pre = 0, cur = 0, n = nums.size();
		while (cur<n)
		{
			if (nums[pre] == nums[cur])
			{
				++cur;
			}
			else
			{
				nums[++pre] = nums[cur++];
			}
		}
		return pre + 1;

	}
};


//复习
//自己的方法
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int j = 0;
		int begin = 0;
		while (j<nums.size())
		{
			int i = j + 1;
			while (i<nums.size() && nums[i] == nums[j])//注意要先判断i<nums.size()
			{
				++i;
			}
			nums[begin] = nums[j];
			j = i;
			++begin;
		}
		return begin;
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int begin = 0;
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[begin] != nums[i])
			{
				nums[++begin] = nums[i];
			}
		}
		return begin + 1;
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int slow = 0, fast = 0, n = nums.size();
		while (fast<n)
		{
			if (nums[slow] == nums[fast])
			{
				++fast;
			}
			else
			{
				++slow;
				nums[slow] = nums[fast];
				++fast;
			}
		}
		return slow + 1;
	}
};

//复习，一遍ac
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 0;
		while (i<nums.size())
		{
			while (i + 1<nums.size() && nums[i + 1] == nums[i])
			{
				++i;
			}
			nums[j] = nums[i];
			++j;
			++i;
		}
		return j;
	}
};