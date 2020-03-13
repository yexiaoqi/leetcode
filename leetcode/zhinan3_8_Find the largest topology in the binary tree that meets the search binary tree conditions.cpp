#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	int largestBSTSubtree(TreeNode* h) {
		if (!h)
		{
			return 0;
		}
		int maxres = count(h, h);
		maxres = max(largestBSTSubtree(h->left), maxres);
		maxres = max(largestBSTSubtree(h->right), maxres);
		return maxres;
	}
	//求以h作为头节点的最大拓扑结构
	int count(TreeNode *h, TreeNode *cur)
	{
		if (cur&&h&&isValid(h, cur))
		{
			return 1 + count(h, cur->left) + count(h, cur->right);
		}
		return 0;
	}
	//判断一个节点是否在以h为头结点的搜索二叉树上
	bool isValid(TreeNode *h, TreeNode *node)
	{
		if (!h)
		{
			return false;
		}
		if (h == node)
		{
			return true;
		}
		return isValid(h->val > node->val ? h->left : h->right, node);
	}
};
int main()
{
	int n, root;
	cin >> n >> root;
	vector<TreeNode> tree(n + 1, TreeNode(0));
	for (int i = 1; i <= n; ++i)
	{
		int index, left, right;
		cin >> index >> left >> right;
		tree[index].val = index;
		if (left)
		{
			tree[index].left = &tree[left];
		}
		if (right)
		{
			tree[index].right = &tree[right];
		}
	}
	Solution s;
	int res = s.largestBSTSubtree(&tree[root]);
	cout << res;
	return 0;
}





//O(n)实在看不懂
struct Node {
	int val;
	int left;
	int right;
};

struct Record {
	int l;
	int r;
	Record() {}
	Record(int l, int r) :l(l), r(r) {}
};


int modifyMap(vector<Node>& tree, int n, int v, unordered_map<int, Record>& m, bool s) {
	if (n == 0 || m.find(n) == m.end())
		return 0;
	Record r = m.at(n);
	//对于这个调用modifyMap(tree, tree[node].left, tree[node].val, map, true);//如果该节点的左子节点的值大于该节点的值
	if (s && tree[n].val > v || !s && tree[n].val < v)
	{
		m.erase(n);
		return r.l + r.r + 1;
	}
	else
	{
		int minus = modifyMap(tree, s ? tree[n].right : tree[n].left, v, m, s);
		if (s)
			r.r = r.r - minus;
		else
			r.l = r.l - minus;
		m[n] = r;
		return minus;
	}
}

int postOrder(vector<Node>& tree, int node, unordered_map<int, Record>& map) {
	if (node == 0)
		return 0;
	int ls = postOrder(tree, tree[node].left, map);
	int rs = postOrder(tree, tree[node].right, map);
	modifyMap(tree, tree[node].left, tree[node].val, map, true);
	modifyMap(tree, tree[node].right, tree[node].val, map, false);
	int lbst = 0, rbst = 0;
	if (map.find(tree[node].left) != map.end()) {
		Record lr = map.at(tree[node].left);
		lbst = lr.l + lr.r + 1;
	}
	if (map.find(tree[node].right) != map.end()) {
		Record rr = map.at(tree[node].right);
		rbst = rr.l + rr.r + 1;
	}
	map.insert(make_pair(node, Record(lbst, rbst)));
	return max(lbst + rbst + 1, max(ls, rs));
}

int main() {
	int n, root;
	cin >> n >> root;
	vector<Node> tree(n + 1);
	for (int i = 0; i < n; i++) {
		int idx;
		cin >> idx;
		tree[idx].val = idx;
		cin >> tree[idx].left >> tree[idx].right;
	}
	unordered_map<int, Record> map;
	cout << postOrder(tree, root, map) << endl;
	return 0;
}
