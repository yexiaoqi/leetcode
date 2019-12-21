//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

class Solution {
public:
	int minNumberInRotateArray(vector<int> nums) {
		if (int(nums.size() == 0))
		{
			return 0;
		}
		int begin = 0, end = int(nums.size()) - 1;
		int minnum = INT_MAX;
		while (begin <= end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]<minnum)
			{
				minnum = nums[mid];
			}
			if (nums[mid] <= nums[end])
			{
				end = mid - 1;
			}
			else
			{
				minnum = nums[begin];
				begin = mid + 1;
			}
		}
		return minnum;
	}
};