enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//�������0������0
class Solution {
public:
	int reverse(int x) {
		int res = 0;//ע��res�����ʼ��Ϊ0��c++�б����ʼ���Ժ���ܵ���
		while (x)
		{
			if (abs(res)>INT_MAX / 10)//ע���жϾ���ֵres
// �ò���if(res>INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0' - flag)>8))��������Ϊx������һ��û���������������res == INT_MAX / 10ʱ�����һλֻ����1����2
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

//��ϰ���Լ��ķ���
enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//�������0������0
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
		for (i; i<str.size(); ++i)//�����͸���i�Ŀ�ʼ��һ��
		{
			if (res>INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0' - flag)>8))//ע�ⲻҪ©����0
			{
				g_nStatus = Invalid;
				return 0;
			}
			res = str[i] - '0' + res * 10;//ע�ⲻҪ©����0,������ res * 10 + str[i] - '0'���������ȼ��� res * 10 + str[i]���Ѿ�������ټ�0û��
		}
		if (flag == -1)
		{
			res = -res;
		}//ע�ⲻҪ©����һ��
		return res;
	}
};

enum Status { Valid = 0, Invalid };
int g_nStatus = Valid;//�������0������0
class Solution {
public:
	int reverse(int x) {
		int res = 0;
		while (x)
		{
			if (abs(res)>INT_MAX / 10)//ע���жϾ���ֵres
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


//��ϰ
//ʵ���ϲ�����ת������
class Solution {
public:
	int reverse(int x) {
		int flag = x >= 0 ? 1 : 0;
		long newx = labs(x);//���ҪתΪ����������labs��������abs���������
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
			if (abs(res)>INT_MAX / 10 || ((res == INT_MAX / 10) && (x % 10 + flag>8)))//ע��abs
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