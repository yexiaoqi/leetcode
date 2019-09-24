class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> res(26, 0);
		for (char task : tasks)
		{
			++res[task - 'A'];
		}
		sort(res.begin(), res.end());//�����res[25]���ǳ��ִ���������ĸ�ĸ�����
		int i = 25, mx = res[25], len = tasks.size();
		while (i>0 && mx == res[i])i--;
		return max(len, (mx - 1)*(n + 1) + 25 - i);
	}
};
//https://www.cnblogs.com/grandyang/p/7098764.html