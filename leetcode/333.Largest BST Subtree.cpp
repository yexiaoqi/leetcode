//把二叉树中序遍历转化为数组，然后看最长升序序列的想法不可行，比如[10,5,15,1,8,null,7]，最长数组为5，但是
//实际上最大的二叉树节点个数为3



//O(n^2)复杂度做法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (isValid(root, LONG_MIN, LONG_MAX))
		{
			return count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool isValid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
	int count(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return count(root->left) + count(root->right) + 1;
	}
};



//O(n)解法
//此时的helper函数返回了一个一维数组，里面有三个数字，分别是以当前结点为根结点的数的最小值，最大值，
//以及最大的 BST 子树的结点个数。那么就可以在边验证 BST 的过程中边统计个数，首先判空，若空，
//则返回一个默认三元组，整型最大值，最小值，和0。那你可能有疑问，定义的不是说第一个值是最小值么？
//没错，后面再解释。若当前结点 node 存在，分别对其左右子结点调用递归函数，
//那么左子树和右子树的信息都保存到了 left 和 right 数组中，就算左右子结点不存在也没关系，由于第一句的判空，
//还是会得到一个默认的三元组。接下来就是根据左右子树的信息来更新结果 res 了，由于 BST 的定义，
//当前结点值肯定是大于左子树的最大值，小于右子树的最小值的。左子树的最大值保存在 left[1] 中，
//右子树的最小值保存在 right[0] 中，如果这两个条件满足了，说明左右子树都是 BST，
//那么返回的三元组的最小值就是当前结点值和左子树最小值中的较小者，最大值就是当前结点值和右子树最大值中的较大值，
//返回的 BST 结点个数就是左右子树的结点个数加上1，即算上了当前结点。
//好，现在解释下为空时返回的三元组为何顺序是整型最大值，整型最小值。
//如果当前是叶结点，其也算是 BST，那么肯定希望能进入 if 从句，从而使得三元组的第三项能加1，
//但是 if 的条件是当前结点值要大于左子树中的最大值，现在左子结点是空的，为了保证条件能通过，
//我们将空的左子树的最大值设置为整型最小值，这样一定能通过，同理，将空的右子树的最小值设置为整型最大值，
//这就是空结点的三元组的作用。好，继续看 else 中的内容，如果破坏了 BST 的规则，
//则返回的三元组的最小值就是整型最小值，最大值是整型最大值，BST 结点个数并不是0，
//因为其左右子树中有可能还有 BST，所以是左右子树中的 BST 结点个数中的较大值，
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(root->val,left[0]),max(root->val,right[1]),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};

//f复习
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (Valid(root, LONG_MIN, LONG_MAX))
		{
			return Count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool Valid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return Valid(root->left, mn, root->val) && Valid(root->right, root->val, mx);
	}
	int Count(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + Count(root->left) + Count(root->right);
	}
};
//复习
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(left[0],root->val),max(right[1],root->val),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};

//复习
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<long> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i<coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount]<INT_MAX ? dp[amount] : -1;
	}
};