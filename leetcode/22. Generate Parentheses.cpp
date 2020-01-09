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

//复习
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str;
		generate(str, n, res, n, n);
		return res;
	}
	void generate(string &str, int n, vector<string> &res, int left, int right)
		//left，right代表还能用的左右括号数目
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);//先在这里push不用下面的
			return;
		}
		// if(str.size()==2*n)
		// {
		//     res.push_back(str);
		// }
		if (left>0)
		{
			str += '(';
			generate(str, n, res, left - 1, right);
			str.pop_back();
			//generate(str+'(',n,res,left-1,right);
		}
		if (right>left)//不用right>0 && 
		{
			str += ')';
			generate(str, n, res, left, right - 1);
			str.pop_back();
		}
	}
};


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str;
		generate(str, n, res, n, n);
		return res;
	}
	void generate(string str, int n, vector<string> &res, int left, int right)
		//left，right代表还能用的左右括号数目
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);//先在这里push不用下面的
			return;
		}
		// if(str.size()==2*n)
		// {
		//     res.push_back(str);
		// }
		if (left>0)
		{
			// str+='(';
			// generate(str,n,res,left-1,right);
			// str.pop_back();
			generate(str + '(', n, res, left - 1, right);//如果用这种写法string str不能传引用，非常量左值引用不可以绑定到右值
		}
		if (right>left)
		{
			// str+=')';
			// generate(str,n,res,left,right-1);
			// str.pop_back();
			generate(str + ")", n, res, left, right - 1);
		}
	}
};