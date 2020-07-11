//根节点应该是有序数组的中间点，从中间点分开为左右两个有序数组，在分别找出其中间点作为原中间点的左右两个子节点，
//这不就是是二分查找法的核心思想么。
//自己做出
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
		int begin = 0, end = nums.size() - 1;
		TreeNode* res = build(nums, begin, end);
		return res;
	}
	TreeNode* build(vector<int>& nums, int begin, int end)
	{
		if (begin>end)
		{
			return NULL;
		}
		int mid = (begin + end) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = build(nums, begin, mid - 1);
		root->right = build(nums, mid + 1, end);
		return root;
	}
};

//复习
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return NULL;
		}
		int begin = 0, end = nums.size() - 1;
		return BuildTree(nums, begin, end);
	}
	TreeNode* BuildTree(vector<int> &nums, int begin, int end)
	{
		if (begin>end)
		{
			return NULL;
		}
		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = BuildTree(nums, begin, mid - 1);
		root->right = BuildTree(nums, mid + 1, end);
		return root;
	}
};

//复习
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
		int begin = 0, end = nums.size() - 1;
		return BuildTree(nums, begin, end);
	}
	TreeNode* BuildTree(vector<int> &nums, int begin, int end)
	{
		if (begin>end)
		{
			return NULL;
		}
		int mid = (begin + end) / 2;
		TreeNode *res = new TreeNode(nums[mid]);
		res->left = BuildTree(nums, begin, mid - 1);
		res->right = BuildTree(nums, mid + 1, end);
		return res;
	}
};