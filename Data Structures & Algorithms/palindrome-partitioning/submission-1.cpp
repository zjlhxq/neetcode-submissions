class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        function<void(int)> backtrack = [&](int start) {
            if(start == s.size()) {
                result.push_back(path);
                return;
            }

            for(int end = start; end < s.size(); end++) {
                if(!is_palindrome(s, start, end)) continue;

                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
private:
    bool is_palindrome(const string& str, int start, int end) {
        while(start < end) {
            if(str[start++] != str[end--]) return false;
        }

        return true;
    }    
};
