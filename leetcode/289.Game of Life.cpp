//可以使用状态机转换：
//
//状态0： 死细胞转为死细胞
//
//状态1： 活细胞转为活细胞
//
//状态2： 活细胞转为死细胞
//
//状态3： 死细胞转为活细胞
//
//最后对所有状态对2取余，则状态0和2就变成死细胞，状态1和3就是活细胞，达成目的。先对原数组进行逐个扫描，
//对于每一个位置，扫描其周围八个位置，如果遇到状态1或2，就计数器累加1，扫完8个邻居，
//如果少于两个活细胞或者大于三个活细胞，而且当前位置是活细胞的话，标记状态2，
//如果正好有三个活细胞且当前是死细胞的话，标记状态3。完成一遍扫描后再对数据扫描一遍，对2取余变成我们想要的结果
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return;
		}
		int dx[8] = { -1,0,1,-1,1,-1,0,1 };
		int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				int cnt = 0;
				for (int k = 0; k<8; ++k)
				{
					int newi = i + dx[k];
					int newj = j + dy[k];
					if (newi<0 || newi >= board.size() || newj<0 || newj >= board[0].size())
					{
						continue;
					}
					if (board[newi][newj] == 1 || board[newi][newj] == 2)
					{
						++cnt;;
					}
				}
				if (board[i][j] && (cnt<2 || cnt>3))
				{
					board[i][j] = 2;
				}
				else if (!board[i][j] && cnt == 3)
				{
					board[i][j] = 3;
				}
			}
		}
		for (int i = 0; i<board.size(); ++i)
		{
			for (int j = 0; j<board[0].size(); ++j)
			{
				board[i][j] %= 2;
			}
		}
	}
};