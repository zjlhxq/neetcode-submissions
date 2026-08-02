class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> needed;
        for (auto c : s1) {
            needed[c] ++;
        }

        int left = 0;
        unordered_map<char, int> window;
        for(int right = 0; right < s2.size(); right ++) {
            window[s2[right]] ++;

            if(right - left + 1 > s1.length()) {
                window[s2[left]] --;
                if(window[s2[left]] <= 0) window.erase(s2[left]);
                
                left ++;
            }

            if (right -left +1 == s1.length()) {
                if(needed == window) return true;
            }
        }

        return false;

    }  
};
