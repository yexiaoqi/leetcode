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

//��ϰ
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str;
		generate(str, n, res, n, n);
		return res;
	}
	void generate(string &str, int n, vector<string> &res, int left, int right)
		//left��right�������õ�����������Ŀ
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);//��������push���������
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
		if (right>left)//����right>0 && 
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
		//left��right�������õ�����������Ŀ
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);//��������push���������
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
			generate(str + '(', n, res, left - 1, right);//���������д��string str���ܴ����ã��ǳ�����ֵ���ò����԰󶨵���ֵ
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