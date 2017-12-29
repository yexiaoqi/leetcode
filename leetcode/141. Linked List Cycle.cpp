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