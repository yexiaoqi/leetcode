//深度优先搜索
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> visit(numCourses);//注意初始化
		for (auto a : prerequisites)
		{
			graph[a[1]].push_back(a[0]);
		}
		for (int i = 0; i<numCourses; ++i)
		{
			if (!canFinishDFS(graph, visit, i))
			{
				return false;
			}
		}
		return true;
	}
	/*这里有三种状态，0表示还未访问过，1表示已经访问了，-1 表示有冲突。大体思路是，先建立好有向图，然后从第一个门课开始，找其可构成哪门课，暂时将当前课程标记为已访问，然后对新得到的课程调用 DFS 递归，直到出现新的课程已经访问过了，则返回 false，没有冲突的话返回 true，然后把标记为已访问的课程改为未访问。*/
	bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i)//传引用！！！
	{
		if (visit[i] == -1)
		{
			return false;
		}
		if (visit[i] == 1)
		{
			return true;
		}
		visit[i] = -1;
		for (auto a : graph[i])
		{
			if (!canFinishDFS(graph, visit, a))
			{
				return false;
			}
		}
		visit[i] = 1;
		return true;

	}
};

//宽度优先搜索
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> in(numCourses);
		for (auto a : prerequisites)
		{
			graph[a[1]].push_back(a[0]);
			++in[a[0]];
		}
		queue<int> q;
		for (int i = 0; i<numCourses; ++i)
		{
			if (in[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			for (auto a : graph[tmp])
			{
				--in[a];
				if (in[a] == 0)
				{
					q.push(a);
				}
			}
		}
		for (int i = 0; i<numCourses; ++i)
		{
			if (in[i] != 0)
			{
				return false;
			}
		}
		return true;
	}

};

//复习
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses == 0)
		{
			return true;
		}
		vector<vector<int>> graph(numCourses, vector<int>());
		for (int i = 0; i<prerequisites.size(); ++i)
		{
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		//unordered_map<int,vector<int>> m;//由于索引是数字，可以直接用vector<vector<int>>来代替unordered_map<int,vector<int>>
		vector<int> marker(numCourses, 0);
		for (int i = 0; i<numCourses; ++i)
		{
			if (!DFS(graph, marker, i))
			{
				return false;
			}
		}
		return true;
	}
	bool DFS(vector<vector<int>>& graph, vector<int>& marker, int i)
	{
		if (marker[i] == -1)
		{
			return false;
		}
		if (marker[i] == 1)
		{
			return true;
		}
		marker[i] = -1;
		for (int j = 0; j<graph[i].size(); ++j)
		{
			if (!DFS(graph, marker, graph[i][j]))//注意是graph[i][j]不是j
			{
				return false;
			}
		}
		marker[i] = 1;
		return true;
	}
};


class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses == 0)
		{
			return true;
		}
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> cnt(numCourses);
		for (auto a : prerequisites)
		{
			graph[a[1]].push_back(a[0]);
			++cnt[a[0]];
		}
		// for(int i=0;i<prerequisites.size();++i)
		// {
		//     graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		//     ++cnt[prerequisites[i][0]];
		// }
		queue<int> q;
		for (int i = 0; i<numCourses; ++i)
		{
			if (cnt[i] == 0)
			{
				q.push(i);
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
				}
			}
			// for(int i=0;i<graph[t].size();++i)
			// {
			//     --cnt[graph[t][i]];
			//     if(cnt[graph[t][i]]==0)
			//     {
			//         q.push(graph[t][i]);
			//     }
			// }
		}
		for (int i = 0; i<numCourses; ++i)
		{
			if (cnt[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
};