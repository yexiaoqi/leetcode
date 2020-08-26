/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//����һ��o(n)�ռ临�Ӷȣ����ұ��������������ظ���һ��
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

//o(n)���Ӷȣ����ظ�����
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


//o(1)�ռ临�ӶȽⷨ
//�Ǿ���˵���ǲ���ʹ�� stack �ˣ���ô��δ��� stack �������أ��� stack ��Ŀ����Ϊ�����������ȳ����ص�
//���õ���ȡ��ǰ��ε�Ԫ�ء���ô���ڲ��� stack �ˣ���ε���ȡԪ���ء����ǿ������ҵ��е�󣬽�
//���ε�����תһ�£��������ǾͿ��԰��ջ��ĵ�˳��Ƚ���
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



//��ϰ
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

//��ϰ
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