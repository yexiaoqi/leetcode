//��һ�����飬ÿ�����ִ���һ����ĸ��a��Ӧ0��b��Ӧ1����������z��Ӧ25�������ղ��������˳����һ�ö�������
//���ӽڵ�����������null��ʾ��Ѱ�����������С·������ӡ��·������ĸֵ

//�����齨����������֪�����ڵ��Ҷ�ӽڵ���±��ϵ��2*i+1��2*i+2,��ô���ǿ��Եݹ�ؽ���һ������
//Ȼ����������������������������ǵ�·����·���ĺ����һ��pair��Ȼ�������pair���ҵ�sum��С��
//pair��Ӧ��·��
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
	string MinPath(vector<int> nums)
	{
		TreeNode* root = BuildTree(nums, 0);
		if (!root)
		{
			return "";
		}
		string path;
		vector<pair<string, int>> res;
		FindMinPath(root, path, res, 0);
		int minsum = INT_MAX;
		string strres = "";
		for (int i = 0; i < res.size(); ++i)
		{
			if (minsum > res[i].second)
			{
				minsum = res[i].second;
				strres = res[i].first;
			}
		}
		return strres;
	}
	void FindMinPath(TreeNode* root, string& path, vector<pair<string, int>> &res, int sum)
	{
		if (!root)
		{
			return;
		}
		path += root->val + 'a';
		sum += root->val;
		if (!root->left && !root->right)
		{
			res.push_back(make_pair(path, sum));
		}
		FindMinPath(root->left, path, res, sum);
		FindMinPath(root->right, path, res, sum);
		path.pop_back();
		sum -= root->val;
	}
	TreeNode* BuildTree(vector<int> &nums, int i)
	{
		if (nums.empty() || nums[i] == -1 || i >= nums.size())
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(nums[i]);
		root->left = BuildTree(nums, 2 * i + 1);
		root->right = BuildTree(nums, 2 * i + 2);
		return root;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 9, 8, 6, -1,4,2,-1,-1,-1,3,2 };
	cout << s.MinPath(nums);
	return 0;
}