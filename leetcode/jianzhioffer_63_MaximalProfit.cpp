class Solution {
public:
	int findmaxdiff(vector<int> num)
	{
		if (num.size() <2)
		{
			return 0;
		}
		int min = num[0];
		int maxdiff = num[1] - num[0];
		for (int i = 2; i < num.size(); ++i)
		{
			if (num[i - 1] < min)
			{
				min = num[i - 1];
			}
			int curdiff = num[i] - min;
			if (curdiff > maxdiff)
			{
				maxdiff = curdiff;
			}
		}
		return maxdiff;
	}
};