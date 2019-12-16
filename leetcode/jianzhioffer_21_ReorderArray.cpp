//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//自己的解法
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		queue<int> jishu;
		queue<int> oushu;
		for (int i = 0; i<int(array.size()); ++i)
		{
			if (array[i] & 0x1)
			{
				jishu.push(array[i]);
			}
			else {
				oushu.push(array[i]);
			}
		}
		int j = 0;
		while (!jishu.empty())
		{
			array[j] = jishu.front();
			++j;
			jishu.pop();
		}
		while (!oushu.empty())
		{
			array[j] = oushu.front();
			++j;
			oushu.pop();
		}
	}
};

//不新建queue：
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int size = array.size();
		if (size <= 1)
		{
			return;
		}
		int i = 0, j = 1;
		while (i<size)
		{
			j = i + 1;
			if (!(array[i] & 0x1))
			{
				while (!(array[j] & 0x1))
				{
					if (j == size - 1)
					{
						return;
					}
					++j;
				}
				int cnt = j - i;
				int tmp = array[j];
				//array[i]=array[j];
				while (cnt)
				{
					array[i + cnt] = array[i + cnt - 1];
					--cnt;
				}
				array[i] = tmp;
				//array[i+1]=tmp;
			}
			++i;
		}
	}
};