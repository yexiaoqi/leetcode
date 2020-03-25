//给一个数组，每个数字代表一个字母，a对应0，b对应1，。。。。z对应25，，按照层序遍历的顺序建立一棵二叉树，
//空子节点在数组中用null表示，寻找这棵树的最小路径，打印出路径的字母值

//从数组建立树，我们知道根节点和叶子节点的下标关系是2*i+1和2*i+2,那么我们可以递归地建立一棵树；
//然后用树的深度优先搜索，存下我们的路径和路径的和组成一个pair，然后遍历所pair，找到sum最小的
//pair对应的路径
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	string MinPath(vector<int> nums)
	{
		TreeNode* root = BuildTree(nums, 0);
		if (!root)
		{
			return "";
		}
		string path;
		vector<pair<string, int>> res;
		FindMinPath(root, path, res, 0);
		int minsum = INT_MAX;
		string strres = "";
		for (int i = 0; i < res.size(); ++i)
		{
			if (minsum > res[i].second)
			{
				minsum = res[i].second;
				strres = res[i].first;
			}
		}
		return strres;
	}
	void FindMinPath(TreeNode* root, string& path, vector<pair<string, int>> &res, int sum)
	{
		if (!root)
		{
			return;
		}
		path += root->val + 'a';
		sum += root->val;
		if (!root->left && !root->right)
		{
			res.push_back(make_pair(path, sum));
		}
		FindMinPath(root->left, path, res, sum);
		FindMinPath(root->right, path, res, sum);
		path.pop_back();
		sum -= root->val;
	}
	TreeNode* BuildTree(vector<int> &nums, int i)
	{
		if (nums.empty() || nums[i] == -1 || i >= nums.size())
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(nums[i]);
		root->left = BuildTree(nums, 2 * i + 1);
		root->right = BuildTree(nums, 2 * i + 2);
		return root;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 9, 8, 6, -1,4,2,-1,-1,-1,3,2 };
	cout << s.MinPath(nums);
	return 0;
}