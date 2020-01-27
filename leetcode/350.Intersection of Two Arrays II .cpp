//自己的方法
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i<nums1.size(); ++i)
		{
			++m[nums1[i]];
		}
		for (int i = 0; i<nums2.size(); ++i)
		{
			if (m[nums2[i]]>0)
			{
				res.push_back(nums2[i]);
				--m[nums2[i]];
			}
		}
		return res;
	}
};

//自己的方法二
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int size1 = nums1.size(), size2 = nums2.size();
		int i = 0;
		int j = 0;
		while (i<nums1.size() && j<nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				res.push_back(nums1[i]);
				++i;
				++j;
			}
			else if (nums1[i]>nums2[j])
			{
				++j;
			}
			else
			{
				++i;
			}
		}
		return res;
	}
};