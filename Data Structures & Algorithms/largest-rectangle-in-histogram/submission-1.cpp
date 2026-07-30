class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> st; // monotonically increasing

        for(int i=0; i<=n; i++) {
            int start = i;
            int current_height = (i==n) ? 0 : heights[i];

            while(!st.empty() && current_height < st.top().second) {
                auto[idx, height] = st.top();
                st.pop();
                maxArea = max(maxArea, height * (i - idx));
                start = idx;
            }

            if(i<n) {
                st.push({start, current_height});
            }
        }

        return maxArea;
    }
};
