class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size()<2)
		{
			return 0;
		}
		int begin = 0;
		int end = height.size() - 1;
		int res = 0;
		while (begin<end)
		{
			int sum = (end - begin)*min(height[begin], height[end]);
			height[begin]>height[end] ? --end : ++begin;//每个长度下最高的
			if (res<sum)
			{
				res = sum;
			}
		}
		return res;
	}
};


//复习
class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size()<2)
		{
			return 0;
		}
		int begin = 0, end = height.size() - 1;
		int res = 0;
		while (begin<end)
		{
			int cur = (end - begin)*min(height[begin], height[end]);
			if (res<cur)
			{
				res = cur;
			}
			if (height[begin]<height[end])
			{
				++begin;
			}
			else
			{
				--end;
			}
		}
		return res;
	}
};