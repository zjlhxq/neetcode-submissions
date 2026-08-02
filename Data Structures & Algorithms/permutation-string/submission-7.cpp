class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> needed(26, 0);
        for (auto c : s1) {
            needed[c - 'a'] ++;
        }

        int left = 0;
        vector<int> window(26, 0);
        for(int right = 0; right < s2.size(); right ++) {
            window[s2[right] - 'a'] ++;

            if(right - left + 1 > s1.length()) {
                window[s2[left]- 'a'] --;

                left ++;
            }

            if (right -left +1 == s1.length()) {
                if(needed == window) return true;
            }
        }

        return false;
    }  
};
