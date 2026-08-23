class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;

        function<void(int, int)> backtrack = [&](int open, int close) {
            if(path.size() == 2*n) {
                result.push_back(path);
                return;
            }

            if(open < n) {
                path.push_back('(');
                backtrack(open + 1, close);
                path.pop_back();
            }

            if( close < open) {
                path.push_back(')');
                backtrack(open, close + 1);
                path.pop_back();
            }
        };

        backtrack(0, 0);

        return result;
    }
};
