//自己做出
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		TreeNode* res = 0;
		int cnt = 0;
		order(pRoot, k, res, cnt);
		return res;
	}
	void order(TreeNode* &pRoot, int k, TreeNode* &res, int &cnt)
	{
		if (!pRoot)
		{
			return;
		}
		order(pRoot->left, k, res, cnt);
		++cnt;
		if (cnt == k)
		{
			res = pRoot;
			return;
		}
		order(pRoot->right, k, res, cnt);
	}

};