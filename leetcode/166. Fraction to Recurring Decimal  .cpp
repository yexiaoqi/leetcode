//那么怎么样找循环呢，肯定是再得到一个数字后要看看之前有没有出现这个数。为了节省搜索时间，
//我们采用哈希表来存数每个小数位上的数字。还有一个小技巧，由于我们要算出小数每一位，
//采取的方法是每次把余数乘10，再除以除数，得到的商即为小数的下一位数字。等到新算出来的数字在之前出现过，
//则在循环开始出加左括号，结束处加右括号。
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
		while (second)//有可能是多位循环，比如300/444就是0.675675675，不能只判断下一位和上一位是否相同
					  //second=300,m[300]=0,first=6,s="0.6"
					  //second=336,m[336]=1,first=7,s="0.67"
					  //second=252,m[252]=2,first=5,s="0.675"
					  //second=300,m[300]=0,已经存在过，所以s="0.(675)"
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