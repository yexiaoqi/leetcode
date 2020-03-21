//�Լ�д��o��n���ⷨ��������
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		if (nums.size() == 1)
		{
			return 0;
		}
		if (nums.size() == 2)
		{
			nums[0]>nums[1] ? 0 : 1;//ע�ⷵ�ص�������
		}
		if (nums[0]>nums[1])
		{
			return 0;
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			int one = nums[i];
			int two = nums[i + 1];
			int three = nums[i + 2];
			if (two>one&&two>three)
			{
				return i + 1;
			}
		}
		if (nums[nums.size() - 2]<nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		return -1;
	}
};

//o��n���ⷨ���򻯰�
//��������Ŀ��˵���˾ֲ���ֵһ�����ڣ���ôʵ���Ͽ��Դӵڶ������ֿ�ʼ�������������ڶ������ֱȵ�һ������С��
//˵����ʱ��һ�����־���һ���ֲ���ֵ�������������������������Ǹ��������ƣ������ʱĳ������С��ǰ���Ǹ����֣�
//˵��ǰ�����־���һ���ֲ���ֵ������λ�ü��ɡ����ѭ�������ˣ�˵��ԭ�����Ǹ��������飬�������һ��λ�ü���
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		for (int i = 1; i<nums.size(); ++i)
		{
			if (nums[i]<nums[i - 1])
			{
				return i - 1;
			}
		}
		return nums.size() - 1;
	}
};

//o(logn)
//�ڱ����У����ǶԶ��ֲ��ҽ���һ���޸ġ����ȴ����� nums ���ҵ��м��Ԫ�� mid��
//����Ԫ��ǡ��λ�ڽ������л���һ���ֲ��½��¶��У�ͨ���� nums[i] ���Ҳ�Ƚ��ж�)��
//��˵����ֵ���ڱ�Ԫ�ص���ߡ����ǣ����ǽ������ռ���СΪ mid �����(�����䱾��)������������������ظ��������̡�
//����Ԫ��ǡ��λ���������л���һ���ֲ������¶��У�ͨ���� nums[i] ���Ҳ�Ƚ��ж�)��
//��˵����ֵ���ڱ�Ԫ�ص��ұߡ����ǣ����ǽ������ռ���СΪ mid ���ұߣ������Ҳ����������ظ��������̡�
//�����������ǲ��ϵ���С�����ռ䣬ֱ�������ռ���ֻ��һ��Ԫ�أ���Ԫ�ؼ�Ϊ��ֵԪ��
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int mid = (left + right) / 2;//����leftС��right�����Ա���nums[mid+1]
			if (nums[mid]<nums[mid + 1])
			{
				left = mid + 1;
			}
			else//��ʱҲ��nums[mid]>nums[mid+1]��ʱ�򣬴�ʱmid��������ֵ��������right=mid����ôreturn right
			{
				right = mid;
			}
		}
		return right;
		//return left;//����left����right��һ������Ϊ��left=right�Ժ�Ų���ѭ����
	}
};