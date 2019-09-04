//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

//https://www.cnblogs.com/grandyang/p/4325648.html
//�����������Ĺؼ����ڻ�����м������ж�����Ҫ�������λ����Ұ�Σ����ǹ۲������ɫ�����ֶ�������ģ�
//�ɴ����ǿ��Թ۲�����ɣ�����м����С�����ұߵ��������Ұ��������ģ����м����������ұ�����������������ģ�
//����ֻҪ������İ��������β�����������ж�Ŀ��ֵ�Ƿ�����һ�����ڣ������Ϳ���ȷ�������İ����
class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int first = 0, last = nums.size();
		while (first != last)//����nums[first]!=nums[last]
		{
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target)return mid;
			if (nums[first] <= nums[mid])
			{
				if (nums[first] <= target&&nums[mid]>target)
					last = mid;
				else
					first = mid + 1;
			}
			else
			{
				if (nums[mid]<target&&nums[last - 1] >= target)
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};