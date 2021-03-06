//同剑指offer 30
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (min.empty())
		{
			min.push(x);
		}
		else
		{
			if (x>min.top())
			{
				x = min.top();
			}
			min.push(x);
		}
	}

	void pop() {
		s.pop();
		min.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack<int> s;
	stack<int> min;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/


//自己做出，一遍ac
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (mins.empty() || x<mins.top())
		{
			mins.push(x);
		}
		else
		{
			mins.push(mins.top());
		}
	}

	void pop() {
		s.pop();
		mins.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return mins.top();
	}
private:
	stack<int> s;
	stack<int> mins;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/