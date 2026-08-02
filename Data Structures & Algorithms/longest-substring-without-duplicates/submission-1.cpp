class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> last_seen(128, false);
        int left = 0, right = 0;
        int max_length = 0;
        while(right < s.length()) {
            char cur_char = s[right];
            while(last_seen[cur_char]) {
                //shrink window
                last_seen[s[left++]] = false;
            }
            
            last_seen[s[right]] = true;

            max_length = max(max_length, right - left + 1);

            right ++;

        }

        return max_length;
    }
};
