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
/**
* 1.要想保证原有次序，则只能顺次移动或相邻交换。
* 2.i从左向右遍历，找到第一个偶数。
* 3.j从i+1开始向后找，直到找到第一个奇数。
* 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
* 5.終止條件：j向後遍歷查找失敗。
*/
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
				while (cnt)
				{
					array[i + cnt] = array[i + cnt - 1];
					--cnt;
				}
				array[i] = tmp;
			}
			++i;
		}
	}
};

//如果不要求保证奇数和奇数，偶数和偶数之间的相对位置不变，可以像书上一样，用两个指针前后向中间遍历交换

//复习
class Solution {
public:
	void reOrderArray(vector<int> &nums) {
		vector<int> tmp;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] & 0x1)
			{
				tmp.push_back(nums[i]);
			}
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (!(nums[i] & 0x1))//！运算优先级高于&，一定要加()
			{
				tmp.push_back(nums[i]);
			}
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[i] = tmp[i];
		}
	}
};


