//ͬleetcode113
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


//��ϰ���Լ���������ϸ
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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<int> path;
		vector<vector<int>> res;
		int sum = 0;
		Find(root, expectNumber, path, res, sum);
		return res;
	}
	void Find(TreeNode* root, int target, vector<int> &path, vector<vector<int>> &res,
		int sum)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root->val);
		sum += root->val;
		if (!root->left && !root->right)
		{
			if (sum == target)
			{
				res.push_back(path);
			}
		}
		Find(root->left, target, path, res, sum);
		Find(root->right, target, path, res, sum);
		path.pop_back();
		sum -= root->val;
	}
};