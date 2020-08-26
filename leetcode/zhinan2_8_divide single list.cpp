//原题
#include <bits/stdc++.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d%d", &n, &pivot);
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


list_node * list_partition(list_node * head, int pivot)
{
	//////在下面完成代码
	vector<int> nums;
	while (head)
	{
		nums.push_back(head->val);
		head = head->next;
	}
	int begin = 0, end = nums.size() - 1;
	int i = 0;
	while (i <= end)
	{
		if (nums[i]<pivot)
		{
			swap(nums[i++], nums[begin++]);
		}
		else if (nums[i]>pivot)
		{
			swap(nums[i], nums[end--]);
		}
		else
		{
			++i;
		}
	}
	list_node *cur = new list_node();
	cur->val = nums[0];
	list_node *res = cur;
	for (int i = 1; i<nums.size(); ++i)
	{
		cur->next = new list_node();
		cur = cur->next;
		cur->val = nums[i];
	}
	list_node *res2 = res;
	while (res2)
	{
		cout << res2->val << " ";
		res2 = res2->next;
	}
	return res;
}


int main()
{
	list_node * head = input_list();
	list_partition(head, pivot);
	return 0;
}


//进阶题
//O(1)空间复杂度方法
# include <bits/stdc++.h>
using namespace std;

struct list_node {
	int val;
	struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d%d", &n, &pivot);
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


list_node * list_partition(list_node * head, int pivot)
{
	//////在下面完成代码
	list_node *sh = NULL;
	list_node *st = NULL;
	list_node *eh = NULL;
	list_node *et = NULL;
	list_node *bh = NULL;
	list_node *bt = NULL;
	while (head)
	{
		list_node *next = head->next;
		head->next = NULL;
		if (head->val<pivot)
		{
			if (sh == NULL)
			{
				sh = head;
				st = head;
			}
			else
			{
				st->next = head;
				st = head;
				//cout<<head->val<<endl;
			}
		}
		else if (head->val == pivot)
		{
			if (eh == NULL)
			{
				eh = head;
				et = head;
			}
			else
			{
				et->next = head;
				et = head;
			}
		}
		else
		{
			if (bh == NULL)
			{
				bh = head;
				bt = head;
			}
			else
			{
				bt->next = head;
				bt = head;
			}
		}
		head = next;
	}

	if (st)
	{
		st->next = eh;
		et = (!et ? st : et);
	}
	if (bt)
	{
		et->next = bh;
	}
	list_node *tmp = sh;
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	return sh;
}


int main()
{
	list_node * head = input_list();
	list_partition(head, pivot);
	return 0;
}