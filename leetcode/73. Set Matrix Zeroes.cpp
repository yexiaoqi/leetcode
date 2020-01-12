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

//��ϰ
//�Լ��ķ���������o(m+n)�Ķ���ռ䣬��������
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

//o(1)�ռ临�Ӷ�
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//�õ�һ�е�һ������¼������ٸ��µ�һ�е�һ��
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