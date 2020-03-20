//自己的方法，o(n)复杂度
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if (!len1)
		{
			if (len2 & 0x1)
			{
				return nums2[len2 / 2];
			}
			else
			{
				return (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0;
			}
		}
		if (!len2)
		{
			if (len1 & 0x1)
			{
				return nums1[len1 / 2];
			}
			else
			{
				return (nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2.0;
			}
		}
		int begin1 = 0, begin2 = 0, end1 = len1 - 1, end2 = len2 - 1;
		int sumsize = len1 + len2;
		int cnt = 0, cntsm = 0, cntbg = 0;
		while ((cnt<(sumsize - !(sumsize & 0x1) - 1)) && (begin1 <= end1) && (begin2 <= end2))
		{
			if (nums1[begin1]<nums2[begin2])
			{
				++begin1;
			}
			else
			{
				++begin2;
			}
			++cnt;
			++cntsm;
			if ((cnt<(sumsize - !(sumsize & 0x1) - 1)) && (begin1 <= end1) && (begin2 <= end2))
			{
				if (nums1[end1]<nums2[end2])
				{
					--end2;
				}
				else
				{
					--end1;
				}
				++cnt;
				++cntbg;
			}
		}
		if ((cnt<(sumsize - !(sumsize & 0x1) - 1)) && (begin1 <= end1))
		{
			if (cntsm<cntbg)
			{
				++begin1;
			}
			else if (cntsm>cntbg)
			{
				--end1;
			}
			if ((sumsize) & 0x1)
			{
				return nums1[(begin1 + end1) / 2];
			}
			else
			{
				return (nums1[(begin1 + end1) / 2] + nums1[(begin1 + end1) / 2 + 1]) / 2.0;
			}
		}
		if ((cnt<(sumsize - !(sumsize & 0x1) - 1)) && (begin2 <= end2))
		{
			if (cntsm<cntbg)
			{
				++begin2;
			}
			else if (cntsm>cntbg)
			{
				--end2;
			}
			if (sumsize & 0x1)
			{
				return nums2[(begin2 + end2) / 2];
			}
			else
			{
				return (nums2[(begin2 + end2) / 2] + nums2[(begin2 + end2) / 2 + 1]) / 2.0;
			}
		}
		if (sumsize & 0x1)
		{
			if (begin1 == end1)
			{
				return nums1[begin1];
			}
			else
			{
				return nums2[begin2];
			}
		}
		else
		{
			if (begin1 == end1&&begin2 == end2)
			{
				return (nums1[begin1] + nums2[begin2]) / 2.0;
			}
			else if (end1 == (begin1 + 1))
			{
				return (nums1[begin1] + nums1[end1]) / 2.0;
			}
			else
			{
				return (nums2[begin2] + nums2[end2]) / 2.0;
			}
		}
		return -1.0;
	}
};

//o(log(m+n))复杂度
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size(), left = (len1 + len2 + 1) / 2, right = (len1 + len2 + 2) / 2;
		return (FindKth(nums1, 0, nums2, 0, left) + FindKth(nums1, 0, nums2, 0, right)) / 2.0;
	}
	int FindKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
	{
		if (i >= nums1.size())
		{
			return nums2[j + k - 1];
		}
		if (j >= nums2.size())
		{
			return nums1[i + k - 1];
		}
		if (k == 1)
		{
			return min(nums1[i], nums2[j]);
		}
		int minnum1 = (i + k / 2 - 1)<nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
		int minnum2 = (j + k / 2 - 1)<nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;
		if (minnum1<minnum2)
		{
			return FindKth(nums1, i + k / 2, nums2, j, k - k / 2);
		}
		else
		{
			return FindKth(nums1, i, nums2, j + k / 2, k - k / 2);
		}//这里最后不用再加return，因为不是仅仅是if，而是ifelse结构，一定会进入其中一个
	}
};


//复习
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i = 0, j = 0, m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
		return (FindMedian(nums1, nums2, i, j, left) + FindMedian(nums1, nums2, i, j, right)) / 2.0;
	}
	int FindMedian(vector<int>& nums1, vector<int>& nums2, int i, int j, int k)
	{
		if (i >= nums1.size())
		{
			return nums2[j + k - 1];
		}
		if (j >= nums2.size())
		{
			return nums1[i + k - 1];
		}
		if (k == 1)
		{
			return min(nums1[i], nums2[j]);
		}
		int minnum1 = i + k / 2 - 1<nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
		int minnum2 = j + k / 2 - 1<nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;
		if (minnum1<minnum2)
		{
			return FindMedian(nums1, nums2, i + k / 2, j, k - k / 2);
		}
		else
		{
			return FindMedian(nums1, nums2, i, j + k / 2, k - k / 2);
		}
	}
};