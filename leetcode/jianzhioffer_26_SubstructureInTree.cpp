//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


//自己写的，不对，因为有重复的数，比如A为一棵树1有左子树1，B为1，我只判断了A的根节点和B比，这两个结构不一样就返回false了，实际上可以有A的第二个1和B比
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		TreeNode* root1 = new TreeNode(-1);
		DFS(pRoot1, pRoot2->val, root1);
		if (!root1)
		{
			return false;
		}
		else
		{
			bool res = judge(root1, pRoot2);
			return res;
		}
	}
	bool judge(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 && !pRoot2)
		{
			return true;
		}
		if ((pRoot1 && !pRoot2) || (pRoot2 && !pRoot1) || pRoot1->val != pRoot2->val)
		{
			return false;
		}
		if (pRoot1->val == pRoot2->val)
		{
			judge(pRoot1->left, pRoot2->left);
			judge(pRoot1->right, pRoot2->right);
		}

	}
	TreeNode* DFS(TreeNode* root, int target, TreeNode* &res)
	{
		if (!root)
		{
			return NULL;
		}
		if (root->val == target)
		{
			res = root;
			return root;
		}
		DFS(root->left, target, res);
		DFS(root->right, target, res);
		return res;
	}
};