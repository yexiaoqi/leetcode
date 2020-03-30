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
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head = NULL;
		while (head)
		{
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};
//�ݹ�汾
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
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* newhead = reverseList(head->next);//����1->2->3,�ȵ���newhead=3return��Ȼ�� head->next->nextҲ����3->nextָ��2�� head->nextָ��NULL��Ȼ��newhead��ʼ����ͷ��㣩����3��head���1��head->next->nextҲ����2->nextָ��1,1->nextָ��գ�һ��һ����ת
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
};


//��ϰ
//�Լ�������һ��ac�������汾��
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
	ListNode* reverseList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		while (cur&&cur->next)
		{
			ListNode *t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};

//��ϰ2
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* newhead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
};