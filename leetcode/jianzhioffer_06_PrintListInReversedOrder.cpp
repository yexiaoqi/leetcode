//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> s;
		vector<int> res;
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;

	}
};