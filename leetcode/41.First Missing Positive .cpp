//˼��ͽ�ָoffer3_01�е���
//��Ȼ���ܽ����µ����飬��ôֻ�ܸ���ԭ�����飬˼·�ǰ�1���������һ��λ�� nums[0]��
//2���ڵڶ���λ�� nums[1]������Ҫ�� nums[i] ���� nums[nums[i] - 1]�ϣ������������飬
//��� nums[i] != i + 1, �� nums[i] Ϊ�����Ҳ�����n������ nums[i] ������ nums[nums[i] - 1] �Ļ���
//������λ�õ����������������������ֱ������������ٱ���һ�����飬�����Ӧλ���ϵ�������ȷ�򷵻���ȷ������
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i<nums.size(); ++i)
		{
			while (nums[i]>0 && nums[i]<nums.size() && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] != i + 1)
			{
				return i + 1;
			}
		}
		return nums.size() + 1;
	}
};