//���������Ķ�����������任ΪԴ�������ľ���

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/

//�Լ�������һ��AC
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot)
		{
			return;
		}
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		/*if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}*/
	}

};

//��ϰ
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (!pRoot)
		{
			return;
		}
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};