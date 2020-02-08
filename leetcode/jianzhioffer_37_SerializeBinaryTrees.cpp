//ͬleetcode297
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
//��һ��ⷨ����û�п��ǽڵ�ֵΪ�������������leetcode297
class Solution {
public:
	char* Serialize(TreeNode *root) {
		string str;
		Serialize2(root, str);
		char * res = new char[str.size() + 1];
		for (int i = 0; i<str.size(); ++i)
		{
			res[i] = str[i];
		}
		res[str.size()] = '\0';
		return res;
	}
	void Serialize2(TreeNode *root, string &str)
	{
		if (!root)
		{
			str = str + '#';
			return;
		}
		str = str + to_string(root->val) + '!';
		Serialize2(root->left, str);
		Serialize2(root->right, str);
	}
	TreeNode* Deserialize(char *str) {
		TreeNode *root = NULL;//ע��Ҫ��ʼ��ΪNULL����������
		Deserialize(root, str);
		return root;
	}
	void Deserialize(TreeNode* &root, char *&str)
	{
		if (*str == '#')
		{
			++str;
			return;
		}
		int num = 0;
		while (*str != '\0'&&*str != '!')
		{
			num = num * 10 + *str - '0';
			++str;
		}
		root = new TreeNode(-1);//��Ҫ�½��ڵ������
		root->val = num;
		if (*str == '\0')
		{
			return;
		}
		else {
			++str;
		}
		Deserialize(root->left, str);
		Deserialize(root->right, str);
	}
};