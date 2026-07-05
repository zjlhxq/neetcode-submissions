class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(auto & str : strs) {
            vector<int> count(26,0);

            for( char c : str) {
                count[c - 'a'] ++;
            }

            string key;
            for (int n : count) {
                key += "#" + to_string(n);
            }

            groups[key].push_back(str);
        }

        vector<vector<string>> result;
        for( auto &[_, group] : groups){
            result.push_back(move(group));
        }

        return result;
    }
};
