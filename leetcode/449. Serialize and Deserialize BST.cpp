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
		string data;
		BST_preorder(root, data);
		return data;
	}
	void BST_preorder(TreeNode* root, string &data)
	{
		if (!root)
		{
			return;
		}
		string str_val;
		data += change_int2str(root->val, str_val);
		data += '#';
		BST_preorder(root->left, data);
		BST_preorder(root->right, data);
	}
	string change_int2str(int val, string &data)
	{
		string tmp;
		while (val)
		{
			tmp += val % 10 + '0';
			val = val / 10;
		}
		for (int i = tmp.length() - 1; i >= 0; --i)
		{
			data += tmp[i];
		}
		return data;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.length() == 0)
		{
			return NULL;
		}//不能少了这个
		vector<TreeNode*> node_vec;
		int val = 0;
		for (int i = 0; i<data.length(); ++i)
		{
			if (data[i] == '#')
			{
				node_vec.push_back(new TreeNode(val));
				val = 0;
			}
			else
			{
				val = val * 10 + data[i] - '0';
			}
		}
		for (int i = 1; i<node_vec.size(); ++i)
		{
			BST_insert(node_vec[0], node_vec[i]);
		}
		return node_vec[0];
	}
	void BST_insert(TreeNode* root, TreeNode* insert_node)
	{
		if (insert_node->val<root->val)
		{
			if (root->left)
			{
				BST_insert(root->left, insert_node);
			}
			else
			{
				root->left = insert_node;
			}
		}
		else
		{
			if (root->right)
			{
				BST_insert(root->right, insert_node);
			}
			else
			{
				root->right = insert_node;
			}
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));