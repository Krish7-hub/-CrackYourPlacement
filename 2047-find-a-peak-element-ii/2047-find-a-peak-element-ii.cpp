class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vat(m+2, vector<int>(n+2, -1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                vat[i][j] = mat[i-1][j-1];
            }
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(vat[i][j] > vat[i][j-1] && vat[i][j] > vat[i-1][j] && vat[i][j] > vat[i][j+1] && vat[i][j] > vat[i+1][j]){
                    return {i-1, j-1};
                }
            }
        }
        return {-1, -1};
    }
};