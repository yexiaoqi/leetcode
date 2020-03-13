//��ֱ�ӵķ������Ƿֱ�˳�������߽��㣬Ҷ��㣬���ұ߽��㡣��ô�����ģ�
//�������Ĳ����϶����õݹ����డ�����Կ���д�ֱ������ݹ麯�����ֱ�����߽��㣬
//Ҷ��㣬���ұ߽��㡣����Ҫ���������������������û�������ӽ��ʱ��
//��Ҳ��һ��Ҷ��㣬��ôһ��ʼ�ͽ�������� res �У���ô�ټ���Ҷ����ʱ���ֻ��ټ���һ�Σ�
//�������ԡ������ж���������������һ���ӽ�㣬����ǰ��������� res �С�Ȼ������������߽���ĺ�����
//�����ǰ��㲻���ڣ�����û���ӽ�㣬ֱ�ӷ��ء�����Ͱѵ�ǰ���ֵ������ res �У�Ȼ��������ӽ����ڣ�
//�Ͷ�����õݹ麯������֮������ӽ�㲻���ڣ���ô�����ӽ����õݹ麯�������������ұ߽���ĺ����ͷ������ˣ�
//������ӽ����ڣ��Ͷ�����õݹ麯������֮������ӽ�㲻���ڣ��Ͷ����ӽ����õݹ麯����
//ע���ڵ��õݹ麯��֮��Ž����ֵ������ res����Ϊ����Ҫ����ʱ���˳�����������������Ҷ���ĺ�����
//ûʲô��˵�ģ����ǿ�û���ӽ������˾ͼ����� res��Ȼ��������ӽ��ֱ���õݹ鼴�ɣ�
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

	void LeftBoundary(TreeNode* root, vector<int> &res)
	{
		if (!root || (!root->left && !root->right))
		{
			return;
		}
		res.push_back(root->val);
		if (root->left)
		{
			LeftBoundary(root->left, res);
		}
		else
		{
			LeftBoundary(root->right, res);
		}
	}
	void RightBoundary(TreeNode* root, vector<int> &res)
	{
		if (!root || (!root->left && !root->right))
		{
			return;
		}
		if (root->right)
		{
			RightBoundary(root->right, res);
		}
		else
		{
			RightBoundary(root->left, res);
		}
		res.push_back(root->val);
	}
	void Leaf(TreeNode* root, vector<int> &res)
	{
		if (!root)
		{
			return;
		}
		if (!root->left && !root->right)
		{
			res.push_back(root->val);
		}
		Leaf(root->left, res);
		Leaf(root->right, res);
	}
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> res;
		if (!root)
		{
			return res;
		}
		if (root->left || root->right)
		{
			res.push_back(root->val);
		}
		LeftBoundary(root->left, res);
		Leaf(root, res);
		RightBoundary(root->right, res);
		return res;
	}
};