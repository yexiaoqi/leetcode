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
		return false;//һ��Ҫ�Ӹ����أ���Ȼ�������е���������ڱ���֮ǰ�������У�����Ҫ����return�����ӣ���Ϊ����ֻ��ifû��ifelse�ṹ��
	}
};

//������д��
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
		return n == 1;//Ϊʲô�ǵüӸ����أ��ֲ������е�����ѵ��в��ϸ�����
	}
};