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
		//������while(walker->next&&runner->next->next)���Կ��runnerΪ׼��
		//���д��walker->next��runner->next�����Ѿ������ڣ���ʱ����runner->next->next�Ͳ�����
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
			if (fast&&fast == slow)//ע�����ж��ǲ���NULL���������NULL��Ⱦ�û��������
			{
				return true;
			}
		}
		return false;
	}
};


//��ϰ2
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