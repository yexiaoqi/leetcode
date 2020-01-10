//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).
//
//Note:
//You have to rotate the image in - place, which means you have to modify the input 2D matrix directly.DO NOT allocate another 2D matrix and do the rotation.
//
//Example 1 :
//
//	Given input matrix =
//	[
//		[1, 2, 3],
//		[4, 5, 6],
//		[7, 8, 9]
//	],
//
//	rotate the input matrix in - place such that it becomes :
//	[
//		[7, 4, 1],
//		[8, 5, 2],
//		[9, 6, 3]
//	]
//	Example 2:
//
//	Given input matrix =
//		[
//			[5, 1, 9, 11],
//			[2, 4, 8, 10],
//			[13, 3, 6, 7],
//			[15, 14, 12, 16]
//		],
//
//		rotate the input matrix in - place such that it becomes :
//		[
//			[15, 13, 2, 5],
//			[14, 3, 4, 1],
//			[12, 6, 8, 9],
//			[16, 7, 10, 11]
//		]

class Solution
{
public:
	//先沿着水平中线翻转一次，再沿着主对角线翻转一次
	void rotate(vector<vector<int>>& matrix)
	{
		reverse(matrix.begin(), matrix.end());//reverse.<algorithm>中函数，in-place翻转
		for (int i = 0;i<matrix.size();++i)
		{
			for (int j = 0;j<i;++j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
//https://www.cnblogs.com/grandyang/p/4389572.html
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i<n; ++i)
		{
			for (int j = i + 1; j<n; ++j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i<n; ++i)
		{
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}

};

//复习，自己做出
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
		{
			return;
		}
		int begin = 0, end = matrix.size() - 1;
		while (begin<end)
		{
			swap(matrix[begin++], matrix[end--]);
		}
		for (int i = 0; i<matrix.size(); ++i)
		{
			for (int j = i + 1; j<matrix[0].size(); ++j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		return;
	}
};

//
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
		{
			return;
		}
		int begin = 0, end = matrix.size() - 1;
		reverse(matrix.begin(), matrix.end());//用这行替代下面几句
											  // while(begin<end)
											  // {
											  //     swap(matrix[begin++],matrix[end--]);
											  // }
		for (int i = 0; i<matrix.size(); ++i)
		{
			for (int j = i + 1; j<matrix[0].size(); ++j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		return;
	}
};