class Solution {
public:
	string multiply(string nums1, string nums2) {
		string res = "";
		if (nums1.size() == 0 || nums2.size() == 0)
		{
			return res;
		}
		int n1 = nums1.size(), n2 = nums2.size(), carry = 0;
		vector<int> val(n1 + n2, 0);
		for (int i = n1 - 1; i >= 0; --i)
		{
			for (int j = n2 - 1; j >= 0; --j)
			{
				int mul = (nums1[i] - '0')*(nums2[j] - '0');
				int p = i + j, q = i + j + 1, sum = val[q] + mul;
				val[p] += sum / 10;
				val[q] = sum % 10;
			}
		}。

		for (int i = 0; i<val.size(); ++i)
		{
			if (val[i] != 0 || !res.empty())//leading 0会被跳过，因为那时候不满足!res.empty()
			{
				res.push_back(val[i] + '0');
			}
		}
		return res.empty() ? "0" : res;
	}
};