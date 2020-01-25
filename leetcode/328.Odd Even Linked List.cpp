//�Լ������ķ���
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next || !head->next->next)//����Ҳ����������Ϊ�������(ocur&&ecur->next)||(ecur&&ocur->next)����break
		{
			return head;
		}
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* ocur = odd, *ecur = even;
		while ((ocur&&ecur->next) || (ecur&&ocur->next))
		{
			if (ocur&&ecur->next)
			{
				ocur->next = ecur->next;
				ocur = ocur->next;
			}
			if (ecur&&ocur->next)
			{
				ecur->next = ocur->next;
				ecur = ecur->next;
			}
			if (ecur->next == ocur&&ocur->next == NULL)
			{
				break;
			}
			if (ocur->next == ecur&&ecur->next == NULL)
			{
				break;
			}
		}
		ocur->next = even;
		ecur->next = NULL;
		return odd;
	}
};


//���汾
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* ocur = odd, *ecur = even;
		while (ecur&&ecur->next)
		{
			ocur->next = ecur->next;
			ocur = ocur->next;
			ecur->next = ocur->next;
			ecur = ecur->next;
		}
		ocur->next = even;
		return odd;
	}
};