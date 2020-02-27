enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//区分溢出0和数字0
class Solution {
public:
	int reverse(int x) {
		int res = 0;//注意res必须初始化为0，c++中必须初始化以后才能调用
		while (x)
		{
			if (abs(res)>INT_MAX / 10)//注意判断绝对值res
// 用不着if(res>INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0' - flag)>8))这样，因为x本身是一个没有溢出的数，所以res == INT_MAX / 10时，最后一位只会是1或者2
			{
				g_nStatus = Invalid;
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};

//复习，自己的方法
enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//区分溢出0和数字0
class Solution {
public:
	int reverse(int x) {
		string str = to_string(x);
		int begin = 0, end = str.size() - 1;
		int flag = 0;
		int i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[0] == '-')
			{
				flag = -1;
			}
			++begin;
			++i;
		}
		while (begin<end)
		{
			swap(str[begin++], str[end--]);
		}
		int res = 0;
		for (i; i<str.size(); ++i)//正数和负数i的开始不一样
		{
			if (res>INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0' - flag)>8))//注意不要漏掉减0
			{
				g_nStatus = Invalid;
				return 0;
			}
			res = str[i] - '0' + res * 10;//注意不要漏掉减0,不能是 res * 10 + str[i] - '0'，这样会先计算 res * 10 + str[i]，已经溢出了再减0没用
		}
		if (flag == -1)
		{
			res = -res;
		}//注意不要漏了这一段
		return res;
	}
};

enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//区分溢出0和数字0
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x)
		{
			if (abs(res)>INT_MAX / 10)//注意判断绝对值res
			{
				g_nStatus = Invalid;
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};


//复习
//实际上不用先转成正数
class Solution {
public:
	int reverse(int x) {
		int flag = x >= 0 ? 1 : 0;
		long newx = labs(x);//如果要转为正数必须用labs而不能用abs，否则溢出
		long res = 0;
		while (newx)
		{
			if (res>INT_MAX / 10 || ((res == INT_MAX / 10) && (newx % 10 + flag>8)))
			{
				return 0;
			}
			res = res * 10 + newx % 10;
			newx /= 10;
		}
		if (!flag)
		{
			res = -res;
		}
		return res;
	}
};


enum Status { Valid = 0, Invalid };
int g_status = Valid;
class Solution {
public:
	int reverse(int x) {
		int flag = x >= 0 ? 1 : 0;
		int res = 0;
		while (x)
		{
			if (abs(res)>INT_MAX / 10 || ((res == INT_MAX / 10) && (x % 10 + flag>8)))//注意abs
			{
				g_status = Invalid;
				return 0;
			}
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};