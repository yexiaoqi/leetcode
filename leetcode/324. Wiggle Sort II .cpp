//o(n)�ռ临�Ӷȣ�o(nlogn)ʱ�临�Ӷȷ���
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		//int begin=0,end=nums.size()-1;
		int j = (nums.size() + 1) / 2 - 1;//�����ȷ�С���������Կ���С����Ҫ�ȴ������1��������������������ʱ��Ӧ��ǰ��αȺ��ζ�1
		int k = nums.size() - 1;
		//���ܲ����������С�ķŵ�һ�������ķŵڶ������ڶ�С�ķŵ��������ڶ���ķŵ��ĸ�����Ϊ������ȵ����ֱ�����������λ�ã�����1,1,2,2,3,3�ͻ���1,3,1,3,2��2
		for (int i = 0; i<nums.size(); ++i)
		{
			nums[i] = i & 1 ? tmp[k--] : tmp[j--];
		}
	}
};


//�ⷨII O(n)ʱ�临�Ӷ� + O(n)�ռ临�ӶȽⷨ��
//https://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		auto midptr = nums.begin() + nums.size() / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;
		// 3-way-partition
		// �ҵ���λ����������Ҫ����3-way-partition�㷨����λ�����������в���ͬʱ��С����λ������������࣬������λ�����������Ҳࡣ3-way-partition �ĵ���������75��
		int begin = 0, i = 0, end = nums.size() - 1;
		while (i < end)
		{
			if (nums[i] > mid)
			{
				swap(nums[i], nums[end]);
				--end;
			}
			else if (nums[i] < mid)
			{
				swap(nums[i], nums[begin]);
				++begin;
				++i;
			}
			else
			{
				++i;
			}
		}//����Ҫ�� 3-way-partition���������[1,3,2,2,3,1]��nth+element�Ժ�2 1 1 2 3 3 �����ջ�õ�[1,3,1,3,2,2]

		if (nums.size() % 2)
		{
			++midptr;
		} //��Ϊtmp1(nums.begin(), midptr);�ǲ�����midptr�ģ����������ǰ���Ӧ�ö�һ��

		vector<int> tmp1(nums.begin(), midptr);
		vector<int> tmp2(midptr, nums.end());
		for (int i = 0; i < tmp1.size(); ++i)
		{
			nums[2 * i] = tmp1[tmp1.size() - 1 - i];//���������ǰ���Ӧ�ö�һ��
		}
		for (int i = 0; i < tmp2.size(); ++i)
		{
			nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
		}
	}
};