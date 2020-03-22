//����һ��o(n^2)�ⷨ
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp(nums.size(), 1);
		int maxres = 1;
		for (int i = 1; i<nums.size(); ++i)
		{
			for (int j = 0; j<i; ++j)
			{
				if (nums[j]<nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (maxres<dp[i])
			{
				maxres = dp[i];
			}
		}
		return maxres;
	}
};

//o(nlogn)�ⷨ
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
//�赱ǰ�����������������еĳ���Ϊ \textit{ len }len����ʼʱΪ 11������ǰ����������� \textit{ nums }nums���ڱ����� \textit{ nums }[i]nums[i] ʱ��
//
//��� \textit{ nums }[i] > d[\textit{ len }]nums[i]>d[len] ����ֱ�Ӽ��뵽 dd ����ĩβ�������� \textit{ len } = \textit{ len } +1len = len + 1��
//
//������ dd �����ж��ֲ��ң��ҵ���һ���� \textit{ nums }[i]nums[i] С���� d[k]d[k] �������� d[k + 1] = \textit{ nums }[i]d[k + 1] = nums[i]��
//
//����������[0, 8, 4, 12, 2][0, 8, 4, 12, 2] Ϊ����
//
//��һ������ 00��d = [0]d = [0]��
//
//�ڶ������� 88��d = [0, 8]d = [0, 8]��
//
//���������� 44��d = [0, 4]d = [0, 4]��
//
//���Ĳ����� 1212��d = [0, 4, 12]d = [0, 4, 12]��
//
//���岽���� 22��d = [0, 2, 12]d = [0, 2, 12]��
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		for (int i = 0; i<nums.size(); ++i)
		{
			int left = 0, right = dp.size();
			while (left<right)//����ÿһ�������������֣��ö��ֲ��ҷ��� dp �����ҵ�һ����С����������
			{
				int mid = (left + right) / 2;
				if (dp[mid]<nums[i])
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			if (right == dp.size())//���right�������������ô˵��������ֲ����ڣ���ôֱ���� dp ���������ϱ�����������
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//������ڣ���������ָ���Ϊ��ǰ������������
			}
		}
		return dp.size();
	}
};


//��lower_bound�����Լ�д����
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<int> dp;
		for (int i = 0; i<nums.size(); ++i)
		{
			int right = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
			if (right == dp.size())//���right�������������ô˵��������ֲ����ڣ���ôֱ���� dp ���������ϱ�����������
			{
				dp.push_back(nums[i]);
			}
			else
			{
				dp[right] = nums[i];//������ڣ���������ָ���Ϊ��ǰ������������
			}
		}
		return dp.size();
	}
};