//自己做出的方法
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
		if (!head || !head->next || !head->next->next)//两个也算特例，因为如果进入(ocur&&ecur->next)||(ecur&&ocur->next)不会break
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


//简洁版本
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