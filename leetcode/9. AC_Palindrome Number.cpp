//自己AC的题
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}
		int res = 0;
		// string res;
		int tmp = x;
		while (tmp != 0)
		{
			if (res>INT_MAX / 10)
			{
				return false;
			}
			//res=res+tmp%10+'0';
			res = res * 10 + tmp % 10;
			tmp /= 10;
		}
		if (res == x)
		{
			return true;
		}
		return false;
	}
};