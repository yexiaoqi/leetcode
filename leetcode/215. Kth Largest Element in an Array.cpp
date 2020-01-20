class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue <int, vector<int>, greater<int>> q;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (i<k)
			{
				q.push(nums[i]);
			}
			else
			{
				if (nums[i]>q.top())
				{
					q.pop();
					q.push(nums[i]);
				}
			}
		}
		return q.top();
	}
};


//������
class Solution {
public:
	int partition(vector<int>& nums, int begin, int end)
	{
		int key = nums[begin];
		while (begin<end)
		{
			while (begin<end&&nums[end] >= key)
			{
				--end;
			}
			nums[begin] = nums[end];
			while (begin<end&&nums[begin] <= key)
			{
				++begin;
			}
			nums[end] = nums[begin];
		}
		nums[begin] = key;
		return begin;
	}
	int findKthLargest(vector<int>& nums, int k) {
		if (k>nums.size())
		{
			return -1;
		}
		int target = nums.size() - k;//����[3,2,1,5,6,4]��k=2����ô�ڶ����5���±���nums.size()-k
		int begin = 0, end = nums.size() - 1;
		int index = partition(nums, begin, end);
		// if(index==k-1)
		// {
		//     return nums[index];
		// }
		while (index != target)
		{
			if (index>target)
			{
				end = index - 1;
				index = partition(nums, begin, end);//Ҫ��index=�����򲻸���index��Զ������
			}
			else
			{
				begin = index + 1;;
				index = partition(nums, begin, end);
			}
		}
		return nums[index];
	}
};

//��ϰ
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> q;
		if (k>nums.size())
		{
			return -1;
		}
		for (int i = 0; i<k; ++i)
		{
			q.push(nums[i]);
		}
		for (int i = k; i<nums.size(); ++i)
		{
			if (nums[i]>q.top())
			{
				q.pop();
				q.push(nums[i]);
			}
		}
		return q.top();
	}
};