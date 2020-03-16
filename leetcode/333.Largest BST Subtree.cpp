//�Ѷ������������ת��Ϊ���飬Ȼ����������е��뷨�����У�����[10,5,15,1,8,null,7]�������Ϊ5������
//ʵ�������Ķ������ڵ����Ϊ3



//O(n^2)���Ӷ�����
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (isValid(root, LONG_MIN, LONG_MAX))
		{
			return count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool isValid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
	int count(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return count(root->left) + count(root->right) + 1;
	}
};



//O(n)�ⷨ
//��ʱ��helper����������һ��һά���飬�������������֣��ֱ����Ե�ǰ���Ϊ������������Сֵ�����ֵ��
//�Լ����� BST �����Ľ���������ô�Ϳ����ڱ���֤ BST �Ĺ����б�ͳ�Ƹ����������пգ����գ�
//�򷵻�һ��Ĭ����Ԫ�飬�������ֵ����Сֵ����0��������������ʣ�����Ĳ���˵��һ��ֵ����Сֵô��
//û�������ٽ��͡�����ǰ��� node ���ڣ��ֱ���������ӽ����õݹ麯����
//��ô������������������Ϣ�����浽�� left �� right �����У����������ӽ�㲻����Ҳû��ϵ�����ڵ�һ����пգ�
//���ǻ�õ�һ��Ĭ�ϵ���Ԫ�顣���������Ǹ���������������Ϣ�����½�� res �ˣ����� BST �Ķ��壬
//��ǰ���ֵ�϶��Ǵ��������������ֵ��С������������Сֵ�ġ������������ֵ������ left[1] �У�
//����������Сֵ������ right[0] �У�������������������ˣ�˵�������������� BST��
//��ô���ص���Ԫ�����Сֵ���ǵ�ǰ���ֵ����������Сֵ�еĽ�С�ߣ����ֵ���ǵ�ǰ���ֵ�����������ֵ�еĽϴ�ֵ��
//���ص� BST �������������������Ľ���������1���������˵�ǰ��㡣
//�ã����ڽ�����Ϊ��ʱ���ص���Ԫ��Ϊ��˳�����������ֵ��������Сֵ��
//�����ǰ��Ҷ��㣬��Ҳ���� BST����ô�϶�ϣ���ܽ��� if �Ӿ䣬�Ӷ�ʹ����Ԫ��ĵ������ܼ�1��
//���� if �������ǵ�ǰ���ֵҪ�����������е����ֵ���������ӽ���ǿյģ�Ϊ�˱�֤������ͨ����
//���ǽ��յ������������ֵ����Ϊ������Сֵ������һ����ͨ����ͬ�����յ�����������Сֵ����Ϊ�������ֵ��
//����ǿս�����Ԫ������á��ã������� else �е����ݣ�����ƻ��� BST �Ĺ���
//�򷵻ص���Ԫ�����Сֵ����������Сֵ�����ֵ���������ֵ��BST ������������0��
//��Ϊ�������������п��ܻ��� BST�����������������е� BST �������еĽϴ�ֵ��
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(root->val,left[0]),max(root->val,right[1]),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};

//f��ϰ
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		if (Valid(root, LONG_MIN, LONG_MAX))
		{
			return Count(root);
		}
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
	}
	bool Valid(TreeNode* root, long mn, long mx)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= mn || root->val >= mx)
		{
			return false;
		}
		return Valid(root->left, mn, root->val) && Valid(root->right, root->val, mx);
	}
	int Count(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		return 1 + Count(root->left) + Count(root->right);
	}
};
//��ϰ
class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		vector<int> res = BST(root);
		return res[2];
	}
	vector<int> BST(TreeNode* root)
	{
		if (!root)
		{
			return{ INT_MAX,INT_MIN,0 };
		}
		vector<int> left = BST(root->left);
		vector<int> right = BST(root->right);
		if (root->val>left[1] && root->val<right[0])
		{
			return{ min(left[0],root->val),max(right[1],root->val),left[2] + right[2] + 1 };
		}
		else
		{
			return{ INT_MIN,INT_MAX,max(left[2],right[2]) };
		}
	}
};

//��ϰ
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<long> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i<coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		return dp[amount]<INT_MAX ? dp[amount] : -1;
	}
};