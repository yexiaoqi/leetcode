//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array nums = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 2)return nums.size();
		int index = 2;
		for (int i = 2;i < nums.size();i++)//ע����i < nums.size();i++
		{
			if (nums[i] != nums[index - 2])
			{
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};

//solution 2
//�׶�
//������������ظ��Ĵ��������Σ���ô���Ǿ���Ҫ��һ������count����¼�������м����ظ���count��ʼ��Ϊ1��
//������ֹ�һ���ظ�����count�ݼ�1����ô�´��ٳ����ظ�����ָ��ֱ��ǰ��һ���������ʱ�����ظ��ģ���count�ָ�1��
//������������������ģ�����һ�����ֲ��ظ���������һ����������󣬴���֮�󲻻������ظ���
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2)
		{
			return n;
		}
		int pre = 0, cur = 1, count = 1;
		while (cur<n)
		{
			if (nums[cur] == nums[pre] && count == 0)
			{
				++cur;
			}
			else
			{
				if (nums[cur] == nums[pre])
				{
					--count;
				}
				else
				{
					count = 1;
				}
				nums[++pre] = nums[cur++];
			}
		}
		return pre + 1;
	}
};