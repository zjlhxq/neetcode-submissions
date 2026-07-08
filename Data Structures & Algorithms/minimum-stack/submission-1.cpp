class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        data_stack.push(val);
        if(min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }
    
    void pop() {
        if(min_stack.top() == data_stack.top()) {
            min_stack.pop();
        }

        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
