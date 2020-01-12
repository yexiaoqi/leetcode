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

//复习
//自己的方法，用了o(m+n)的额外空间，不是最优
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		unordered_map<int, int> rows;
		unordered_map<int, int> cols;
		for (int i = 0; i<matrix.size(); ++i)
		{
			for (int j = 0; j<matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					rows[i] = 1;
					cols[j] = 1;
				}
			}
		}
		for (int i = 0; i<matrix.size(); ++i)
		{
			if (rows[i] == 1)
			{
				for (int j = 0; j<matrix[0].size(); ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 0; j<matrix[0].size(); ++j)
		{
			if (cols[j] == 1)
			{
				for (int i = 0; i<matrix.size(); ++i)
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};

//o(1)空间复杂度
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//用第一行第一列来记录，最后再更新第一行第一列
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return;
		}
		bool row0flag = false, col0flag = false;
		for (int i = 0; i<matrix.size(); ++i)
		{
			if (matrix[i][0] == 0)
			{
				col0flag = true;
			}
		}
		for (int i = 0; i<matrix[0].size(); ++i)
		{
			if (matrix[0][i] == 0)
			{
				row0flag = true;
			}
		}
		for (int i = 1; i<matrix.size(); ++i)
		{
			for (int j = 1; j<matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i<matrix.size(); ++i)
		{
			for (int j = 1; j<matrix[0].size(); ++j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
				{
					matrix[i][j] = 0;
				}
			}
		}
		if (row0flag)
		{
			for (int i = 0; i<matrix[0].size(); ++i)
			{
				matrix[0][i] = 0;
			}
		}
		if (col0flag)
		{
			for (int i = 0; i<matrix.size(); ++i)
			{
				matrix[i][0] = 0;
			}
		}
	}
};