//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
class Solution {
public:
	int  NumberOf1(int n) {
		int cnt = 0;
		while (n)
		{
			++cnt;
			n = n&(n - 1);
		}
		return cnt;
	}
};