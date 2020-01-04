//ͬleetcode232
class Solution
{
public:
	void push(int node) {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack2.push(node);
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	int pop() {
		int x = stack1.top();
		stack1.pop();
		return x;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};