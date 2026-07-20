class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        for( auto token : tokens) {
            if( token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') ) {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
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
                s.push(c);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
        
    }
};
