//����ʹ��״̬��ת����
//
//״̬0�� ��ϸ��תΪ��ϸ��
//
//״̬1�� ��ϸ��תΪ��ϸ��
//
//״̬2�� ��ϸ��תΪ��ϸ��
//
//״̬3�� ��ϸ��תΪ��ϸ��
//
//��������״̬��2ȡ�࣬��״̬0��2�ͱ����ϸ����״̬1��3���ǻ�ϸ�������Ŀ�ġ��ȶ�ԭ����������ɨ�裬
//����ÿһ��λ�ã�ɨ������Χ�˸�λ�ã��������״̬1��2���ͼ������ۼ�1��ɨ��8���ھӣ�
//�������������ϸ�����ߴ���������ϸ�������ҵ�ǰλ���ǻ�ϸ���Ļ������״̬2��
//���������������ϸ���ҵ�ǰ����ϸ���Ļ������״̬3�����һ��ɨ����ٶ�����ɨ��һ�飬��2ȡ����������Ҫ�Ľ��
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