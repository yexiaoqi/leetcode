//�����ڽ�ָoffer45
bool compare(string a, string b)
{
	string res1 = a + b;
	string res2 = b + a;
	return res1>res2;//��������res1>res2������
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
		if (strs[0] == "0")//�����[0,0]������
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

//��ϰ
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