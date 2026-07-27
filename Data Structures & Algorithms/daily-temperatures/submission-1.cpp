class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> temp_stack;

        for(int i=0; i< temperatures.size(); i++) {
            while(!temp_stack.empty() && temperatures[i] > temperatures[temp_stack.top()]) {
                int index = temp_stack.top();
                temp_stack.pop();
                result[index] = (i - index);
            }

            temp_stack.push(i);
        }

        return result;
    }
};
