class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int max_length = 0;
        while(right < s.length()) {
            char cur_char = s[right];
            while(window.contains(cur_char)) {
                //shrink window
                window.erase(s[left++]);
            }
            
            window.insert(cur_char);

            max_length = max(max_length, right - left + 1);

            right ++;

        }

        return max_length;
    }
};
