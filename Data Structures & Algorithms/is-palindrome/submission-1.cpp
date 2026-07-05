class Solution {
public:
    bool isPalindrome(string s) {
        string preprocessed;
        for(char c: s) {
            if(isalnum(c)) {
                preprocessed.push_back(tolower(c));
            } 
        }

        std::cout << "preprocessed:" << preprocessed << endl;
        int l=0, r=preprocessed.length()-1;
        std::cout << "r: " << r << endl;
        while(l < r) {
            std::cout << "l=" << l <<", r=" << r << endl;
            if(preprocessed[l] != preprocessed[r]){
                return false;
            }
            l ++;
            r --;
        }

        return true;
    }

};
