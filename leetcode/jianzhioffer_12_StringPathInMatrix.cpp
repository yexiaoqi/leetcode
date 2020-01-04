class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if ((matrix == NULL || rows<1 || cols<1) && str)
		{
			return false;
		}
		if ((matrix == NULL || rows<1 || cols<1) && str == NULL)
		{
			return true;
		}
		char *marker = new char[rows*cols];
		memset(marker, 0, rows*cols);//注意注意
		//bool judge = false;
		for (int i = 0; i<rows; ++i)
		{
			for (int j = 0; j<cols; ++j)
			{
				bool res = search(matrix, marker, rows, cols, str, i, j);
				if (res == true)
				{
					return true;
				}
			}
		}
		delete[]marker;
		return false;
	}
	bool search(char* matrix, char *&marker, int rows, int cols, char* &str, int row, int col)
	{
		if (*str == '\0')
		{
			return true;
		}
		bool judge = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&*str == matrix[row*cols + col] && marker[row*cols + col] == 0)
		{
			marker[row*cols + col] = 1;
			++str;
			judge = search(matrix, marker, rows, cols, str, row - 1, col)
				|| search(matrix, marker, rows, cols, str, row + 1, col)
				|| search(matrix, marker, rows, cols, str, row, col - 1)
				|| search(matrix, marker, rows, cols, str, row, col + 1);//用了||,必须有返回值，所以得是bool search
			if (!judge)
			{
				marker[row*cols + col] = 0;
				--str;
			}
		}

		return judge;
	}

};



class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if ((matrix == NULL || rows<1 || cols<1) && str)
		{
			return false;
		}
		if ((matrix == NULL || rows<1 || cols<1) && str == NULL)
		{
			return true;
		}
		char *marker = new char[rows*cols];
		memset(marker, 0, rows*cols);
		bool judge = false;
		for (int i = 0; i<rows; ++i)
		{
			for (int j = 0; j<cols; ++j)
			{
				bool res = search(matrix, marker, rows, cols, str, i, j, judge);
				if (res == true)
				{
					return true;
				}
			}
		}
		delete[]marker;
		return false;
	}
	bool search(char* matrix, char *&marker, int rows, int cols, char* &str, int row, int col, bool &judge)
	{
		if (*str == '\0')
		{
			return true;
		}
		//bool judge = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&*str == matrix[row*cols + col] && marker[row*cols + col] == 0)
		{
			marker[row*cols + col] = 1;
			++str;
			judge = search(matrix, marker, rows, cols, str, row - 1, col, judge)
				|| search(matrix, marker, rows, cols, str, row + 1, col, judge)
				|| search(matrix, marker, rows, cols, str, row, col - 1, judge)
				|| search(matrix, marker, rows, cols, str, row, col + 1, judge);//用了||,必须有返回值，所以得是bool search
			if (!judge)
			{
				marker[row*cols + col] = 0;
				--str;
			}
		}

		return judge;
	}

};