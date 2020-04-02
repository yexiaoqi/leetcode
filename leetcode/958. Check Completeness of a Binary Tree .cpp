//按照层序遍历的顺序
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		queue<TreeNode*> q;
		q.push(root);
		bool flag = true;
		while (!q.empty())
		{
			TreeNode* tmp = q.front();
			if (flag&&tmp->left)
			{
				q.push(tmp->left);
			}
			else if (flag && !tmp->left)
			{
				flag = false;
			}
			else if (!flag&&tmp->left)
			{
				cout << tmp->val;
				return false;
			}
			if (flag&&tmp->right)
			{
				q.push(tmp->right);
			}
			else if (flag && !tmp->right)
			{
				flag = false;
			}
			else if (!flag&&tmp->right)
			{
				cout << tmp->val;
				return false;
			}
			q.pop();
		}
		return true;
	}
};


//复习
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		//queue<TreeNode*> q{root};
		queue<TreeNode*> q{ { root } };//因为本质上queue里面有个list，所以这样初始化
		bool flag = true;
		while (!q.empty())
		{
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				if (!flag)
				{
					return false;
				}
				q.push(tmp->left);
			}
			else
			{
				flag = false;
			}
			if (tmp->right)
			{
				if (!flag)
				{
					return false;
				}
				q.push(tmp->right);
			}
			else
			{
				flag = false;
			}
		}
		return true;
	}
};