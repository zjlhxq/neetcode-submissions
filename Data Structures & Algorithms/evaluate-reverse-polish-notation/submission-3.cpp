class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> s;
        for( auto token : tokens) {
            if( token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') ) {
                int b = stoi(s.top()); s.pop();
                int a = stoi(s.top()); s.pop();
                
                int c = -1;
                if (token[0] == '+') {
                    c = a + b;
                } else if(token[0] == '-') {
                    c = a - b;
                } else if (token[0] == '*') {
                    c = a * b;
                } else if (token[0] == '/') {
                    c = a / b;
                }
                s.push(to_string(c));
            } else {
                s.push(token);
            }
        }

        return stoi(s.top());
        
    }
};
