//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note : The solution set must not contain duplicate triplets.
//
//	For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]
class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res;
		std::sort(nums.begin(), nums.end());
		for (int i = 0;i<nums.size();++i)
		{
			int target = -nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			if (target<0)
			{
				break;
			}
			while (front<back)
			{
				int sum = nums[front] + nums[back];
				if (sum<target)
				{
					++front;
				}
				else if (sum>target)
				{
					--back;
				}
				else
				{
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[front];
					triplet[2] = nums[back];
					res.push_back(triplet);
					while (front<back&&nums[front] == triplet[1])
					{
						++front;
					}//ע��ȥ��
					while (front<back&&nums[back] == triplet[2])
					{
						--back;
					}//ע��ȥ��
				}
			}
			while (nums[i + 1] == nums[i] && i + 1<nums.size())
			{
				++i;
			}//ע��ȥ��
		}
		return res;
	}
};

//��ϰ
//�Լ�д���������ֽⷨ���� fix һ������Ȼ������������ʹ�� Two Sum ���� HashMap �Ľⷨ����ʱ
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		map<char, int> m;
		if (nums.size() <3)
		{
			return vector<vector<int>>();
		}
		//vector<vector<int>> res;
		set<vector<int>> res_set;
		for (int i = 0; i<nums.size(); ++i)
		{
			m[nums[i]] = i;
		}
		for (int i = 0; i<nums.size(); ++i)
		{
			for (int j = i + 1; j<nums.size(); ++j)
			{
				int gap = -nums[i] - nums[j];
				if (m.find(gap) != m.end() && m[gap]>j)
				{
					vector<int> one;
					one.push_back(nums[i]);
					one.push_back(nums[j]);
					one.push_back(gap);
					sort(one.begin(), one.end());
					res_set.insert(one);
					// res.push_back(one);
				}
			}
		}
		return vector<vector<int>>(res_set.begin(), res_set.end());
	}
};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());//�����������������ж�
		if (nums.size()<3 || nums.back()<0 || nums.front()>0)//���ж��Ƿ�ȫ����������
		{
			return vector<vector<int>>();
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;//ȥ���ظ��ı���
			}
			int begin = i + 1;
			int end = nums.size() - 1;
			while (begin<end)
			{
				if (nums[begin] + nums[end]<-nums[i])
				{
					++begin;
				}
				else if (nums[begin] + nums[end]>-nums[i])
				{
					--end;
				}
				else
				{
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])
					{
						++begin;//ȥ���ظ��ı���
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;//ȥ���ظ��ı���
					}
					++begin;
					--end;//�ҵ�һ���Ҫ�ƶ�begin��end
				}
			}
		}
		return res;
	}
};



//��ϰ
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size()<3)
		{
			return vector<vector<int>>();
		}
		sort(nums.begin(), nums.end());
		if (nums[0]>0 || nums[nums.size() - 1]<0)
		{
			return vector<vector<int>>();
		}
		vector<vector<int>> res;
		//set<vector<int>> res_set;
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
				//if(nums[i]==nums[i+1])//����-1��-1,2��������nums[i]==nums[i+1]�ж�������û�н���
			{
				continue;//���ܶ�����setȥ�أ������Ӷ�̫��
			}
			int target = -nums[i];
			int begin = i + 1, end = nums.size() - 1;
			while (begin<end)
			{
				int sum = nums[begin] + nums[end];
				if (sum == target)
				{
					//res_set.insert({nums[i],nums[begin],nums[end]});
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])//Ҫ��֤begin<end
					{
						++begin;
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;
					}
					++begin;
					--end;
				}
				else if (sum<target)
				{
					++begin;
				}
				else
				{
					--end;
				}
			}
		}
		return res;
		//return vector<vector<int>>(res_set.begin(),res_set.end());
	}
};


//��ϰ
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size()<3)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		int begin = 0, end = nums.size() - 1;
		if (nums[begin]>0 || nums[end]<0)
		{
			return res;
		}
		for (int i = 0; i<nums.size() - 2; ++i)
		{
			if (nums[i]>0)
			{
				break;
			}
			if (i>0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			begin = i + 1;
			end = nums.size() - 1;//ע��Ҫ���¸�ֵ����һ�ֱ��ı����
			while (begin<end)
			{
				int tmp = nums[i] + nums[begin] + nums[end];
				if (tmp == 0)
				{
					res.push_back({ nums[i],nums[begin],nums[end] });
					while (begin<end&&nums[begin] == nums[begin + 1])
					{
						++begin;
					}
					while (begin<end&&nums[end] == nums[end - 1])
					{
						--end;
					}
					++begin;
					--end;
				}
				else if (tmp<0)
				{
					++begin;
				}
				else
				{
					--end;
				}
			}
		}
		return res;
	}
};