class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int totalNumber = m * n;
        int count = 0;

        vector<int>ans;

        int startRow = 0;
        int endRow = m - 1;
        int startCol = 0;
        int endCol = n - 1;

        while(count < totalNumber){

            for(int i = startCol; i <= endCol && count < totalNumber; i++){
                ans.push_back(matrix[startRow][i]);
                 count++;
            }
            startRow++;

            for(int i = startRow; i <= endRow && count < totalNumber; i++){
                ans.push_back(matrix[i][endCol]);
                 count++;
            }
            endCol--;

            for(int i = endCol; i >= startCol && count < totalNumber; i--){
                ans.push_back(matrix[endRow][i]);
                 count++;
            }
            endRow--;

            for(int i = endRow; i >= startRow && count < totalNumber; i--){
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
        
    }
};