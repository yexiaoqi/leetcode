void bucketsort(vector<int> &arr, int bucketSize)//bucketSize是桶的大小
{
	if (arr.size() == 0)
	{
		return;
	}
	int minValue = arr[0];
	int maxValue = arr[0];
	for (int i = 0; i<arr.size(); ++i)
	{
		if (arr[i] < minValue)
		{
			minValue = arr[i];
		}
		else if (arr[i]  > maxValue)
		{
			maxValue = arr[i];
		}
	}
	int bucketCount = (maxValue - minValue) / bucketSize + 1;//bucketCount是桶的数量，注意要加1，比如arr={1,2}，bucketsize=1，则count要为2
	vector<vector<int>> buckets(bucketCount, vector<int>());
	// 利用映射函数将数据分配到各个桶中
	for (int i = 0; i < arr.size(); i++)
	{
		int index = (arr[i] - minValue) / bucketSize;
		buckets[index].push_back(arr[i]);
	}
	int arrIndex = 0;
	for (int i = 0; i<buckets.size(); ++i)
	{
		if (buckets[i].size() <= 0)//如果是空桶跳过
		{
			continue;
		}
		sort(buckets[i].begin(), buckets[i].end());
		for (int j = 0; j < buckets[i].size(); ++j)
		{
			arr[arrIndex++] = buckets[i][j];
		}
	}
	return;
}













//下面这种感觉有很多不必要的
const int BUCKET_NUM = 10;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = 0) :val(x), next(NULL) {}
};

ListNode* insert(ListNode* head, int insertval)
{
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *insertnode = new ListNode(insertval);
	ListNode *pre = dummy, *cur = head;
	while (cur && cur->val <= insertval)
	{
		pre = cur;
		cur = cur->next;
	}
	insertnode->next = cur;
	pre->next = insertnode;
	return dummy->next;
}

ListNode* Merge(ListNode *head1, ListNode *head2)
{
	ListNode *dummy = new ListNode(-1);
	ListNode *cur = dummy;
	while (head1 &&head2)
	{
		if (head1->val <= head2->val)
		{
			cur->next = head1;
			head1 = head1->next;
		}
		else
		{
			cur->next = head2;
			head2 = head2->next;
		}
		cur = cur->next;
	}
	if (head1)
	{
		cur->next = head1;
	}
	if (head2)
	{
		cur->next = head2;
	}
	return dummy->next;
}

void BucketSort(int n, vector<int> &arr)
{
	vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
	for (int i = 0; i<n; ++i)
	{
		int index = arr[i] / BUCKET_NUM;//index代表第index个桶
		ListNode *head = buckets[index];
		buckets[index] = insert(head, arr[i]);//使用插入排序对一个桶中的元素进行排序，返回插入新元素后的桶头
	}
	ListNode *head = buckets[0];
	for (int i = 1; i<BUCKET_NUM; ++i)
	{
		head = Merge(head, buckets[i]);
	}
	for (int i = 0; i<n; ++i)
	{
		arr[i] = head->val;
		head = head->next;
	}
}