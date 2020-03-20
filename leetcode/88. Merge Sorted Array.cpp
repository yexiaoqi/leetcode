//给了m和n，那就知道了混合之后的数组的大小，这样就从 nums1 和 nums2 数组的末尾开始一个一个比较，
//把较大的数，按顺序从后往前加入混合之后的数组末尾。
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n - 1;
		while (m&&n)
		{
			if (nums1[m - 1]<nums2[n - 1])
			{
				nums1[k--] = nums2[n - 1];
				--n;
			}
			else
			{
				nums1[k--] = nums1[m - 1];
				--m;
			}
		}
		while (n)
		{
			nums1[k--] = nums2[n - 1];
			--n;
		}
	}
};