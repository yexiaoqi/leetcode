//同剑指offer37
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
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		if (!root)
		{
			res += "null";
			return res;
		}
		res += to_string(root->val);
		res += '#';
		res += serialize(root->left);
		res += serialize(root->right);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int i = 0;
		return deserialize(data, i);
	}
	TreeNode* deserialize(string data, int &i)//注意必须是&i，否则进入root->right = deserialize(data, i);又变回了root->left = deserialize(data, i);前的i
	{
		TreeNode *root = new TreeNode(-1);
		int tmp = 0, flag = 1;
		if (i<data.size())
		{
			while (data[i] != '#')
			{
				if (data[i] == 'n')
				{
					i += 4;
					root = NULL;
					return root;
				}
				if (data[i] == '-')//注意有负号的情况
				{
					flag = -1;
					++i;
				}
				else
				{
					tmp = tmp * 10 + (data[i] - '0');
					++i;
				}
			}
			++i;
			root->val = flag*tmp;
			root->left = deserialize(data, i);
			root->right = deserialize(data, i);
		}
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));