class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int max_length = 0;
        for(int right = 0; right < s.length(); right ++) {
            count[s[right]] ++;
            int cur_length = right - left + 1;
            if(cur_length - get_max_freq_count(count) > k) { // breaks the condition
                count[s[left]] --;
                left ++;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
private:
    int get_max_freq_count(unordered_map<char, int> freq_map) {
        int max_count = 0;
        for(auto[_, count]: freq_map) {
            max_count = max(max_count, count);
        }

        return max_count;
    }    
};
