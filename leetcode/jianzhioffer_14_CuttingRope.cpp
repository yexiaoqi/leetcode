//给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0], k[1], ..., k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
//自己想的做法，找到绳子长度最接近的平方数，然后尽可能按开平方长度减绳子

//感觉是牛客上用例太少。。。比如49就应该拆成15个3和2个2，不应该是7个7
class Solution {
public:
	int cutRope(int number) {
		if (number == 3)
		{
			return 2;
		}//3开平方为1太特别了，单独列出来
		int s = round(sqrt(number));
		int count = number / s - 1;//比如n=10，剪成4*3*3而不是3*3*3*1
		int re = number%s + s;
		return pow(s, count)*re;
	}
};