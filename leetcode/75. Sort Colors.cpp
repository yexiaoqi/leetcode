//���ڼ������������ɨ���㷨
class Solution {
public:
	void sortColors(vector<int>& nums) {
		vector<int> color(3, 0);
		for (int i = 0; i<nums.size(); ++i)
		{
			++color[nums[i]];
		}
		int cur = 0;
		for (int i = 0; i<3; ++i)
		{
			for (int j = 0; j<color[i]; ++j)
			{
				nums[cur] = i;
				++cur;
			}
		}
	}
};

//һ��ɨ�裬�����ռ�
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		//for(int i=0;i<nums.size();++i)
		for (int i = 0; i <= end; ++i)//���ܱ���nums.size()�Σ������Ե�˳���е����ˣ�end���
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i--], nums[end--]);//ע��i--����end�������ı�����0������Ӧ�ñ��ٴ���һ�ε�����ǰ��ȥ
			}
		}
	}
};

//��ϰ
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.empty())
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		int i = 0;
		while (i <= end)//ע����i <= end����begin<=end
		{
			if (nums[i] == 0)
			{
				swap(nums[i++], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[end--]);
			}
			else
			{
				i++;
			}
		}
	}
};

//
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return;
		}
		int begin = 0, end = nums.size() - 1;
		int i = 0;
		while (i <= end)
		{
			if (nums[i] == 0)
			{
				swap(nums[i++], nums[begin++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[end--]);
			}
			else
			{
				++i;
			}
		}
	}
};