//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//注意这题和leetcode 572的区别，这题是子结构不是子树
//同指南3_11

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




class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;

		if (pRoot1&&pRoot2)
		{
			if (pRoot1->val == pRoot2->val)
			{
				res = issame(pRoot1, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!res)
			{
				res = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return res;
	}
	bool issame(TreeNode* s, TreeNode* t)
	{
		if (!t)
		{
			return true;
		}
		if (!s)
		{
			return false;
		}
		if (s->val != t->val)
		{
			return false;
		}
		return issame(s->left, t->left) && issame(s->right, t->right);
	}
};


//复习，自己的方法通过
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot2)
		{
			return false;
		}
		vector<TreeNode*> root;
		FindTreeRoot(pRoot1, pRoot2, root);
		bool judge = false;
		for (int i = 0; i<root.size(); ++i)
		{
			judge = SubTree(root[i], pRoot2);
			if (judge)
			{
				return true;
			}
		}
		return false;
	}
	void FindTreeRoot(TreeNode* &pRoot1, TreeNode* &pRoot2, vector<TreeNode*> &root)
	{
		if (!pRoot1)
		{
			return;
		}
		if (pRoot2->val == pRoot1->val)
		{
			root.push_back(pRoot1);
		}
		FindTreeRoot(pRoot1->left, pRoot2, root);
		FindTreeRoot(pRoot1->right, pRoot2, root);
	}
	bool SubTree(TreeNode* &pRoot1, TreeNode* &pRoot2)
	{
		if (!pRoot2)
		{
			return true;
		}
		if (!pRoot1)
		{
			return false;
		}
		if (pRoot2->val != pRoot1->val)
		{
			return false;
		}
		return SubTree(pRoot1->left, pRoot2->left) && SubTree(pRoot1->right, pRoot2->right);
	}
};

//复习简化
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool judge = false;
		if (pRoot1&&pRoot2)
		{
			judge = SubTree(pRoot1, pRoot2);
			if (!judge)
			{
				judge = HasSubtree(pRoot1->left, pRoot2);//不要忘记judge=
			}
			if (!judge)
			{
				judge = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return judge;
	}
	bool SubTree(TreeNode* &pRoot1, TreeNode* &pRoot2)
	{
		if (!pRoot2)
		{
			return true;
		}
		if (!pRoot1)
		{
			return false;
		}
		if (pRoot2->val != pRoot1->val)
		{
			return false;
		}
		return SubTree(pRoot1->left, pRoot2->left) && SubTree(pRoot1->right, pRoot2->right);
	}
};