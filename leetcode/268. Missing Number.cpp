//���ڲ�������õ����飬�޷�ʹ�ý�ָoffer53_02�еĶ��ֲ��ҷ�����ֻ��������˵�ĵ�һ�ַ���
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		int allsum = n*(n + 1) / 2;
		int sum = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			sum += nums[i];
		}
		int res = allsum - sum;
		return res;
	}
};