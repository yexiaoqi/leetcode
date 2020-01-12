class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0)
		{
			return vector<vector<int>>();//不要忘记特殊
		}
		sort(intervals.begin(), intervals.end());//按照intervals中每个vector中的第一个元素排序，第一个元素一样再按第二个排序，以此类推
		vector<vector<int>> res;
		res.push_back(intervals[0]);
		for (int i = 1; i<intervals.size(); ++i)
		{
			if (intervals[i][0]>res.back()[1])
			{
				res.push_back(intervals[i]);
			}
			else
			{
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
		}
		return res;
	}
};