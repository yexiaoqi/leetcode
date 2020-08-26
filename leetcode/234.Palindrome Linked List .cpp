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
//那就是说我们不能使用 stack 了，那么如何代替 stack 的作用呢，用 stack 的目的是为了利用其后进先出的特点
//，好倒着取出前半段的元素。那么现在不用 stack 了，如何倒着取元素呢。我们可以在找到中点后，将
//后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了
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



//复习
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
	bool isPalindrome(ListNode* head) {
		if (!head)
		{
			return true;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		stack<int> s;
		s.push(slow->val);
		while (fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			s.push(slow->val);
		}
		if (!fast->next)
		{
			s.pop();
		}
		slow = slow->next;
		while (!s.empty())
		{
			if (s.top() != slow->val)
			{
				return false;
			}
			s.pop();
			slow = slow->next;
		}
		return true;
	}
};

//复习
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
		{
			return true;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *cur = slow->next;
		while (cur&&cur->next)
		{
			ListNode* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}
		slow = slow->next;
		while (slow)
		{
			if (slow->val != head->val)
			{
				return false;
			}
			slow = slow->next;
			head = head->next;
		}
		return true;
	}
};