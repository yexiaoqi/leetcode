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
	bool findTarget(TreeNode* root, int target) {
		vector<int> nums;
		MakeNum(root, nums);
		if (nums.size()<2)
		{
			return false;
		}
		int begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int sum = nums[begin] + nums[end];
			if (sum == target)
			{
				return true;
			}
			else if (sum<target)
			{
				++begin;
			}
			else
			{
				--end;
			}
		}
		return false;
	}
	void MakeNum(TreeNode* root, vector<int> &num)
	{
		if (!root)
		{
			return;
		}
		MakeNum(root->left, num);
		num.push_back(root->val);
		MakeNum(root->right, num);
	}
};