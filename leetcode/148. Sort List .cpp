//������������Ҫ����Ĳ��ܱȽ����� merge����ô����һ�������������β��ܲ�ֳ���������������أ�
//���ǴӼ����룬ʲôʱ����������һ����������ģ����ǵ����������ֻ��һ������ʱ��һ��������ġ�
//���鲢����ĺ�����ʵ�Ƿ��η� Divide and Conquer�����ǽ�������м�Ͽ����ֳ������֣�
//���������ٷֱ��������ĵݹ麯�� sortList()���õ����������������ٽ��� merge()��
//�����������������ˡ���Ϊ������ĵݹ麯���л��ǻ��ٴβ�����룬��������ֻ��һ�����ʱ��
//�޷���������ˣ���������������ǰ����˵�ġ�һ������ʱ��һ��������ġ��������Ϳ��Խ��� merge �ˡ�
//Ȼ���ٻ��ݻ�ȥ��ÿ�εõ��Ķ������������Ȼ����� merge��ֱ����ԭ�������ȡ����ｫ������м�Ͽ��ķ�����
//���õľ��ǿ���ָ�룬
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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* slow = head, *fast = head, *pre = head;
		while (fast&&fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;
		return merge(sortList(head), sortList(slow));
	}
	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		if (l1)
		{
			cur->next = l1;
		}
		if (l2)
		{
			cur->next = l2;
		}
		return dummy->next;
	}
};