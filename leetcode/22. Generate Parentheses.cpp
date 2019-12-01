class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		generate(n, n, "", res);
		return res;
	}
	void generate(int left, int right, string item, vector<string> &res)
	{
		if (left == 0 && right == 0)
		{
			res.push_back(item);
			return;
		}
		if (left>0)
		{
			generate(left - 1, right, item + '(', res);
		}
		if (left<right)
		{
			generate(left, right - 1, item + ')', res);
		}
	}
};