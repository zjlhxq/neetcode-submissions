class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int max_length = 0;
        int max_freq_count = 0;
        for(int right = 0; right < s.length(); right ++) {
            max_freq_count = max(max_freq_count, ++count[s[right]]);

            if (right - left + 1 - max_freq_count > k) { // breaks the condition
                count[s[left]] --;
                left ++;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }  
};
