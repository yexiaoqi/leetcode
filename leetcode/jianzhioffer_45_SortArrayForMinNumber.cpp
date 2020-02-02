//相似于leetcode179
bool compare(string a,string b)
{
    string str1=a+b;
    string str2=b+a;
    return str1<str2;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        vector<string>  strs;
        if(numbers.size()==0)
        {
            return res;
        }
        for(int i=0;i<numbers.size();++i)
        {
            strs.push_back(to_string(numbers[i]));//数字转字符串to_string
        }
        sort(strs.begin(),strs.end(),compare);
		if (strs[0] == "0")//针对有[0,0]这样的
		{
			return "0";
		}
        for(int i=0;i<strs.size();++i)
        {
            res=res+strs[i];
        }
        return res;
    }
};


//复习，自己做出，一遍ac
bool compare(string a, string b)
{
	string ab = a + b;
	string ba = b + a;
	return ab<ba;
}
class Solution {
public:
	string PrintMinNumber(vector<int> nums) {
		vector<string> strs;
		for (int i = 0; i<nums.size(); ++i)
		{
			strs.push_back(to_string(nums[i]));
		}
		sort(strs.begin(), strs.end(), compare);
		string res;
		for (int i = 0; i<strs.size(); ++i)
		{
			res += strs[i];
		}
		return res;
	}
};