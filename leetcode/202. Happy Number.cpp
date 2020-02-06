class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> us;
		if (n == 1)
		{
			return true;
		}
		while (n != 1)
		{
			int sum = 0;
			while (n)
			{
				sum += pow(n % 10, 2);
				n /= 10;
			}
			n = sum;
			if (us.count(n))
			{
				return false;
			}
			if (n == 1)
			{
				return true;
			}
			us.insert(n);
		}
		return false;//一定要加个返回，虽然不会运行到这里，但是在编译之前不会运行，所以要给个return的样子（因为这里只有if没有ifelse结构）
	}
};

//更简洁的写法
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> us;
		while (n != 1)
		{
			int sum = 0;
			while (n)
			{
				sum += pow(n % 10, 2);
				n /= 10;
			}
			n = sum;
			if (us.count(n))
			{
				break;
			}
			us.insert(n);
		}
		return n == 1;//为什么非得加个返回，又不会运行到这里，难道有不合格输入
	}
};