//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。
//这里不把空树看成二叉搜索树的亚子。。。
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		if (size == 0)
		{
			return false;
		}
		return Verify(sequence, 0, size);
	}
	bool Verify(vector<int> sequence, int start, int end)
	{
		int root = sequence[end - 1];
		int i = 0;
		for (; i<end-1; ++i)
		{
			if (sequence[i]>root)
			{
				break;
			}
		}
		for (int j = i; j<end-1; ++j)
		{
			if (sequence[j]<root)
			{
				return false;
			}
		}
		--end;
		bool left = true, right = true;
		if (i>1)
		{
			left = Verify(sequence, 0, i - 1);
		}
		if (i<end - 1)
		{
			right = Verify(sequence, i, end);
		}
		return left&&right;
	}
};


//复习
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
		{
			return false;
		}
		int start = 0;
		return Verify(sequence, start, sequence.size() - 1);
	}
	bool Verify(vector<int> nums, int start, int end)
	{
		int i = start;//start被后面的Verify(nums, i, end);修改了
		int value = nums[end];
		for (i; i<end; ++i)
		{
			if (nums[i]>value)
			{
				break;
			}
		}
		for (int j = i; j<end; ++j)
		{
			if (nums[j]<value)
			{
				return false;
			}
		}
		--end;
		bool left = true, right = true;
		if (i - start>1)//不是i
		{
			left = Verify(nums, start, i - 1);
		}
		if (i<end)
		{
			right = Verify(nums, i, end);
		}
		return left&&right;
	}
};