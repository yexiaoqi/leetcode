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
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root)
		{
			return NULL;
		}
		vector<TreeNode*> res;
		MakeVec(root, res);
		int n = res.size();
		for (int i = 0; i<n - 1; ++i)
		{
			if (p->val == res[i]->val)
			{
				return res[i + 1];
			}
		}
		return NULL;
	}
	void MakeVec(TreeNode* root, vector<TreeNode*> &res)
	{
		if (!root)
		{
			return;
		}
		MakeVec(root->left, res);
		res.push_back(root);
		MakeVec(root->right, res);
	}
};


//更好的方法
//我们首先看根节点值和p节点值的大小，如果根节点值大，说明p节点肯定在左子树中，
//那么此时我们先将 res 赋为 root，然后 root 移到其左子节点，循环的条件是 root 存在，
//我们再比较此时 root 值和p节点值的大小，如果还是 root 值大，我们重复上面的操作，如果p节点值>root->val，
//那么我们将 root 移到其右子节点，这样当 root 为空时，res 指向的就是p的后继节点，

//也就是res是当前节点值，然后找它前一个节点，那么前一个节点等于p的之后，res就是我们要找的后一个节点
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode *res = NULL;
		while (root)
		{
			if (root->val>p->val)
			{
				res = root;
				root = root->left;
			}
			else
			{
				root = root->right;
			}
		}
		return res;
	}
};


//比较好理解的方法
中序遍历的递归写法，我们需要两个变量 pre 和 res，然后在进行递归中序遍历时，对于遍历到的节点，
我们首先看 pre 和p是否相同，如果相同，则 res 赋为当前节点，然后将 pre 赋为 root，那么在遍历下一个节点时，
pre 就起到记录上一个节点的作用
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!p)
		{
			return NULL;
		}
		TreeNode* pre = NULL;
		TreeNode* res = NULL;
		inorder(root, pre, res, p);
		return res;
	}
	void inorder(TreeNode* root, TreeNode* &pre, TreeNode* &res, TreeNode* p)
	{
		if (!root)
		{
			return;
		}
		inorder(root->left, pre, res, p);
		if (pre == p)
		{
			res = root;
		}
		pre = root;
		inorder(root->right, pre, res, p);
	}
};