/*��һ����ά�Թ���0��ʾ�����ߣ�1��ʾ�����ߣ������Ͻǿ�ʼ�������½ǣ����ж��������·��*/
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





/*��һ����ά�Թ���0��ʾ�����ߣ�1��ʾ�����ߣ������Ͻǿ�ʼ�������½ǣ������·���Ƕ���*/
//ֻ��һ�����·���Ļ���BFS
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
		d[0][0] = 0;	//����������������Ϊ0������������׶�
		while (!q.empty()) //��Ŀ��֤��·���յ㣬���Բ��õ�����ѭ��
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
					q.push(make_pair(newx, newy));	//�����ƶ����趨����Ϊ֮ǰ��һ���������
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




/*��һ����ά�Թ���1��ʾ�����ߣ�0��ʾ�����ߣ������Ͻǿ�ʼ�������½ǣ������·����ʲô����*/
//1����ͨ����0�谭
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
					mp[newx][newy] = p;//�������Ǵ���һ��λ�ñ������
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
		cout << "����·�����£�" << endl;
		//vector<point> res;
		while (!(mp[des.x][des.y] == src))
		{
			cout << des.x << " " << des.y << endl;
			des = mp[des.x][des.y];
		}//�ӳ��ڵ���ڴ�ӡ����Ϊ���ڼ�¼����һ��λ�ã����Ա��밴�����˳��
		cout << des.x << " " << des.y << endl;
	}
};
