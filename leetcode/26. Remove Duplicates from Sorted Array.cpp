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