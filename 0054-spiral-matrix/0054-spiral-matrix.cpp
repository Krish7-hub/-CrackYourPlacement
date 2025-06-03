class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int total = m * n;
        int count = 0;

        int firstRow = 0;
        int lastRow = m - 1;
        int firstCol = 0;
        int lastCol = n - 1;

        vector<int>ans;

        while(count < total){

            for(int i = firstRow; i <= lastCol && count < total; i++){
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;

            for(int i = firstRow; i <= lastRow && count < total; i++){
                ans.push_back(matrix[i][lastCol]);
                count++;
            }
            lastCol--;

            for(int i = lastCol; i >= firstCol && count < total; i--){
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;

            for(int i = lastRow; i >= firstRow && count < total; i--){
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }

        return ans;

    }
};