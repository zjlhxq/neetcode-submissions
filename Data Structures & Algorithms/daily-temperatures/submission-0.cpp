class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> temp_stack;

        for(int i=0; i< temperatures.size(); i++) {
            while(!temp_stack.empty() && temperatures[i] > temp_stack.top().first) {
                auto [temp, index] = temp_stack.top();
                temp_stack.pop();
                result[index] = (i - index);
            }

            temp_stack.push({temperatures[i], i});
        }

        return result;
    }
};
