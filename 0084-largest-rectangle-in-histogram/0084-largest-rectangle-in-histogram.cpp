class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int>st;
        int maxArea = INT_MIN;
        int len = heights.size();
        for(int i = 0; i < len; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = len;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * heights[element]);
        }
        return maxArea;
    }
};