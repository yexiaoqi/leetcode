//自己写的方法一
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (!n)
		{
			return false;
		}
		if (n == 1)
		{
			return true;//3的0次方也算
		}
		while (n != 1)
		{
			if (n % 3 != 0)
			{
				return false;
			}
			n /= 3;
		}
		return true;
	}
};

//方法二
class Solution {
public:
	bool isPowerOfThree(int n) {
		while (n&&n % 3 == 0)
		{
			n /= 3;
		}
		return n == 1;
	}
};



//方法三
class Solution {
public:
	bool isPowerOfThree(int n) {
		return n>0 && (log10(n) / log10(3) - int(log10(n) / log10(3)) == 0);
	}
};