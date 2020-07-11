/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
		{
			return NULL;
		}
		if (!head->next)
		{
			return new TreeNode(head->val);
		}
		ListNode *slow = head, *fast = head, *last = head;
		while (fast->next&&fast->next->next)
		{
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		last->next = NULL;
		TreeNode* res = new TreeNode(slow->val);
		if (head != slow)
		{
			res->left = sortedListToBST(head);
		}
		res->right = sortedListToBST(fast);
		return res;
	}
};