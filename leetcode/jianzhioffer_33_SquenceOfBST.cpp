//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��
//���ﲻ�ѿ������ɶ��������������ӡ�����
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> nums) {
		if (nums.empty())
		{
			return false;
		}
		int n = nums.size();
		return Verify(nums, 0, n - 1);
	}
	bool Verify(vector<int> &nums, int start, int end)
	{
		if (start<end)//��������
		{
			int root = nums[end];
			int i = start;
			for (; i<end; ++i)
			{
				if (nums[i]>root)
				{
					break;
				}
			}
			int value = i;
			for (i; i<end; ++i)
			{
				if (nums[i]<root)
				{
					return false;
				}
			}
			--end;
			int left = Verify(nums, start, i - 1);
			int right = Verify(nums, i, end);
			return left&&right;
		}
		else
		{
			return true;
		}
	}
};



//��������
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
		int i = start;//start�������Verify(nums, i, end);�޸���
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
		if (i - start>1)//����i
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


//���д�Ĳ�̫��
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


//��ϰ
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
		int i = start;//start�������Verify(nums, i, end);�޸���
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
		if (i - start>1)//����i
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

//��ϰ
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> nums) {
		if (nums.empty())
		{
			return false;
		}
		int n = nums.size();
		return Verify(nums, 0, n - 1);
	}
	bool Verify(vector<int> &nums, int start, int end)
	{
		if (start<end)
		{
			int root = nums[end];
			int i = start;
			for (; i<end; ++i)
			{
				if (nums[i]>root)
				{
					break;
				}
			}
			int value = i;
			for (i; i<end; ++i)
			{
				if (nums[i]<root)
				{
					return false;
				}
			}
			--end;
			int left = Verify(nums, start, i - 1);
			int right = Verify(nums, i, end);
			return left&&right;
		}
		else
		{
			return true;
		}
	}
};