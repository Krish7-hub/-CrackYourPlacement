class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int col0 = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0 && j == 0){
                    col0 = 0;
                }
                else if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = m-1; i >= 1; i--){
            for(int j = n-1; j >= 1; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(matrix[0][0] == 0){
                matrix[0][i] = 0;
            }
        }

        for(int i = m-1; i >= 0; i--){
            if(col0 == 0){
                matrix[i][0] = 0;
            }
        }
        return;

    }
};