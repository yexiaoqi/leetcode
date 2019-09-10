//The set[1, 2, 3, …, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//	Given n and k, return the kth permutation sequence.
//
//	Note: Given n will be between 1 and 9 inclusive.


class Solution
{
public:
	string getPermutation(int n, int k)
	{
		int ptable[10] = { 1 };
		for (int i = 1;i<n;++i)
		{
			ptable[i] = i*ptable[i - 1];
		}
		vector<char> numset = { '1','2','3','4','5','6','7','8','9' };
		string result;
		while (n>0)
			//不能是for(int i=0;i<=n;++i)，因为--n，n会变，但我们其实就想执行最初的n+1次
		{
			int temp;
			temp = (k - 1) / ptable[n - 1];
			result += numset[temp];
			numset.erase(numset.begin() + temp);
			k = k - temp*ptable[n - 1];
			--n;
		}
		return result;
	}
};


//https://www.cnblogs.com/grandyang/p/4358678.html
class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		string nums = "123456789";
		vector<int> f(n, 1);
		for (int i = 1; i<n; ++i)
		{
			f[i] = f[i - 1] * i;
		}
		--k;
		for (int i = n; i >= 1; --i)
		{
			int j = k / f[i - 1];
			k %= f[i - 1];
			res.push_back(nums[j]);
			nums.erase(j, 1);
		}
		return res;
	}
};