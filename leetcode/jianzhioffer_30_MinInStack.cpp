//同leetcode 155
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
//自己一遍AC
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