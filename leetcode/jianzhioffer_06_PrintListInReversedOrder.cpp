//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
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

//复习，自己的方法（反转链表）
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = head;
		while (cur&&cur->next)
		{
			ListNode* t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		vector<int> res;
		ListNode* forres = dummy->next;
		while (forres)
		{
			res.push_back(forres->val);
			forres = forres->next;
		}
		return res;
	}
};