class Solution {
public:

    string encode(vector<string>& strs) {
        // '<length>#string<length>#string
        string result;
        for (auto & str : strs) {
            result = result + to_string(str.length()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        
        vector<string> result;
        for(int i=0; i<s.length(); ) {
            int j = i;
            while(s[j] != '#') {
                j++; 
            }

            //
            int len = stoi(s.substr(i, j-i +1));
            
            i = j + 1 + len;
            result.push_back(s.substr(j+1, len));
        }
        return result;
    }
};
