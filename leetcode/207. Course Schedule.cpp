//�����������
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> visit(numCourses);//ע���ʼ��
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
	/*����������״̬��0��ʾ��δ���ʹ���1��ʾ�Ѿ������ˣ�-1 ��ʾ�г�ͻ������˼·�ǣ��Ƚ���������ͼ��Ȼ��ӵ�һ���ſο�ʼ������ɹ������ſΣ���ʱ����ǰ�γ̱��Ϊ�ѷ��ʣ�Ȼ����µõ��Ŀγ̵��� DFS �ݹ飬ֱ�������µĿγ��Ѿ����ʹ��ˣ��򷵻� false��û�г�ͻ�Ļ����� true��Ȼ��ѱ��Ϊ�ѷ��ʵĿγ̸�Ϊδ���ʡ�*/
	bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i)//�����ã�����
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

//�����������
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

//��ϰ
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
		//unordered_map<int,vector<int>> m;//�������������֣�����ֱ����vector<vector<int>>������unordered_map<int,vector<int>>
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
			if (!DFS(graph, marker, graph[i][j]))//ע����graph[i][j]����j
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