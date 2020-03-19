//1.Êý×Ö
void testall()
{
	test(INT_MAX);
	test(-1);
	test(8);
	test(4);
	test(0);
}
void test(int x)
{
	cout << mySqrt(x) << endl;
}

//2.Á´±í
struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {}
};
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

//3.×Ö·û´®
void testall()
{
	test("");
	test("abcabcbb");
	test("bbbbb");
	test("pwwkew");
}
void test(string s)
{
	cout << lengthOfLongestSubstring(s) << endl;
}