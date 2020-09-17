//BFS
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> cnt(numCourses);
		for (auto a : prerequisites)
		{
			graph[a[1]].push_back(a[0]);
			++cnt[a[0]];
		}
		vector<int> res;
		queue<int> q;
		for (int i = 0; i<numCourses; ++i)
		{
			if (cnt[i] == 0)
			{
				res.push_back(i);
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			for (int i = 0; i<graph[tmp].size(); ++i)
			{
				--cnt[graph[tmp][i]];
				if (cnt[graph[tmp][i]] == 0)
				{
					res.push_back(graph[tmp][i]);
					q.push(graph[tmp][i]);
				}
			}
		}
		for (int i = 0; i<numCourses; ++i)
		{
			if (cnt[i] != 0)
			{
				return vector<int>();
			}
		}
		return res;
	}
};

//本题由于需要先输出没有依赖的课程，所以如果仅仅像207题一样，顺序会错，比如，2，[[0, 1]]，会先看0,0依赖于1，
//应该先输出1，但按照207会先输出0
//算法流程：
//
//第 1 步：构建逆邻接表；
//
//第 2 步：递归处理每一个还没有被访问的结点，具体做法很简单：对于一个结点来说，先输出指向它的所有顶点，
//再输出自己。
//
//第 3 步：如果这个顶点还没有被遍历过，就递归遍历它，把所有指向它的结点都输出了，再输出自己。
//注意：当访问一个结点的时候，应当先递归访问它的前驱结点，直至前驱结点没有前驱结点为止。
//邻接表（可算出度）和逆邻接表（可算入度）。
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>());
		for (auto a : prerequisites)
		{
			graph[a[0]].push_back(a[1]);//这里，逆邻接
		}
		vector<int> res;
		vector<int> marker(numCourses);
		for (int i = 0; i<numCourses; ++i)
		{
			if (!DFS(graph, res, marker, i))
			{
				return vector<int>();
			}
		}
		return res;
	}
	bool DFS(vector<vector<int>> &graph, vector<int> &res, vector<int> &marker, int i)
	{
		if (marker[i] == -1)
		{
			return false;
		}
		if (marker[i] == 1)
		{
			return true;
		}
		//res.push_back(i);
		marker[i] = -1;
		for (int j = 0; j<graph[i].size(); ++j)//注意graph[i]不是graph
		{
			if (!DFS(graph, res, marker, graph[i][j]))
			{
				return false;
			}
		}
		res.push_back(i);//在这边添加而不是上面
		marker[i] = 1;
		return true;
	}
};


//复习
logo
探索
题库
圈子
竞赛
面试
职位
商店
25


课程表 II
提交记录
44 / 44 个通过测试用例
状态：通过
执行用时 : 52 ms
	内存消耗 : 14.1 MB
	提交时间：9 天前
	执行用时分布图表
	执行消耗内存分布图表
	邀请好友来挑战 课程表 II
	提交的代码： 9 天前
	语言： cpp


	class Solution {
	public:
		vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
			vector<vector<int>> graph(numCourses);
			vector<int> cnt(numCourses);
			for (auto a : prerequisites)
			{
				graph[a[1]].push_back(a[0]);
				++cnt[a[0]];
			}
			queue<int> q;
			vector<int> res;
			for (int i = 0; i<numCourses; ++i)
			{
				if (cnt[i] == 0)
				{
					q.push(i);
					res.push_back(i);
				}
			}
			while (!q.empty())
			{
				int t = q.front();
				q.pop();
				for (auto a : graph[t])
				{
					--cnt[a];
					if (cnt[a] == 0)
					{
						q.push(a);
						res.push_back(a);
					}
				}
			}
			for (int i = 0; i<numCourses; ++i)
			{
				if (cnt[i] != 0)
				{
					return vector<int>();
				}
			}
			return res;
		}
};