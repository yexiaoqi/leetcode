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
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root)
		{
			return{};//���ؿն�����root�����Ͳ�ͬ
		}
		stack<TreeNode*> s{ { root } };//ջ�ĳ�ʼ��
									   //stack<TreeNode*> s={{root}};
		vector<int> res;
		TreeNode* head = root;
		while (!s.empty())
		{
			TreeNode* t = s.top();
			if ((!t->left && !t->right) || t->left == head || t->right == head)//Ҷ�ڵ�����ӽڵ�Ϊ�Ѿ�������Ľڵ�����
			{
				res.push_back(t->val);
				s.pop();
				head = t;
			}
			else
			{
				if (t->right)
				{
					s.push(t->right);
				}
				if (t->left)
				{
					s.push(t->left);
				}
			}
		}
		return res;
	}
};


//ģ��ⷨ
//���ں��������˳������ - �� - ���������������˳���Ǹ� - �� - �ң�������ʵ���Ǻ������
//������������������ķ�������ЩС�Ķ���ʹ�����˳���Ϊ�� - �� - ��Ȼ��תһ�£������� - �� - ������
//��ת�ķ�������ʹ�÷���Q��Ŷ�����Ƿ�������� res��ÿ�ζ��ڽ�� res �Ŀ�ͷ������ֵ��
//���ı����������˳���ֻҪ�ñ���һ����ջ˳��������ң�������ջ�����ʱ��������Һ�����
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *p = root;
		while (!s.empty() || p) {
			if (p) {
				s.push(p);
				res.insert(res.begin(), p->val);
				p = p->right;
			}
			else {
				TreeNode *t = s.top(); s.pop();
				p = t->left;
			}
		}
		return res;
	}
};

//��ϰ
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode* p = root;
		while (!s.empty() || p)
		{
			if (p)
			{
				s.push(p);
				res.insert(res.begin(), p->val);
				p = p->right;
			}
			else
			{
				p = s.top();
				s.pop();
				p = p->left;
			}
		}
		return res;
	}
};