class Solution {
public:
    int lHist(vector<int>arr){
        stack<int>st;
        int maxArea = INT_MIN;
        int len = arr.size();

        for(int i = 0; i < len; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (nse - pse - 1)*arr[element]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = len;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse - pse - 1) * arr[element]);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>pSum(row, vector<int>(col, 0));
        for(int i = 0; i < col; i++){
            int sum = 0; 
            for(int j = 0; j < row; j++){
                sum += (matrix[j][i] - '0');
                if((matrix[j][i] - '0') == 0) sum = 0;
                pSum[j][i] = sum;
            }
        }
        int maxArea = INT_MIN;
        for(int i = 0; i < row; i++){
            maxArea = max(maxArea, lHist(pSum[i]));
        }
        return maxArea;        
    }
};