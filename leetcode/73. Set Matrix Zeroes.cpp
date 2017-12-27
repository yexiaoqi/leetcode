//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.

class Solution
	//o(1)�ռ䣬���õ�һ�к͵�һ�У���Ϊ��1,1������㱻�����õ�����ɴ������Ե���һ��col0��ʾ��һ��
{
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		int col0 = 1;
		int rows = matrix.size(), cols = matrix[0].size();//���еı�ʾ
		for (int i = 0;i<rows;++i)
		{
			if (matrix[i][0] == 0)
			{
				col0 = 0;
			}
			for (int j = 1;j<cols;++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		for (int i = rows - 1;i >= 0;--i)
			//ע�⣬��������½������Ͻǣ�������ע�͵���˳���ǲ��еģ�������if(col0==0)Ҫ�����forѭ��֮�󣬷���ᵼ������ֵ��Ϊ0
			//for(int i=0;i<rows;++i)
		{
			for (int j = cols - 1;j >= 1;--j)
				//for(int j=1;j<cols;++j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
				{
					matrix[i][j] = 0;
				}
			}
			if (col0 == 0)//ע��==
			{
				matrix[i][0] = 0;
			}
		}

	}
};