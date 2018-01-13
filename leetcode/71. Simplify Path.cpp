//Given an absolute path for a file(Unix - style), simplify it.
//
//For example,
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//click to show corner cases.
//
//Corner Cases :
//Did you consider the case where path = "/../" ?
//In this case, you should return "/".
//Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
//In this case, you should ignore redundant slashes and return "/home/foo".


class Solution
{
public:
	string simplifyPath(string path)
	{
		string res, tmp;
		vector<string> stk;
		stringstream ss(path);
		while (getline(ss, tmp, '/'))
		{
			if (tmp == "" || tmp == ".")
			{
				continue;
			}
			else if (tmp == ".." && !stk.empty())
			{
				stk.pop_back();
			}
			else if (tmp != "..")//不能只是else，否则比如输入"/..",输出应为"/",但运行得到"/.."
			{
				stk.push_back(tmp);
			}
		}
		for (auto str : stk)
		{
			res += '/' + str;
		}
		return res.empty() ? "/" : res;//是"/"不是'/'
	}
};