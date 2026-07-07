class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> open_stack;
        
        for (char c : s) {
            auto it = pairs.find(c);
            
            // If not found, it is an opening bracket
            if (it == pairs.end()) {
                open_stack.push(c);
            } 
            // If found, it is a closing bracket
            else {
                if (open_stack.empty()) return false;
                
                if (open_stack.top() != it->second) return false;
                
                open_stack.pop();
            }
        }

        return open_stack.empty();
    }
};
