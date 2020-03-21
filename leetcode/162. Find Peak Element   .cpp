//自己写的o（n）解法，不够快
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		if (nums.size() == 1)
		{
			return 0;
		}
		if (nums.size() == 2)
		{
			nums[0]>nums[1] ? 0 : 1;//注意返回的是索引
		}
		if (nums[0]>nums[1])
		{
			return 0;
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			int one = nums[i];
			int two = nums[i + 1];
			int three = nums[i + 2];
			if (two>one&&two>three)
			{
				return i + 1;
			}
		}
		if (nums[nums.size() - 2]<nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		return -1;
	}
};

//o（n）解法，简化版
//。由于题目中说明了局部峰值一定存在，那么实际上可以从第二个数字开始往后遍历，如果第二个数字比第一个数字小，
//说明此时第一个数字就是一个局部峰值；否则就往后继续遍历，现在是个递增趋势，如果此时某个数字小于前面那个数字，
//说明前面数字就是一个局部峰值，返回位置即可。如果循环结束了，说明原数组是个递增数组，返回最后一个位置即可
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[i]<nums[i - 1])
			{
				return i - 1;
			}
		}
		return nums.size() - 1;
	}
};

//o(logn)
//在本例中，我们对二分查找进行一点修改。首先从数组 nums 中找到中间的元素 mid。
//若该元素恰好位于降序序列或者一个局部下降坡度中（通过将 nums[i] 与右侧比较判断)，
//则说明峰值会在本元素的左边。于是，我们将搜索空间缩小为 mid 的左边(包括其本身)，并在左侧子数组上重复上述过程。
//若该元素恰好位于升序序列或者一个局部上升坡度中（通过将 nums[i] 与右侧比较判断)，
//则说明峰值会在本元素的右边。于是，我们将搜索空间缩小为 mid 的右边，并在右侧子数组上重复上述过程。
//就这样，我们不断地缩小搜索空间，直到搜索空间中只有一个元素，该元素即为峰值元素
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int mid = (left + right) / 2;//由于left小于right，所以必有nums[mid+1]
			if (nums[mid]<nums[mid + 1])
			{
				left = mid + 1;
			}
			else//此时也是nums[mid]>nums[mid+1]的时候，此时mid就是所求值，在下面right=mid，那么return right
			{
				right = mid;
			}
		}
		return right;
		//return left;//返回left或者right都一样，因为是left=right以后才不在循环的
	}
};