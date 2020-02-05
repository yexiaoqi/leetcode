//与leetcode189相似
class Solution {
public:
    void reverse(string &str,int begin,int end)//注意引用
    {
        while(begin<end)
        {
            swap(str[begin++],str[end--]);
        }
    }
    string LeftRotateString(string str, int n) {
        int begin=0;
        int end=str.size()-1;
        if(str.size()<=1)
        {
            return str;
        }
        n=n%str.size();
        reverse(str,0,n-1);
        reverse(str,n,end);
        reverse(str,begin,end);
        return str;
    }
};

//复习，一遍ac
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (n == 0 || str.empty())
		{
			return str;
		}
		n = n%str.size();
		myreverse(str, 0, n - 1);
		myreverse(str, n, str.size() - 1);
		myreverse(str, 0, str.size() - 1);
		return str;
	}
	void myreverse(string &str, int begin, int end)
	{
		while (begin<end)
		{
			swap(str[begin++], str[end--]);
		}
	}
};
