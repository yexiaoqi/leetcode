//Í¬½£Ö¸offer8
/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
		{
			return NULL;
		}
		TreeLinkNode* rightnode = pNode->right;
		if (rightnode)
		{
			while (rightnode->left)
			{
				rightnode = rightnode->left;
			}
			return rightnode;
		}
		else
		{
			while (pNode->next)
			{
				if (pNode == pNode->next->left)
				{
					return pNode->next;
				}
				pNode = pNode->next;
			}
		}
		return NULL;
	}
};