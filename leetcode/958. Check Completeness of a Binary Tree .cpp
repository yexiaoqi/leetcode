//°´ÕÕ²ãĞò±éÀúµÄË³Ğò
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