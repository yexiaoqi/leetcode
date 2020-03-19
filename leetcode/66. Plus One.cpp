//Given a non - negative integer represented as a non - empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.



class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		for (int i = n - 1; i >= 0; i--)//ע����n-1����n
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;//ֻҪ��1�����Լ���1�Ժ�Ҫ���̽���return
			}
		}
		digits.insert(digits.begin(), 1);//�������99��������������ǰ�����1
		return digits;
	}
};



class Solution
{
	//�����⡿ ����һ���������ʾ���������һ֮��Ľ������������������ʾ��
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n - 1;i >= 0;i--)//ע����n-1����n
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;//ֻҪ��1�����Լ���1�Ժ�Ҫ���̽���return
			}
		}
		digits[0] = 1;
		digits.push_back(0);//�������99�����������������forѭ�����Ϊ00�����ڰѵ�һ��0��Ϊ1������ĩβ����һ��0����Ϊ100
		return digits;
	}
};


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				++digits[i];
				return digits;
			}
		}
		if (digits[0] == 0)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

//��ϰ
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int i = digits.size();
		int carry = 1;
		while (i&&carry)
		{
			int num = (digits[i - 1] + carry) % 10;
			carry = (digits[i - 1] + carry) / 10;
			digits[i - 1] = num;
			i--;
		}
		if (carry == 1)
		{
			//digits.insert(0,1);
			digits.insert(digits.begin(), 1);//ע���������ָ�����������
		}
		return digits;
	}
};