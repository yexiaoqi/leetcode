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
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
			{
				pNode = pNode->left;
			}
			return pNode;
		}
		while (pNode->next)
		{
			if (pNode->next->left == pNode)
			{
				return pNode->next;
			}
			pNode = pNode->next;
		}
		return NULL;
	}
};


//复习，自己的方法
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
		{
			return NULL;
		}
		if (pNode->next&&pNode->next->left == pNode)
		{
			if (!pNode->right)
			{
				return pNode->next;
			}
			else
			{
				TreeLinkNode *cur = pNode->right;
				while (cur&&cur->left)
				{
					cur = cur->left;
				}
				return cur;
			}
		}
		else if (pNode->next&&pNode->next->right == pNode)
		{
			if (pNode->right)
			{
				TreeLinkNode *cur = pNode->right;
				while (cur&&cur->left)
				{
					cur = cur->left;
				}
				return cur;
			}
			else
			{
				TreeLinkNode *cur = pNode;
				while (cur&&cur->next)
				{
					if (cur->next->left == cur)
					{
						return cur->next;
					}
					cur = cur->next;
				}
			}
		}
		else if (!pNode->next)
		{
			TreeLinkNode *cur = pNode->right;
			while (cur&&cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}
		return NULL;
	}
};


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
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode&&pNode->left)
			{
				pNode = pNode->left;
			}
			return pNode;
		}
		while (pNode->next)
		{
			if (pNode->next->left == pNode)
			{
				return pNode->next;
			}
			pNode = pNode->next;
		}
		return NULL;
	}
};