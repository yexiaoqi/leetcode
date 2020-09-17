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

//����������Ҫ�����û�������Ŀγ̣��������������207��һ����˳�������磬2��[[0, 1]]�����ȿ�0,0������1��
//Ӧ�������1��������207�������0
//�㷨���̣�
//
//�� 1 �����������ڽӱ�
//
//�� 2 �����ݹ鴦��ÿһ����û�б����ʵĽ�㣬���������ܼ򵥣�����һ�������˵�������ָ���������ж��㣬
//������Լ���
//
//�� 3 �������������㻹û�б����������͵ݹ��������������ָ�����Ľ�㶼����ˣ�������Լ���
//ע�⣺������һ������ʱ��Ӧ���ȵݹ��������ǰ����㣬ֱ��ǰ�����û��ǰ�����Ϊֹ��
//�ڽӱ�������ȣ������ڽӱ�������ȣ���
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>());
		for (auto a : prerequisites)
		{
			graph[a[0]].push_back(a[1]);//������ڽ�
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
		for (int j = 0; j<graph[i].size(); ++j)//ע��graph[i]����graph
		{
			if (!DFS(graph, res, marker, graph[i][j]))
			{
				return false;
			}
		}
		res.push_back(i);//�������Ӷ���������
		marker[i] = 1;
		return true;
	}
};


//��ϰ
logo
̽��
���
Ȧ��
����
����
ְλ
�̵�
25


�γ̱� II
�ύ��¼
44 / 44 ��ͨ����������
״̬��ͨ��
ִ����ʱ : 52 ms
	�ڴ����� : 14.1 MB
	�ύʱ�䣺9 ��ǰ
	ִ����ʱ�ֲ�ͼ��
	ִ�������ڴ�ֲ�ͼ��
	�����������ս �γ̱� II
	�ύ�Ĵ��룺 9 ��ǰ
	���ԣ� cpp


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