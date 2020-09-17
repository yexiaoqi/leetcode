//相似于剑指offer45
bool compare(string a, string b)
{
	string res1 = a + b;
	string res2 = b + a;
	return res1>res2;//返回满足res1>res2的排列
}
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())
		{
			return "";
		}
		vector<string> strs(nums.size());
		for (int i = 0; i<nums.size(); ++i)
		{
			strs[i] = to_string(nums[i]);
		}
		sort(strs.begin(), strs.end(), compare);
		if (strs[0] == "0")//针对有[0,0]这样的
		{
			return "0";
		}
		string res;
		for (int i = 0; i<nums.size(); ++i)
		{
			res += strs[i];
		}
		return res;
	}
};

//复习
bool compare(string a, string b)
{
	string res1 = a + b;
	string res2 = b + a;
	return res1>res2;
}
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		if (nums.empty())
		{
			return "";
		}
		vector<string> strs(nums.size());
		for (int i = 0; i<nums.size(); ++i)
		{
			strs[i] = to_string(nums[i]);
		}
		sort(strs.begin(), strs.end(), compare);
		if (strs[0] == "0")
		{
			return "0";
		}
		string res = "";
		for (int i = 0; i<nums.size(); ++i)
		{
			res += strs[i];
		}
		return res;
	}
};