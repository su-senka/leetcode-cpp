class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;              
        long long maxArea = 0;
        const int n = (int)heights.size();

        for (int i = 0; i <= n; ++i) {
            int curr = (i < n ? heights[i] : 0); 

            while (!st.empty() && curr < heights[st.back()]) {
                int h = heights[st.back()];
                st.pop_back();
                int left = st.empty() ? -1 : st.back();
                long long width = i - left - 1;
                maxArea = max(maxArea, 1LL * h * width);
            }
            
            st.push_back(i);
        }
        return maxArea;
    }
};
