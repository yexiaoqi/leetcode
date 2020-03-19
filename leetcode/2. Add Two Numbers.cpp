//You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.


//加测试用例
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		int sum = 0, carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			sum = val1 + val2 + carry;
			cur->next = new ListNode(sum % 10);//不能写成ListNode *cur=dummy->next;cur=new ListNode(sum%10),因为这样cur又变成一个新建的节点，和前面没啥关系了;
			carry = sum / 10;
			cur = cur->next;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry)
		{
			cur->next = new ListNode(carry);
			cur = cur->next;
		}
		return dummy->next;
	}
	void testall()
	{
		ListNode a1(2);
		ListNode a2(4);
		ListNode a3(3);
		ListNode b1(5);
		ListNode b2(6);
		ListNode b3(4);
		a1.next = &a2;
		a2.next = &a3;
		b1.next = &b2;
		b2.next = &b3;
		test(&a1, &b1);
		test(NULL, NULL);
	}
	void test(ListNode* l1, ListNode* l2)
	{
		ListNode* head = addTwoNumbers(l1, l2);
		while (head)
		{
			cout << head->val << " ";
			head = head->next;
		}
	}
};







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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode StackAnchor(0);
		ListNode *tail = &StackAnchor;
		div_t sum = { 0,0 };
		while (sum.quot>0 || l1 || l2)
		{
			if (l1)
			{
				sum.quot += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum.quot += l2->val;
				l2 = l2->next;
			}
			sum = div(sum.quot, 10);
			tail->next = new ListNode(sum.rem);
			tail = tail->next;
		}
		return StackAnchor.next;
	}
};

https://www.cnblogs.com/grandyang/p/4129891.html
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1), *current = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry;
			carry = sum / 10;
			current->next = new ListNode(sum % 10);
			current = current->next;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry)
		{
			current->next = new ListNode(1);
		}
		return dummy->next;
	}
};

//复习1
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* res = dummy;
		int flag = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;//这样就可以不像下面这样写三次
			int sum = val1 + val2 + flag;
			flag = sum / 10;
			res->next = new ListNode(sum % 10);//进一步简化下面两句，然后返回dummy->next
											   //res->val=sum%10;
											   //res->next=new ListNode(-1);//简化下面两句变成一句
											   // ListNode* tmp=new ListNode(-1);
											   // res->next=tmp;
			res = res->next;
			//注意要先判断有没有再next！！！！！！！！！！！
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
			// l1=l1->next;
			// l2=l2->next;//注意l1,l2向后移动！！！！！！！！！！！
		}
		if (flag)//注意如果最后还有进位
		{
			res->next = new ListNode(1);
		}
		// while(l1&&l2)
		// {
		//     int sum=l1->val+l2->val+flag;
		//     flag=sum/10;
		//     res->val=sum%10;
		//     ListNode* tmp=new ListNode(-1);
		//     res->next=tmp;
		//     res=res->next;
		// }
		// while(l1)
		// {
		//     int sum=l1->val+flag;
		//     flag=sum/10;
		//     res->val=sum%10;
		//     ListNode* tmp=new ListNode(-1);
		//     res->next=tmp;
		//     res=res->next;
		// }
		// while(l2)
		// {
		//     int sum=l2->val+flag;
		//     flag=sum/10;
		//     res->val=sum%10;
		//     ListNode* tmp=new ListNode(-1);
		//     res->next=tmp;
		//     res=res->next;
		// }
		return dummy->next;
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		int carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			int sum = val1 + val2 + carry;
			ListNode* t = new ListNode(sum % 10);
			carry = sum / 10;
			cur->next = t;
			cur = cur->next;
			//注意要先判断有没有再next！！！！！！！！！！！
			if (l1)//注意l1,l2向后移动！！！！！！！！！！！
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry)
		{
			ListNode* t = new ListNode(carry);
			cur->next = t;
		}
		return dummy->next;
	}
};


//复习3
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		int sum = 0, carry = 0;
		while (l1 || l2)
		{
			int val1 = l1 ? l1->val : 0;
			int val2 = l2 ? l2->val : 0;
			sum = val1 + val2 + carry;
			cur->next = new ListNode(sum % 10);//不能写成ListNode *cur=dummy->next;cur=new ListNode(sum%10),因为这样cur又变成一个新建的节点，和前面没啥关系了;
			carry = sum / 10;
			cur = cur->next;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry)
		{
			cur->next = new ListNode(carry);
			cur = cur->next;
		}
		return dummy->next;
	}
};