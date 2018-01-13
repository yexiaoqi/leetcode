//Given a singly linked list L : L0��L1������Ln - 1��Ln,
//reorder it to : L0��Ln��L1��Ln - 1��L2��Ln - 2����
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1,2,3,4 }, reorder it to{ 1,4,2,3 }.
//
//






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
	void reorderList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)//����������������������жϣ���ʡʱ��
		{
			return;
		}
		ListNode *p1, *p2;
		p1 = head;
		p2 = head;
		while (p2->next&&p2->next->next)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
		ListNode *preMiddle = p1;
		ListNode *preCurrent = p1->next;
		while (preCurrent->next)
		{
			ListNode *current = preCurrent->next;
			preCurrent->next = current->next;
			current->next = preMiddle->next;
			preMiddle->next = current;
		}
		p1 = head;
		p2 = preMiddle->next;
		while (p1 != preMiddle)
		{
			preMiddle->next = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
			p2 = preMiddle->next;
		}
	}
};