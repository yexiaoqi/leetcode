//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Note: Do not modify the linked list.
//
//	Follow up :
//Can you solve it without using extra space ?
//
 //leetcodeˢ����3
//ʹ�ÿ���ָ�뷨
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		if (!head)
		{
			return NULL;
		}
		ListNode *runner = head;
		ListNode *walker = head;
		while (runner&&runner->next)
		{
			walker = walker->next;
			runner = runner->next->next;
			if (runner == walker)
			{
				break;
			}
		}
		if (!runner || !runner->next)
		{
			return NULL;
		}
		walker = head;
		while (runner != walker)
		{
			runner = runner->next;
			walker = walker->next;
		}
		return walker;
	}
};



//ʹ�ÿ���ָ�뷨������д������һ��
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
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* meet = NULL;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (!fast)
			{
				return NULL;
			}
			fast = fast->next;
			if (fast == slow)
			{
				meet = fast;
				break;
			}
		}
		if (meet == NULL)
		{
			return NULL;
		}
		while (1)
		{
			if (head == meet)
			{
				return head;
			}
			head = head->next;
			meet = meet->next;
		}
	}
};


//ʹ�ü���set����
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
	ListNode *detectCycle(ListNode *head) {
		set<ListNode *> node_set;
		while (head)
		{
			if (node_set.find(head) != node_set.end())
			{
				return head;
			}
			node_set.insert(head);
			head = head->next;
		}
		return NULL;
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
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		ListNode* meet = NULL;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				meet = slow;
				break;//����
			}
		}
		if (meet == NULL)
		{
			return NULL;
		}
		while (head)
		{
			if (head == meet)
			{
				return head;
			}
			head = head->next;
			meet = meet->next;
		}
		return NULL;
	}
};

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
	ListNode *detectCycle(ListNode *head) {
		unordered_set<ListNode*> us;
		while (head)
		{
			if (us.find(head) != us.end())
			{
				return head;
			}
			us.insert(head);
			head = head->next;
		}
		return NULL;
	}
};