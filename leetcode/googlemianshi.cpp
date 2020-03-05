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





/*有一个二维迷宫，0表示可以走，1表示不能走，从左上角开始，到右下角，问最短路径是多少*/
//只求一条最短路径的话用BFS
class Solution2
{
public:
	int FindPath(vector<vector<int>> &nums)
	{
		if (nums.empty() || nums[0].empty())
		{
			return 0;
		}
		vector<vector<int>> d(nums.size(), vector<int>(nums[0].size(), INT_MIN));
		if (nums[0][0] == 1)
		{
			return 0;
		}
		BFS(nums, d, 0, 0);
		return d[nums.size() - 1][nums[0].size() - 1];
	}
	void BFS(vector<vector<int>> &nums, vector<vector<int>> &d, int x, int y)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		d[0][0] = 0;	//从起点出发将距离设为0，并放入队列首端
		while (!q.empty()) //题目保证有路到终点，所以不用担心死循环
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int i;
			int dx[4] = { 1,-1,0,0 };
			int dy[4] = { 0,0,1,-1 };
			for (i = 0; i < 4; i++)
			{
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (newx < 0 || newy < 0 || newx >= nums.size() || newy >= nums[0].size())
				{
					continue;
				}
				if (nums[newx][newy] == 0 && d[newx][newy] == INT_MIN)
				{
					q.push(make_pair(newx, newy));	//可以移动则设定距离为之前加一，放入队列
					d[newx][newy] = d[x][y] + 1;
					if ((newx == nums.size() - 1) && (newy == nums[0].size() - 1))
					{
						break;
					}
				}
			}
		}
	}
};




/*有一个二维迷宫，1表示可以走，0表示不能走，从左上角开始，到右下角，求最短路径是什么样的*/
//1可以通过，0阻碍
struct point
{
	int x;
	int y;
	int step;
	point(int _x, int _y, int _step) :x(_x), y(_y), step(_step) {}
	point(int _x, int _y) :x(_x), y(_y), step(0) {}
	point() {}
	bool operator==(point& other)
	{
		return x == other.x&&y == other.y;
	}
};

class Solution3
{
public:
	int minSteps_BFS(const vector<vector<int>>& nums, vector<vector<int>> &marker, vector<vector<point>>& mp, point src, point des, int step)
	{
		int n = nums.size();
		int m = nums[0].size();
		marker[src.x][src.y] = 1;
		queue<point> q;
		q.push(src);
		while (!q.empty())
		{
			point p = q.front();
			int dx[4] = { 1,-1,0,0 };
			int dy[4] = { 0,0,1,-1 };
			for (int i = 0; i < 4; ++i)
			{
				int newx = p.x + dx[i];
				int newy = p.y + dy[i];
				if (newx < 0 || newx >= n || newy < 0 || newy >= m)
				{
					continue;
				}
				if (nums[newx][newy] == 1 && !marker[newx][newy])
				{
					marker[newx][newy] = true;
					q.push(point(newx, newy, p.step + 1));
					mp[newx][newy] = p;//存下它是从哪一个位置变过来的
					if (point(newx, newy, p.step + 1) == des)
					{
						return p.step + 1;
					}
				}
			}
			q.pop();
		}
		return -1;
	}
	void FindPath(vector<vector<int>> nums)
	{
		if (nums.empty() || nums[0].empty())
		{
			return;
		}
		vector<vector<int>> marker(nums.size(), vector<int>(nums[0].size(), 0));
		vector<vector<point>> mp(5, vector<point>(5));
		point src(0, 0);
		point des(3, 3);
		int step = 0;
		cout << minSteps_BFS(nums, marker, mp, src, des, step) << endl;
		cout << "具体路径如下：" << endl;
		//vector<point> res;
		while (!(mp[des.x][des.y] == src))
		{
			cout << des.x << " " << des.y << endl;
			des = mp[des.x][des.y];
		}//从出口到入口打印，因为出口记录了上一个位置，所以必须按照这个顺序
		cout << des.x << " " << des.y << endl;
	}
};
