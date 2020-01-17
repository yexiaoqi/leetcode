class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int flag1 = numerator >= 0 ? 1 : -1;
		int flag2 = denominator>0 ? 1 : -1;
		long long num = labs((long long)(numerator));
		long long den = labs((long long)(denominator));//����ȡ���ţ��������"-0.-5(-8-3)"���ֵ�
		long long first = num / den;//����INT_MIN����һ����С�ĸ���С�����ͻᳬ��intҲ�ᳬ��long��
									//ע��(long long)(numerator/denominator)��long LongҪ�У���
		long long second = num%den;
		string res;
		res = to_string(first);
		unordered_map<long long, int> m;
		if (flag1*flag2<0 && num != 0)//ע��num!=0���������0/(-5)�õ�-0
		{
			res = "-" + res;
		}
		if (second == 0)
		{
			return res;
		}
		res += '.';
		string s = "";
		int pos = 0;
		while (second)//�п����Ƕ�λѭ��������3/444����0.012012012������ֻ�ж���һλ����һλ�Ƿ���ͬ
		{
			if (m.find(second) != m.end())
			{
				s.insert(m[second], "(");
				s += ")";
				return res + s;
			}
			m[second] = pos;
			first = second * 10 / den;
			s += to_string(first);
			second = second * 10 % den;
			++pos;
		}
		return res + s;
	}
};