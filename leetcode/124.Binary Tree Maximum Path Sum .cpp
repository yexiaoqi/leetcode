//在递归函数中，如果当前结点不存在，直接返回0。否则就分别对其左右子节点调用递归函数，
//由于路径和有可能为负数，这里当然不希望加上负的路径和，所以和0相比，取较大的那个，
//就是要么不加，加就要加正数。然后来更新全局最大值结果 res，
//就是以左子结点为终点的最大 path 之和加上以右子结点为终点的最大 path 之和，
//还要加上当前结点值，这样就组成了一个条完整的路径。
//而返回值是取 left 和 right 中的较大值加上当前结点值，因为返回值的定义是以当前结点为终点的 path 之和，
//所以只能取 left 和 right 中较大的那个值，而不是两个都要
public:
	int maxPathSum(TreeNode* root) {
		int maxres = 0;
		if (!root)
		{
			return maxres;
		}
		maxPath(root, maxres);
		return maxres;
	}
	int maxPath(TreeNode *root, int &res)
	{
		if (!root)
		{
			return;
		}
		int left = max(maxPath(root->left, res), 0);
		int right = max(maxPath(root->right, res), 0);
		res = max(res, left + right + root->val);
		return max(left, right) + root->val;
	}
};