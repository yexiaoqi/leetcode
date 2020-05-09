//ָͬ��4_16
//ʹ��һ������HashSet�������е����֣�Ȼ����������е�ÿ�����֣�������ڼ����д��ڣ���ô�����Ƴ���
//Ȼ��ֱ�����������pre��next�����ǰһ��������һ������Ȼ���ڼ�����ѭ�����ң����pre�ڼ����У�
//��ô��pre�Ƴ����ϣ�Ȼ��pre���Լ�1��ֱ��pre���ڼ���֮�У���next����ͬ���ķ�����
//��ônext - pre - 1���ǵ�ǰ���ֵ���������У�����res���ɡ�
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int res = 0;
		unordered_set<int> us(nums.begin(), nums.end());
		// for(int i=0;i<nums.size();++i)
		// {
		//     us.insert(nums[i]);
		// }
		//for(auto a=us.begin();a!=us.end();++a)//��Ϊ������us.erase(nums[i]);��ôд�ᵽ����֪��
		for (int i = 0; i<nums.size(); ++i)
		{
			//int num=*a;
			if (!us.count(nums[i]))
			{
				continue;
			}
			int pre = nums[i] - 1, next = nums[i] + 1;
			us.erase(nums[i]);
			while (us.count(pre))
			{
				us.erase(pre);
				--pre;
			}
			while (us.count(next))
			{
				us.erase(next);
				++next;
			}
			res = max(res, next - pre - 1);//ע����-1����Ϊpre��next�ǲ�����������ʱ��pre�ĺ�һ����next��ǰһ�����Ƿ���������

		}
		return res;
	}
};


//��ϰ
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			int cnt = 1;
			if (us.count(nums[i]))
			{
				int tmp = nums[i] + 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					++tmp;
				}
				tmp = nums[i] - 1;
				while (us.count(tmp))
				{
					++cnt;
					us.erase(tmp);
					--tmp;
				}
			}
			if (res<cnt)
			{
				res = cnt;
			}
		}
		return res;
	}
};