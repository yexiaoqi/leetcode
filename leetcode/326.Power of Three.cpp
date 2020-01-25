//�Լ�д�ķ���һ
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (!n)
		{
			return false;
		}
		if (n == 1)
		{
			return true;//3��0�η�Ҳ��
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

//������
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



//������
class Solution {
public:
	bool isPowerOfThree(int n) {
		return n>0 && (log10(n) / log10(3) - int(log10(n) / log10(3)) == 0);
	}
};