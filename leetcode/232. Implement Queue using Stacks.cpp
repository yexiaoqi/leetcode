class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack<int> temp;

		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		temp.push(x);
		while (!temp.empty())
		{
			s.push(temp.top());
			temp.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int x = s.top();
		s.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		return s.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s.empty();
	}
private:
	stack<int> s;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/