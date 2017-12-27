//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.

class Solution
	//o(1)空间，复用第一行和第一列，因为（1,1）这个点被交叉用到会造成错误，所以单建一个col0表示第一列
{
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		int col0 = 1;
		int rows = matrix.size(), cols = matrix[0].size();//行列的表示
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
			//注意，必须从右下角往左上角（即下面注释掉的顺序是不行的），并且if(col0==0)要在里层for循环之后，否则会导致所有值都为0
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
			if (col0 == 0)//注意==
			{
				matrix[i][0] = 0;
			}
		}

	}
};