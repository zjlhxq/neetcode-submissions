class Solution {
public:
    bool isPalindrome(string s) {
        string preprocessed;
        for(char c: s) {
            if(isalnum(c)) {
                preprocessed.push_back(tolower(c));
            } 
        }

        int l=0, r=preprocessed.length()-1;

        while(l < r) {
            if(preprocessed[l] != preprocessed[r]){
                return false;
            }
            l ++;
            r --;
        }

        return true;
    }

};
