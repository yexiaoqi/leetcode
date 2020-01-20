/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//方法一，o(n)空间复杂度，并且遍历了整个链表重复了一半
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> st;
		ListNode *cur = head;
		while (cur)
		{
			st.push(cur->val);
			cur = cur->next;
		}
		while (!st.empty())
		{
			if (head->val != st.top())
			{
				return false;
			}
			st.pop();
			head = head->next;
		}
		return true;
	}
};

//o(n)复杂度，不重复遍历
/**
*Definition for singly - linked list.
* struct ListNode {
	*int val;
	*ListNode *next;
	*ListNode(int x) : val(x), next(NULL) {}
	*
};
*/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
		{
			return true;
		}
		stack<int> st{ { head->val } };
		ListNode *slow = head, *fast = head;
		while (fast->next&&fast->next->next)
		{

			slow = slow->next;
			fast = fast->next->next;
			st.push(slow->val);
		}
		if (!fast->next)
		{
			st.pop();
		}
		while (slow->next)
		{
			slow = slow->next;
			if (slow->val != st.top())
			{
				return false;
			}
			st.pop();
		}
		return true;
	}
};


//o(1)空间复杂度解法
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool isPalindrome(ListNode* head)
	{
		if (!head || !head->next)
		{
			return true;
		}
		ListNode* slow = head, *fast = head;
		while (fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* last = slow->next, *pre = head;
		while (last->next)
		{
			ListNode* tmp = last->next;
			last->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}
		while (slow->next)
		{
			slow = slow->next;
			if (slow->val != pre->val)
			{
				return false;
			}
			pre = pre->next;
		}
		return true;
	}


};