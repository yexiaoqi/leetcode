/*有一个二维迷宫，0表示可以走，1表示不能走，从左上角开始，到右下角，问有多少条最短路径*/
class Solution
{
public:
	int FindPath(vector<vector<int>> &nums)
	{
		if (nums.size() == 0 || nums[0].size() == 0)
		{
			return 0;
		}
		vector<vector<int>> marker(nums.size(), vector<int>(nums[0].size(), 0));
		//vector<int> path;
		//vector<pair<int,int> pathwithcnt;
		int cnt = 0;
		int rescount = 0;
		vector<int> allpath;
		Findpath2(nums, marker, 0, 0, cnt, allpath);
		int minpathsize = INT_MAX;
		for (int i = 0; i<allpath.size(); ++i)
		{
			if (minpathsize>allpath[i])
			{
				minpathsize = allpath[i];
			}
		}
		for (int i = 0; i<allpath.size(); ++i)
		{
			if (allpath[i] == minpathsize)
			{
				++rescount;
			}
		}
		return rescount;

	}
	void Findpath2(vector<vector<int>> &nums, vector<vector<int>> &marker,
		int x, int y, int &cnt, vector<int> &allpath)
	{
		if (x == nums.size() - 1 && y == nums[0].size() - 1)
		{
			allpath.push_back(cnt);
			return;
		}
		marker[x][y] = 1;
		int dx[4] = { 0,0,1,-1 };
		int dy[4] = { 1,-1,0,0 };
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= nums.size() || newy<0 || newy >= nums[0].size())
			{
				continue;
			}
			if (nums[newx][newy] == 0 && marker[newx][newy] == 0)
			{
				++cnt;
				Findpath2(nums, marker, newx, newy, cnt, allpath);
				--cnt;
			}
			//marker[x][y]=0;
			//--cnt;
		}
		marker[x][y] = 0;
		//if(nums[x][y]==0)
		//{	
		//	--cnt;
		//}
	}
};