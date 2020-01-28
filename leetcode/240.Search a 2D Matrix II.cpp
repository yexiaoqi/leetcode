//同剑指offer4
//自己做出
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int row = 0;
		int col = matrix[0].size() - 1;
		return search(matrix, target, row, col);
	}
	bool search(vector<vector<int>>& matrix, int target, int row, int col)
	{
		if (row >= matrix.size() || col<0)
		{
			return false;
		}
		int num = matrix[row][col];
		if (num == target)
		{
			return true;
		}
		if (num>target)
		{
			return search(matrix, target, row, col - 1);
		}
		else
		{
			return search(matrix, target, row + 1, col);
		}
	}
};

//迭代版本
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int sizei = int(array.size());
		int sizej = int(array[0].size());
		int i = 0, j = sizej - 1;
		while (i<sizei&&j >= 0)
		{
			if (array[i][j] == target)
			{
				return true;
			}
			else if (array[i][j]>target)
			{
				--j;
			}
			else
			{
				++i;
			}
		}
		return false;
	}
};

//复习
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& array, int target) {
		if (array.empty() || array[0].empty())
		{
			return false;
		}
		int row = array.size() - 1;
		int col = 0;
		while (row >= 0 && col<array[0].size())
		{
			int num = array[row][col];
			if (num>target)
			{
				row--;
			}
			else if (num<target)
			{
				++col;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

//复习，自己用上lower_bound
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& array, int target) {
		if (array.empty() || array[0].empty())
		{
			return false;
		}
		int row = array.size() - 1;
		int col = 0;
		while (row >= 0 && col<array[0].size())
		{
			int num = array[row][col];
			if (num>target)
			{
				row--;
			}
			else if (num<target)
			{
				//++col;
				col = lower_bound(array[row].begin(), array[row].end(), target) - array[row].begin();
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};