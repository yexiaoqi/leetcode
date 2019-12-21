//����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
bool compare(vector<int> a, vector<int> b)
{
	return a.size()>b.size();
}
class Solution {
public:

	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		if (!root)
		{
			return res;
		}
		vector<int> path;
		Find(0, root, expectNumber, res, path);
		sort(res.begin(), res.end(), compare);
		return res;
	}
	void Find(int sum, TreeNode* root, int expectNumber, vector<vector<int>> &res, vector<int> &path)
	{
		if (!root)
		{
			return;
		}
		sum += root->val;
		path.push_back(root->val);
		if (!root->left && !root->right)
		{
			if (sum == expectNumber)
			{
				res.push_back(path);
			}
		}
		Find(sum, root->left, expectNumber, res, path);
		Find(sum, root->right, expectNumber, res, path);
		sum -= root->val;
		path.pop_back();
	}
};