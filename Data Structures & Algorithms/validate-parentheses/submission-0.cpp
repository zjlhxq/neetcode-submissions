class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> p_map = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> char_stack;
        for(char c : s) {
            if( c == '(' || c == '{' || c == '[') {
                char_stack.push(c);
            } else {
                if (char_stack.empty()) return false;

                char cur_char = char_stack.top();
                char_stack.pop();
                if(cur_char != p_map[c]) return false;
            }
        }

        return char_stack.empty();
    }
};
