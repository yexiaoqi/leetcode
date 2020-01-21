//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?

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
	bool hasCycle(ListNode *head)
	{
		if (!head)
		{
			return false;
		}
		ListNode *runner = head;
		ListNode *walker = head;
		while (runner&&runner->next)
		//不能是while(walker->next&&runner->next->next)，以快的runner为准，
		//如果写成walker->next，runner->next可能已经不存在，这时候用runner->next->next就不对了
		{
			runner = runner->next->next;
			walker = walker->next;
			if (runner == walker)
			{
				return true;
			}
		}
		return false;
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
	bool hasCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
			if (fast)
			{
				fast = fast->next;
			}
			if (fast&&fast == slow)//注意先判断是不是NULL，如果都是NULL相等就没有意义了
			{
				return true;
			}
		}
		return false;
	}
};


//复习2
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
	bool hasCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				return true;
			}
		}
		return false;
	}
};