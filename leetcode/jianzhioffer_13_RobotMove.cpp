class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<int>> marker;
		if (rows<1 || cols<1 || threshold<0)
		{
			return 0;
		}
		for (int i = 0; i<rows; ++i)
		{
			marker.push_back(vector<int>());
			for (int j = 0; j<cols; ++j)
			{
				marker[i].push_back(0);
			}
		}
		int count = 1;
		search(threshold, rows, cols, count, 0, 0, marker);
		return count;
	}
	void search(int threshold, int rows, int cols, int &count, int x, int y, vector<vector<int>> &marker)
	{
		int dx[4] = { 0,0,1,-1 };
		int dy[4] = { 1,-1,0,0 };
		marker[x][y] = 1;
		for (int i = 0; i<4; ++i)
		{
			int newx = x + dx[i];
			int newy = y + dy[i];
			if (newx<0 || newx >= rows || newy<0 || newy >= cols)
			{
				continue;
			}
			if ((sumofnum(newx) + sumofnum(newy)) <= threshold&&marker[newx][newy] == 0)
			{
				++count;
				search(threshold, rows, cols, count, newx, newy, marker);
			}
		}
		return;
	}
	int sumofnum(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};