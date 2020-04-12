
class Solution {
public:
	/**
	* 接收两个表示9进制数的字符串，返回表示它们相加后的9进制数的字符串
	* @param num1 string字符串 第一个加数
	* @param num2 string字符串 第二个加数
	* @return string字符串
	*/
	string add(string num1, string num2) {
		// write code here
		//int point1 = 0, point2 = 0;
		int m = num1.size(), n = num2.size();
		int i = 0, j = 0;
		for (; i < m; ++i)
		{
			if (num1[i] == '.')
			{
				break;
			}
		}
		for (; j < n; ++j)
		{
			if (num2[j] == '.')
			{
				break;
			}
		}


		string sum2 = "";
		int carry2 = 0;
		//int maxindex = max(m, n);
		int tmpi = m-1, tmpj = n-1;

		int sizepoint1 = m - 1-i, sizepoint2 = n -1- j;
		while (tmpi > i)
		{
			int val1 = 0, val2 = 0;
			if (sizepoint1 > sizepoint2)
			{
				val1 = num1[tmpi] - '0';
				--sizepoint1;
				--tmpi;
			}
			else if (sizepoint1 < sizepoint2)
			{
				val2 = num2[tmpj] - '0';
				--sizepoint2;
				--tmpj;
			}
			else
			{
				val1 = num1[tmpi] - '0';
				val2 = num2[tmpj] - '0';
				--tmpi;
				--tmpj;
			}
			//int val1 = tmpi < m ? num1[tmpi] - '0' : 0;
			//int val2 = tmpj < n ? num2[tmpj] - '0' : 0;
			int tmpsum = (val1 + val2 + carry2) % 9;
			carry2 = (val1 + val2 + carry2)  /9;
			sum2.insert(0, 1, tmpsum + '0');
			
		}
		if (sum2.size() != 0)
		{
			sum2.insert(0, 1, '.');
		}
		
		//string sum1 = "";
		int carry1 = carry2;
		tmpi = i - 1;
		tmpj = j - 1;
		while (tmpi >= 0 || tmpj >= 0)
		{
			int val1 = tmpi >= 0 ? num1[tmpi]-'0' : 0;
			int val2 = tmpj >= 0 ? num2[tmpj]-'0' : 0;
			int tmpsum = (val1 + val2 + carry1) % 9;
			carry1 = (val1 + val2 + carry1) / 9;
			//sum1.insert(0, 1, tmpsum + '0');
			sum2.insert(0, 1, tmpsum + '0');
			--tmpi;
			--tmpj;
		}
		return sum2;
	}
};