//同leetcode240
/*在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 */
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

//自己做出，递归版本
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

//复习
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return false;
		}
		int m = matrix.size(), n = matrix[0].size();
		int i = 0, j = n - 1;
		while (i<m&&j >= 0)
		{
			if (matrix[i][j] == target)
			{
				return true;
			}
			else if (matrix[i][j]<target)
			{
				++i;
			}
			else
			{
				--j;
			}
		}
		return false;
	}
};