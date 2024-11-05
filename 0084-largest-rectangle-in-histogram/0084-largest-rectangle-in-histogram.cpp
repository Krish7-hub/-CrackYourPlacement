class Solution {
public:
    vector<int>nextSmallestNumber(vector<int>& heights){
        int len = heights.size();
        stack<int>st;
        vector<int>nse(len);
        for(int i = len-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            nse[i] = st.empty() ? len : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>prevSmallestNumber(vector<int>& heights){
        int len = heights.size();
        stack<int>st;
        vector<int>pse(len);
        for(int i = 0; i < len; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int>nse(len);
        nse = nextSmallestNumber(heights); 
        vector<int>pse(len);
        pse = prevSmallestNumber(heights);
        int maxi = INT_MIN;
        for(int i = 0; i < len; i++){
            maxi = max(maxi, ((nse[i] - pse[i] - 1) * heights[i]));
        }
        return maxi;
    }
};