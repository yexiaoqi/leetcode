//ͬleetcode 155
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
//�Լ�һ��AC
class Solution {
public:
	void push(int value) {
		s.push(value);
		if (mins.empty())
		{
			mins.push(value);
		}
		else
		{
			if (value<mins.top())
			{
				mins.push(value);
			}
			else
			{
				mins.push(mins.top());
			}
		}
	}
	void pop() {
		s.pop();
		mins.pop();
	}
	int top() {
		return s.top();
	}
	int min() {
		return mins.top();
	}
private:
	stack<int> s;
	stack<int> mins;
};