class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> digit_letter_map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} 
        };

        vector<string> result;


        string path;

        function<void(int)> backtrack = [&](int index) {
            if(path.size() == digits.size()) {
                result.push_back(path);
                return;
            }

            auto& choices = digit_letter_map[digits[index]];

            for(char choice : choices) {
                path.push_back(choice);
                backtrack(index + 1);
                path.pop_back();
            }
        };

        backtrack(0);

        return result;
    }
};
