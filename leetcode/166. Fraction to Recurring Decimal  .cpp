class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int flag1 = numerator >= 0 ? 1 : -1;
		int flag2 = denominator>0 ? 1 : -1;
		long long num = labs((long long)(numerator));
		long long den = labs((long long)(denominator));//先提取负号，负责会变成"-0.-5(-8-3)"这种的
		long long first = num / den;//比如INT_MIN除以一个极小的负的小数，就会超过int也会超过long型
									//注意(long long)(numerator/denominator)的long Long要有（）
		long long second = num%den;
		string res;
		res = to_string(first);
		unordered_map<long long, int> m;
		if (flag1*flag2<0 && num != 0)//注意num!=0，否则会有0/(-5)得到-0
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
		while (second)//有可能是多位循环，比如3/444就是0.012012012，不能只判断下一位和上一位是否相同
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