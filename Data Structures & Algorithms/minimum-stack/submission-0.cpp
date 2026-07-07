class MinStack {
private:
    stack<pair<int,int>> backing_stack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(backing_stack.empty()) {
            backing_stack.push({val, val});
        } else {
            int min_val = min(val, backing_stack.top().second);
            backing_stack.push({val, min_val});
        }
    }
    
    void pop() {
        if(backing_stack.empty()) return;

        backing_stack.pop();
    }
    
    int top() {
        return backing_stack.top().first;
    }
    
    int getMin() {
        return backing_stack.top().second;
    }
};
