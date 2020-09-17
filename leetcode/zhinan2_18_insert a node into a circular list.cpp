# include <bits/stdc++.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
};


list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node * new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
			if (i == n) {
				new_pnode->next = phead;
			}
		}
	}
	return phead;
}


list_node * insert_num(list_node * head, int num)
{
	//////在下面完成代码
	list_node *pre = head;
	if (!head)
	{
		list_node *tmp = new list_node();
		tmp->val = num;
		cout << tmp->val;
		return tmp;
	}
	list_node *cur = head->next;
	while (cur != head)
	{
		if (num >= pre->val&&num<cur->val)
		{
			list_node *tmp = new list_node();
			tmp->val = num;
			pre->next = tmp;
			tmp->next = cur;
			list_node *tmp2 = head;
			return head;
		}
		pre = pre->next;
		cur = pre->next;
	}
	if (num>pre->val)
	{
		list_node *tmp = new list_node();
		tmp->val = num;
		pre->next = tmp;
		tmp->next = cur;
		list_node *tmp2 = head;
		return head;
	}
	else
	{
		list_node *tmp = new list_node();
		tmp->val = num;
		pre->next = tmp;
		tmp->next = cur;
		list_node *tmp2 = tmp;
		return tmp;
	}
}


void print_list(list_node * head)
{
	list_node * h = head;
	while (1) {
		printf("%d ", head->val);
		if (head->next == h) break;
		head = head->next;
	}
	puts("");
}


int main()
{
	list_node * head = input_list();
	int n;
	scanf("%d", &n);
	list_node * new_head = insert_num(head, n);
	print_list(new_head);
	return 0;
}