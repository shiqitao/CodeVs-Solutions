class MyQueue {
public:
	stack<int> stack1;
	stack<int> stack2;
	MyQueue() {
		// do intialization if necessary
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element) {
		// write your code here
		if (stack1.empty()) {
			while (!stack2.empty()) {
				stack1.push(stack2.top());
				stack2.pop();
			}
			stack1.push(element);
		}
		else {
			stack1.push(element);
		}
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		if (stack2.empty()) {
			while (stack1.size() != 1) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			int result = stack1.top();
			stack1.pop();
			return result;
		}
		else {
			int result = stack2.top();
			stack2.pop();
			return result;
		}
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			return stack2.top();
		}
		else {
			return stack2.top();
		}
	}
};