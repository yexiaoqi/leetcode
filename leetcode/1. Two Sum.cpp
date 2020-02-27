//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].


class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> mapping;
		vector<int>result;
		for (int i = 0;i<nums.size();++i)
		{
			mapping[nums[i]] = i;
		}
		for (int i = 0;i<nums.size();++i)
		{
			const int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap]>i)
			{
				result.push_back(i);
				result.push_back(mapping[gap]);
			}
		}
		return result;
	}
};


//��ϰ1���Լ�����
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.size()<2)
		{
			return res;
		}
		unordered_map<int, int> mapping;
		for (int i = 0; i<nums.size(); ++i)
		{
			mapping[nums[i]] = i;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] != i)//��Ŀ�е��������壬�ǲ����������������ͬ���±��Ԫ�أ��������������������ͬ��Ԫ�ؿ����ã����Բ�����gap!=nums[i]
			{
				res.push_back(mapping[gap]);
				res.push_back(i);//ע�ⷵ�ص����±겻�������Լ���Ҫ�ظ����ر���0,1��1,0
				return res;
			}
		}
		return res;
	}
};


//��ϰ2
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> res(2, -1);
		for (int i = 0; i<nums.size(); ++i)
		{
			m[nums[i]] = i;//����[3,3]���Ƚ���m[3]=0,�����ָ���Ϊm[3]=1
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			int gap = target - nums[i];
			if (m.count(gap) && i != m[gap])//����������m[nums[i]]
											//if(m.count(gap)&&m[nums[i]]!=m[gap])
			{
				res[0] = i;
				res[1] = m[gap];
				return res;
			}
		}
		return res;
	}
};