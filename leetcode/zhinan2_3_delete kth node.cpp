//ɾ����k���ڵ�
# include <bits/stdc++.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
}; //����Ľڵ�

int K;

list_node * input_list(void) //��������
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d %d", &n, &K);
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

list_node * remove_kth_node(list_node * head, int K)
{
	//////��������ɴ���
	list_node *pre = head;
	for (int i = 0; i<K - 2; ++i)
	{
		pre = pre->next;
	}
	pre->next = pre->next->next;
	return head;


}

void print_list(list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
}

int main()
{
	list_node * head = input_list(); // �����ͷ�ڵ�
	list_node * rhead = remove_kth_node(head, K);
	print_list(rhead);
	return 0;
}