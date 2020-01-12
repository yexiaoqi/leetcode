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