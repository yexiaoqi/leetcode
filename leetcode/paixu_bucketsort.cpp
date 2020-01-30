void bucketsort(vector<int> &arr, int bucketSize)//bucketSize��Ͱ�Ĵ�С
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
	int bucketCount = (maxValue - minValue) / bucketSize + 1;//bucketCount��Ͱ��������ע��Ҫ��1������arr={1,2}��bucketsize=1����countҪΪ2
	vector<vector<int>> buckets(bucketCount, vector<int>());
	// ����ӳ�亯�������ݷ��䵽����Ͱ��
	for (int i = 0; i < arr.size(); i++)
	{
		int index = (arr[i] - minValue) / bucketSize;
		buckets[index].push_back(arr[i]);
	}
	int arrIndex = 0;
	for (int i = 0; i<buckets.size(); ++i)
	{
		if (buckets[i].size() <= 0)//����ǿ�Ͱ����
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













//�������ָо��кܶ಻��Ҫ��
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
		int index = arr[i] / BUCKET_NUM;//index�����index��Ͱ
		ListNode *head = buckets[index];
		buckets[index] = insert(head, arr[i]);//ʹ�ò��������һ��Ͱ�е�Ԫ�ؽ������򣬷��ز�����Ԫ�غ��Ͱͷ
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