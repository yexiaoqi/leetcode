//Ҫ������ dp ���飬���� f[i] ��ʾ������[0, i] ��Χ�ڲ���һ������ nums[i] ���ֵ����������˻���
//g[i] ��ʾ������[0, i] ��Χ�ڲ���һ������ nums[i] ���ֵ���С������˻���
//��ʼ��ʱ f[0] �� g[0] ����ʼ��Ϊ nums[0]�����඼��ʼ��Ϊ0����ô������ĵڶ������ֿ�ʼ������
//��ô��ʱ�����ֵ����Сֵֻ��������������֮��������� f[i - 1] * nums[i]��g[i - 1] * nums[i]���� nums[i]��
//�����������е����ֵ������ f[i]������Сֵ������ g[i]��Ȼ���� f[i] �����½�� res ���ɣ�
//�������յĽ����һ������� nums[n - 1] ������֣����� f[n - 1] ��һ�������ս⣬���ϸ��µĽ�� res ���ǣ�
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		vector<vector<int>> dp(2, (vector<int>(nums.size(), 0)));
		dp[0][0] = nums[0];
		dp[1][0] = nums[0];
		int res = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			dp[0][i] = max(max(nums[i], dp[1][i - 1] * nums[i]), dp[0][i - 1] * nums[i]);
			dp[1][i] = min(min(nums[i], dp[1][i - 1] * nums[i]), dp[0][i - 1] * nums[i]);
			if (res<dp[0][i])
			{
				res = dp[0][i];
			}
		}
		return res;
	}
};