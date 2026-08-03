class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char,int> needed;
        for(char c: t) {
            needed[c] ++;
        }

        int left =0;

        unordered_map<char, int> window;
        int min_length = INT_MAX;
        int min_left = 0;
        const int required = needed.size();
        int formed = 0;
        for(int right = 0; right < s.size(); right++ ) {
            char cur_char = s[right];
            window[cur_char] ++;

            if(needed.contains(cur_char) && needed[cur_char] == window[cur_char]) {
                formed ++;
            }

            while(formed == required) {
                int cur_length = right - left + 1;
                if (cur_length < min_length) {
                    min_length = cur_length;
                    min_left = left;
                }

                char lc = s[left];
            
                if(needed.contains(lc) && window[lc] == needed[lc]) {
                    formed --;
                }
                
                window[lc] --;
                left ++;
            }

        }

        if(min_length == INT_MAX) return "";
        
        return s.substr(min_left, min_length);
        
    }    
};
