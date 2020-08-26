//Í¬leetcode234
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

//¸´Ï°
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