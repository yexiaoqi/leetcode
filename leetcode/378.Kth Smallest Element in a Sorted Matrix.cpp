class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return -1;
		}
		int left = matrix[0][0], right = matrix.back().back();
		//int mid=(left+right)/2;
		int mid = left + (right - left) / 2;//这边如果是[[2000000000]]，用上面这种会溢出
		int cnt = findnum(matrix, mid);
		while (left<right)
		{
			if (cnt<k)
			{
				left = mid + 1;
				mid = (left + right) / 2;
				cnt = findnum(matrix, mid);
			}
			else
			{
				right = mid;
				mid = (left + right) / 2;
				cnt = findnum(matrix, mid);
			}
		}
		return left;
	}
	int findnum(vector<vector<int>> &matrix, int target)
	{
		int i = matrix.size() - 1, j = 0;
		int res = 0;
		while (i >= 0 && j<matrix[0].size())
		{
			if (matrix[i][j] <= target)
			{
				res += i + 1;
				++j;
			}
			else
			{
				--i;
			}
		}
		return res;
	}
};


// O(nlgn*lgX)
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int left = matrix[0][0], right = matrix.back().back();
		while (left < right) {
			int mid = left + (right - left) / 2, cnt = 0;
			for (int i = 0; i < matrix.size(); ++i) {
				cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
			}
			if (cnt < k) left = mid + 1;
			else right = mid;
		}
		return left;
	}
};

//简化O(nlgX)
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return -1;
		}
		int left = matrix[0][0], right = matrix.back().back();
		while (left<right)
		{
			//int mid=(left+right)/2;
			int mid = left + (right - left) / 2;//这边如果是[[2000000000]]，用上面这种会溢出
			int cnt = findnum(matrix, mid);
			if (cnt<k)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return left;
	}
	int findnum(vector<vector<int>> &matrix, int target)
	{
		int i = matrix.size() - 1, j = 0;
		int res = 0;
		while (i >= 0 && j<matrix[0].size())
		{
			if (matrix[i][j] <= target)
			{
				res += i + 1;
				++j;
			}
			else
			{
				--i;
			}
		}
		return res;
	}
};