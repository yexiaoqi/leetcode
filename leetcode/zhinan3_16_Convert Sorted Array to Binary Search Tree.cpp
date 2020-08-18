//ͬleetcode108
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return NULL;
		}
		return ArraytoBST(nums, 0, nums.size() - 1);
	}
	TreeNode* ArraytoBST(vector<int> &nums, int begin, int end)
	{
		if (begin>end)
		{
			return NULL;
		}
		int mid = (begin + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = ArraytoBST(nums, begin, mid - 1);
		root->right = ArraytoBST(nums, mid + 1, end);
		return root;
	}
};