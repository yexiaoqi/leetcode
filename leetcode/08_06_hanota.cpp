//面试题 08.06. 汉诺塔问题
class Solution {
public:
	void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
		int n = A.size();
		move(n, A, B, C);
	}
	void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
	{
		if (n == 1)
		{
			C.push_back(A.back());
			A.pop_back();
		}
		else
		{
			move(n - 1, A, C, B);
			move(1, A, B, C);
			move(n - 1, B, A, C);
		}
	}
};