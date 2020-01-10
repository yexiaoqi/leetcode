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
			height[begin]>height[end] ? --end : ++begin;//ÿ����������ߵ�
			if (res<sum)
			{
				res = sum;
			}
		}
		return res;
	}
};