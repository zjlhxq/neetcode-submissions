class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int maxArea = 0;
        stack<pair<int, int>> st; // monotonically increasing

        for(int i=0; i<heights.size(); i++) {
            int start = i;
            while(!st.empty() && heights[i] < st.top().second) {
                auto[idx, height] = st.top();
                st.pop();
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
            }

            st.push({start, heights[i]});
        }

        while(!st.empty()) {
            auto[idx, height] = st.top();
            st.pop();
            maxArea = max<int>(maxArea, height * (heights.size() - idx));
        }
        
        return maxArea;
    }
};
