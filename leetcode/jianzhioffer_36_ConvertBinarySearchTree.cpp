//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* last = NULL;
		ConvertNode(pRootOfTree, last);
		while (last&&last->left)//ע��Ҫ���ж�last��������һpRootOfTreeΪ��ֱ��last->left�����
		{
			last = last->left;
		}
		return last;
	}
	void ConvertNode(TreeNode* root, TreeNode* &last)
	{
		if (!root)
		{
			return;
		}
		ConvertNode(root->left, last);
		root->left = last;
		if (last)
		{
			last->right = root;
		}
		last = root;
		ConvertNode(root->right, last);
	}
};


//��ϰ
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
	TreeNode* Convert(TreeNode* root)
	{
		TreeNode* last = NULL;
		ConvertNode(root, last);
		while (last&&last->left)
		{
			last = last->left;
		}
		return last;
	}
	void ConvertNode(TreeNode* root, TreeNode* &last)//������&root������root->left�ȵ��޸���root
	{
		if (!root)
		{
			return;
		}
		ConvertNode(root->left, last);
		root->left = last;
		if (last)
		{
			last->right = root;
		}
		last = root;
		ConvertNode(root->right, last);
	}
};