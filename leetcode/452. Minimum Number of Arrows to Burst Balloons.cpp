// bool cmp(const pair<int,int> &a,pair<int,int> &b)
//    {
//        return a.first<b.first;
//    }
bool cmp(const vector<int> &a, vector<int> &b)
{
	return a[0]<b[0];
}
class Solution {
public:
	//int findMinArrowShots(vector<pair<int,int>>& points)
	int findMinArrowShots(vector<vector<int>>& points)
	{
		if (points.size() == 0)
		{
			return 0;
		}
		sort(points.begin(), points.end(), cmp);
		int arrow_count = 1;
		int begin = points[0][0];
		int end = points[0][1];
		for (int i = 1; i<points.size(); ++i)
		{
			if (points[i][0] <= end)
			{
				begin = points[i][0];
				if (points[i][1]<end)
				{
					end = points[i][1];
				}
			}
			else
			{
				++arrow_count;
				begin = points[i][0];
				end = points[i][1];
			}
		}
		return arrow_count;
	}
};