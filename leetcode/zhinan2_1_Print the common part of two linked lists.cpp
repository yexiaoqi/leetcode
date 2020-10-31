# include <bits/stdc++.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
}; //�����Ľڵ�

list_node * input_list(void) //��������
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
		}
	}
	return phead;
}

void sol(list_node * a_head, list_node * b_head)
{
	//////��������ɴ���
	while (a_head&&b_head)
	{
		if (a_head->val<b_head->val)
		{
			a_head = a_head->next;
		}
		else if (a_head->val>b_head->val)
		{
			b_head = b_head->next;
		}
		else
		{
			cout << a_head->val << " ";
			a_head = a_head->next;
			b_head = b_head->next;
		}
	}


}

int main()
{
	list_node * a_head = input_list(); // A ������ͷ�ڵ�
	list_node * b_head = input_list(); // B ������ͷ�ڵ�
	sol(a_head, b_head);
	return 0;
}