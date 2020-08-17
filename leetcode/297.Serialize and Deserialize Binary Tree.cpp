//ͬ��ָoffer37
//�Լ�����
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
	TreeNode* deserialize(string data, int &i)//ע�������&i���������root->right = deserialize(data, i);�ֱ����root->left = deserialize(data, i);ǰ��i
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
				if (data[i] == '-')//ע���и��ŵ����
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